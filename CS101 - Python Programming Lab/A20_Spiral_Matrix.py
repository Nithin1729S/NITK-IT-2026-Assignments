
def spiral_matrix(size):
    mat = [[0] * size for _ in range(size)]
    i = j = di = 0
    dj = 1
    for mat[i][j] in range(1, size ** 2 + 1):
        if mat[(i+di) % size][(j + dj) % size]:
            di, dj = dj, -di
        i += di
        j += dj
    return mat

