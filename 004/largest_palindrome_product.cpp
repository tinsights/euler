/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 x 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include "../euler.hpp"
#include <string>
#include <algorithm>

using std::string;

bool is_palindrome(string nb)
{
	/* Using <algo>s */
	string bn = nb;
	std::reverse(bn.begin(), bn.end());
	return (nb == bn);

	/* "rudimentary" way */
	// if (nb.front() != nb.back())
	// 	return false;

	// if (nb.length() > 2)
	// 	return is_palindrome(string(nb.begin() + 1, nb.end() - 1));

	// return true;
}

int main(void)
{
	for (int i = 900; i < 1000; ++i) {
		for (int j = 900; j < 1000; ++j) {
			if (is_palindrome(std::to_string(i * j)))
				cout << i << " x " << j << " = " << i * j << endl;
		}
	}
}