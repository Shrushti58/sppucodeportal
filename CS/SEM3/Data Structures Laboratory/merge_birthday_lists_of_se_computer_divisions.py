# Function to input student data
def input_students(n):
    students = []
    for i in range(n):
        prn = input(f"Enter PRN of student {i+1}: ")
        dob = input(f"Enter DOB of student {i+1} (dd-mm): ")
        students.append((prn, dob))
    return students

# Function to sort by date and month
def sort_by_dob(student_list):
    return sorted(student_list, key=lambda x: (int(x[1].split("-")[1]), int(x[1].split("-")[0])))

# Input List A
print("Enter details for List A:")
list_A = input_students(3)

# Input List B
print("\nEnter details for List B:")
list_B = input_students(3)

# Sort both lists
list_A = sort_by_dob(list_A)
list_B = sort_by_dob(list_B)

# Merge and sort
list_SE_Comp_DOB = sort_by_dob(list_A + list_B)

# Display merged list
print("\nMerged and Sorted DOB List:")
for prn, dob in list_SE_Comp_DOB:
    print(f"PRN: {prn}, DOB: {dob}")
