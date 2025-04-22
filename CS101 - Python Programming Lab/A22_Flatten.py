
def flatten(l):
    l2=[]
    for i in l:
        for j in i:
            if isinstance(j,int):
                l2.append(j)
            if isinstance(j,list):
                for k in j:
                    if isinstance(k, int):
                        l2.append(k)
    return l2

#print(flatten(l=[ [ ], [ None ], [ None, [ ] ], [ 1, [None] ], [ [ 2, None ] ] ]))