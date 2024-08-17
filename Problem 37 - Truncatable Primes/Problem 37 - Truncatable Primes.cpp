/*PROBLEM STATEMENT:
* 
* <p>The number $3797$ has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: $3797$, $797$, $97$, and $7$. Similarly we can work from right to left: $3797$, $379$, $37$, and $3$.</p>
<p>Find the sum of the only eleven primes that are both truncatable from left to right and right to left.</p>
<p class="smaller">NOTE: $2$, $3$, $5$, and $7$ are not considered to be truncatable primes.</p>


* 
*/

#include <stdio.h>
#include <charconv>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <ranges>
#include <stack>
#include <string>
#include <vector>

/*
* there's a major optimization that can be made here
* First of all, when removing digits from right to left, every digit will be in the ones column
* Therefore, any number that contains an even digit, or a 5 (collectively, "illegal digits"), cannot be a truncatable prime
* note this rule applies only after the first digit (because if the first digit is a five, when it gets truncated into the ones column, the number is "5", which is prime; same for 2)
* So before going through the expensive prime number checking process, checking each digit against the invalid list will save time, as will iterating past them

*/

static const int IncrementPastIllegalDigits(int);
static const bool IsLeftTruncatable(int);
static const bool IsPrime(int);
static const bool IsRightTruncatable(int);

int main()
{
    std::vector<int> primes = std::vector<int>();

    int counter = 11; // we know that single digit primes are expressly excluded
    while (primes.size() != 11)
    {
        counter = IncrementPastIllegalDigits(counter);

        if (IsPrime(counter))// checking if original number is prime
        {
            if (IsLeftTruncatable(counter) && IsRightTruncatable(counter))
                primes.push_back(counter);
        }
        counter += 2; //not incrementing by 1 because every other digit will be even and not prime
    }

    int sum = std::accumulate(primes.begin(), primes.end(), 0);
    std::cout << "result: ";
    std::cout<< sum;
    std::cout << std::endl;
    std::getchar();
    
}

static const int IncrementPastIllegalDigits(int input)
{
    //char is used here because the easiest way to parse out individual digits is by converting to a string
    std::string inputString = std::to_string(input);
    std::string outputString = "";

    //map to increment past any illegal digits, on to the digits which are permissible
    //Note that this includes both digits taht cannot be in truncatable primes, and ones that can (when they can the key value pair is identical)
    //This is done to avoid branching code, which seems faster intuitively
    std::map<char, char> digitTransfer{ {'0','1'}, {'1','1'}, { '2','3' },{'3','3'}, { '4','7' },{'5','7'}, {'6','7'}, {'7','7'}, { '8','9' },{'9','9'} };

    outputString += inputString[0];//carry over the first digit because it doesn't have the same illegallity rules
    for (int i = 1; i < inputString.length(); i++) // skipping the first digit, because it is possible for it to not be an illegal digit
    {
        char currentChar = inputString[i]; //take the current char
        outputString += digitTransfer[currentChar]; //replace it with the next non-illegal digit (identical digit if not illegal)
    }
    
    //modern foreach style ranges can't be used here because we need to have the index
    

    return std::stoll(outputString);
}

//Left Truncatable = Removing digits from the left side
static const bool IsLeftTruncatable(int input) 
{
    int length = (int)std::log10l(input) + 1;
    for (int i = length-1; i > 0; i--)
    {
        int currentNumber = input % ((int)std::powl(10, i));
        if (!IsPrime(currentNumber))
            return false;
    }
    return true;
}

//From Problem 10; modified
static const bool IsPrime(int input)
{
    if (input <= 1)
        return false;
    int factor = 2;
    while (factor * factor <= input)
    {
        if (input % factor == 0)
            return false;
        factor++;
    }
    return true;
}

//Right Truncatable = Removing digits from the right side
static const bool IsRightTruncatable(int input)
{
    int length = (int)std::log10l(input) + 1;
    for (int i = length - 1; i > 0; i--)
    {
        int currentNumber = input / ((int)std::powl(10, i));
        if (!IsPrime(currentNumber))
            return false;
    }
    return true;
}

