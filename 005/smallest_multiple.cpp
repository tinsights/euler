/**
 * 2520 is the smallest number that can be divided
 * by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is
 * evenly divisible by all of the numbers from 1 to 20?
 *
 */

#include "../euler.hpp"
#include <map>

bool is_prime(unsigned long nb);
unsigned long find_next_prime(unsigned long i);
void tally_prime_factors(unsigned long i, std::map<int, int> &pf_count);

int main(void)
{
	std::map<int, int> pf_count;

	// pf_count.insert(std::pair<int, int>(1, 1));
	// from 1 to limit
	for (int i = 2; i <= 20; ++i) {
		// if it's a prime, add to map
		if (is_prime(i)) {
			pf_count.insert(std::pair<int, int>(i, 1));
			continue;
		}
		else {
			// find all prime factors;
			tally_prime_factors(i, pf_count);
		}
	}
	unsigned long result = 1;
	for (std::pair<int, int> i : pf_count) {
		result *= std::pow(i.first, i.second);
	}
	cout << result << endl;
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

void tally_prime_factors(unsigned long number, std::map<int, int> &pf_count)
{
	unsigned long prime_factor = 2;

	while (number != 1)
	{
		int count = 0;
		while (number % prime_factor == 0) {
			count++;
			number /= prime_factor;
		}
		if (count && count > pf_count[prime_factor]) {
			pf_count[prime_factor] = count;
		}
		prime_factor = find_next_prime(prime_factor + 1);
	}
}
