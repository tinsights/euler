/**
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 * find the sum of the even-valued terms.
 */

#include "../euler.hpp"
#define LIMIT 4000000
unsigned long fibonacci(unsigned int i)
{
	if (i <= 1)
		return 1;
	else
		return fibonacci(i - 1) + fibonacci(i - 2);
}

int main(void)
{
	int i = 2; // starting with the index of the first even fibonacci number [1, 1, 2, 3, ...]
	long result = 0;
	unsigned long fib = fibonacci(i);
	while (fib < LIMIT)
	{
		if (!(fib % 2))
			result += fib;
		i += 3; // nifty trick after proving every 3rd fib number is even.
		fib = fibonacci(i);
	}
	cout << result << endl;
}