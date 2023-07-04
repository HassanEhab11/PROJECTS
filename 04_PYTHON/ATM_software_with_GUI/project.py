import tkinter as tk
from tkinter import messagebox

# Dictionary to store client information
clients = {
    '215321701332': {'name': 'Ahmed Abdelrazek Mohamed', 'password': '1783', 'balance': 3500166},
    '203659302214': {'name': 'Salma Mohamed Foaad', 'password': '1390', 'balance': 520001},
    '126355700193': {'name': 'Adel Khaled Abdelrahman', 'password': '1214', 'balance': 111000},
    '201455998011': {'name': 'Saeed Amin Elsawy', 'password': '2001', 'balance': 1200},
    '201122369851': {'name': 'Amir Salama Elgendy', 'password': '8935', 'balance': 178933},
    '203366789564': {'name': 'Mina Sameh Bishoy', 'password': '1179', 'balance': 18000},
    '201236787812': {'name': 'Omnia Ahmed Awad', 'password': '1430', 'balance': 180350}
}

# Global variables
current_account = ''
current_password = ''
password_attempts = 0
change_password_attempts = 0


# ATM functions
def check_account():
    global current_account, current_password, password_attempts
    account_number = account_entry.get()
    if account_number == '':
        messagebox.showerror("Error", "Please enter the account number.")
        return 
    if account_number in clients:
        current_account = account_number
        current_password = clients[account_number]['password']
        password_attempts = 0
        show_password_entry()
    else:
        messagebox.showerror("Error", "Account not found")
        reset()


def show_password_entry():
    enter_button.config(state=tk.DISABLED)
    password_frame.pack()


def submit_password():
    global password_attempts
    password = password_entry.get()

    if password == current_password:
        password_attempts = 0
        show_home_menu()
    else:
        password_attempts += 1
        if password_attempts >= 3:
            messagebox.showerror("Error", "Account locked. Please visit the branch.")
            reset()
        else:
            messagebox.showerror("Error", "Incorrect password. Try again.")
            password_entry.delete(0, tk.END)


def show_home_menu():
    account_frame.pack_forget()
    password_frame.pack_forget()
    home_frame.pack(fill=tk.BOTH, expand=True)


def show_balance():
    balance = clients[current_account]['balance']
    name = clients[current_account]['name']
    messagebox.showinfo("Balance Inquiry", f"Name: {name}\nBalance: {balance}")
    reset()


def cash_withdrawal():
    account_frame.pack_forget()
    password_frame.pack_forget()
    home_frame.pack_forget()
    cash_frame.pack()


def withdraw_amount():
    amount = amount_entry.get()

    if amount == '':
        messagebox.showerror("Error", "Please enter the amount to withdraw.")
        return

    amount = int(amount)

    if amount % 100 != 0:
        messagebox.showerror("Error", "Invalid withdrawal amount. Please enter a multiple of 100.")
    elif amount > clients[current_account]['balance']:
        messagebox.showerror("Error", "Insufficient balance.")
    elif amount > 5000:
        messagebox.showerror("Error", "Maximum withdrawal limit exceeded.")
    else:
        # Perform withdrawal operation (to be implemented)
        clients[current_account]['balance'] -= amount
        messagebox.showinfo("Cash Withdrawal", f"Withdrawal successful. \n current balance :{clients[current_account]['balance']} LE \n Thank you!")

    reset()


def fawry_services():
    account_frame.pack_forget()
    password_frame.pack_forget()
    home_frame.pack_forget()
    fawry_frame.pack()


def transfer_services():
    fawry_frame.pack_forget()
    transfer_frame.pack()


def transfer_amount():
    amount = transferAmount_entry.get()

    if amount == '':
        messagebox.showerror("Error", "Please enter the amount to transfer.")
        return

    amount = int(amount)

    if amount % 100 != 0:
        messagebox.showerror("Error", "Invalid transfer amount. Please enter a multiple of 100.")
    elif amount > clients[current_account]['balance']:
        messagebox.showerror("Error", "Insufficient balance.")
    elif amount > 5000:
        messagebox.showerror("Error", "Maximum transfer limit exceeded.")
    else:
        # Perform withdrawal operation (to be implemented)
        clients[current_account]['balance'] -= amount
        messagebox.showinfo("Cash transfer", "Transfer successful. Thank you!")

    reset()


def change_pass_menu():
    global change_password_attempts
    change_password_attempts = 0
    account_frame.pack_forget()
    password_frame.pack_forget()
    home_frame.pack_forget()
    pass_change_frame.pack()


def password_change():
    global change_password_attempts

    new_password = newpass_entry.get()
    confirm_password = confirm_password_entry.get()
	
    if new_password == current_password:
        change_password_attempts += 1
        messagebox.showerror("Error", "New password must be different from the current password.")
    
    elif new_password == '':
        change_password_attempts += 1
        newpass_entry.delete(0, tk.END)
        confirm_password_entry.delete(0, tk.END)
        messagebox.showerror("Error", "Please enter a new password.")
   
    elif len(new_password) != 4:
        change_password_attempts += 1
        newpass_entry.delete(0, tk.END)
        confirm_password_entry.delete(0, tk.END)
        messagebox.showinfo("password Change", "length not equal four")

    elif new_password != confirm_password:
        change_password_attempts += 1
        newpass_entry.delete(0, tk.END)
        confirm_password_entry.delete(0, tk.END)
        messagebox.showinfo("password Change", "Passwords do not match. Please try again.")
    else:
        change_password_attempts = 0
        clients[current_account]['password'] = new_password
        messagebox.showinfo("password Change", "Password changed successfully.")
        reset()
        return
    if change_password_attempts >= 3:
        change_password_attempts = 0
        reset()
        return

