# 6502 Architecture

[http://archive.6502.org/books/mcs6500_family_hardware_manual.pdf](6502 Documentation)

[https://www.westerndesigncenter.com/wdc/documentation/w65c02s.pdf](65C02 Documentation) - 65C02 is the static version of the 6502. This manual can be used, as long as the static features are not implemented

## State: Registers

A = Accumulator -> Stores result of most computations

Y and X = Index Registers -> Stores a byte that might be needed later (ex: other computation)

PCH (high) and PCL (low) = Program Counter (implemented as 2 registers) -> pointer into memory that keeps track of the instruction being executed -> 2 registers so that it can address a 16-bit address space (the 6502 has 16 address ports); high and low define which one is the high byte and which one is the low

S = Stack Pointer -> 8 bits + plus one bit at the beginning; pointer that indicates the top of the stack

P = Process Status Register -> Every time you do an instruction, you set the conditional bit according to it. Conditional bits are, in order: N (Negative; set to 1 indicates negative), V (Overflow; set to 1 indicates true), 1 (fixed), B (BRK command; set to 1 is BRK, set to 0 is IRQB), D (Decimal mode; set to 1 is true), I (IRQB disable; set to 1 is disable), Z (Zero; set to 1 is true), C (Carry; set to 1 is true) || P = [N V 1 B D I Z C]
