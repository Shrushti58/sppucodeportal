def to_sparse(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    sparse = []
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] != 0:
                sparse.append([i, j, matrix[i][j]])
    return [[rows, cols, len(sparse)]] + sparse

def display_sparse(sparse):
    print("Row Col Value")
    for row in sparse:
        print("  ".join(map(str, row)))

def transpose_sparse(sparse):
    rows, cols, non_zero = sparse[0]
    result = [[cols, rows, non_zero]]
    for col in range(cols):
        for i in range(1, len(sparse)):
            if sparse[i][1] == col:
                result.append([sparse[i][1], sparse[i][0], sparse[i][2]])
    return result

def fast_transpose_sparse(sparse):
    rows, cols, non_zero = sparse[0]
    result = [[cols, rows, non_zero]]
    count = [0] * cols
    index = [0] * cols

    # Count number of terms in each column
    for i in range(1, len(sparse)):
        count[sparse[i][1]] += 1

    # Index of first element in transposed matrix
    index[0] = 1
    for i in range(1, cols):
        index[i] = index[i-1] + count[i-1]

    # Place elements in transposed matrix
    result += [[0, 0, 0] for _ in range(non_zero)]
    for i in range(1, len(sparse)):
        pos = index[sparse[i][1]]
        result[pos] = [sparse[i][1], sparse[i][0], sparse[i][2]]
        index[sparse[i][1]] += 1

    return result

def add_sparse(s1, s2):
    if s1[0][0] != s2[0][0] or s1[0][1] != s2[0][1]:
        print("Matrix dimensions do not match!")
        return []

    result = [[s1[0][0], s1[0][1], 0]]
    i = j = 1
    while i < len(s1) and j < len(s2):
        if s1[i][:2] == s2[j][:2]:
            added_val = s1[i][2] + s2[j][2]
            if added_val != 0:
                result.append([s1[i][0], s1[i][1], added_val])
            i += 1
            j += 1
        elif s1[i][0] < s2[j][0] or (s1[i][0] == s2[j][0] and s1[i][1] < s2[j][1]):
            result.append(s1[i])
            i += 1
        else:
            result.append(s2[j])
            j += 1

    # Append remaining elements
    while i < len(s1):
        result.append(s1[i])
        i += 1
    while j < len(s2):
        result.append(s2[j])
        j += 1

    result[0][2] = len(result) - 1
    return result

# Example usage
matrix1 = [
    [0, 0, 3],
    [4, 0, 0],
    [0, 0, 5]
]

matrix2 = [
    [0, 2, 6],
    [4, 0, 0],
    [0, 1, 5]
]

sparse1 = to_sparse(matrix1)
sparse2 = to_sparse(matrix2)

print("Sparse Matrix 1:")
display_sparse(sparse1)

print("\nSparse Matrix 2:")
display_sparse(sparse2)

print("\n(a) Transpose of Sparse Matrix 1:")
display_sparse(transpose_sparse(sparse1))

print("\n(b) Fast Transpose of Sparse Matrix 1:")
display_sparse(fast_transpose_sparse(sparse1))

print("\n(c) Addition of Sparse Matrix 1 and 2:")
result_add = add_sparse(sparse1, sparse2)
display_sparse(result_add)
