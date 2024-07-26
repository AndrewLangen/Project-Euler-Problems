// Problem 1 - Multiples of 3 or 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*<p>If we list all the natural numbers below $10$ that are multiples of $3$ or $5$, we get $3, 5, 6$ and $9$. The sum of these multiples is $23$.</p>
<p>Find the sum of all the multiples of $3$ or $5$ below $1000$.</p>*/

#include <stdio.h>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>

int main()
{
    //problem specifies a multiple of "3 or 5", suggesting no doublecounting (eg 15)
    std::vector<int> input(999);
    std::iota(input.begin(), input.end(), 1); //iota is [start, end), so we need to make sure we start at 1 (besides, we know 0 doesn't matter for a sum)
    //filter for divisibility
    int sum = 0;
    auto output = input
        | std::views::filter([](const int n) {return (n % 3 == 0) || (n % 5 == 0); });
    for (const int n : output)
    {
        sum += n;
    }
    std::cout << "sum: " << sum << std::endl;
    std::getchar();
}

