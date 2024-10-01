/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get
 * 3, 5, 6 ,and 9.
 * The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include "../euler.hpp"
#define LIMIT 1000

int main(void)
{
  int sum = 0;

  for (int i = 1; i < LIMIT; i++)
    if (!(i % 3) || !(i % 5))
      sum += i;

  /**
   * marginally faster for larger LIMITs:
  for (int threes = 3, fives = 5; (threes < LIMIT); threes += 3, fives += 5)
  {
    sum += threes;
    if (fives < LIMIT && fives % 3)
      sum += fives;
  }
  */

  cout << sum << endl;
}
