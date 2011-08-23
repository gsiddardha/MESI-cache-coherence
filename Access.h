#ifndef ACCESS_H_
#define ACCESS_H_

#include "Memory.h"
#include "Cache.h"

class Access {
	public:
		Access(int cache_size, int block_size, int assoc, int data_numbers);

		void write(int value);
		int get(int addr);
		void print(char* str);
		void restart_cache(void);

		~Access(void);

	private:
		Memory* memory;
		Cache* cache;

		int accesses;
};

#endif /* ACCESS_H_ */
