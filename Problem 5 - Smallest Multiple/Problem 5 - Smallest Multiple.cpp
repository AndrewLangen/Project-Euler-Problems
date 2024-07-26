/*PROBLEM STATEMENT:
* 
* <p>$2520$ is the smallest number that can be divided by each of the numbers from $1$ to $10$ without any remainder.</p>
<p>What is the smallest positive number that is <strong class="tooltip">evenly divisible<span class="tooltiptext">divisible with no remainder</span></strong> by all of the numbers from $1$ to $20$?</p>


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

std::vector<int> GetPrimeFactors(int input);
std::vector<std::vector<int>> GetPrimeFactorVectors(int start, int end);
void PrintPrimeFactorVectors(std::vector<std::vector<int>> vectors);

int main()
{
	//naive solution below this (that didn't work)
	//every number can be written by its prime factors
	//the smallest number that is evenly divisible by a group of numbers is the multiple of all of said numbers unique prime factors (so, if 2 numbers have a factor, it only counts once, but if one number has the same factor twice, it gets doublecounted
	//therefore, we create a function to list out all prime factors, then combine them manually to get the result
	//in practice, there should be a more efficient way to do this, but I don't know
    //PrintPrimeFactorVectors(GetPrimeFactorVectors(2, 20));

    //once we know the factors, calculation is trivial
    std::vector<int> factors = std::vector<int>{ 2,2,2,2,3,3,5,7,11,13,17,19 };
    int result = 1;
    for (int a : factors)
        result *= a;
    std::cout << "result: " << result << std::endl;
    std::getchar();
}

std::vector<std::vector<int>> GetPrimeFactorVectors(int start, int end)
{
    std::vector<std::vector<int>> factors = std::vector<std::vector<int>>(end - start);
    for (int i = start; i <= end; i++)
    {
        factors.push_back(GetPrimeFactors(i));
    }
    return factors;
}

std::vector<int> GetPrimeFactors(int input)
{
	std::vector<int> toReturn;
    //to make it clearer later on, all returned vectors start with their input
    toReturn.push_back(input);
    //this section is pulled from problem 3
    int factor = 2;
    int workingnumber = input;
    while (factor * factor < workingnumber) //squaring is cheaper than square rooting
    {
        while (workingnumber % factor == 0)
        {
            toReturn.push_back(workingnumber); // note that this is somewhat inefficient if there are multiple factors (it only needs to be assigned once), but I suspect that in practice this is cheaper than doing an initial check (can't use do while because may not divide)
            workingnumber /= factor;
        }
        factor++;
    }
    if (workingnumber != 1)
        toReturn.push_back(workingnumber);
	return toReturn;
}

void PrintPrimeFactorVectors(std::vector<std::vector<int>> vectors)
{
    for (auto a : vectors)
    {
        for (auto b : a)
        {
            std::cout << b << ", ";
        }
        std::cout << std::endl;
    }

}

//bool EvenlyDivisible(long long& divisor);
//
//int main()
//{
//    long long test = 12252240;
//    EvenlyDivisible(test);
//    // definitionally, we know that this has to be <= 1 * 2 * 3 * . . . * 18 * 19 * 20, setting an upper bound on our answer
//    // furthermore, we don't need to check any number below 7, because 12 divides 2, 3, 4, and 6, and 20 divides 5
//    long long maximum = 1;
//    for (int i = 20; i >= 7; i--)
//    {
//        maximum *= i;
//    }
//    // there are a few non-coprime numbers we can cut here
//    //if a number is evenly divisible by 
//    long long result = maximum; // has to be either maximum or some number less than that
//    //we know that 7, 11, 13, 17, 19, and 20 are all coprime
//    // so when we iterate through, we can subtract by their multiple, because all of the intermediate steps won't be divisible by one of those numbers
//    int step = 7 * 11 * 13 * 17 * 20;
//    for (long long i = maximum; i > 20; i -= step)
//    {
//        if (EvenlyDivisible(i))
//        {
//            result = i;
//        }
//
//        
//    }
//
//    std::cout << "result: ";
//    std::cout << result;
//    std::cout << std::endl;
//    std::getchar();
//    
//}
//bool EvenlyDivisible(long long& divisor)
//{
//    // we can skip 19 and 20 since we subtract by a multiple of them in the other loop
//    // we also don't need to check anything below 12; everything less than 11 is half of another number, and 11 is coprime so we cut it
//    for (int j = 18; j >= 12; j--)
//    {
//        if (divisor % j != 0)
//            return false;
//
//    }
//    return true;
//}
