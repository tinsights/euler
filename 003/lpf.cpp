/*
The prime factors of 13195 are 5, 7, 13, 29.

What is the largest prime factor of the number 600851475143?
*/
#include "../euler.hpp"
#include <cstdbool>

#define TARGET 600851475143

void print_prime_factors(unsigned long number);

int main(void)
{
	print_prime_factors(TARGET);
}

bool is_prime(unsigned long nb)
{
	unsigned long i;

	if (nb <= 1)
		return (false);
	i = 2;
	while (i <= nb / i) // factorisation "midpoint"
	{
		if (nb % i == 0)
			return (false);
		++i;
	}
	return (true);
}

unsigned long find_next_prime(unsigned long i)
{
	while (!is_prime(i))
		++i;
	return (i);
}

void print_prime_factors(unsigned long number)
{
	unsigned long prime_factor = 2;

	while (number != 1)
	{
		if (number % prime_factor == 0)
		{
			cout << prime_factor << endl;
			while (number % prime_factor == 0)
				number /= prime_factor;
		}
		prime_factor = find_next_prime(prime_factor + 1);
	}
}
