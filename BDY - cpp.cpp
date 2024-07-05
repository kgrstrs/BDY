//Reyes, Yoel Dwayne
//Baranda, Darryl
//Flores, Lorenzo
//Balitayo, Jimiel
//Rodriguez, Justine

#include <iostream>
#include <limits> 

using namespace std;

struct account {
    int accnum;
    double bal;
    account* next;
};

class Bank {
private:
    account* head;

public:
    Bank() {
        head = NULL;
    }

    void createact(int accnum, double intbal) {
        if (findaccount(accnum) != NULL) {
            cout << "Account number taken, Choose a different one." << endl;
            return;
        }

        account* newacc = new account;
        newacc->accnum = accnum;
        newacc->bal = intbal;
        newacc->next = NULL;

        if (head == NULL) {
            head = newacc;
        } else {
            account* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newacc;
        }
        cout << "Your Account was successfully created." << endl;
    }

    void deposit(int accnum, double amt) {
        account* acc = findaccount(accnum);
        if (acc != NULL) {
            acc->bal += amt;
            cout << "Deposit complete. \nYour New balance is: " << acc->bal << endl;
        } else {
            cout << "Account not found in the database." << endl;
        }
    }

    void withdraw(int accnum, double amt) {
        account* acc = findaccount(accnum);
        if (acc != NULL) {
            if (acc->bal >= amt) {
                acc->bal -= amt;
                cout << "Withdrawal complete. \nYour New balance is: " << acc->bal << endl;
            } else {
                cout << "Not enough Balance." << endl;
            }
        } else {
            cout << "Account not found in the database." << endl;
        }
    }

    void checkbal(int accnum) {
        account* acc = findaccount(accnum);
        if (acc != NULL) {
            cout << "Balance: " << acc->bal << endl;
        } else {
            cout << "Account not found in the database." << endl;
        }
    }

    account* findaccount(int accnum) {
        account* temp = head;
        while (temp != NULL) {
            if (temp->accnum == accnum) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (cin.peek() == '\n') {
                break;
            } else {
                cout << "Invalid input. Please reenter." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Invalid input. Please reenter." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

double getDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (cin.peek() == '\n') {
                break;
            } else {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

int main() {
    Bank bank;

    int choice;
    int accnum;
    double amt;

    do {
        cout << "\nPlease Choose An Option." << endl;
        cout << "[1] - Create an Account" << endl;
        cout << "[2] - Deposit" << endl;
        cout << "[3] - Withdraw" << endl;
        cout << "[4] - Check your Balance" << endl;
        cout << "[5] - Exit" << endl;
        cout << "Enter your choice: ";
        choice = getIntegerInput("");

        switch (choice) {
            case 1:
                reenter11:
                accnum = getIntegerInput("Enter account number: ");
                if (accnum < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter11;
                }

                reenter12:
                amt = getDoubleInput("Enter starting balance: ");
                if (amt < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter12;
                }

                bank.createact(accnum, amt);
                break;
            case 2:
                
                reenter21:
                accnum = getIntegerInput("Enter account number: ");
                if (accnum < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter21;
                }

                reenter22:
                amt = getDoubleInput("Enter amount: ");
                if (amt < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter22;
                }

                bank.deposit(accnum, amt);
                break;
            case 3:
                
                reenter31:
                accnum = getIntegerInput("Enter account number: ");
                if (accnum < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter31;
                }

                reenter32:
                amt = getDoubleInput("Enter amount: ");
                if (amt < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter32;
                }

                bank.withdraw(accnum, amt);
                break;
            case 4:
                
                reenter41:
                accnum = getIntegerInput("Enter account number: ");
                if (accnum < 0) {
                    cout << "Invalid Format. Please Reenter.\n" << endl;
                    goto reenter41;
                }

                bank.checkbal(accnum);
                break;
            case 5:
                cout << "Thank you for using BDY." << endl;
                break;
            default:
                
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}
