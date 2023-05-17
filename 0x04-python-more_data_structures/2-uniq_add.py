#!/usr/bin/python3
def uniq_add(my_list=[]):
    overall = 0
    for x in set(my_list):
        overall += x
    return(overall)
