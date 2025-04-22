"""
Grains on a Chess Board
"""


def square(number):
    if 1 <= number <= 64:
        return 2 ** (number - 1)

    else:
        raise ValueError("Square number out of range")

pass





def total():
    return (2 ** 64) - 1
    pass

print(square(8))
print(square(13))
print(square(60))
print(total())
