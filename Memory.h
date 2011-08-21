#ifndef MEMORY_H
#define MEMORY_H

class Memory {
	public:
		Memory(int size);

		void write(int value);
		int read(int address);
		void store(int address, int value);

		~Memory(void);

	private:
		int* memory;
		int size;
		int writer; // Current position of writer
};

#endif
