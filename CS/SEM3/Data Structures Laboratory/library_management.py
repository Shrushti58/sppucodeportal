def input_books(n):
    books = []
    for i in range(n):
        print(f"\nEnter details for Book {i + 1}")
        title = input("Title: ").strip()
        author = input("Author: ").strip()
        cost = float(input("Cost: "))
        books.append({'title': title, 'author': author, 'cost': cost})
    return books

def remove_duplicates(books):
    unique = []
    seen = set()
    for book in books:
        identifier = (book['title'].lower(), book['author'].lower(), book['cost'])
        if identifier not in seen:
            unique.append(book)
            seen.add(identifier)
    return unique

def display_sorted_by_cost(books):
    sorted_books = sorted(books, key=lambda x: x['cost'])
    print("\n📚 Books sorted by cost:")
    for book in sorted_books:
        print(f"Title: {book['title']}, Author: {book['author']}, Cost: ₹{book['cost']}")

def count_books_above_500(books):
    return sum(1 for book in books if book['cost'] > 500)

def copy_books_below_500(books):
    return [book for book in books if book['cost'] < 500]

# ---------- Main Program ----------
n = int(input("Enter number of books: "))
book_list = input_books(n)

print("\n✅ Removing duplicates...")
book_list = remove_duplicates(book_list)

display_sorted_by_cost(book_list)

count = count_books_above_500(book_list)
print(f"\n📈 Number of books with cost > ₹500: {count}")

cheap_books = copy_books_below_500(book_list)
print("\n📥 Books with cost < ₹500:")
for book in cheap_books:
    print(f"Title: {book['title']}, Author: {book['author']}, Cost: ₹{book['cost']}")
