#include <iostream>
#include <cstdlib>

#include "Memory.h"

using namespace std;

Memory::Memory(int memory_size, int block_size) {
	this->blocks_n	= memory_size*1024/block_size;
	this->words_n	= block_size/4;
	this->writer	= 0;
	this->memory	= new Block*[this->blocks_n];
	for(int i=0; i<blocks_n; i++)
		this->memory[i] = new Block(i, i, block_size);
}

void Memory::write(int value) {
	int block_num = writer/words_n;
	this->memory[block_num]->set_word(writer % words_n, value);
	this->writer++;
}

Block* Memory::read(int address) {
	int block_num = address / words_n;
	return this->memory[block_num];
}

void Memory::print(void) {
	for(int i=0; i<blocks_n; i++) {
		for(int j=0; j<words_n; j++)
			cout << "\t" << this->memory[i]->get_word(j);
		cout << endl;
	}
}

Memory::~Memory(void) {
	for(int i=0; i<blocks_n; i++)
		delete this->memory[i];
	delete this->memory;
}
