/*PROBLEM STATEMENT:
* 
* <p>The number, $197$, is called a circular prime because all rotations of the digits: $197$, $971$, and $719$, are themselves prime.</p>
<p>There are thirteen such primes below $100$: $2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79$, and $97$.</p>
<p>How many circular primes are there below one million?</p>


* 
*/

#include <stdio.h>
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <stack>
#include <vector>

bool IsCircularPrime(const std::vector<int>& digits);
static const bool IsPrime(int);
static std::set<int> RotateDigits(std::vector<int>);
static int ToInteger(const std::vector<int>&);
static std::vector<int> SplitDigits(int);

int main()
{
    
    //checking for primes is computationally expensive. Checking multiple times (if there are d digits it will need to be checked d times) is even more expensive
    //Note that every circular prime needs to be prime with each digit in the ones position
    //that means none of the digits can be even (with the exception of 2 itself, which is pre-included along with all of the other sub-100 primes

    std::set<int> evenNumbers = std::set<int>{ 0,2,4,6,8 };
    std::vector<int> circularPrimes{ 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97 }; //pre-including sub-100 primes from the problem to simplify the algorithm for above-100 primes

    for (int i = 101; i < 1000000; i+= 2)
    {
        auto digits = SplitDigits(i);
        //checking to make sure none of the digits are even numbers
        if (std::find_first_of(digits.begin(), digits.end(), evenNumbers.begin(), evenNumbers.end()) == digits.end())
        {
            if (IsCircularPrime(digits))
                circularPrimes.push_back(i);
        }
    }

    std::cout << "result: ";
    std::cout << circularPrimes.size();
    std::cout << std::endl;
    std::getchar();
    
}

bool IsCircularPrime(const std::vector<int>& digits)
{

    auto rotatedDigits = RotateDigits(digits);
    for (int rotation : rotatedDigits)
    {
        if (!IsPrime(rotation))
            return false;
    }
    return true;
}

//From Problem 10
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


//Produces all rotations of the digits
//The output is a set here because it is theoretically possible for two rotations to reach the same number (for example, 4747 rotated twice), but I haven't been able to find any primes that match that
//Note: because the algorithm involves rotating the vector in place, it can't use a const& parameter. It may be more efficient to copy it locally, but not by much
static std::set<int> RotateDigits(std::vector<int> input)
{
    std::set<int> toReturn = std::set<int>();

    for (int i = 0; i < input.size(); i++)
    {
        toReturn.insert(ToInteger(input));
        std::rotate(input.begin(), input.begin() + 1, input.end());
    }

    return toReturn;
}

//taken from Problem 30
static std::vector<int> SplitDigits(int input)
{
    std::vector<int> toReturn{};
    int numDigits = std::floor(std::log10(input)) + 1;
    int remainder = input;
    while (numDigits != 1)
    {
        numDigits--;
        //taking advantage of the fact that integer / integer division excludes anything after the decimal, which is beneficial when splitting out whole numbers
        int nextdigit = remainder / ((int)std::pow(10, numDigits));
        toReturn.push_back(nextdigit);
        //whatever would have been after the decimal becomes the basis for the next iteration
        remainder = remainder % ((int)std::pow(10, numDigits));
    }
    toReturn.push_back(remainder);
    return toReturn;
}

//This section converts the vector of digits into a single integer

int ToInteger(const std::vector<int>& input)
{

    int currentNumber = 0;
    for (int j = input.size(); j > 0; j--)
    {
        currentNumber += input[j - 1] * std::powl(10, j - 1); // takes the input, multiplies it by 10^j-1 to shift it into the appropriate position in the final number
    }
    return currentNumber;
}