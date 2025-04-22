def round_scores(student_scores):
    student_scores_scores=[round(x) for x in student_scores]
    return student_scores_scores

def count_failed_students(student_scores):
    count=0
    for i in student_scores:
        if i<=40:
            count+=1
    else:
        return count

def above_threshold(student_scores,threshlod):
    threshlod_lst=[]
    for i in student_scores:
        if i>=threshlod:
            threshlod_lst.append(i)
    return threshlod_lst

def letter_grades(highest):
    interval_size = (highest - 40) / 4
    d_threshold = 40 + interval_size
    c_threshold = d_threshold + interval_size
    b_threshold = c_threshold + interval_size
    return [41,int(d_threshold)+1, int(c_threshold)+1, int(b_threshold)+1]

def student_ranking(student_scores,student_names):
    lst=[]
    for i in range(0,len(student_scores)):
        string_1=f"{i+1}. {student_names[i]}: {student_scores[i]}"
        lst.append(string_1)
    return lst

def perfect_score(student_info):
    lst=[]
    for i in range(len(student_info)):
        if student_info[i][1]==100:
            lst.append(student_info[i][0])
            lst.append(student_info[i][1])
            break
    return lst



# student_ranking([100,99,90,84,66,53,47],["Aditya","Leslie","Vinayak","Shivam","Abhilash","Karan","Vishnu"])
#
# print(perfect_score([["Charles",90],["Shiven",100]]))
# print(perfect_score([['Joci', 100], ['Vlad', 100], ['Raiana', 100], ['Alessandro', 100]]))
# print(above_threshold([88, 91, 78, 41, 36], 78))
# print(perfect_score([['Yoshi', 52], ['Jan', 86], ['Raiana', 100], ['Betty', 60], ['Joci', 100], ['Kora', 81], ['Bern', 41]]))