#ifndef MEMORY_H_
#define MEMORY_H_

#include "Block.h"

class Memory {
	public:
		Memory(int data_numbers, int block_size);

		Block* read(int address);
		void write(int value);
		void print(void);

		~Memory(void);

	private:
		Block** data;

		int num_blocks;
		int num_words;
		int writer;
};

#endif /* MEMORY_H_ */
