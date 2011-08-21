#ifndef ACCESS_H
#define ACCESS_H

#include "Memory.h"
#include "Cache.h"

class Access {
public:
	Access(int cache_size, int block_size, int assoc, int memory_size);

	void write(int value);
	void set(int addr, int value);
	int get(int addr);

	~Access(void);

private:
	Memory* memory;
	Cache* cache;
	int bits_n;	// Number of bits in the address
};

#endif
