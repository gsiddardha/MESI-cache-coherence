#include <iostream>
#include <cstdlib>

#include "Memory.h"

using namespace std;

Memory::Memory(int size) {
	this->size = size*256;
	this->writer = 0;
	this->memory = new int[this->size];
}

void Memory::write(int value) {
	this->memory[writer++] = value;
}

int Memory::read(int address) {
	return this->memory[address];
}

void Memory::store(int address, int value) {
	this->memory[address] = value;
}

Memory::~Memory(void) {
	delete this->memory;
}
