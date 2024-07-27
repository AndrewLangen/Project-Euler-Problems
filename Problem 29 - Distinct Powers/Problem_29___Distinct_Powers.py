#100^100 is going to be way to large for C++ literals, so python is preferable here

results = set()
for a in range(2,101): #python ranges are [start, end), so we need one extra for 2 to 100
    for b in range(2, 101):
        results.add(a**b)
        
print(len(results))