def reset():
    account_entry.delete(0, tk.END)
    password_entry.delete(0, tk.END)
    amount_entry.delete(0, tk.END)
    transferAmount_entry.delete(0, tk.END)
    newpass_entry.delete(0, tk.END)
    confirm_password_entry.delete(0, tk.END)

    password_frame.pack_forget()
    home_frame.pack_forget()
    cash_frame.pack_forget()
    fawry_frame.pack_forget()
    transfer_frame.pack_forget()
    pass_change_frame.pack_forget()

    enter_button.config(state=tk.NORMAL)
    account_frame.pack()


# GUI setup
# window Configuration
window = tk.Tk()
window.title("ATM Machine")
window.geometry("350x550+600+120") 
# window.configure(background="#E6F7C1")
window.resizable(False, False)

# account widget
account_frame = tk.Frame(window)
account_label = tk.Label(account_frame, text="Enter account number:", font=("Arial", 14, "bold"))
account_entry = tk.Entry(account_frame, borderwidth=5)
enter_button = tk.Button(account_frame, text="Enter", command=check_account, width=13, height=1, borderwidth=5)

account_label.pack()
account_entry.pack()
enter_button.pack()

account_frame.pack()

# password widget
password_frame = tk.Frame(window)

password_label = tk.Label(password_frame, text="Enter password:", font=("Arial", 14, "bold"))
password_entry = tk.Entry(password_frame, show="*", borderwidth=5)
submit_button = tk.Button(password_frame, text="Submit", command=submit_password, width=13, height=1, borderwidth=5)

password_label.pack()
password_entry.pack()
submit_button.pack()

# home_frame Frame
home_frame = tk.Frame(window)

home_label = tk.Label(home_frame, text="Home Menu", font=("Arial", 12, "bold"))

button_width = 20
button_height = 5

cash_button = tk.Button(home_frame, text="Cash Withdraw", command=cash_withdrawal, width=button_width,
                        height=button_height, borderwidth=5, font=("Arial", 10, "bold"))
balance_button = tk.Button(home_frame, text="Balance Inquiry", command=show_balance, width=button_width,
                           height=button_height, borderwidth=5, font=("Arial", 10, "bold"))
fawry_button = tk.Button(home_frame, text="Fawry Service", command=fawry_services, width=button_width,
                         height=button_height, borderwidth=5,
                         font=("Arial", 10, "bold"))
passChange_button = tk.Button(home_frame, text="Password Change", command=change_pass_menu, width=button_width,
                              height=button_height,
                              borderwidth=5, font=("Arial", 10, "bold"))
exit_button = tk.Button(home_frame, text="Exit", command=window.quit, width=button_width, height=button_height,
                        borderwidth=5, font=("Arial", 10, "bold"))

home_label.pack()
cash_button.pack()
balance_button.pack()
fawry_button.pack()
passChange_button.pack()
exit_button.pack()

# cash_Frame
cash_frame = tk.Frame(window)

amount_label = tk.Label(cash_frame, text="Enter the amount to withdraw:", font=("Arial", 12, "bold"))
amount_entry = tk.Entry(cash_frame, borderwidth=5)
confirm_button = tk.Button(cash_frame, text="Confirm", command=withdraw_amount)

amount_label.pack()
amount_entry.pack()
confirm_button.pack()

# fawry_Frame
fawry_frame = tk.Frame(window)

fawry_label = tk.Label(fawry_frame, text="Fawry Service", font=("Arial", 12, "bold"))
button_width = 20
button_height = 5

Orange_button = tk.Button(fawry_frame, text="Orange Recharge", command=transfer_services, width=button_width,
                          height=button_height, borderwidth=5, font=("Arial", 10, "bold"))
Etisalat_button = tk.Button(fawry_frame, text="Etisalat Recharge", command=transfer_services, width=button_width,
                            height=button_height, borderwidth=5, font=("Arial", 10, "bold"))
Vodafone_button = tk.Button(fawry_frame, text="Vodafone Recharge", command=transfer_services, width=button_width,
                            height=button_height, borderwidth=5, font=("Arial", 10, "bold"))
We_button = tk.Button(fawry_frame, text="We Recharge", command=transfer_services, width=button_width,
                      height=button_height, borderwidth=5, font=("Arial", 10, "bold"))

fawry_label.pack()
Orange_button.pack()
Etisalat_button.pack()
Vodafone_button.pack()
We_button.pack()
# Transfer_Frame
transfer_frame = tk.Frame(window)
transfer_label = tk.Label(transfer_frame, text="Enter Phone Number : ", font=("Arial", 8, "bold"))
number_entry = tk.Entry(transfer_frame, borderwidth=5)
transferAmount_label = tk.Label(transfer_frame, text="Enter Transfer Amount : ", font=("Arial", 8, "bold"))
transferAmount_entry = tk.Entry(transfer_frame, borderwidth=5)
transfer_button = tk.Button(transfer_frame, text="Confirm", command=transfer_amount)

transfer_label.pack()
number_entry.pack()
transferAmount_label.pack()
transferAmount_entry.pack()
transfer_button.pack()
# password_change
pass_change_frame = tk.Frame(window)

newpass_label = tk.Label(pass_change_frame, text="Enter New Password (length four): ", font=("Arial", 8, "bold"))
newpass_entry = tk.Entry(pass_change_frame, borderwidth=5)
confirmpass_label = tk.Label(pass_change_frame, text="Confirm New Password: ", font=("Arial", 8, "bold"))
confirm_password_entry = tk.Entry(pass_change_frame, borderwidth=5)
change_button = tk.Button(pass_change_frame, text="Change", command=password_change)

newpass_label.pack()
newpass_entry.pack()
confirmpass_label.pack()
confirm_password_entry.pack()
change_button.pack()

window.mainloop()
