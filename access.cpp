#include <iostream>
#include <cstdlib>
#include "access.h"

using namespace std;

Access::Access(int matrix_n, int cache_size, int block_size, int set_size, int memory_size) {
	this->matrix_n = matrix_n;
	this->memory = new Memory(memory_size);
	this->cache = new Cache(cache_size, block_size, set_size);
}

void Access::write(int value) {
	this->memory->write(value);
}

void Access::set(int x, int y, int value) {
	this->memory->store(x*matrix_n+y, value);
}

int Access::get(int x, int y) {
	return this->memory->read(x*matrix_n+y);
}

Access::~Access(void) {
	delete this->memory;
}
