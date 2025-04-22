"""
Numbers - Triangle example
"""

def is_triangle(side1, side2, side3):
    if side1>=0 and  side2>=0 and side3>=0:
        flag=True

        if side1==side2==side3==0:
            flag=False
            return flag

        elif side1+side2>=side3 and side1+side3>=side2 and side2+side3>=side1:
            return flag

        else:
            flag=False
            return flag

    else:
        raise ValueError ("Side cannot be negative.")
pass





def is_equilateral(side1, side2, side3):
    if side1 >= 0 and side2 >= 0 and side3 >= 0:
        if side1+side2>=side3 and side1+side3>=side2 and side2+side3>=side1:
            flag=True

            if side1==side2==side3==0:
                flag=False
                return flag

            elif side1==side3==side2:
                return flag

            else:
                flag=False
                return flag

        else:
            flag=False
            return flag

    else:
        raise ValueError("Side cannot be negative.")


pass






def is_isosceles(side1, side2, side3):
    if side1 >= 0 and side2 >= 0 and side3 >= 0:
        if side1 + side2 >= side3 and side1 + side3 >= side2 and side2 + side3 >= side1:
            flag=True

            if side1==side2==side3==0:
                flag=False
                return flag

            elif side1==side2 or side1==side3 or side2==side3:
                return flag

            else:
                flag=False
                return flag

        else:
            flag=False
            return flag

    else:
        raise ValueError("Side cannot be negative.")
pass




def is_scalene(side1, side2, side3):
    if side1 >= 0 and side2 >= 0 and side3 >= 0:
        if side1 + side2 >= side3 and side1 + side3 >= side2 and side2 + side3 >= side1:
            flag=True

            if side1==side2==side3==0:
                flag=False
                return flag

            elif side1!=side2 and side2!=side3 and side1!=side3:
                return flag

            else:
                flag=False
                return flag

        else:
            flag = False
            return flag

    else:
        raise ValueError("Side cannot be negative.")
pass


def is_degenerate(side1, side2, side3):
    if side1 >= 0 and side2 >= 0 and side3 >= 0:
        if side1 + side2 >= side3 and side1 + side3 >= side2 and side2 + side3 >= side1:
            flag=True
            s = (side1 + side2 + side3)/2
            area = (s * (s - side1) * (s - side2) * (s - side3)) ** 0.5

            if side1==side2==side3==0:
                flag=False
                return flag

            elif area==0:
                return flag

            else:
                flag=False
                return flag
        else:
            flag = False
            return flag

    else:
        raise ValueError("Side cannot be negative.")
pass


print(is_triangle(0,0,0))
print(is_triangle(10,0,0))
print(is_triangle(10,20,0))
print(is_triangle(10,20,30))
print(is_triangle(10,1,1))
print(is_triangle(10,5,5))
print(is_triangle(10,5,4))
print("==============================================================")
print(is_equilateral(10,10,10))
print(is_equilateral(0,0,0))
print(is_equilateral(5,5,5))
print(is_equilateral(5,5,4))
print(is_equilateral(5,3,4))
print(is_equilateral(0.5,0.5,0.5))
print(is_equilateral(10,1,1))
print("==============================================================")
print(is_isosceles(3,4,4))
print(is_isosceles(4,3,4))
print(is_isosceles(4,4,3))
print(is_isosceles(4,4,4))
print(is_isosceles(3,4,5))
print(is_isosceles(0,0,0))
print(is_isosceles(10,0,1))
print(is_isosceles(1,10,1))
print(is_isosceles(1,1,10))
print(is_isosceles(0.5,0.5,0.4))
print("============================================================")
print(is_scalene(5,4,6))
print(is_scalene(4,4,4))
print(is_scalene(4,4,3))
print(is_scalene(10,1,1))
print(is_scalene(0.5,0.4,0.6))
print("=====================================================")

print(is_degenerate(0,0,0))
print(is_degenerate(10,5,5))
print("====================================================")









