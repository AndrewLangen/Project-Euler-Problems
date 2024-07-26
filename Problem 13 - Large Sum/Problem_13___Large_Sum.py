#This problem is pretty much trivialized by python handling arbitrary length integers
datafile = open('Numbers.txt', 'r')
lines = datafile.readlines()
sum = 0
for line in lines:
    sum += int(line)
#only want the first 10 digits, which can be given by converting to string and taking a range
sumstring = str(sum)
print(sumstring[0:10])
