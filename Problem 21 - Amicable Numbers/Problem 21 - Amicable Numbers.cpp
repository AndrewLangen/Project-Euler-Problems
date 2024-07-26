/*PROBLEM STATEMENT:
* 
* <p>Let $d(n)$ be defined as the sum of proper divisors of $n$ (numbers less than $n$ which divide evenly into $n$).<br>
If $d(a) = b$ and $d(b) = a$, where $a \ne b$, then $a$ and $b$ are an amicable pair and each of $a$ and $b$ are called amicable numbers.</p>
<p>For example, the proper divisors of $220$ are $1, 2, 4, 5, 10, 11, 20, 22, 44, 55$ and $110$; therefore $d(220) = 284$. The proper divisors of $284$ are $1, 2, 4, 71$ and $142$; so $d(284) = 220$.</p>
<p>Evaluate the sum of all the amicable numbers under $10000$.</p>
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

int DivisorSum(int input);

int main()
{
    //to improve efficiency, previous results will be stored in an array
    //it should be impossible to get -1, so that will show that address hasn't been written to yet
    //we do not need 1 because it has no proper divisors less than 1, and we do not need 10000 because the problem says under 10000
    //therefore, we need only 9997 entries here
    //but note that that means that all entries are offset by 2 (so array index 0 corresponds to d(2), index 100 corresponds to d(102), etc.)
    int results[9997] = { -1 };
    int offset = 2;
    for (int i = offset; i < 9999; i++)
    {
        results[i-offset] = DivisorSum(i);
    }

    int sum = 0;

    for (int i = offset; i < 9999; i++)
    {
        if (i == 220)
            auto a = 10;
        int divisors = results[i-offset];
        if ((i < divisors) //doing it this way means we can add both numbers whenever the first one is hit without worrying about overcounting; also automatically checks the a != b requirement in the problem
            && (divisors >2)
            && (divisors <10000)) // prevents array out of bounds errors (array capped at 9997 because we are offsetting
        {
            if (results[divisors - offset] == i)
                sum += i + divisors;
        }
    }

    std::cout << "result: ";
    std::cout << sum;
    std::cout << std::endl;
    std::getchar();
    
}

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
