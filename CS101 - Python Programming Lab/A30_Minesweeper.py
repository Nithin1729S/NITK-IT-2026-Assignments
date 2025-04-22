def count_adj_stars(matrix, row, col):
    num_rows = len(matrix)
    num_cols = len(matrix[0])
    offsets = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    count=0
    for offset in offsets:
        new_row = row + offset[0]
        new_col = col + offset[1]
        if 0 <= new_row < num_rows and 0 <= new_col < num_cols:
            adjacent_element = matrix[new_row][new_col]
            if adjacent_element=="*":
                count+=1
    return count

def annotate(minefield):
    new_matrix=[]
    if any([len(row)!=len(minefield[0]) for row in minefield]):
        raise ValueError("The board is invalid with current input.")

    for i in range(len(minefield)):
        new_row = ""
        for j in range(len(minefield[i])):
            if minefield[i][j] not in ('*', ' ', ''):
                raise ValueError("The board is invalid with current input.")
            elif minefield[i][j] != " ":
                new_row+=minefield[i][j]
            else:
                star_count = count_adj_stars(minefield, i, j)
                if star_count > 0:
                    new_row+=str(star_count)
                else:
                    new_row+=" "
        new_matrix.append(new_row)
    return new_matrix





























































