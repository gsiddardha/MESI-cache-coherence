#ifndef ACCESS_H_
#define ACCESS_H_

#include "Memory.h"
#include "Cache.h"

class Access {
	public:
		Access(int cache_size, int block_size, int assoc, int memory_size);

		void write(int value);
		int get(int addr);
		void print(void);
		void restart_cache(void);

		~Access(void);

	private:
		Memory* memory;
		Cache* cache;

		int accesses;
};

#endif /* ACCESS_H_ */
