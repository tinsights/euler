/*
The prime factors of 13195 are 5, 7, 13, 29.

What is the largest prime factor of the number 600851475143?
*/
#include "../euler.hpp"
#include <cstdbool>

#define TARGET 600851475143

unsigned long  find_largest_pf(unsigned long number);

int main(void)
{
	cout << find_largest_pf(TARGET) << endl;
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

unsigned long find_largest_pf(unsigned long number)
{
	unsigned long factor_candidate = 2;
	unsigned long largest_prime_factor = 0;

	while (number != 1)
	{
		if (number % factor_candidate == 0)
		{
			// cout << factor_candidate << endl;
			while (number % factor_candidate == 0)
				number /= factor_candidate;
			largest_prime_factor = factor_candidate;
		}
		factor_candidate = find_next_prime(factor_candidate + 1);
	}
	return (largest_prime_factor);
}
