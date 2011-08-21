#ifndef CACHE_H
#define CACHE_H

#include "Set.h"

/* Class: Cache
 *
 * We have implemented Set-Associative Mapping i.e. a combination
 * of direct and associative-mapping techniques.
 *
 * Blocks of cache are grouped into sets, and the mapping allows a
 * block of the main memory to reside in any block of a specific set.
 *
 * Main memory Address is parsed to the following format
 * -----------------------------------
 * | Tag Bits | Set Bits | Word Bits |
 * -----------------------------------
 *
 * The number of bits for tag, set and word are calculated from
 * the block size, cache size and associativity.
 */


class Cache {
	public:
		Cache(int cache_size, int block_size, int set_size, int bits_n);

		int get_hits(void);
		int get_misses(void);
		int get_memory(int address);

		void insert_block(int address, Block* new_block);

		~Cache(void);

	private:
		int cache_size; // Size of cache in bytes
		int block_size;	// Size of block in bytes
		int set_size;	// Size of set in bytes
		int assoc;		// Associativity

		int set_n;		// Number of sets
		int bits_n;		// Number of bits in Main memory address

		int set_bits;	// Number of bits for Set
		int tag_bits;	// Number of bits for Tag
		int word_bits;	// Number of bits for Word

		int set_mul;	// Number to be bitwise-multiplied with location to get set index
		int tag_mul;	// Number to be bitwise-multiplied with location to get tag index
		int word_mul;	// Number to be bitwise-multiplied with location to get word index

		int hits;		// Number of hits
		int misses;		// Number of misses

		Set** memory;	// Cache memory - Has set_n sets
};

#endif /* CACHE_H_ */
