#ifndef SET_H_
#define SET_H_

#include "Block.h"

class Set {
	public:
		Set(int assoc, int block_size);

		Block* get_block(int index);
		bool get_dirty(void);

		void insert_block(int tag_value, Block* new_block);
		int counter(void);
		void inc_counter(int index);

		void set_dirty(void);

		~Set();

	private:
		Block** data;	// Array of Blocks
		bool* dirty;	// Array of dirty bits

		int assoc;	// Associativity
		int block_size;	// Size of each block
		int _counter;	// Counter for giving unique index to each block
		int lru;		// Index of block having the least value of counter
};

#endif /* SET_H_ */
