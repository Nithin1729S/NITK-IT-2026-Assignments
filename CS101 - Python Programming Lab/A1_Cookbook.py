"""
CS101. W2 - Numbers.
The Mysore Pak Cookbook
"""

# insert the value 
EXPECTED_COOK_TIME=40


def cooking_time_remaining(elapsed_cooking_time):
    return EXPECTED_COOK_TIME-elapsed_cooking_time
    pass
"""Calculate the cooking time remaining.

    :param elapsed_cooking_time: int cooking time already elapsed.
    :return: int remaining cooking time derived from 'EXPECTED_COOK_TIME'.

    Function that takes the actual minutes the Mysore Pak has been in the cooking pan
    on fire as an argument and returns how many minutes the sweet still needs to cook
    based on the `EXPECTED_COOK_TIME`.
    """


def preparation_time_required_in_minutes(num_pieces):
    if num_pieces<1:
        raise ValueError("Number of pieces should be greater than Zero.")

    return (num_pieces/10)*5
"""
    Calculate preparation time for the given number of pieces
    Preparation time is (num_pieces // BATCH_SIZE) * PREPARATION_TIME

    Assumption: num_pieces % 10 == 0 always
    """

pass
    
def remaining_time_in_minutes(num_pieces, elapsed_time):
    cooking_time= (((num_pieces/10)*5)+EXPECTED_COOK_TIME)
    if elapsed_time>cooking_time:
        return 0
    else:
        return cooking_time-elapsed_time

pass



"""
    Two parameters:
    num_pieces: number of Mysore Pak pieces being prepared
    elapsed_cooking_time: the number of minutes elapsed from start till now

    Returns the number of minutes remaining till all the
    Mysore Paks are fully done.
    """

