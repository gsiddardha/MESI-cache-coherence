#include <iostream>
#include <cstdlib>

#include "Memory.h"

using namespace std;

Memory::Memory(int data_numbers, int block_size) {
	this->num_words	= block_size/4;
	this->num_blocks	= data_numbers/this->num_words + 1;
	this->writer	= 0;
	this->data	= new Block*[this->num_blocks];
	for(int i=0; i<num_blocks; i++)
		this->data[i] = new Block(i, i, block_size);
}

void Memory::write(int value) {
	int block_num = writer/num_words;
	this->data[block_num]->set_word(writer % num_words, value);
	this->writer++;
}

Block* Memory::read(int address) {
	int block_num = address/num_words;
	return this->data[block_num];
}

void Memory::print(void) {
	for(int i=0; i<num_blocks; i++) {
		for(int j=0; j<num_words; j++)
			cout << "\t" << this->data[i]->get_word(j);
		cout << endl;
	}
}

Memory::~Memory(void) {
	for(int i=0; i<num_blocks; i++)
		delete this->data[i];
	delete this->data;
}
