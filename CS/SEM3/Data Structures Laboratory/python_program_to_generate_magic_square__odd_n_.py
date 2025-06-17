def generate_magic_square(n):
    if n % 2 == 0:
        print("Magic square is only possible for odd numbers using this method.")
        return

    magic_square = [[0] * n for _ in range(n)]

    i, j = 0, n // 2  # Start from middle of top row

    for num in range(1, n * n + 1):
        magic_square[i][j] = num
        new_i, new_j = (i - 1) % n, (j + 1) % n  # Move up and right

        if magic_square[new_i][new_j] != 0:  # Cell already filled
            i = (i + 1) % n
        else:
            i, j = new_i, new_j

    # Display the magic square
    print(f"\nMagic Square of size {n}x{n}:")
    for row in magic_square:
        print(" ".join(f"{num:2d}" for num in row))

    print(f"\nSum of each row/column/diagonal: {n * (n * n + 1) // 2}")

# Example usage
n = int(input("Enter an odd number for the size of the magic square: "))
generate_magic_square(n)
