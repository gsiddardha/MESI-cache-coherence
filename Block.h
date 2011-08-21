#ifndef BLOCK_H_
#define BLOCK_H_

class Block {
public:
	Block(int index, int counter, int block_size);
	~Block();

	void set_block(int counter, int tag, Block* new_block);
	void set_tag(int tag);

	int	get_tag();
	int get_index();
	int get_word(int index);
	int get_counter();

private:
	int tag;		// Tag bits of the block
	int counter;	// Unique counter of the block
	int index;		// Index in the array.
	int word_n;		// Number of words present in the block

	int* words;		// Array of words (integers)
};

#endif /* BLOCK_H_ */
