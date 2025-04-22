from math import sqrt

def roots(equation):
    if type(equation) != str:
        raise ValueError("Invalid input type. Expecting a String.")
    if ","  in equation:
        raise ValueError("Not a Quadratic equation.")
    if "x2" not in equation:
        raise ValueError("Not a Quadratic equation.")
    equation = equation.replace('-', '+-').replace(' ', '')
    chars = equation.split("+")

    a, b, c = 0, 0, 0

    for i in chars:
        if i == "":
            continue
        if "x2" in i:
            if len(i) == 2 or i == "-x2":
                a += -1 if i[0] == "-" else 1
            else:
                a += int(i[:-2]) if i[0] != '-' else -int(i[1:-2])
        elif "x" in i:
            if i == "x" or i == "-x":
                b += -1 if i[0] == '-' else 1
            else:
                b += int(i[:-1]) if i[0] != '-' else -int(i[1:-1])
        else:
            c += float(i)
    d = (b ** 2) - (4 * a * c)
    if d < 0:
        raise ValueError("Roots are Complex.")
    root1 = round((-b + sqrt(d)) / (2 * a),3)
    root2 = round((-b - sqrt(d)) / (2 * a),3)
    if root1==-0:
        root1=0
    if root2==-0:
        root2=0
    if root2==root1:
        return [root1]
    else:
        return [root1,root2]




# print(roots('4x2'))
# print(roots('4x2 + 4x'))
# print(roots('4x2+4x+0.75'))
# print(roots("x2 - 1"))
# print(roots("2x2 - 1"))
# print(roots("-4x2 + 4x + 10"))
#print(roots("-4x2+4x+10"))
#print(roots("-4x2-4x+0"))
# print(roots("4x2 + x + 10"))
#print(roots("4x2,x+10"))

