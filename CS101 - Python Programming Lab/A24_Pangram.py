import string

# def is_pangram(sentence):
#     sentence=sentence.lower()
#     alphabet=string.ascii_lowercase
#     count=0
#     for i in alphabet:
#         if i in sentence:
#             count+=1
#     else:
#         if count==26:
#             return True
#         else:
#             return False
#
# print(is_pangram("Five quacking Zephyrs jolt my wax bed."))

def is_pangram(sentence):
    alphabet = string.ascii_lowercase
    sentence = sentence.lower()
    return all(letter in sentence for letter in alphabet)

print(is_pangram("Five quacking Zephyrs jolt my wax bed."))

