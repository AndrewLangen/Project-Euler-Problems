#1000 digits is way too large for C++ literals, so python is better here

import math
from tkinter import CURRENT

#because this involves adding two digits together, I don't think it is possible for it to skip a digit

currentnum = 1
lastnum = 1
counter = 2 #currentnum starts at F2

#it is possible to approximate the number of digits in a number using log base ten
#for example, 100 = 10^2, log10(100) = 2, 10000 = 10^4, log10(10000) = 4
#therefore, the number of digits in a number is one greater than the log base 10 of it, rounded down, plus one
#this is also possible to do by converting to string and getting the length of the string, but I suspect that is slower

while math.log10(currentnum) <= 999:
    tempnum = currentnum
    currentnum = lastnum + currentnum
    lastnum = tempnum
    counter = counter+1
    
print (counter)
    
