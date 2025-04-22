"""
n is a factor of number?
"""
def factor(number, n):
        if isinstance(n,int):
            flag=True
            if number%n==0:
                return flag
            else:
                flag=False
                return flag
        else:
            raise ValueError ("n must be an integer")

pass
