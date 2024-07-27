/*PROBLEM STATEMENT:
* 
* <p>Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
\begin{align}
1634 &amp;= 1^4 + 6^4 + 3^4 + 4^4\\
8208 &amp;= 8^4 + 2^4 + 0^4 + 8^4\\
9474 &amp;= 9^4 + 4^4 + 7^4 + 4^4
\end{align}
</p><p class="smaller">As $1 = 1^4$ is not a sum it is not included.</p>
<p>The sum of these numbers is $1634 + 8208 + 9474 = 19316$.</p>
<p>Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.</p>


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

std::vector<int> SplitDigits(int input);

int main()
{
    //the largest single digit fifth power is 9^5 = 59049, so anything with 7 digits or more would be too large
    //then, because the maximum is six digits, the largest possible number is 6 * 59049 = 354294 (in practice that doesn't meet the requirements here because the number would be 999999, but it is the theoretical upper bound)

    //problem explicitly excludes 1 (not a sum), and all other single digit numbers are intuitively excluded
    int sum = 0;
    for (int i = 10; i <= 354294; i++)
    {
        auto digits = SplitDigits(i);
        auto digitPowers = digits | std::views::transform([](const int n) {return std::pow(n, 5); });

        //this would be trivialized by accumulate(), but it isn't in the standard for ranges yet

        int digitSum = std::reduce(digitPowers.begin(), digitPowers.end());
        if (i == digitSum)
            sum += i;
    }


    std::cout << "result: ";
    std::cout << sum;
    std::cout << std::endl;
    std::getchar();
    
}

//for a given number, splits out each individual digit
//while not strictly necessary for this problem, it outputs the digits in the same order as the input (so toreturn[0] is always the leading digit)
//this may be helpful in future problems
std::vector<int> SplitDigits(int input)
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
