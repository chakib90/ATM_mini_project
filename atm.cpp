#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to store account details
class Account {
private:
    string name;
    string address;
    string contact;
    int balance;
    string pin;
public:
    Account(string n, string addr, string cnt, int bal, string p) {
        name = n;
        address = addr;
        contact = cnt;
        balance = bal;
        pin = p;
    }
    string get_name() {
        return name;
    }
    int get_balance() {
        return balance;
    }
    void deposit(int amount) {
        balance += amount;
    }
    bool withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
        cout << "Balance: " << balance << endl;
    }
    bool check_pin(string p) {
        return p == pin;
    }
    void change_pin(string new_pin) {
        pin = new_pin;
    }
};

// Function to find an account in the accounts vector by name
int find_account(vector<Account>& accounts, string name) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].get_name() == name) {
            return i;
        }
    }
    return -1;
}

// Function to create a new account
void create_account(vector<Account>& accounts) {
    string name, address, contact, pin;
    int balance;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter contact: ";
    cin >> contact;
    cout << "Enter initial balance: ";
    cin >> balance;
    cout << "Enter PIN: ";
    cin >> pin;
    Account acc(name, address, contact, balance, pin);
    accounts.push_back(acc);
    cout << "Account created successfully!" << endl;
}

// Function to withdraw cash from an account
void withdraw(vector<Account>& accounts, int index) {
    int amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (accounts[index].withdraw(amount)) {
        cout << "Cash withdrawn successfully!" << endl;
        cout << "New balance: " << accounts[index].get_balance() << endl;
    } else {
        cout << "Insufficient balance" << endl;
    }
}

// Function to transfer funds between accounts
void transfer(vector<Account>& accounts, int index) {
    string name;
    int amount;
    cout << "Enter account name to transfer to: ";
    cin >> name;
    int index2 = find_account(accounts, name);
    if (index2 == -1) {
        cout << "Account not found" << endl;
        return;
    }
    cout << "Enter amount to transfer: ";
    cin >> amount;
    if (accounts[index].withdraw(amount)) {
        accounts[index2].deposit(amount);
        cout << "Funds transferred successfully!" << endl;
        cout << "New balance: " << accounts[index].get_balance() << endl;
    } else {
        cout << "Insufficient balance" << endl;
    }
}

// Function to change PIN for an account
void change_pin(vector<Account>& accounts, int index) {
string old_pin, new_pin, confirm_pin;
cout << "Enter old PIN: ";
cin >> old_pin;
if (!accounts[index].check_pin(old_pin)) {
cout << "Incorrect PIN" << endl;
return;
}
cout << "Enter new PIN: ";
cin >> new_pin;
cout << "Confirm new PIN: ";
cin >> confirm_pin;
if (new_pin != confirm_pin) {
cout << "PINs do not match" << endl;
return;
}
accounts[index].change_pin(new_pin);
cout << "PIN changed successfully!" << endl;
}

// Main function
int main() {
vector<Account> accounts;
int choice, index;
string name, pin;
while (true) {
cout << "1. Create new account" << endl;
cout << "2. Deposit cash" << endl;
cout << "3. Withdraw cash" << endl;
cout << "4. Transfer funds" << endl;
cout << "5. Check balance" << endl;
cout << "6. Change PIN" << endl;
cout << "7. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
create_account(accounts);
break;
case 2:
cout << "Enter account name: ";
cin >> name;
index = find_account(accounts, name);
if (index == -1) {
cout << "Account not found" << endl;
} else {
int amount;
cout << "Enter amount to deposit: ";
cin >> amount;
accounts[index].deposit(amount);
cout << "Cash deposited successfully!" << endl;
cout << "New balance: " << accounts[index].get_balance() << endl;
}
break;
case 3:
cout << "Enter account name: ";
cin >> name;
index = find_account(accounts, name);
if (index == -1) {
cout << "Account not found" << endl;
} else {
withdraw(accounts, index);
}
break;
case 4:
cout << "Enter account name: ";
cin >> name;
index = find_account(accounts, name);
if (index == -1) {
cout << "Account not found" << endl;
} else {
transfer(accounts, index);
}
break;
case 5:
cout << "Enter account name: ";
cin >> name;
index = find_account(accounts, name);
if (index == -1) {
cout << "Account not found" << endl;
} else {
accounts[index].display();
}
break;
case 6:
cout << "Enter account name: ";
cin >> name;
index = find_account(accounts, name);
if (index == -1) {
cout << "Account not found" << endl;
} else {
change_pin(accounts, index);
}
break;
case 7:
cout << "Exiting..." << endl;
return 0;
default:
cout << "Invalid choice" << endl;
}
}
}