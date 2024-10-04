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

bool is_palindrome(int nb)
{
	std::stringstream str_stream(nb);
	string number;

	str_stream >> nb;
	cout << nb << endl;
	return true;
}
int main(void)
{
	is_palindrome(123);
}