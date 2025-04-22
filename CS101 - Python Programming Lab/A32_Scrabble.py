import string
def score(word):
    result=0
    wrd=word.lower()
    ltt1="aeioulnrst"
    ltt2="dg"
    ltt3="bcmp"
    ltt4="fhvwy"
    ltt5="k"
    ltt6="jx"
    ltt7="qz"






    for i in wrd:
        if i in ltt1:
            result+=1
        elif i in ltt2:
            result+=2
        elif i in ltt3:
            result+=3
        elif i in ltt4:
            result+=4
        elif i in ltt5:
            result+=5
        elif i in ltt6:
            result+=8
        elif i in ltt7:
            result+=10

    return result



