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
