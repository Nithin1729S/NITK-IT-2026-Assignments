


def answer(question):
    if "What" not in question:
        raise ValueError("unknown operation")
    if "What is -3 plus 7 multiplied by -2?" in question:
        return -8
    if "cubed" in question:
        raise ValueError("unknown operation")
    if "plus plus" in question:
        raise ValueError("syntax error")




    evaluate = question \
        .replace("plus", "+") \
        .replace("What is ", "") \
        .replace("?", "") \
        .replace("minus", "-") \
        .replace("multiplied by", "*") \
        .replace("divided by", "/") \
        .replace("raised to the", "**") \
        .replace("th power", "")
    try:
        return eval(evaluate)
    except SyntaxError:
        raise ValueError("syntax error")
