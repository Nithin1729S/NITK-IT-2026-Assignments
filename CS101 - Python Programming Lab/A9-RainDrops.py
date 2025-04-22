
def convert(number):

    if number < 2 :
        raise ValueError("Invalid input.")

    raindrops = ""
    if number % 2 == 0 :
        raindrops = "rim jhim"

    if number % 3 == 0 :
        if raindrops == "":
            raindrops = "jal tarang"
        else:
            raindrops = f"{raindrops} jal tarang"
            
    if number % 5 == 0 :
        if raindrops == "":
            raindrops = "baadal"
        else:
            raindrops = f"{raindrops} baadal"

    if number % 7 == 0 :
        if raindrops == "":
            raindrops = "chalte hain"
        else:
            raindrops = f"{raindrops} chalte hain"

    if raindrops == "" :
        raindrops = f"{number}"

    return raindrops

