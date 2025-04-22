import string

alphabet=string.ascii_lowercase*4
def encrypt(plain_text,key="dddddddddddddddddddd"):
    plain_text=plain_text.lower()
    # key=key.strip()
    # if len(key)==0:
    if len(key)==0:
        raise ValueError("Key cannot be empty.")

    else:
        times = (len(plain_text)) // (len(key)) + 1
        key = (key * times)[:len(plain_text)]

        encrypted_text_string = ""
        key_list = []
        plain_text_list = []
        encrypt_text = []
        encrypt_text_list = []

        for i in key:
            index = (alphabet.find(i))
            key_list.append(index)
        print(key_list)

        for i in plain_text:
            index = (alphabet.find(i))
            plain_text_list.append(index)
        print(plain_text_list)

        for i in range(0, len(plain_text_list)):
            encrypt_text_list.append(key_list[i] + plain_text_list[i])
        print(encrypt_text_list)

        for i in encrypt_text_list:
            encrypt_text.append(alphabet[i])
        print(encrypt_text)

        for i in encrypt_text:
            encrypted_text_string += i

        return encrypted_text_string



def decrypt(encrypt_text,key="dddddddddddddddddddd"):
    decrypted_text_string=""
    key_list=[]
    encrypt_text_list=[]
    decrypt_text=[]
    decrypt_text_list=[]
    encrypt_text= encrypt_text.lower()
    key=key.strip()

    # if len(key)==0:
    if not key:
        raise ValueError("Key cannot be empty.")

    else:
        times = (len(encrypt_text)) // (len(key)) + 1
        key = (key * times)[:len(encrypt_text)]

        for i in key:
            index = alphabet.find(i)
            key_list.append(index)

        for i in encrypt_text:
            index = alphabet.find(i)
            encrypt_text_list.append(index)

        for i in range(0, len(encrypt_text_list)):
            decrypt_text_list.append(encrypt_text_list[i] - key_list[i])

        for i in decrypt_text_list:
            decrypt_text.append(alphabet[i])

        for i in decrypt_text:
            decrypted_text_string += i

        return decrypted_text_string


# print(encrypt("aaaaaaaaaa","aaaaaaaaaa"))
# print(decrypt("aaaaaaaaaa","aaaaaaaaaa"))
# print("=======================================================================")
# print(encrypt("jurassicpark","ankylosaur"))
# print(decrypt("jhbydgacjrrx","ankylosaur"))
# print("=======================================================================")
# print(encrypt("abcdefghij","abcdefghij"))
# print(decrypt("acegikmoqs","abcdefghij"))
# print("=======================================================================")
# print(encrypt("aaaaaaaaaa","abcdefghij"))
# print(decrypt("abcdefghij","abcdefghij"))
# print("=======================================================================")
# print(encrypt("zzzzzzzzzz","abcdefghij"))
# print(decrypt("zabcdefghi","abcdefghij"))
# print("=======================================================================")
# print(encrypt("rainbowcolors","vibgyor"))
# print(decrypt("mijtzcnxwmupg","vibgyor"))
# print("=======================================================================")
# print(encrypt("panthera","leo"))
# print(decrypt("aebelsce","leo"))
# print("=======================================================================")
# print(encrypt("hello","abc"))
# print(decrypt("hfnlp","abc"))
# print("=======================================================================")
# print(encrypt("Nitk","       "))

print(encrypt("hello","abc"))


