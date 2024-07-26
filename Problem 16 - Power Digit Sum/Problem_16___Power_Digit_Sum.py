#using python for this one because it requires large integers

number = 2**1000
#I suspect there's a better way of parsing out individual digits, but I think converting to string, parsing out chars, and then converting back to integers is good enough for this
numberstring = str(number)

sum = 0
for digit in numberstring:
    sum += ord(digit) - ord('0')
print(sum)

