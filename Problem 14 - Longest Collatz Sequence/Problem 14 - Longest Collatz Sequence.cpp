/*PROBLEM STATEMENT:
* 
* <p>The following iterative sequence is defined for the set of positive integers:</p>
<ul style="list-style-type:none;">
<li>$n \to n/2$ ($n$ is even)</li>
<li>$n \to 3n + 1$ ($n$ is odd)</li></ul>
<p>Using the rule above and starting with $13$, we generate the following sequence:
$$13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1.$$</p>
<p>It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at $1$.</p>
<p>Which starting number, under one million, produces the longest chain?</p>
<p class="note"><b>NOTE:</b> Once the chain starts the terms are allowed to go above one million.</p>


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
#include <cassert>

static const int CollatzCycleCount(int initialValue);

int main()
{
    int maxCycles = 0;
    int bestStartingNumber = 0;
    for (int i = 1; i < 1000000; i++)
    {
        int currentCycles = CollatzCycleCount(i);
        if (currentCycles > maxCycles)
        {
            bestStartingNumber = i;
            maxCycles = currentCycles;
        }
    }

    std::cout << "result: ";
    std::cout<< bestStartingNumber;
    std::cout << std::endl;
    std::getchar();
    
}

static const int CollatzCycleCount(int initialValue)
{
    // note: this can also be done recursively; the problem is that it would require passing along a counter as part of the parameters
    // It is likely the compiler would just optimize that out (it would all be tail call recursive anyway), but it may have a performance penalty

    //we use long here because int caused overflow issues
    //it is fine for the function signature to use int because all values are capped at 1 million
    long long currentvalue = initialValue;
    int cyclecount = 0;

    // while not formally proven to always converge, it is known through brute force that all numbers in this scope do
    while (true) 
    {
        if (currentvalue == 1)
            return cyclecount;
        if (currentvalue % 2 == 0) // even
            currentvalue /= 2;
        else // odd
            currentvalue = (currentvalue * 3) + 1;
        cyclecount++;
    }
    return cyclecount; //this should never happen, but it does prevent compiler errors
}

