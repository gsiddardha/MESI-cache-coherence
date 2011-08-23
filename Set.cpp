#include <cstdlib>
#include "Set.h"

Set::Set(int assoc, int block_size) {
	this->assoc		= assoc;
	this->block_size	= block_size;
	this->_counter 	= 0;

	// Initialising dirty and Blocks
	this->dirty = new bool[assoc];
	this->data = new Block*[assoc];
	for(int i=0; i<assoc; i++) {
		this->data[i] = new Block(i, this->counter(), block_size);
		this->dirty[i] = false;
	}
}

Block* Set::get_block(int index) {
	return this->data[index];
}

bool Set::get_dirty(void) {
	return this->dirty[this->lru];
}

void Set::insert_block(int tag_value, Block* new_block) {
	this->lru = 0;

	for(int i=0; i<assoc; i++) {
		Block* temp = this->data[i];
		if(temp->get_counter() < (this->data[lru])->get_counter())
			this->lru = i;
	}

	Block* temp_block = this->data[this->lru];
	temp_block->set_block(this->counter(), tag_value, new_block);
}

int Set::counter() {
	this->_counter++;
	return this->_counter;
}

void Set::inc_counter(int index) {
	Block* temp_block = this->data[index];
	temp_block->set_counter(this->counter());
}

void Set::set_dirty(void) {
	this->dirty[this->lru] = true;
}

Set::~Set() {
	for(int i=0; i<assoc; i++)
		delete this->data[i];
	delete this->data;
	delete this->dirty;
}
