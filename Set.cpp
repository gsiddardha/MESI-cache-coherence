#include <cstdlib>
#include "Set.h"

Set::Set(int assoc, int block_size) {
	this->assoc			= assoc;
	this->block_size 	= block_size;

	this->counter 	= 0;
	this->lru 		= 0;

	for(int i=0; i < this->assoc; i++) {
		this->blocks[i] = new Block(i, this->get_counter(), block_size);
	}
}

Block* Set::get_block(int index) {
	return this->blocks[index];
}

void Set::insert_block(int tag_value, Block* new_block) {
	int least = 0;

	for(int i=0; i < this->assoc; i++) {
		Block* temp = this->blocks[i];
		if(temp->get_counter() < (this->blocks[least])->get_counter())
			least = i;
	}
	this->lru = least;

	Block* temp_block = this->blocks[this->lru];
	temp_block->set_block(this->get_counter(), tag_value, new_block);
}

int Set::get_counter() {
	this->counter++;
	return this->counter;
}

void Set::inc_counter(int index) {
	Block* temp_block = this->blocks[index];
	temp_block->set_counter(this->get_counter());
}

Set::~Set() {
	for(int i=0; i < this->assoc; i++)
		delete this->blocks[i];
}
