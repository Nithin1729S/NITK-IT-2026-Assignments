def steps(x):
    if x<=0:
        raise ValueError("Only Positive numbers are allowed.")
    seq = [x]
    if x < 1:
       return []
    while x > 1:
       if x % 2 == 0:
         x = x / 2
       else:
         x = 3 * x + 1
       seq.append(x)
    return len(seq)-1


# print(collatz(12))
# print(collatz(1024))
# print(collatz(77777))
# print(collatz(1000000))
# print(collatz(1))