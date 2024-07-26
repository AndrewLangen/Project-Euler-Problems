# problem statement:
#<p>$n!$ means $n \times (n - 1) \times \cdots \times 3 \times 2 \times 1$.</p>
#<p>For example, $10! = 10 \times 9 \times \cdots \times 3 \times 2 \times 1 = 3628800$,<br>and the sum of the digits in the number $10!$ is $3 + 6 + 2 + 8 + 8 + 0 + 0 = 27$.</p>
#<p>Find the sum of the digits in the number $100!$.</p>



#again, using python here because it handles large numbers better

number = 1
for i in range(2,100):
    number = number * i

sum = 0
numberString = str(number)
for c in numberString:
    sum = sum + int(c)

print(sum)
    
