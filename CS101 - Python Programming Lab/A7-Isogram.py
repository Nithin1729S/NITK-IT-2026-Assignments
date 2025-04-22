
def is_isogram(string):
    in_chars=[]
    for i in string:
        if i.lower() in in_chars:
            return False
        else:
            if i.isalpha() is True:
                in_chars.append(i.lower())
    else:
        return True

print(is_isogram(""))
print(is_isogram("isogram"))
print(is_isogram("eleven"))
print(is_isogram("zzyzx"))
print(is_isogram("subdermatoglyphic"))
print(is_isogram("Alphabet"))
print(is_isogram("alphAbet"))
print(is_isogram("thumbscrew-japingly"))
print(is_isogram("Dictionary"))
print(is_isogram("thumbscrew-jappingly"))
print(is_isogram("six-year-old"))
print(is_isogram("Emily Jung Schwartzkopf"))
print(is_isogram("Accenture"))
print(is_isogram("BackGround"))
print(is_isogram("First# Clan!"))
print(is_isogram("uncopyrightable"))
