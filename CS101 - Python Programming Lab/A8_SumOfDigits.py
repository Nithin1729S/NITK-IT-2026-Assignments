def sum_of_digits(number):
    if isinstance(number,int):
        sum=0
        for digit in str(number):
            sum+=int(digit)
        return sum
    else:
        raise ValueError ("Invalid input type. Expecting an integer.")






