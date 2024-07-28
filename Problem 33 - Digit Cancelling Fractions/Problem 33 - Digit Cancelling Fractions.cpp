/*PROBLEM STATEMENT:
* 
* <p>The fraction $49/98$ is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that $49/98 = 4/8$, which is correct, is obtained by cancelling the $9$s.</p>
<p>We shall consider fractions like, $30/50 = 3/5$, to be trivial examples.</p>
<p>There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.</p>
<p>If the product of these four fractions is given in its lowest common terms, find the value of the denominator.</p>


* 
*/

#include <stdio.h>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <math.h>
#include <numeric>
#include <ranges>
#include <stack>
#include <vector>

std::tuple<int, int> ReducedFraction(int, int);

int main()
{
    
    int multipliedNumerators = 1, multipliedDenominators = 1;
    
    //only considering fractions with two digits in both the numerator and denominator, where the fraction is less than 1 (so numerator < denominator)
    //also excluding trivial cases, which occur whenever one of the numbers has a 0 in it (which conveniently means avoiding dividing by 0 errors)
    //when starting from 11, the only two digit numbers with a 0 in them will have it in the ones digit (so divisible by 10)
    for (int numerator = 11; numerator < 100; numerator++)
    {
        if (numerator % 10 != 0)
        {
            for (int denominator = numerator + 1; denominator < 100; denominator++)
            {
                if (denominator % 10 != 0)
                {
                    if (numerator == 49 && denominator == 98)
                        auto q = 1;
                    auto originalReducedFraction = ReducedFraction(numerator, denominator);
                    std::vector<int> numeratorDigits{ numerator / 10, numerator % 10 }; // no need for complicated digit splitting operations for two digit numbers
                    std::vector<int> denominatorDigits{ denominator / 10, denominator % 10 };
                    
                    //can't do foreach because knowing the other digit is important (need to make sure the other digits are equal so they can be "removed"
                    for (int nd = 0; nd < 2; nd++) // numerator digit
                    {
                        for (int dd = 0; dd < 2; dd++) // denominator digit
                        {
                            if (numeratorDigits[1 - nd] == denominatorDigits[1 - dd]) // compares "other" digits
                            {
                                auto newReducedFraction = ReducedFraction(numeratorDigits[nd],denominatorDigits[dd]);
                                if (originalReducedFraction == newReducedFraction)
                                {
                                    multipliedNumerators *= numerator;
                                    multipliedDenominators *= denominator;
                                }

                            }
                        }
                    }
                }
            }
        }
    }


    std::cout << "result: ";
    std::cout << std::get<1>(ReducedFraction(multipliedNumerators,multipliedDenominators));
    std::cout << std::endl;
    std::getchar();
    
}

std::tuple<int, int> ReducedFraction(int numerator, int denominator)
{
    if (numerator == 1)
        return std::tuple<int, int>{numerator, denominator};
    for (int i = 2; i <=numerator; i++)
        if ((numerator % i == 0) && (denominator % i == 0))
            return ReducedFraction(numerator/i, denominator/i);
    return std::tuple<int, int>{numerator, denominator};
}