
#include <bits/stdc++.h>

using namespace std;

/* This is a Bank Application System where we are performing various funtionalities like
deposit money, withdraw money, transfer money, check balance, display bank account details, 
close account.
*/

// To perfom various funtionalities, user need to first sign up and then login

class BankAccount {
    
    private:
        // member variable of BankAccount
        long accountNumber;
        
        string accountHolder;
        
        double balance;
        
        string username;
        
        string password;
        
        long mobileNo;
        
    
    public:
        // constructor of BankAccount
        BankAccount(long accNum, string accHolder, double initialBalance, string uname, string pwd, long mno) {
            
            accountNumber = accNum;
            
            accountHolder = accHolder;
            
            balance = initialBalance;
            
            username = uname;
            
            password = pwd;
            
            mobileNo = mno;
        }
        
        // get account Number
        
        long getAccountNumber()  { return accountNumber; }
        
        // get user name
        
        string getUsername()  { return username; }
        
        // get account holder name
        
        string getAccountHolder()  { return accountHolder; }
        
        // get account balance
        
        double getBalance() { return balance; }
        
        // validate login createdentials
        
        bool verifyCredentials(string& uname,string& pwd)  {
            
            return (username == uname && password == pwd);
            
        }
        
        // deposit money to bank account 
        
        void deposit(double amount) {
            
            balance += amount;
            
            cout << "Deposit successful. New balance: ₹" << balance << endl;
        }
        
        //withdraw money from bank account
        
        bool withdraw(double amount) {
            
            if (balance >= amount) {
                
                balance -= amount;
                
                cout << "Withdrawal successful. New balance: ₹" << balance << endl;
                
                return true;
            } 
            else {
                
                cout << "Insufficient balance." << endl;
                
                return false;
            }
        }
        
        //function to display Bank account details
        
        void displayDetails() {
            
            cout << "Account Number: " << accountNumber << endl;
            
            cout << "Account Holder Name: " << accountHolder << endl;
            
            cout << "Balance: ₹" << balance << endl;
            
            cout << "Mobile No: " << mobileNo << endl;
        }
        
        //transfer money to recipient bank account 
        
        bool transfer(BankAccount& receiver, double amount) {
            
            if (withdraw(amount)) {
                
                receiver.deposit(amount);
                
                cout << "Transferred ₹" << amount << " to " << receiver.getAccountHolder() << endl;
                
                return true;
                
            } 
            else {
                
                cout << "Transfer failed. Insufficient balance." << endl;
                
                return false;
            }
        }
};

class Bank {
    
    private:
        // accounts will store all the BankAccount
        vector<BankAccount> accounts;
        
    public:
        BankAccount* findAccount(long accNum) {
            
            for (auto& account : accounts) {
                
                if (account.getAccountNumber() == accNum) {
                    
                    return &account;
                }
            }
            return nullptr;
        }
    
    public:
        // sign Up function
        
        void signUp(long accNum, string accHolder, double initialBalance, string uname, string pwd, long mno) {
            
            for(auto &account: accounts){
                if(account.getAccountNumber() == accNum){
                    cout<<"Account number already exists. Please choose a different number.\n";
                    return;
                }
            }
            
            accounts.push_back(BankAccount(accNum, accHolder, initialBalance, uname, pwd, mno));
            
            cout << "Account created successfully." << endl;
        }
        
        // Log In function
        BankAccount* login(string& uname, string& pwd) {
            
            for (auto& account : accounts) {
                
                if (account.verifyCredentials(uname, pwd)) {
                    
                    std::cout << "Login successful." << endl;
                    
                    return &account;
                }
            }
            
            cout << "Invalid credentials. Login failed." << endl;
            
            return nullptr;
        }
        
        // check password is valid or not 
        
        bool isPasswordValid(string &password){
            try{
                bool hasDigit = false;
                bool hasUppercase = false;
                bool hasSpecialChar = false;
                
                for(char ch : password){
                    if(isdigit(ch)){
                        hasDigit = true;
                    }
                    else if(isupper(ch)){
                        hasUppercase = true;
                    }
                    else if(isalnum(ch)){
                        hasSpecialChar = true;
                    }
                }
                
                return (hasDigit && hasUppercase && hasSpecialChar);
                
            }catch (const char* e) { 
                
              cerr << e << endl;  
            }  
        }
        
        // check Mobile no is of 10 digit or not
        
        bool isMoblieNoValid(long mobileNo){
            try{
                if (mobileNo < 1000000000 || mobileNo > 9999999999){
                return false;
                }
                return true;
            }catch (const char* e) { 
                
              cerr << e << endl;  
            }  

        }
        
        // Close Account function
       
        void closeAccount(long accNumber){
            
            for (auto it = accounts.begin(); it != accounts.end(); ++it) {
                
            if (it->getAccountNumber() == accNumber) {
                
                accounts.erase(it);
                
                cout << "Account deleted successfully." << endl;
                
                return;
            }
        }
        cout << "Account not found." << endl;
        
        }
        
};

