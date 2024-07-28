/*PROBLEM STATEMENT:
* 
* <p>The decimal number, $585 = 1001001001_2$ (binary), is palindromic in both bases.</p>
<p>Find the sum of all numbers, less than one million, which are palindromic in base $10$ and base $2$.</p>
<p class="smaller">(Please note that the palindromic number, in either base, may not include leading zeros.)</p>


* 
*/

#include <stdio.h>
#include <bitset>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <stack>
#include <string>
#include <vector>

bool IsPalindromic(std::string input);

int main()
{
    int sum = 0;
    //because the result cannot include leading zeroes, no even numbers will be palindromic, because all binary represenations of even numbers end in 0
    //so only iterating through odds is necessary
    for (int i = 1; i < 1000000; i += 2)
    {
        if (i == 585)
            auto b = 1;
        std::string base10String = std::to_string(i);
        std::string base2String = std::bitset<sizeof(int)*8>(i).to_string(); //sizeof returns bytes, bitset needs bits (otherwise larger digits get cut off)
        //By default, bitset includes leading zeroes in the number when it is small enough 
        base2String.erase(0, base2String.find_first_not_of('0'));
        if (IsPalindromic(base10String) && IsPalindromic(base2String))
            sum += i;
    }

    std::cout << "result: ";
    std::cout << sum;
    std::cout << std::endl;
    std::getchar();
    
}

bool IsPalindromic(std::string input)
{
    for (int i = 0; i < input.size() / 2; i++)
    {
        if (input[i] != input[input.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}