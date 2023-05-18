#!/usr/bin/python3
def weight_average(my_list=[]):
    if my_list is not None:
        overall = 0
        freq = 0
        for tupp in my_list:
            (weight, occurence) = tupp
            overall += (weight * occurence)
            freq += occurence
        return (overall/freq) if freq > 0 else 0
    else:
        return (0)
