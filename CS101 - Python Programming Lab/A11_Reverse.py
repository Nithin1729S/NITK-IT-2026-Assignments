def reverse(number):
    positive=True
    if isinstance(number,int):
        if number<0:
            positive=False
            number=-number
        reverse_number=0
        while number!=0:
            rem=number%10
            reverse_number=(reverse_number*10)+rem
            number//=10
    else:
        raise ValueError("Invalid input type, Expectating an integer.")

    if not positive:
        reverse_number=-reverse_number
        return reverse_number
    else:
        return reverse_number


# # print(reverse(-1.0))
# print(reverse(10))
# print(reverse(34))
# print(reverse(-12345))
# print(reverse(10000))