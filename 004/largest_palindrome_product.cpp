/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 x 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include "../euler.hpp"
#include <string>
#include <sstream>

using std::string;

bool is_palindrome(string nb)
{
	if (nb.front() == nb.back()) {
		if (nb.length() > 2)
			return is_palindrome(string(nb.begin() + 1, nb.end() - 1));
		else return true;
	}
	else
		return false;

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