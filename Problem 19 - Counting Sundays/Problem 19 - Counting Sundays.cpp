/*PROBLEM STATEMENT:
* 
* 
<p>You are given the following information, but you may prefer to do some research for yourself.</p>
<ul><li>1 Jan 1900 was a Monday.</li>
<li>Thirty days has September,<br />
April, June and November.<br />
All the rest have thirty-one,<br />
Saving February alone,<br />
Which has twenty-eight, rain or shine.<br />
And on leap years, twenty-nine.</li>
<li>A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.</li>
</ul><p>How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?</p>

* 
*/

#include <stdio.h>
#include <cassert>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>
#include <stack>

int main()
{
    //if each day is assigned a number (so Monday = 1, Tuesday = 2, . . . Sunday = 0), everything can be handled through modular arithmetic
    //Add the number or days in each month, reduce mod 7, if the new number is 0, that day is a Sunday

    std::vector<int> regularDaysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    assert(regularDaysInMonth.size() == 12);
    assert(std::reduce(regularDaysInMonth.begin(), regularDaysInMonth.end()) == 365);
    std::vector<int> leapDaysInMonth = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    assert(leapDaysInMonth.size() == 12);
    assert(std::reduce(leapDaysInMonth.begin(), leapDaysInMonth.end()) == 366);

    //because 1900 is given as a Monday, it makes sense to start there, even if the actual numbers that matter are starting from 1901
    //It can be precomputed, but it isn't much work anyway

    int dayOfWeek = 1;
    int numSundays = 0;

    //adding the days in 365 without considering them for the sum
    dayOfWeek = (dayOfWeek + 365) % 7; //1900 is divisible by 4 but on a non-400 century, so it isn't a leap year

    //iterating 1 to 100 instead of 0 to 99 because it makes debugging easier (currentyear = i + 1900), as well as calculating leap years (leap year if divisible by 4; 1900 is divisible by 4 so not necessary to add in)
    for (int i = 1; i < 101; i++)
    {
        //checking if the year is a leap year
        //note that the rule about not being on a century unless it is divisible by 400 doesn't matter here, because the only century that counts is 2000, which is divisible by 400
        //1900 would matter, but is outside the scope (and handled separately)
        if (i % 4 == 0)
        {
            for (int d : leapDaysInMonth)
            {
                //checking whether the value is 0 (Sunday)
                //checking before iterating because the logic flow starts with the first of a relevant month and ends outside the scope, so post-incrementing checks aren't necessary
                if (dayOfWeek == 0)
                    numSundays++;
                dayOfWeek = (dayOfWeek + d) % 7;
            }
        }
        else //not leap year; essentially the same logic
        {
            for (int d : regularDaysInMonth)
            {
                if (dayOfWeek == 0)
                    numSundays++;
                dayOfWeek = (dayOfWeek + d) % 7;
            }
        }
    }



    std::cout << "result: ";
    std::cout << numSundays;
    std::cout << std::endl;
    std::getchar();
    
}
