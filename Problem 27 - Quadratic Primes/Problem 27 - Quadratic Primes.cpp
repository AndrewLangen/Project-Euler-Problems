/*PROBLEM STATEMENT:
* 
* <p>Euler discovered the remarkable quadratic formula:</p>
<p class="center">$n^2 + n + 41$</p>
<p>It turns out that the formula will produce $40$ primes for the consecutive integer values $0 \le n \le 39$. However, when $n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41$ is divisible by $41$, and certainly when $n = 41, 41^2 + 41 + 41$ is clearly divisible by $41$.</p>
<p>The incredible formula $n^2 - 79n + 1601$ was discovered, which produces $80$ primes for the consecutive values $0 \le n \le 79$. The product of the coefficients, $-79$ and $1601$, is $-126479$.</p>
<p>Considering quadratics of the form:</p>
<blockquote>
$n^2 + an + b$, where $|a| &lt; 1000$ and $|b| \le 1000$<br><br><div>where $|n|$ is the modulus/absolute value of $n$<br>e.g. $|11| = 11$ and $|-4| = 4$</div>
</blockquote>
<p>Find the product of the coefficients, $a$ and $b$, for the quadratic expression that produces the maximum number of primes for consecutive values of $n$, starting with $n = 0$.</p>
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

int ConsecutivePrimes(int, int);
bool IsPrime(int input);

int main()
{
    int maxCoefficients = 0;
    int longestSequence = 0;
    //there's a handful of optimizations available here
    //first of all, because we start with n=0, the first entry in the series will be 0^2 + 0*a + b = b, so b needs to be prime
    //therefore, if b is not prime, the equation won't produce the a sequence of primes
    //as a result, even though it might look weird, iterating through b first is faster than starting with a (fewer initial prime checks)
    //it also means that b can't be negative, 0, or 1, so that reduces the number of iterations

    for (int b = 2; b <= 1000; b++)
    {
        if (IsPrime(b))
        {
            for (int a = -1000; a <= 1000; a++)
            {
                int currentSequence = ConsecutivePrimes(a, b);
                if (currentSequence > longestSequence)
                {
                    longestSequence = currentSequence;
                    maxCoefficients = a * b;
                }
            }
        }
    }

    std::cout << "result: ";
    std::cout << maxCoefficients;
    std::cout << std::endl;
    std::getchar();
    
}

int ConsecutivePrimes(int a, int b)
{
    //because there's an initial check for b being prime, the first number in the sequence is always a prime, so we can skip ahead to n = 1
    int n = 1;

    while (IsPrime((n * n) + (n * a) + b))
        n++;

    return n + 1; //n is zero indexed, so the number of primes produced is equal to n + 1 (first number in sequence is n = 0)
}

bool IsPrime(int input)
{
    if (input <= 1)
        return false;
    int i = 2;
    while (i * i <= input)
    {
        if (input % i == 0)
            return false;
        i++;
    }
    return true;
}