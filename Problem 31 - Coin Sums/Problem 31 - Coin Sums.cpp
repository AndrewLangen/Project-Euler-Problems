/*PROBLEM STATEMENT:
* 
* <p>In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:</p>
<blockquote>1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).</blockquote>
<p>It is possible to make £2 in the following way:</p>
<blockquote>1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p</blockquote>
<p>How many different ways can £2 be made using any number of coins?</p>


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

int main()
{
    int numPossibilities = 1; //there's only one combination that involves 2pound, so it can be excluded from calculation and added back manually

    for (int i = 0; i <= 200; i += 100)
    {
        int runningTotal = 200 - i;
    }


    std::cout << "result: ";
    /*std::cout<< */ /*answer goes here << */;
    std::cout << std::endl;
    std::getchar();
    
}
