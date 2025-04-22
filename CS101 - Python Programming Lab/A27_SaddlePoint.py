def transpose_matrix(matrix):
    rows = len(matrix)
    columns = len(matrix[0]) if rows > 0 else 0
    transpose = [[0 for _ in range(rows)] for _ in range(columns)]
    for i in range(rows):
        for j in range(columns):
            transpose[j][i] = matrix[i][j]
    return transpose

def saddle_points(matrix):
    row_lengths=[len(row) for row in matrix]
    if len(set(row_lengths))==1:
        transpose=transpose_matrix(matrix)
        result=[]
        lst = []
        for i in range(len(matrix)):

            for j in range(len(matrix[i])):
                if matrix[i][j]==max(matrix[i]) and transpose[j][i]==min(transpose[j]) :

                    lst.append(("row",i+1))
                    lst.append(("column",j+1))

                    dct=dict((x, y) for x, y in lst)
                    result.append(dct)
        return result
    else:
        raise ValueError("irregular matrix")






