

def create_inventory(lst):
        dict_ = {i: lst.count(i) for i in lst}
        return dict_

def add_items(dict1,lst):
        dict2={i: lst.count(i) for i in lst}
        ini_dict = [dict1, dict2]
        result = {k: sum(d[k] for d in ini_dict if k in d) for k in set(k for d in ini_dict for k in d)}
        return result

def decrement_items(dct1,lst):
        dct2 = {i: -lst.count(i) for i in lst}

        ini_dict=[dct1,dct2]
        result={k:sum(d[k] for d in ini_dict if k in d) for k in set(k for d in ini_dict for k in d)}
        for key,value in (result.items()):
            if value<0:
                result[key]=0
        return result

def remove_item(dct,item):
        try:
            del dct[item]
            return dct
        except KeyError:
            return dct

def list_inventory(dct):
        lst=[(key,value) for key,value in dct.items() if value>0]
        return lst




