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
    //note that the number of one pence coins doesn't "matter"; any combination of all of the others that does not exceed 200p will have some amount of 1p coins in them, and that number of 1p coins will be unique to that other coin combination
    //instead, the goal is to find the number of combinations that do not exceed 200p


    int numPossibilities = 1; //there's only one combination that involves 2pound, so it can be excluded from calculation and added back manually

    //100p
    for (int i = 0; i <= 200; i += 100)
    {
        int runningTotal = 200 - i;
        //50p
        for (int j = 0; j < runningTotal; j += 50)
        {
            int runningTotal2 = runningTotal - j;
            //20p
            for (int k = 0; k < runningTotal2; k += 20)
            {
                int runningTotal3 = runningTotal2 - k;
                //5p
                for (int l = 0; l < runningTotal3; l += 5)
                {
                    int runningTotal4 = runningTotal3 - l;
                    //2p; 1p isn't necessary so counting here works
                    for (int m = 0; m < runningTotal4; m += 2)
                        numPossibilities++;
                }
            }
        }
    }


    std::cout << "result: ";
    std::cout << numPossibilities;
    std::cout << std::endl;
    std::getchar();
    
}
