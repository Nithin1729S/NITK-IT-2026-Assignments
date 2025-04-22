import string

def substitute(letter,n):
    alphabet = string.ascii_lowercase * 5
    count=0
    for i in alphabet:
        if i==letter and 51<count<78:
            return alphabet[count + n]
        count += 1
    # index=alphabet.find(letter,51) #will start counting after 51 index



# substitute('a',1)
# substitute('a',25)
# substitute('a',26)
# substitute('a',-1)
# substitute('a',-25)
# substitute('a',-26)
# substitute('z',1)
# substitute('z',25)
# substitute('z',26)
# substitute('z',-1)
# substitute('z',-25)
# substitute('z',-26)
