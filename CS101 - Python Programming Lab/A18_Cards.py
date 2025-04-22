
def get_rounds(number):
    lst=[]
    while (len(lst)<3):       
        lst.append(number)
        number+=1
    return lst
pass



def concatenate_rounds(rounds_1, rounds_2):
    rounds_1.extend(rounds_2)
    return rounds_1
pass



def list_contains_round(rounds, number):
    if number in rounds:
        return True
    else:
        return False
pass


def card_average(hand):
    return sum(hand)/len(hand)
pass



def approx_average_is_average(hand):
    avg_first_last=(hand[0]+hand[-1])/2
    median=hand[(len(hand)-1)//2]
    avg=sum(hand)/len(hand)
    if median==avg or avg_first_last==avg:
        return True
    else:
        return False
pass



def average_even_is_average_odd(hand):
    even=[]
    odd=[]
    for i in range(len(hand)):
        if i%2==0:
            even.append(hand[i])
        else:
            odd.append(hand[i])
    even_avg=sum(even)/len(even)
    odd_avg=sum(odd)/len(odd)
    if even_avg==odd_avg:
        return True
    else:
        return False
pass



def maybe_double_last(hand):
    if hand[-1]==11:
        hand[-1]*=2
    return hand

pass



