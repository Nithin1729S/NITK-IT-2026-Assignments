def sieve(n):
    if n>=2:
        non_prime_list=[]
        prime_list=[]
        for i in range(2,n+1):
            if i not in non_prime_list:
                prime_list.append(i)
                for j in range(i*2,n+1,i):
                    non_prime_list.append(j)
        return prime_list
    else:
        raise ValueError("Invalid input.")
pass




# print(sieve(19))