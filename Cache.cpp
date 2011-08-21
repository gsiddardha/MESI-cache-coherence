#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Cache.h"

using namespace std;

Cache::Cache(int cache_size, int block_size, int assoc, int bits_n) {
	this->hits			= 0;
	this->misses		= 0;

	this->assoc 		= assoc;
	this->cache_size	= cache_size*1024;	// Cache size is given in KB
	this->block_size	= block_size;		// Block size is given in B
	this->set_size 	 	= this->block_size * assoc;

	this->set_n 	 	= this->cache_size / this->set_size;
	this->bits_n 	 	= bits_n;

	this->word_bits		= this->block_size / 4;
	this->set_bits		= log2(set_n);
	this->tag_bits		= this->bits_n - (this->set_bits + this->word_bits);

	this->set_mul 		= pow10(this->word_bits) * (pow(2, set_bits) - 1);
	this->tag_mul 		= pow10(this->word_bits + this->set_bits) * (pow(2, tag_bits) - 1);
	this->word_mul 		= pow(2, this->word_bits) -1;

	for( int i=0; i<set_n; i++) {
		this->memory[i] = new Set(this->assoc, this->block_size);
	}
}

int Cache::get_hits(void) {
	return this->hits;
}

int Cache::get_misses(void) {
	return this->misses;
}

int Cache::get_memory(int address) {
	int set_num = this->set_mul & address;
	int tag_num = this->tag_mul & address;
	int word_num = this->word_mul & address;

	Set* cur_set = this->memory[set_num];
	for(int i=0; i < this->assoc; i++) {
		Block* cur_block = cur_set->get_block(i);
		if(cur_block->get_tag() == tag_num) {
			cur_set->inc_counter(cur_block->get_index());
			this->hits++;
			return cur_block->get_word(word_num);
		}
	}

	this->misses++;
	return -1;
}

void Cache::insert_block(int address, Block* new_block) {
	int set_num = this->set_mul & address;
	int tag_num = this->tag_mul & address;

	Set* cur_set = memory[set_num];
	cur_set->insert_block(tag_num, new_block);
}

Cache::~Cache(void) {
	delete this->memory;
}
