student_list=("Alice", "Bob","Charlie","David","Eve","Fred","Ginny", "Harriet","Ileana", "Joseph", "Kincaid", "Larry")
class Garden:
    def __init__(self,diagram,students=student_list):
        self.diagram=diagram
        self.students=sorted(students)


    def plants(self,name):
        lst = []
        name_pos=self.students.index(name)*2
        for i in self.diagram.splitlines():
            lst.append(i)

        result=[]
        for i in lst:
            for idx,plant in enumerate(i):
                if name_pos <= idx <= name_pos+1:
                    result.append(plant)

        for i in range(len(result)):
            if result[i]=="R":result[i]="Radishes"
            if result[i]=="C":result[i]="Clover"
            if result[i]=="V":result[i]="Violets"
            if result[i]=="G":result[i]="Grass"


        return result




