/**
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 * sum of squares: 1^2 + 2^2 + ...
 * square of the sum (1 + 2 + ...)^2
 * 
 * difference: 2(ab + ac + ad ++... + bc + bd + ... + cd + ...)
 */

#include "../euler.hpp"
#include <vector>
#include <numeric> // for iota
int main (void) {

	std::vector<u_short> nums(100);
	std::iota(nums.begin(), nums.end(), 1); // wow wth. iota as in greek? 

	u_long result = 0;

	for (int i : nums) {
		for (std::vector<u_short>::iterator it = nums.begin() + i; it != nums.end(); ++it) {
			result += i * *it;
		}
	}
	cout << 2 * result << endl;
}