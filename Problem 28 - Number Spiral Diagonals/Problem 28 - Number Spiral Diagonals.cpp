/*PROBLEM STATEMENT:
* 
* <p>Starting with the number $1$ and moving to the right in a clockwise direction a $5$ by $5$ spiral is formed as follows:</p>
<p class="monospace center"><span class="red"><b>21</b></span> 22 23 24 <span class="red"><b>25</b></span><br>
20  <span class="red"><b>7</b></span>  8  <span class="red"><b>9</b></span> 10<br>
19  6  <span class="red"><b>1</b></span>  2 11<br>
18  <span class="red"><b>5</b></span>  4  <span class="red"><b>3</b></span> 12<br><span class="red"><b>17</b></span> 16 15 14 <span class="red"><b>13</b></span></p>
<p>It can be verified that the sum of the numbers on the diagonals is $101$.</p>
<p>What is the sum of the numbers on the diagonals in a $1001$ by $1001$ spiral formed in the same way?</p>

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
    //There are a handful of different ways to calculate this, but this is what I think is the best
    //Instead of thinking of this as a 1001x1001 spiral, it is easier to see it as 500 rings (plus the 1 in the center that can be added separately
    //then, each ring has two more "interior" (not diagonal) numbers on each side than the ring before (first has 1, so second has 3, third has 5, etc.)
    //Therefore, if the last number on the previous spiral is known, then the sum of the next ring's diagonals requires adding the number of interior numbers (plus one) to it, four times (adding each result to the total)

    int currentNumber = 1;
    int sum = 1; //counting the center 1, which otherwise wouldn't be included in this ring based setup

    //this for loop can be thought of as iterating through the rings
    for (int i = 0; i < 500; i++)
    {
        int interval = 2 * (i + 1); //number of "interior" numbers between diagonals
        //this for loop can be thought of as iterating through the diagonals of each ring
        for (int j = 0; j < 4; j++)
        {
            currentNumber += interval;
            sum += currentNumber;
        }

    }


    std::cout << "result: ";
    std::cout << sum;
    std::cout << std::endl;
    std::getchar();
    
}
