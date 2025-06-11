def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if amount > balance:
        print(f"Cannot withdraw {amount}. Insufficient balance.")
        return balance
    return balance - amount

def process_transactions():
    balance = 0
    print("Enter transaction log (e.g., D 100 or W 50). Press Enter to finish.")
    
    while True:
        line = input()
        if not line:
            break
        
        parts = line.split()
        if len(parts) != 2:
            print("Invalid input format. Use D <amount> or W <amount>.")
            continue
        
        action, value = parts[0], parts[1]
        if not value.isdigit():
            print("Amount should be a number.")
            continue

        amount = int(value)

        if action.upper() == 'D':
            balance = deposit(balance, amount)
        elif action.upper() == 'W':
            balance = withdraw(balance, amount)
        else:
            print("Unknown transaction type. Use D or W.")

    print(f"Final Balance: {balance}")

# Run the program
process_transactions()
