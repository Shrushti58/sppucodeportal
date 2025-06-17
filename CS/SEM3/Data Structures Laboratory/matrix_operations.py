def display_matrix(matrix):
    for row in matrix:
        print(row)

def add_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(A[0])):
            row.append(A[i][j] + B[i][j])
        result.append(row)
    return result

def subtract_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(A[0])):
            row.append(A[i][j] - B[i][j])
        result.append(row)
    return result

def multiply_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(B[0])):
            total = 0
            for k in range(len(B)):
                total += A[i][k] * B[k][j]
            row.append(total)
        result.append(row)
    return result

def transpose_matrix(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    transposed = []
    for j in range(cols):
        row = []
        for i in range(rows):
            row.append(matrix[i][j])
        transposed.append(row)
    return transposed

# Example matrices
A = [
    [1, 2, 3],
    [4, 5, 6]
]

B = [
    [7, 8, 9],
    [1, 2, 3]
]

print("Matrix A:")
display_matrix(A)

print("\nMatrix B:")
display_matrix(B)

# Addition
print("\n(a) Addition of A and B:")
display_matrix(add_matrices(A, B))

# Subtraction
print("\n(b) Subtraction of A and B:")
display_matrix(subtract_matrices(A, B))

# Matrix multiplication (A: 2x3, B_T: 3x2 for valid multiplication)
B_T = transpose_matrix(B)  # Transpose B to make it 3x2
print("\n(c) Multiplication of A and B_T (Transpose of B):")
display_matrix(multiply_matrices(A, B_T))

# Transpose
print("\n(d) Transpose of Matrix A:")
display_matrix(transpose_matrix(A))
