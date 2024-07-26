/*PROBLEM STATEMENT:
* 
* 
* <p>Starting in the top left corner of a $2 \times 2$ grid, and only being able to move to the right and down, there are exactly $6$ routes to the bottom right corner.</p>
<div class="center">
<img src="resources/images/0015.png?1678992052" class="dark_img" alt=""></div>
<p>How many such routes are there through a $20 \times 20$ grid?</p>

* 
*/

#include <stdio.h>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <math.h>
#include <numeric>
#include <ranges>
#include <vector>
#include <stack>

long long PathCount(int size);
std::vector<int> PascalsTriangleRow(int row);
int PossiblePathsFromPoint(int xpos, int ypos, int xmax = 20, int ymax = 20);

int main()
{
    

    //int result = PossiblePathsFromPoint(0, 0, 20, 20);

    std::cout << "result: ";
    std::cout << PathCount(20);
    std::cout << std::endl;
    std::getchar();
    
}

long long PathCount(int size)
{
    //This can be calculated recursively, but the performance is subpar
    //instead, we can solve this iteratively
    //Because the problem uses a square area with an even size, the grid can be viewed as a diamond, with the start at the top and end at the bottom
    //Therefore, the longest line is across the middle, along what would have been (0,0) to (20,20) on the original square
    //Every solution must reach one (and only one) point along the centerline
    //Therefore, if we know the number of ways to reach each point along the centerline, and the number of ways each point along the centerline can reach the end, we can figure out all possibilities
    //The top to the center is given by Pascal's triangle, because it is calculated by taking the number of possible ways to reach the two earlier nodes and adding them together
    //Note that there is a way to calculate the values of a given point on a given row "in place," without knowing the values of the lines above, but this requires factorials and bumps up against primitive type size limits
    
    std::vector<int> centerlinePascalValues = PascalsTriangleRow(size+1); //the centerline will have one more entry than the size of grid

    //calculating what happens from each of those points is trickier
    //In my mind, this feels like it should be the row above it on pascal's triangle added on, but I can't prove that (and empirical checking doesn't support that)
    //however, because I can't prove it, this side is done recursively

    //this vector can be thought of as the number of paths that pass through each centerline point
    //note we need long longs here because int overflows
    std::vector<long long> centerlinetoBottomValues = std::vector<long long>(size + 1);
    for (int i = 0; i < size + 1; i++)
    {
        centerlinetoBottomValues[i] = (long long)centerlinePascalValues[i] * PossiblePathsFromPoint(i, i, size, size);
    }

    //from there, we just need to add together all of these values
    long long sum = 0;
    for (long long i : centerlinetoBottomValues)
    {
        sum += i;
    }

    return sum;
    
}

std::vector<int> PascalsTriangleRow(int row)
{
    if (row == 1)
        return std::vector<int>{1};
    std::vector<int> previousRow = PascalsTriangleRow(row - 1);
    std::vector<int> toReturn = std::vector<int>(row); //the nth row has n entries (one-indexed because it makes the math easier)
    toReturn[0] = 1;
    for (int i = 1; i <= previousRow.size()-1; i++)
    {
        toReturn[i] = previousRow[i - 1] + previousRow[i];
    }
    toReturn[row - 1] = 1;
    return toReturn;
}

int PossiblePathsFromPoint(int xpos, int ypos, int xmax, int ymax)
{
    //(0,0) is set to be the origin, so the start point is (0, ymax) and the endpoint is (xmax, 0);
    if (xpos == xmax || ypos == 0)
        return 1;
    else
        return PossiblePathsFromPoint(xpos + 1, ypos, xmax, ymax) + PossiblePathsFromPoint(xpos, ypos - 1, xmax, ymax);
}