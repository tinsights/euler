/**
 * 
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13  we can see that the 6th prime is 13.
What is the 10,001 st prime number?
 */

#include "../euler.hpp"

bool is_prime(unsigned long nb) {
	if (nb <= 1)
		return false;

	unsigned long factor = 2;
	while (factor < nb / factor) {
		if (nb % factor == 0)
			return false;
		factor++;
	}
	return true;
}

#include <iostream>
#include <string>
int main(int ac, char **av) {
	if (ac == 2) {
		cout << av[1] ;
		if (is_prime(std::stoi(av[1])))
				cout << " is prime" << endl;
		else
			cout << " isn't prime" << endl;
	} else
		std::cerr << "Usage: ./a.out <num>" << endl;
}