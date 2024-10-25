/**
 * 
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13  we can see that the 6th prime is 13.
What is the 10,001 st prime number?
 */

#include "../euler.hpp"
#include <iostream>
#include <string>

bool is_prime(unsigned long nb) {
	if (nb <= 1)
		return false;

	unsigned long factor = 2;
	while (factor <= nb / factor) {
		if (nb % factor == 0)
			return false;
		factor++;
	}
	return true;
}

unsigned long find_next_prime(unsigned long nb) {
	// given a number nb, assuming it is not prime, find next largest prime
	// if it is prime, return nb

	if (!is_prime(nb))
		return find_next_prime(nb + 1);
	return nb;

}


int main(int ac, char **av) {
	int count = -1;
	unsigned long prime = 1;
	while (++count < 10001) {
		prime = find_next_prime(prime + 1);
	}
	cout << prime << endl;
}