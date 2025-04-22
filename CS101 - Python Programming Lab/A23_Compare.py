def compare_lists(a_list, b_list):
    count=0
    for i in b_list:
        if i<0:
            raise ValueError

    for i in a_list:
        if i**2 in b_list:
            count+=1
    if count==len(a_list):
        return True
    else:
        return False
