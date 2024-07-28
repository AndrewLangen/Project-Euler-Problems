/*PROBLEM STATEMENT:
* 
* <p>$145$ is a curious number, as $1! + 4! + 5! = 1 + 24 + 120 = 145$.</p>
<p>Find the sum of all numbers which are equal to the sum of the factorial of their digits.</p>
<p class="smaller">Note: As $1! = 1$ and $2! = 2$ are not sums they are not included.</p>


* 
*/

#include <stdio.h>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <stack>
#include <vector>

static int Factorial(int);
static std::vector<int> SplitDigits(int);

int main()
{
    
    //The largest single digit factorial is 9! = 362880, so the maximum number of digits is 7 (because 9! * 8 = 2903040, a seven digit number)
    //The therefore, the upper bound here is 9! * 7 = 2540160

    int total = 0;

    for (int i = 10; i < 2540160; i++)
    {
        auto digits = SplitDigits(i);
        auto factorialDigits = digits | std::views::transform([](const int n) {return Factorial(n); });
        int sum = std::reduce(factorialDigits.begin(), factorialDigits.end());
        if (sum == i)
            total += sum;
    }

    std::cout << "result: ";
    std::cout << total;
    std::cout << std::endl;
    std::getchar();
    
}

//Perhaps surprisingly, C++/STL has no built in factorial function
static int Factorial(int input)
{
    int result = 1;
    while (input >= 2)
    {
        result *= input;
        input--;
    }
    return result;
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
