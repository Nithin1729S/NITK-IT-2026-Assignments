def encrypt(text, key):
    if key != '':
        sum  = ''
        while len(text) > len(key):
            key = key + key


        for i in range(len(text)):
            x = ord(text[i]) + (ord(key[i]) - 97)
            if x > 122:
                sum = sum + chr(x-26)
            else:
                sum = sum + chr(x)
        return sum

    else:
        raise ValueError("Key cannot be empty.")

def decrypt(text, key):
    if key != '':
        sum  = ''
        while len(text) > len(key):
            key = key + key


        for i in range(len(text)):
            x = ord(text[i]) - (ord(key[i]) - 97)
            if x < 97:
                sum = sum + chr(x+26)
            else:
                sum = sum + chr(x)
        return sum

    else:
        raise ValueError("Key cannot be empty.")

