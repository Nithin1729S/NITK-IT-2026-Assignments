import string

def f_substitute(letter):
    alphabet=string.ascii_lowercase+string.ascii_lowercase
    index=(alphabet.find(letter))
    return alphabet[index + 5]


# f_substitute('a')
# f_substitute('f')
# f_substitute('u')
# f_substitute('z')