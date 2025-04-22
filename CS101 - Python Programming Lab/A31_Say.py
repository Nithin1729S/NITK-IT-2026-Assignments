def word(number):
    string1=""
    single_digits = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    two_digits = [ "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                  "nineteen"]
    tens_multiple = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

    if number[0]==0 and number[1]==0:
        for idx,num in enumerate(number):
            if idx==2 and num!=0:
                string1+=f"{single_digits[num]}"

    elif number[0]==0 and number[1]==1:
        for idx,num in enumerate(number):
            if idx==2 and num!=0:
                string1+=f"{two_digits[num]}"

    elif number[1]==1:
        for idx,num in enumerate(number):
            if idx==0 and num!=0:
                string1+=f"{single_digits[num]} hundred "
            if idx==2 and num!=0 :
                string1+=f"{two_digits[num]}"

    else:
        for idx,num in enumerate(number):
            if idx==0 and num!=0:
                string1+=f"{single_digits[num]} hundred "
            if idx==1 and num!=0:
                string1 += f"{tens_multiple[num]}"
            if idx==2 and num!=0 :
                string1+=f"-{single_digits[num]}"
    return string1


def say(num):
    if num==0:
        return "zero"

    elif 0 < num < 999_999_999_999:
        pos_nums = []
        num_in_words=""



        while num != 0:
            pos_nums.append(num % 10)
            num = num // 10

        while len(pos_nums)<12:
            pos_nums.append(0)

        place=list(reversed(pos_nums))

        matrix = [place[i:i+3] for i in range(0, len(place), 3)]


        result=list(map(word,matrix))


        for idx,wrd in enumerate(result):
            if idx==0 and wrd:
                num_in_words+=f"{result[idx]} billion "
            if idx==1 and wrd:
                num_in_words+=f"{result[idx]} million "
            if idx==2 and wrd:
                num_in_words+=f"{result[idx]} thousand "
            if idx==3 and wrd:
                num_in_words+=f"{result[idx]}"

        return num_in_words.rstrip().lstrip()

    else:
        raise ValueError("input out of range")


