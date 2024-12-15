# Global variable for account balance
account_balance = 0


def display_balance():
    print("Current balance:", account_balance)


def deposit(amount):
    global account_balance
    account_balance += amount
    print(f"Deposited {amount:}. New balance: {account_balance:}")


def withdraw(amount):
    global account_balance
    if amount > account_balance:
        print(f"Insufficient funds. Withdrawal canceled.")
    else:
        account_balance -= amount
        print(f"Withdrew {amount:}. New balance: {account_balance:}")


def main():
    while True:
        print(30 * "*")
        print("\t\tWELCOME TO SBI")
        print(30 * "*")
        print("\nBank Account Management")
        print("1. Balance Inquiry")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Exit")

        choice = input("Enter your choice (1/2/3/4): ")

        if choice == '1':
            display_balance()
        elif choice == '2':

            deposit_amount = float(input("Enter deposit amount: "))
            deposit(deposit_amount)

        elif choice == '3':

            withdrawal_amount = float(input("Enter withdrawal amount: "))
            withdraw(withdrawal_amount)

        elif choice == '4':
            print("Exiting bank account management. Have a great day!")
            break
        else:
            print("Invalid choice. Please select 1, 2, 3, or 4.")


if "_main_":
    main()