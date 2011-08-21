#ifndef SET_H_
#define SET_H_

#include "Block.h"

class Set {
public:
	Set(int assoc, int block_size);
	~Set();

	Block* get_block(int index);
	void insert_block(int tag_value, Block* new_block);
	int	get_counter();

private:
	int assoc;		// Associativity
	int block_size;	// Size of each block

	int counter;	// Counter for giving unique index to each block
	int lru;		// Index of block having least value of counter

	Block** blocks;	// Array of Blocks
};

#endif /* SET_H_ */
