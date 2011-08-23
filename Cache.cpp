#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Cache.h"

using namespace std;

Cache::Cache(int cache_size, int block_size, int assoc, int num_bits, Memory* memory) {
	this->memory		= memory;

	this->cache_size	= cache_size;
	this->block_size	= block_size;

	if(assoc==0) {
		this->assoc = cache_size/block_size;
		this->set_size = cache_size;
	} else {
		this->assoc = assoc;
		this->set_size = this->block_size * assoc;
	}

	this->num_words		= this->block_size/4;
	this->num_sets 	 	= this->cache_size/this->set_size;
	this->num_bits 		= num_bits;

	this->word_bits		= log2(this->num_words);
	this->set_bits		= log2(this->num_sets);
	this->tag_bits		= this->num_bits - (this->set_bits + this->word_bits);

	this->word_mul 		= pow(2, this->word_bits) -1;
	this->set_mul 		= pow(2, this->word_bits) * (pow(2, this->set_bits) - 1);
	this->tag_mul 		= pow(2, this->word_bits + this->set_bits) * (pow(2, this->tag_bits) - 1);

	// Initialising Statistics
	this->hits = 0;
	for(int i=0; i<4; i++)
		this->misses[i] = 0;

	// Initialising Cache
	this->data = new Set*[this->num_sets];
	for( int i=0; i<num_sets; i++) {
		this->data[i] = new Set(this->assoc, this->block_size);
	}
}

void Cache::restart(void) {
	for(int i=0; i<num_sets; i++)
		delete this->data[i];
	delete this->data;

	this->data = new Set*[this->num_sets];
	for(int i=0; i<num_sets; i++)
		this->data[i] = new Set(this->assoc, this->block_size);

	this->hits = 0;
	for(int i=0; i<4; i++)
		this->misses[i] = 0;
}

int Cache::get_hits(void) {
	return this->hits;
}

int Cache::get_misses(void) {
	return this->misses[0];
}

int Cache::get_cold_misses(void) {
	return this->misses[1];
}

int Cache::get_capacity_misses(void) {
	return this->misses[2];
}

int Cache::get_conflict_misses(void) {
	return this->misses[3];
}

int Cache::get_cached(int address) {
	int word_num	= this->word_mul & address;
	int set_num	= (this->set_mul & address)/pow(2, this->word_bits);
	int tag_num	= (this->tag_mul & address)/pow(2, this->word_bits + this->set_bits);

	Set* cur_set = this->data[set_num];
	for(int i=0; i<assoc; i++) {
		Block* cur_block = cur_set->get_block(i);
		if(cur_block->get_tag() == tag_num) {
			cur_set->inc_counter(cur_block->get_index());
			this->hits++;
			return cur_block->get_word(word_num);
		}
	}

	this->misses[0]++;

	Block* cur_block = this->memory->read(address);
	cur_set->insert_block(tag_num, cur_block);
	if(cur_set->get_dirty()==false) {
		this->misses[1]++;
		cur_set->set_dirty();
	} else {
		this->misses[3]++;
	}

	return cur_block->get_word(address % this->num_words);
}

Cache::~Cache(void) {
	for(int i=0; i<this->num_sets; i++)
		delete this->data[i];
	delete this->data;
}
