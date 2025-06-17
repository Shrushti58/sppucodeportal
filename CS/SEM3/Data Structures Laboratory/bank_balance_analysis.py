# Function to deposit amount
def deposit(balance, amount):
    return balance + amount

# Function to withdraw amount (only if balance is sufficient)
def withdraw(balance, amount):
    if amount > balance:
        print(f"Cannot withdraw ₹{amount}. Insufficient balance: ₹{balance}")
        return balance
    return balance - amount

# ---- Main Program ----
def main():
    balance = 0
    print("Enter transactions (e.g., D 100 or W 50). Type 'done' to finish.")

    while True:
        entry = input(">> ").strip()
        if entry.lower() == 'done':
            break

        parts = entry.split()
        if len(parts) != 2 or not parts[1].isdigit():
            print("Invalid input format. Use D <amount> or W <amount>")
            continue

        action, amount = parts[0].upper(), int(parts[1])

        if action == 'D':
            balance = deposit(balance, amount)
        elif action == 'W':
            balance = withdraw(balance, amount)
        else:
            print("Invalid transaction type. Use 'D' or 'W'.")

    print(f"\nFinal Balance: ₹{balance}")

# Run the program
main()
