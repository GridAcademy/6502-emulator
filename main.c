#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	uint8_t A;
	uint8_t Y;
	uint8_t X;
	uint8_t PCH;
	uint8_t PCL;
	uint8_t S;
	uint8_t P;
} Cpu_state;

uint8_t memory [0x10000]

// Set bit (0-7) in registry
void set_bit(uint8_t *reg, int shift){
	*reg = *reg | (0x01 << shift); // OR (bitwise)
}

// Unset bit (0-7) in registry
void unset_bit(uint8_t *reg, int shift){
	*reg = *reg ^ (0x01 << shift); // XOR (bitwise)
	// could also be done as AND reg (NOT (0x01 << shift))
}

// Get bit (0-7) from registry
bool get_bit(uint8_t *reg, int shift) {
	return *reg & (0x01 << shift); // AND (bitwise)
}

/* ADC - Add With Carry:  Take value1 from accumulator, add value2 to value1, store result in accumulator

Value 2 can be obtained in several different ways (depending on Opcode):
- Immediate (69): constant(fixed) value, specified immediately after instruction (in the sequence of hex codes, the value comes right after instruction)

Affects flags:
- n: set if most significant bit of result is set; cleared otherwise - n is for negative, so think about two's complement
- v: set if signed overflow; cleared if valid signed result
- z: set if zero; cleared otherwise
- c: set if unsigned overflow; cleared if valid unsigned result
*/
void add_with_carry(Cpu_state *cpu){
	uint8_t val1 = *cpu.A
	
	// The address of the opcode is the program counter, the address of val2 is prog counter+1
	uint16_t op_address = (*cpu.PCH << 8) + *cpu.PCL
	uint8_t val2 = memory[op_address + 1]

	//TODO: Add val1 + val2, set flags (handle overflow), increase program counter
}

int main() {
	uint8_t reg = 0xdf; //1101 1111

	set_bit(&reg, 5);
	bool active = get_bit(&reg, 5);
	printf("Active 5: %d\n", active);

	active = get_bit(&reg, 4);
	printf("Active 4: %d\n", active);

	unset_bit(&reg, 5);
	active = get_bit(&reg, 5);
	printf("Active 5: %d\n", active);

	return 0;
}
