#ifndef MEMORY_H_
#define MEMORY_H_

#include "Block.h"

class Memory {
	public:
		Memory(int memory_size, int block_size);

		Block* read(int address);
		void write(int value);
		void print(void);

		~Memory(void);

	private:
		Block** memory;

		int blocks_n;
		int words_n;
		int writer;
};

#endif /* MEMORY_H_ */
