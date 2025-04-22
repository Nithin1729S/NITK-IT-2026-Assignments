"""
number of uppercase, lowercase, numerical digits,and other characters in a string.
"""


def string_composition(input_string):
    no_uppercase=0
    no_lowercase=0
    no_numbers=0
    no_others=0
    if type(input_string)==str:
        for _ in input_string:
            if _.isupper():
                no_uppercase+=1
            elif _.islower():
                no_lowercase+=1
            elif _.isnumeric():
                no_numbers+=1
            else:
                no_others+=1
        lst=[no_uppercase,no_lowercase,no_numbers,no_others]
        return lst
    else:
        raise ValueError ("Invalid input type. Expecting a String.")
pass

#
#
# print(string_composition("NITK"))
# print(string_composition("Mangalore - 575025."))
# print(string_composition("NITK, Surathkal."))
# print(string_composition("575025"))
# print(string_composition("NITK, Surathkal. Mangalore - 575025."))
# print(string_composition(10.0))