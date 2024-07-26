/*<p>The prime factors of $13195$ are $5, 7, 13$ and $29$.</p>
<p>What is the largest prime factor of the number $600851475143$?</p>
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
    long long input = 600851475143;
    //by dividing by factors as we go, we keep from having to do expensive large number divided by large number divisions
    long long workingnumber = input;
    int factor = 2; //1 always divides and doesn't matter
    int largestfactor = 1; //if it stays at 1, we know no divisions have taken place
    //There are three possible results here: either no prime factors divide it, and the answer is the number itself (it is prime), or we get a smaller prime factor, which is no bigger than the square root of the input after dividing all other prime factors
    //note that we don't actually have to check whether the number we are dividing is prime if we divide the input along the way; if a composite number would have divided it, it will be divided by the composite number's prime factors
    // that looks inefficient, but it suspect it is cheaper than trying to tell if a number is prime
    //this does, however, mean that we need an inner loop to make sure we divide out all of the factors (for numbers like 2*2*3 = 12)
    while (factor * factor < workingnumber) //squaring is cheaper than square rooting
    {
        while (workingnumber % factor == 0)
        {
            largestfactor = factor; // note that this is somewhat inefficient if there are multiple factors (it only needs to be assigned once), but I suspect that in practice this is cheaper than doing an initial check (can't use do while because may not divide)
            workingnumber /= factor;
        }
        factor++;
    }
    //one of three things has happened here:
    //nothing has divided it, and we return the output (it is prime)
    //the above loop fully divided out the input, so we want the largest saved factor
    //the above loop left some remainder; that remainder amount is the last prime factor
    //note: in practice, the remainder amount is what happened, leading me to wonder if it is ever possible to have an output that dervies from the largestfactor.
    long long output = (largestfactor == 1) ? input : (largestfactor > workingnumber) ? largestfactor : workingnumber;
    std::cout << "result: " << output << std::endl;
    std::getchar();

}