int main() {
    
    Bank bank;
    
    BankAccount* currentAccount = nullptr;
    
    long accountNumber;
    
    long mobileNo;
    
    string accountHolder, username, password;
    
    double initialBalance;
    
    int choice;
    
    double amount;

    do {
        cout << "\n===== Bank Application Menu =====" << endl;
        
        cout << "1. New to Bank ? Sign Up" << endl;
        
        cout << "2. Login to your Bank Account" << endl;
        
        cout << "3. Deposit Money" << endl;
        
        cout << "4. Withdraw Money" << endl;
        
        cout << "5. Check Balance" << endl;
        
        cout << "6. Transfer Money" << endl;
        
        cout << "7. Display Account Details" << endl;
        
        cout << "8. Log Out" << endl;
        
        cout << "9. Close Account" << endl;
        
        cout << "10. Exit" << endl;
        
        cout << "===============================" << endl;
        
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        cout<< "-------------------------------\n";
        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                
                cin >> accountNumber;
                
                cin.ignore();  // Ignore the newline character in the input buffer
            
                cout << "Enter Account Holder: ";
                
                getline(cin, accountHolder);
            
                cout << "Enter Initial Balance: ₹";
                
                cin >> initialBalance;
                
                cout << "Enter username: ";
                
                cin >> username;
                
                cout << "Enter password: ";
                
                cin >> password;
                
                while(!bank.isPasswordValid(password)){
                    
                  cout<<"Password must contain at least one numerical, one uppercase letter and one special character.\n";
                  
                  cout<<"Enter a valid password: ";
                  
                  cin>>password;
                }
                
                cout << "Enter Moblie Number: ";
                
                cin >> mobileNo;
                
                while(!bank.isMoblieNoValid(mobileNo)){
                    
                  cout<<"Please enter only 10 digits... \n";
                  
                  cout<<"Enter a valid mobile number: ";
                  
                  cin>>mobileNo;
                }
                
                cin.ignore();
                
                bank.signUp(accountNumber, accountHolder, initialBalance, username, password, mobileNo);
                
                break;
                
            case 2:
                cout << "Enter username: ";
                
                cin >> username;
                
                cout << "Enter password: ";
                
                cin >> password;
                
                currentAccount = bank.login(username, password);
                
                break;

            case 3:
                if (currentAccount) { // before depositing money, checking user is valid or not
                    
                    cout << "Enter the amount to deposit: ";
                    
                    cin >> amount;
                    
                    currentAccount->deposit(amount);
                    
                } 
                else {
                    
                    cout << "Please log in first." << std::endl;
                }
                break;

            case 4:
                if (currentAccount) { // before withdrawing money, checking user is valid or not
                    
                    cout << "Enter the amount to withdraw: ";
                    
                    cin >> amount;
                    
                    currentAccount->withdraw(amount);
                    
                } 
                else {
                    
                    cout << "Please log in first." << std::endl;
                }
                break;
            
            case 5:
                if (currentAccount) { // // before checking balance , checking user is valid or not
                    
                    cout << "Account balance: ₹" << currentAccount->getBalance() << endl;
                    
                } else {
                    cout << "Please log in first." << endl;
                }
                break;
            
            case 6:
                if (currentAccount) { // before transfer money to recipient, checking user is valid or not
                    
                    long receiverAccountNumber;
                    
                    cout << "Enter receiver's account number: ";
                    
                    cin >> receiverAccountNumber;
                    
                    BankAccount* receiverAccount = bank.findAccount(receiverAccountNumber);
                    
                    if (receiverAccount) {
                        
                        cout << "Enter the amount to transfer: ";
                        
                        cin >> amount;
                        
                        currentAccount->transfer(*receiverAccount, amount);
                    } 
                    else {
                        cout << "Receiver account not found." << endl;
                    }
                }
                else {
        
                        cout << "Please log in first." << endl;
                }
                break;

            case 7:
                if (currentAccount) { // before displaying bank account details, checking user is valid or not
                    
                    currentAccount->displayDetails();
                    
                } 
                else {
                    
                    cout << "Please log in first." << endl;
                }
                break;
            
            case 8:
                if (currentAccount) { // before log out, checking user is valid or not
                    
                currentAccount = nullptr;
            
                cout << "You have been logged out.\n";
                
                }
                else {
                    
                    cout << "Please log in first." << endl;
                }
                
                break;
            
            case 9:
                if (currentAccount) { // before deleting the accoung, checking user is valid or not
                    
                bank.closeAccount(currentAccount->getAccountNumber());
                
                currentAccount = nullptr;
                
                }
                else {
                    
                    cout << "Please log in first." << endl;
                }
                
                break;
            
            case 10:
                cout << "Thank you for using the Bank Application!" << endl;
                
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                
                break;
        }

    } while (choice != 10);

    return 0;
}

