#!/usr/bin/python3
def update_dictionary(a_dictionary, key, value):
    if a_dictionary is not None:
        dic_2 = {key: value}
        a_dictionary.update(dic_2)
        return(a_dictionary)
    else:
        return None
