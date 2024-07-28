/*PROBLEM STATEMENT:
* 
* <p>We shall say that an $n$-digit number is pandigital if it makes use of all the digits $1$ to $n$ exactly once; for example, the $5$-digit number, $15234$, is $1$ through $5$ pandigital.</p>

<p>The product $7254$ is unusual, as the identity, $39 \times 186 = 7254$, containing multiplicand, multiplier, and product is $1$ through $9$ pandigital.</p>

<p>Find the sum of all products whose multiplicand/multiplier/product identity can be written as a $1$ through $9$ pandigital.</p>

<div class="note">HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.</div>


* 
*/

#include <stdio.h>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <math.h>
#include <numeric>
#include <ranges>
#include <set>
#include <stack>
#include <vector>

bool IsPandigital(int a, int b, int product);
std::set<int> UniqueDigits(int input);

int main()
{
    //There's probably a more elegant solution here, but this is what I have
    //Immediately, the three elements (two multiples and product) must have a total of 9 digits
    //If one number has n digits and the second has m digits, their product must have m+n or m+n-1 digits
    //therefore, the only situations to consider are when m + n + (m+n) = 2*(m+n) OR m+n + (m+n-1) =  2*(m+n) -1 = 9
    //intuitively, because m and n are integers, 2 * (m+n) = 9 has no solutions
    //therefore, the only important situation here is 2*(m+n) - 1 = 9, or m + n = 5 (note this is the situation in the original problem
    //as a result, each digit has an upper bound of 4 digits (neither can have 0 digits), m*n must have 4 digits, and all three taken together must have 9 digits
    //while not perfect, this does significantly reduce the amount of situations to consider in the much more computationally expensive step of deciding if the numbers are pandigital

    //store the results prior to calculating the sum
    //Note that the problem asks only for the sum of products, not how they were reached, so only 1 int needs to be stored per equation
    //Finally, note that the problem explicitly says there are multiple possibilities for some products, and should only be included once, so a set (which automatically disallows duplicate insertion) is preferable
    std::set<int> products;

    for (int a = 1; a <= 9999; a++)
    {
        int aDigits = std::floorl(std::log10l(a)) + 1;
        int bDigits = 5 - aDigits; // digits in a and b must equal 5

        for (int b = std::powl(10, bDigits - 1); b < std::powl(10, bDigits); b++)
        {
            int product = a * b;
            int productDigits = std::floorl(std::log10l(product)) + 1;
            if (productDigits == 4) // need 9 total digits and we know a and b have 5
            {
                if (products.find(product) == products.end()) // duplicates are known to exist; no sense in going through intense calculation if already in set (expected to not be that many products)
                {
                    if (IsPandigital(a, b, product))
                        products.insert(product);
                }
            }
        }

    }

    int sum = std::reduce(products.begin(), products.end());

    std::cout << "result: ";
    std::cout << sum;
    std::cout << std::endl;
    std::getchar();
    
}

bool IsPandigital(int a, int b, int product)
{
    std::set<int> aDigits = UniqueDigits(a);
    std::set<int> bDigits = UniqueDigits(b);
    std::set<int> productDigits = UniqueDigits(product);
    std::set<int> combinedDigits;

    combinedDigits.insert(aDigits.begin(), aDigits.end());
    combinedDigits.insert(bDigits.begin(), bDigits.end());
    combinedDigits.insert(productDigits.begin(), productDigits.end());
    
    //to be 1 through nine pandigital, two things must be true: the combined digits, with duplicate entries removed, must have 9 digits, and must not contain zero
    if ((combinedDigits.size() == 9) && (combinedDigits.find(0) == combinedDigits.end()))
        return true;
    return false;

}

std::set<int> UniqueDigits(int input)
{
    std::set<int> toReturn{};
    int numDigits = std::floor(std::log10(input)) + 1;
    int remainder = input;
    while (numDigits != 1)
    {
        numDigits--;
        //taking advantage of the fact that integer / integer division excludes anything after the decimal, which is beneficial when splitting out whole numbers
        int nextdigit = remainder / ((int)std::pow(10, numDigits));
        toReturn.insert(nextdigit);
        //whatever would have been after the decimal becomes the basis for the next iteration
        remainder = remainder % ((int)std::pow(10, numDigits));
    }
    toReturn.insert(remainder);
    return toReturn;
}