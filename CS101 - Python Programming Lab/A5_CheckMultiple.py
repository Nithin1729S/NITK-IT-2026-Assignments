"""
Check multiple
"""
def check_multiple(number):
    if isinstance(number,int):
        flag=True
        if number%7==0 and number%3!=0:
            return flag
        else:
            flag=False
            return flag
    else:
        raise ValueError ("input must be an integer")

pass
