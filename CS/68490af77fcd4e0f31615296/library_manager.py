# Initial list of books
books = []

# a) Remove duplicate entries
def remove_duplicates(book_list):
    unique = []
    seen = set()
    for book in book_list:
        key = (book['title'], book['cost'])
        if key not in seen:
            seen.add(key)
            unique.append(book)
    return unique

# b) Display books in ascending order by cost
def display_sorted_books(book_list):
    sorted_books = sorted(book_list, key=lambda x: x['cost'])
    print("\nBooks sorted by cost:")
    for book in sorted_books:
        print(f"{book['title']} - ₹{book['cost']}")

# c) Count books with cost > 500
def count_books_above_500(book_list):
    count = sum(1 for book in book_list if book['cost'] > 500)
    print(f"\nNumber of books with cost > ₹500: {count}")

# d) Copy books with cost < 500
def copy_books_below_500(book_list):
    cheap_books = [book for book in book_list if book['cost'] < 500]
    print("\nBooks with cost < ₹500:")
    for book in cheap_books:
        print(f"{book['title']} - ₹{book['cost']}")
    return cheap_books

# Add new book
def add_book():
    title = input("Enter book title: ")
    try:
        cost = float(input("Enter book cost: "))
        books.append({"title": title, "cost": cost})
        print("Book added successfully.")
    except ValueError:
        print("Invalid cost. Please enter a number.")

# Menu loop
while True:
    print("\n====== Department Library Menu ======")
    print("1. Add Book")
    print("2. Remove Duplicates")
    print("3. Display Books Sorted by Cost")
    print("4. Count Books with Cost > ₹500")
    print("5. Copy Books with Cost < ₹500")
    print("6. Show All Books")
    print("0. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        add_book()
    elif choice == '2':
        books = remove_duplicates(books)
        print("Duplicates removed.")
    elif choice == '3':
        display_sorted_books(books)
    elif choice == '4':
        count_books_above_500(books)
    elif choice == '5':
        copy_books_below_500(books)
    elif choice == '6':
        print("\nAll books:")
        for book in books:
            print(f"{book['title']} - ₹{book['cost']}")
    elif choice == '0':
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please try again.")
