/*PROBLEM STATEMENT:
* 
* <p>The sum of the squares of the first ten natural numbers is,</p>
$$1^2 + 2^2 + ... + 10^2 = 385.$$
<p>The square of the sum of the first ten natural numbers is,</p>
$$(1 + 2 + ... + 10)^2 = 55^2 = 3025.$$
<p>Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 - 385 = 2640$.</p>
<p>Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.</p>
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

int main()
{
    //sum of squares
    long long sumofsquares = 0; //almost certainly too large a variable type but easier than debugging
    for (int i = 1; i <= 100; i++)
        sumofsquares += i * i;

    long long squareofsums = 0;
    for (int i = 1; i <= 100; i++)
        squareofsums += i;
    squareofsums = squareofsums * squareofsums;


    std::cout << "result: ";
    std::cout << squareofsums - sumofsquares;
    std::cout << std::endl;
    std::getchar();
    
}
