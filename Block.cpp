#include "Block.h"

Block::Block(int index, int counter, int block_size) {
	this->index		= index;
	this->word_n 	= block_size / 4;
	this->words		= new int[this->word_n];
	this->counter	= counter;
}

int Block::get_tag() {
	return this->tag;
}

int Block::get_index() {
	return this->index;
}

int Block::get_word(int index) {
	return words[index];
}

int Block::get_counter() {
	return this->counter;
}

void Block::set_counter(int counter) {
	this->counter = counter;
}

void Block::set_block(int counter, int tag_value, Block* new_block) {
	this->counter 	= counter;
	this->tag 		= tag_value;

	for(int i=0; i < this->word_n; i++) {
		this->words[i] = new_block->get_word(i);
	}
}

void Block::set_tag(int tag) {
	this->tag = tag;
}

Block::~Block() {
	delete this->words;
}
