/*PROBLEM STATEMENT:
* 
* <p>By listing the first six prime numbers: $2, 3, 5, 7, 11$, and $13$, we can see that the $6$th prime is $13$.</p>
<p>What is the $10\,001$st prime number?</p>


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

static const bool IsPrime(int i);

int main()
{
    int counter = 2; //number used to iterate through all numbers to find primes
    std::vector<int> primes = std::vector<int>();
    while (primes.size() != 10002)
    {
        if (IsPrime(counter))
        {
            primes.push_back(counter);
        }
        counter++;
    }


    std::cout << "result: ";
    std::cout<< primes[10000]; //vectors are zero indexed
    std::cout << std::endl;
    std::getchar();
    
}

static const bool IsPrime(int input)
{
    int checker = 2;
    while (checker * checker <= input)
    {
        if (input % checker == 0)
            return false;
        checker++;
    }
    return true;
}
