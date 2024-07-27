/*PROBLEM STATEMENT:
* 
* <p>A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of $28$ would be $1 + 2 + 4 + 7 + 14 = 28$, which means that $28$ is a perfect number.</p>
<p>A number $n$ is called deficient if the sum of its proper divisors is less than $n$ and it is called abundant if this sum exceeds $n$.</p>

<p>As $12$ is the smallest abundant number, $1 + 2 + 3 + 4 + 6 = 16$, the smallest number that can be written as the sum of two abundant numbers is $24$. By mathematical analysis, it can be shown that all integers greater than $28123$ can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.</p>
<p>Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.</p>


* 
*/

#include <stdio.h>
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>
#include <stack>

int DivisorSum(int);
std::vector<int> FindAbundantNumbers(int = 28123);
bool IsAbundantSum(int, const std::vector<int>&);


int main()
{
    
    std::vector<int> abundantNumbers = FindAbundantNumbers();
    int sum = 0;
    //An earlier version of this program checked each number between 1 and 28123 to see if it was an abundant number
    // precomputing all possible sums first turned out to be about 4 times faster in practice (1 min vs 4)
    //this can be further optimized with parallel computing, but I don't think that is necessary right now
    std::vector<int> abundantSums;
    for (int i = 0; i < abundantNumbers.size(); i++)
    {
        for (int j = i; j < abundantNumbers.size(); j++)
        {
            int potentialNumber = abundantNumbers[i] + abundantNumbers[j];
            if ((potentialNumber <= 28123) && (std::find(abundantSums.begin(), abundantSums.end(), potentialNumber) == abundantSums.end()))
                abundantSums.push_back(potentialNumber);
        }
    }

    for (int i = 1; i <= 28123; i++)
    {
        if (std::find(abundantSums.begin(), abundantSums.end(), i) == abundantSums.end())
            sum += i;
    }


    //for (int i = 1; i <= 28123; i++)
    //{
    //    if (!IsAbundantSum(i, abundantNumbers))
    //        sum += i;
    //}

    std::cout << "result: ";
    std::cout<< sum;
    std::cout << std::endl;
    std::getchar();
    
}

//taken from solution to Problem 21
int DivisorSum(int input)
{
    int divisor = 2;
    int sum = 1; // problem gives 1 as a proper divisor, and it will always be in every number, so we can skip checking it and just start from 1

    while (divisor != ((input / 2) + 1))
    {
        if (input % divisor == 0)
            sum += divisor;
        divisor++;
    }
    return sum;
}

std::vector<int> FindAbundantNumbers(int upperBound)
{
    std::vector<int> toReturn{};
    for (int i = 2; i <= upperBound; i++)
    {
        if (i < DivisorSum(i))
            toReturn.push_back(i);
    }
    return toReturn;
}

bool IsAbundantSum(int input, const std::vector<int>& abundantNumbers)
{
    for (int i = 0; i < abundantNumbers.size(); i++)
    {
        int firstNumber = abundantNumbers[i]; 
        //we know that, for any given abundant number, the smallest sum it could be part of is it plus itself (so it multiplied by 2); if it ever exceeds that number we know no other abundant number will qualify
        //similarly, because the abundant numbers vector is sorted from smallest to largest, every subsequent minimum sum will be bigger than this, so it also won't work, so we can abort entirely here
        if (firstNumber * 2 > input)
        {
            return false;
        }
        int j = i; // any sum that involves a number smaller than firstNumber would have been found at that stage of the iteration; note also that sums of identical numbers count (problem lists 12+12 = 24)
        do
        {
            if (firstNumber + abundantNumbers[j] == input)
                return true;
            j++;
        } while ((j < abundantNumbers.size()) && (abundantNumbers[j] + firstNumber <= input));
    }
    return false;
}