def find(search_list, value):
    lower=0
    upper=len(search_list)-1

    while lower<=upper:
        mid=(lower+upper)//2

        if search_list[mid]==value:
            globals() ['pos'] =mid
            return mid

        else:
            if search_list[mid]<value:
                lower=mid+1
            else:
                upper=mid-1

    raise ValueError("value not in array")






