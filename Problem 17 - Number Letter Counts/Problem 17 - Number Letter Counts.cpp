/*PROBLEM STATEMENT:
* 
* <p>If the numbers $1$ to $5$ are written out in words: one, two, three, four, five, then there are $3 + 3 + 5 + 4 + 4 = 19$ letters used in total.</p>
<p>If all the numbers from $1$ to $1000$ (one thousand) inclusive were written out in words, how many letters would be used? </p>
<br><p class="note"><b>NOTE:</b> Do not count spaces or hyphens. For example, $342$ (three hundred and forty-two) contains $23$ letters and $115$ (one hundred and fifteen) contains $20$ letters. The use of "and" when writing out numbers is in compliance with British usage.</p>

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
#include <string>

int main()
{
    //This problem becomes significantly simpler by batching together numbers instead of trying to count them individually
    //for example, exactly one hundred numbers contain the characters "one hundred" (100-199), and the same is true for two hundred, three hundred, etc.
    //Therefore, we can count based on groups instead of individual numbers
    //We'll split this problem into two sums: the numbers for the hundreds digit, and the numbers for the tens and ones (not subdividing those because of thirteen etc.)
    //Then, once we have the amounts for 1-99, we multiply those by 10 (ten different hundreds digits, 0-9)
    
    //Note: because the set is 1-1000 inclusive, we don't have to think about 0, but we do have to add one thousand, which can be done manually

    //counting the number of letters in each digit
    //this can be done in advance and stored (same for the teen numbers below), but it helps to have it here to ensure no errors
    std::vector<std::string> onesNumbers = std::vector<std::string>{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    int digitSum = 0;
    for (std::string s : onesNumbers)
    {
        digitSum += s.length();
    }

    int hundredsSum = 0;
    
    //each number occurs 100 times, so we multiply by 100
    hundredsSum += (digitSum * 100);

    //the word "hundred" (7 char) occurs 9 times, once for every nonzero digit, again times 100
    hundredsSum += 7 * 9 * 100;

    //finally, we need to add the "and" (eg one hundred AND twelve), but only for numbers that don't end in double zero
    //so we have an and for three hundred AND forty two, but not three hundred
    //this means it is the number of digits in "and" (3), times the number of occurrences in each hundred range (99), times the number of hundred ranges (9)
    hundredsSum += (3 * 99 * 9);
    
    //for the tens and ones, we can split out 10-19 and focus on the rest, which have considerable overlap
    //note this section will be written focused soley on the 1-99 range, with the rest added in after

    //starting with the "teens" numbers, which are handled manually
    std::vector<std::string> teensNumbers { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    int teensSum = 0;
    for (std::string s : teensNumbers)
    {
        teensSum += s.length();
    }


    //each ones digit occurs 9 times (001-009, 021-099)
    //therefore, we iterate through the vector and add each number multiplied by 9
    //note that, again we don't care about zeroes here, because they don't show up in text (eg, 20 is twenty, not twenty-zero)
    int onesSum = 0;
    onesSum += (digitSum * 9);

    //Each tens digit appears ten times, so each number gets multipled by 10;
    //note this list starts from 20, because there are no tens digits in 0-9, and 10-19 are handled separately, above
    int tensSum = (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) * 10;

    //combining all the tens and ones numbers together
    int tensAndOnesSum = teensSum + onesSum + tensSum;

    //combining the hundreds and tens and ones
    //note that each tens and one number occurs ten times (once for each hundred), so we multiply it by 10
    int total = hundredsSum + (tensAndOnesSum * 10);
    //adding in "one thousand"
    total += 11;
    


    std::cout << "result: ";
    std::cout << total;
    std::cout << std::endl;
    std::getchar();
    
}
