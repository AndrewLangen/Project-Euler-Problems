/*PROBLEM STATEMENT:
* 
* <p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$, for which,
$$a^2 + b^2 = c^2.$$</p>
<p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
<p>There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.<br>Find the product $abc$.</p>

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

std::tuple<int, int, int> CalculateSpecialPythagoreanTriplet();
static bool IsSpecialPythagoreanTriplet(int a, int b, int c);

int main()
{
    auto a = CalculateSpecialPythagoreanTriplet();

    

    std::cout << "result: ";
    std::cout << std::get<0>(a) * std::get<1>(a) * std::get<2>(a);
    std::cout << std::endl;
    std::getchar();
    
}

std::tuple<int,int,int> CalculateSpecialPythagoreanTriplet()
{
    //because a<b<c and a + b + c = 1000, a<334, b<500, and c<1000
    for (int c = 3; c < 1000; c++)
    {
        for (int b = 2; b < 500 && b < c; b++)
        {
            for (int a = 1; a < 334 && a < b; a++)
            {
                if (IsSpecialPythagoreanTriplet(a,b,c))
                    return std::tuple<int, int, int>(a, b, c);
            }

        }
    }
    return std::tuple<int, int, int>(-1, -1, -1);
}

static bool IsSpecialPythagoreanTriplet(int a, int b, int c)
{
    if (a + b + c != 1000)
        return false;
    if ((a * a) + (b * b) != (c * c))
        return false;
    return true;
}
