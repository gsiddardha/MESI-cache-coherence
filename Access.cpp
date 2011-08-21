#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Access.h"

using namespace std;

Access::Access(int cache_size, int block_size, int assoc, int memory_size) {
	this->bits_n = log2(memory_size);
	this->memory = new Memory(memory_size);
	this->cache = new Cache(cache_size, block_size, assoc, this->bits_n);
}

void Access::write(int value) {
	this->memory->write(value);
}

void Access::set(int addr, int value) {
	this->memory->store(addr, value);
}

int Access::get(int addr) {
	return this->memory->read(addr);
}

Access::~Access(void) {
	delete this->memory;
	delete this->cache;
}
