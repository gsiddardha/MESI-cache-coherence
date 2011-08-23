#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Access.h"

using namespace std;

Access::Access(int cache_size, int block_size, int assoc, int data_numbers) {
	this->accesses	= 0;
	this->memory	= new Memory(data_numbers, block_size);
	this->cache	= new Cache(cache_size, block_size, assoc, log2(data_numbers*4), this->memory);
}

void Access::print(char* str) {
	cout << endl;
	cout << "\tCache " << str << " Statistics:" << endl;
	cout << "\t\tAccesses: " << this->accesses << endl;
	cout << "\t\tHits: " << this->cache->get_hits() << endl;
	cout << "\t\tMisses: " << this->cache->get_misses() << endl;
	cout << "\t\tCold Misses: " << this->cache->get_cold_misses() << endl;
	cout << "\t\tCapacity Misses: " << this->cache->get_capacity_misses() << endl;
	cout << "\t\tConflict Misses: " << this->cache->get_conflict_misses() << endl;
}

void Access::restart_cache(void) {
	this->accesses = 0;
	this->cache->restart();
}

void Access::write(int value) {
	this->memory->write(value);
}

int Access::get(int addr) {
	this->accesses++;
	return this->cache->get_cached(addr);
}

Access::~Access(void) {
	delete this->memory;
	delete this->cache;
}
