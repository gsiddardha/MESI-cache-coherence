#ifndef BLOCK_H_
#define BLOCK_H_

class Block {
	public:
		Block(int index, int counter, int block_size);

		void set_block(int counter, int tag, Block* new_block);
		void set_tag(int tag);
		void set_word(int index, int value);

		int get_tag(void);
		int get_index(void);
		int get_word(int index);
		int get_word_by_addr(int addr);

		int get_counter(void);
		void set_counter(int counter);

	~Block();

	private:
		int tag;	// Tag bits of the block
		int counter;	// Unique counter of the block
		int index;	// Index in the array.
		int word_n;	// Number of words present in the block

		int* words;	// Array of words (integers)
};

#endif /* BLOCK_H_ */
