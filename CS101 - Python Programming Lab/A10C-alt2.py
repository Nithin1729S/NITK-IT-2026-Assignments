def encrypt(text,key):
  if key== "":
    raise ValueError("Key cannot be empty.")
  key = key + key + key + key
  a = "abcdefghijklmnopqrstuvwxyz"
  ans=""
  for i in range(0,len(text)):
    p=a.index(text[i])
    q=a.index(key[i])
    r=p+q
    ans = ans + a[r%26]
  return ans

def decrypt(text,key):
  if key== "":
    raise ValueError("Key cannot be empty.")
  key = key + key + key + key
  a = "abcdefghijklmnopqrstuvwxyz"
  ans=""
  for i in range(0,len(text)):
    p=a.index(text[i])
    q=a.index(key[i])
    r=p-q
    ans = ans + a[r%26]
  return ans


# print(encrypt("hello","abc"))