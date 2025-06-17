def ternary_search(arr, key, left, right):
    if left > right:
        return -1

    mid1 = left + (right - left) // 3
    mid2 = right - (right - left) // 3

    if arr[mid1] == key:
        return mid1
    elif arr[mid2] == key:
        return mid2

    if key < arr[mid1]:
        return ternary_search(arr, key, left, mid1 - 1)
    elif key > arr[mid2]:
        return ternary_search(arr, key, mid2 + 1, right)
    else:
        return ternary_search(arr, key, mid1 + 1, mid2 - 1)


# Main program
club_members = []

# Input number of students
n = int(input("Enter number of club members: "))
print("Enter roll numbers:")
for _ in range(n):
    roll = int(input())
    club_members.append(roll)

# Sort roll numbers
club_members.sort()
print("\nClub Members (Sorted Roll Numbers):", club_members)

# Search
roll_to_search = int(input("\nEnter roll number to search: "))
index = ternary_search(club_members, roll_to_search, 0, len(club_members) - 1)

if index != -1:
    print(f"Roll number {roll_to_search} is a **club member** at position {index}.")
else:
    print(f"Roll number {roll_to_search} is **not a club member**.")
