/*
 * Solution to "Number Generator", using no division and 32-bit ints.
 * Factors are limited to 16 bits, though extension to 32-bit factors
 * is trivial.
 *
 * We want to perform an operation of the form:
 *  0xXXXXYYYY * 0xZZZZ (mod 2^31-1)
 *  
 * This can be broken into:
 *  0xYYYY * 0xZZZZ + 0xXXXX * 0xZZZZ * 2^16 (mod 2^31-1)
 *
 * The second term results in an expression that can be simplified
 * by what is nearly a circular shift. See rot().
 *
 */

#include<iostream>

// Simplification of the second term from above:
// 2*0xXXXX*2^31 + 0xYYYY * 2^16 (mod 2^31-1)
static inline uint32_t rot(uint32_t n) {
	return (((n&0xffff0000) >> 15)) + (n << 16);
}

// mod 2^31-1
static inline uint32_t mod(uint32_t n) {
	return (n>>31) + (n & 0x7fffffff);
}

int main() {
	const uint32_t startA = 65;
	const uint32_t startB = 8921;

	const uint16_t factorA = 16807;
	const uint16_t factorB = 48271;

	std::cout << "Starting values: \n"
		<< "\t startA = " << startA
		<< "\n\t startB = " << startB << "\n";

	std::cout << "Generator factors: \n"
		<< "\t factorA = " << factorA
		<< "\n\t factorB = " << factorB << std::endl;

	std::cout << "Processing generator pairs..." << std::endl;

	int count = 0;
	uint32_t A = startA;
	uint32_t B = startB;
	for (int i = 0; i < 40000000; i++) {
		if ((A & 0xffff) == (B & 0xffff)) {
			count++;
		}

		uint32_t nextA, nextB;
		nextA = mod(rot((A>>16) * factorA)) + mod(factorA * (0xffff & A));
		nextB = mod(rot((B>>16) * factorB)) + mod(factorB * (0xffff & B));

		A = mod(nextA);
		B = mod(nextB);
	}

	std::cout << "Done." << std::endl;

	std::cout << "Total matching pairs: " << count << "." << std::endl;
}
