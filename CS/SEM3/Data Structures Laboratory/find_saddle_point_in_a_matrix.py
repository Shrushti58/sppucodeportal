def find_saddle_point(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    found = False

    for i in range(rows):
        # Find the minimum element in the current row
        row_min = matrix[i][0]
        col_index = 0
        for j in range(1, cols):
            if matrix[i][j] < row_min:
                row_min = matrix[i][j]
                col_index = j

        # Check if it's the maximum in its column
        is_saddle_point = True
        for k in range(rows):
            if matrix[k][col_index] > row_min:
                is_saddle_point = False
                break

        if is_saddle_point:
            print(f"Saddle point found at ({i}, {col_index}) with value {row_min}")
            found = True

    if not found:
        print("No saddle point found in the matrix.")

# Example usage
matrix = [
    [3, 8, 4],
    [2, 7, 9],
    [5, 1, 6]
]

print("Matrix:")
for row in matrix:
    print(row)

find_saddle_point(matrix)
