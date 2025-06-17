def display_phonebook(phonebook):
    print("\nCurrent Phonebook:")
    for name, number in phonebook:
        print(f"{name} : {number}")
    print()


def binary_search_recursive(phonebook, key, low, high):
    if low > high:
        return -1
    mid = (low + high) // 2
    if phonebook[mid][0] == key:
        return mid
    elif phonebook[mid][0] > key:
        return binary_search_recursive(phonebook, key, low, mid - 1)
    else:
        return binary_search_recursive(phonebook, key, mid + 1, high)


def binary_search_iterative(phonebook, key):
    low = 0
    high = len(phonebook) - 1
    while low <= high:
        mid = (low + high) // 2
        if phonebook[mid][0] == key:
            return mid
        elif phonebook[mid][0] > key:
            high = mid - 1
        else:
            low = mid + 1
    return -1


def fibonacci_search(phonebook, key):
    n = len(phonebook)
    fibMMm2 = 0
    fibMMm1 = 1
    fibM = fibMMm1 + fibMMm2

    while fibM < n:
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm1 + fibMMm2

    offset = -1

    while fibM > 1:
        i = min(offset + fibMMm2, n - 1)
        if phonebook[i][0] < key:
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i
        elif phonebook[i][0] > key:
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1
        else:
            return i

    if fibMMm1 and offset + 1 < n and phonebook[offset + 1][0] == key:
        return offset + 1

    return -1


def insert_if_not_found(phonebook, name, number):
    phonebook.append((name, number))
    phonebook.sort()


# -------------------------------
# Main program
# -------------------------------
phonebook = [
    ("Amit", "9876543210"),
    ("Kiran", "9823456712"),
    ("Neha", "9912345678"),
    ("Ravi", "9834567123"),
    ("Zoya", "9988776655")
]

phonebook.sort()
display_phonebook(phonebook)

search_name = input("Enter friend's name to search: ")

# ---------- Binary Search (Recursive) ----------
index = binary_search_recursive(phonebook, search_name, 0, len(phonebook) - 1)
if index != -1:
    print(f"Found using Recursive Binary Search: {phonebook[index][0]} - {phonebook[index][1]}")
else:
    print("Friend not found using Recursive Binary Search.")
    add = input("Do you want to add this friend? (yes/no): ").lower()
    if add == "yes":
        mobile = input("Enter mobile number: ")
        insert_if_not_found(phonebook, search_name, mobile)

# ---------- Binary Search (Iterative) ----------
index = binary_search_iterative(phonebook, search_name)
if index != -1:
    print(f"Found using Iterative Binary Search: {phonebook[index][0]} - {phonebook[index][1]}")
else:
    print("Friend not found using Iterative Binary Search.")

# ---------- Fibonacci Search ----------
index = fibonacci_search(phonebook, search_name)
if index != -1:
    print(f"Found using Fibonacci Search: {phonebook[index][0]} - {phonebook[index][1]}")
else:
    print("Friend not found using Fibonacci Search.")

# Final phonebook display
display_phonebook(phonebook)
