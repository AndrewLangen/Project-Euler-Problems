/*PROBLEM STATEMENT:
* 
* <p>The sum of the primes below $10$ is $2 + 3 + 5 + 7 = 17$.</p>
<p>Find the sum of all the primes below two million.</p>




* 
*/

#include <stdio.h>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>
#include <stack>

static const bool IsPrime(int input);

int main()
{
    long long sum = 0;
    for (int i = 2; i < 2000000; i++) // problem excludes 1 from list of primes
    {
        if (IsPrime(i))
            sum += i;
    }

    std::cout << "result: ";
    std::cout << sum;
    std::cout << std::endl;
    std::getchar();
    
}

static const bool IsPrime(int input)
{
    int factor = 2;
    while (factor * factor <= input)
    {
        if (input % factor == 0)
            return false;
        factor++;
    }
    return true;
}
