/*PROBLEM STATEMENT:
* <p>A palindromic number reads the same both ways. The largest palindrome made from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
<p>Find the largest palindrome made from the product of two $3$-digit numbers.</p>
* 
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
#include "Problem 4 - Largest Palindrome Product.h"

static bool fiveDigitPalindrome(const int& input);
static bool sixDigitPalindrome(const int& input);

int main()
{
    //because we start with two 3 digit numbers, we know this has to be a five or six digit number (because 100 * 100 = 10,000 and 1,000 * 1,000 = 1,000,000)
    //in practice, if we start from the largest numbers (largest numbers produce largest multiples), we may never need to check a five digit palindrome

    int largestresult = 0;
    for (int x = 999; x >= 100; x--)
    {
        //once we find a palindrome at a given (x,y) pair, we can stop decrementing y, because it will only produce strictly smaller numbers
        // however, that doesn't mean we can stop entirely, because a lower x may produce a better result at a higher y
        // therefore, we split out the inner loop to allow exiting easily without having to deal with break commands (theoretically it could also be done with another condition on the loop but that's a bit less clear
        InnerLoop(x, largestresult);
    }

    std::cout << "result:" << largestresult << std::endl;

    std::getchar();
    
}

static bool sixDigitPalindrome(const int& input)
{
    //char conversions are expensive, so we are going to try this without conversion
    //3 different comparisons need to happen here (each outer pair), and I suspect most comparisons will fail the first one, which is the quickest, so nested ifs make sense here
    if (input / 100000 == input % 10)
    {
        int secondnumber = (input / 10000) % 10;
        int fifthnumber = (input / 10) % 10;
        if (secondnumber == fifthnumber)
        {
            int thirdnumber = (input / 1000) % 10;
            int fourthnumber = (input / 100) % 10;
            if (thirdnumber == fourthnumber)
                return true;
        }
    }
    return false;
}

static bool fiveDigitPalindrome(const int& input)
{
    //char conversions are expensive, so we are going to try this without conversion
    //3 different comparisons need to happen here (each outer pair), and I suspect most comparisons will fail the first one, which is the quickest, so nested ifs make sense here
    if (input / 10000 == input % 10)
    {
        int secondnumber = (input / 1000) % 10;
        int fourthnumber = (input / 10) % 10;
        if (secondnumber == fourthnumber)
        {
            //third number doesn't have a "mirror" so it is never an issue
            return true;
        }
    }
    return false;
}

void InnerLoop(int x, int& largestresult)
{
    for (int y = 999; y >= 100; y--)
    {
        int numbertotest = x * y;
        if (numbertotest < largestresult)
            return; // if we know this result is below what we've found, it and everything else further down the loop is irrelevant
        if (numbertotest >= 100000)
        {
            if (sixDigitPalindrome(numbertotest))
            {
                largestresult = numbertotest;
                return;
            }

        }
        else
        {
            if (fiveDigitPalindrome(numbertotest))
            {
                largestresult = numbertotest;
                return;
            }
        }
    }
}
