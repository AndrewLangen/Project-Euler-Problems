/*PROBLEM STATEMENT:
* 
* 
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

int numdivisors(long input);

int main()
{
    //new solution, based on what I saw online
    //essentially, all triangular numbers are of the form (n*(n+1))/2
    //n and n+1 are coprime, so their divisors can be calculated separately and added together (with one two subtracted because of the /2 in the formula, but that's ok because one of n and n+1 will always be even)
    //finally, because the last n+1 becomes the next n, we only have to calculate half the divisors at a time and store the results after

    int n = 1;
    int ndivisors = numdivisors(n);
    int nplusdivisors = numdivisors(n+1);
    int totaldivisors = 0;
    while (true)
    {
        n++;
        int triangularnumber = (n * (n + 1)) / 2; // not strictly necessary but good for debugging
        ndivisors = nplusdivisors;
        nplusdivisors = numdivisors(n);
        totaldivisors = ndivisors + nplusdivisors - 1; //removing one for the /2 in the formula
        if (totaldivisors > 500)
            break;
    }

}


int numdivisors(long input)
{
    //every number is divisible by 1 and itself, so we can skip it in the loop and start the count there
    //note that this means the output for the first triangular number (1) is technically wrong, but it isn't the answer to the question anyway
    int count = 2;
    int factor = 2;
    while (factor * 2 <= input)
    {
        if (input % factor == 0)
            count++;
        factor++;
    }
    return count;    
}
//NAIVE SOLUTION: WAY TOO SLOW

//int main()
//{
//    //interestingly, we can calculate the triangular numbers as we go, without having to start from scratch every step
//    //this is because they are all the sum of 1 to n, so we just keep adding new n's to the end
//
//    long triangularnumber = 0;
//    int n = 1;
//    while (true)
//    {
//        triangularnumber += n;
//        int divisors = numdivisors(triangularnumber);
//        if (divisors > 500)
//            break;//we only return the triangular number itself, not the "base" number, so we don't have to worry about incrementing it once we find a number with 500 divisors
//        n++;
//    }
//
//    std::cout << "result: ";
//    std::cout << triangularnumber;
//    std::cout << std::endl;
//    std::getchar();
//
//}