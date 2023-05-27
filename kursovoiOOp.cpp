#include <iostream>
#include <string>
#include <vector>

class Person {
protected:
    std::string name;

public:
    Person(std::string name) : name(name) {}

    std::string get_name() const { return name; }

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Transaction {
private:
    std::string type;
    double amount;
    std::string account_name;

public:
    Transaction(std::string type, double amount, std::string account_name)
        : type(type), amount(amount), account_name(account_name) {}

    void display() const {
        std::cout << "Transaction: " << type << ", Amount: " << amount
            << ", Account: " << account_name << std::endl;
    }
};

class Loan {
protected:
    double amount;
    double interest_rate;
    Person* client;

public:
    Loan(double amount, double interest_rate, Person* client)
        : amount(amount), interest_rate(interest_rate), client(client) {}

    virtual void display() const {
        std::cout << "Loan: " << amount << ", Interest rate: " << interest_rate
            << ", Client: " << client->get_name() << std::endl;
    }
};

class Mortgage : public Loan {
private:
    int term_in_years;

public:
    Mortgage(double amount, double interest_rate, Person* client, int term_in_years)
        : Loan(amount, interest_rate, client), term_in_years(term_in_years) {}

    void display() const override {
        Loan::display();
        std::cout << "Term in years: " << term_in_years << std::endl;
    }
};

class Card {
protected:
    std::string number;
    Account* account;

public:
    Card(std::string number, Account* account)
        : number(number), account(account) {}

    virtual void display() const {
        std::cout << "Card: " << number << ", Account: " << account->get_name() << std::endl;
    }
};

class DebitCard : public Card {
public:
    DebitCard(std::string number, Account* account) : Card(number, account) {}

    void display() const override {
        Card::display();
        std::cout << "Type: Debit Card" << std::endl;
    }
};

class CreditCard : public Card {
public:
    CreditCard(std::string number, Account* account) : Card(number, account) {}

    void display() const override {
        Card::display();
        std::cout << "Type: Credit Card" << std::endl;
    }
};

class Account {
protected:
    std::string name;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(std::string name, double balance) : name(name), balance(balance) {}

    std::string get_name() const { return name; }

    double get_balance() const { return balance; }

    virtual bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        transactions.push_back(Transaction("deposit", amount, name));
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        transactions.push_back(Transaction("withdraw", amount, name));
        return true;
    }

    virtual bool transfer(Account* account, double amount) {
        if (withdraw(amount)) {
            if (account->deposit(amount)) {
                transactions.push_back(Transaction("transfer", amount, account->get_name()));
                return true;
            }
            deposit(amount); // reverse withdrawal if deposit failed
        }
        return false;
    }

    virtual void display() const {
        std::cout << "Account: " << name << ", Balance: " << balance << std::endl;
        for (const Transaction& transaction : transactions) {
            transaction.display();
        }
    }
};

class SavingsAccount : public Account {
private:
    double interest_rate;

public:
    SavingsAccount(std::string name, double balance, double interest_rate)
        : Account(name, balance), interest_rate(interest_rate) {}

    void add_interest() {
        double interest = balance * (interest_rate / 100);
        deposit(interest);
    }

    void display() const override {
        Account::display();
        std::cout << "Interest Rate: " << interest_rate << std::endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string name, double balance)
        : Account(name, balance) {}
};

class Client : public Person {
private:
    std::vector<Account*> accounts;

public:
    Client(std::string name) : Person(name) {}

    void add_account(Account* account) {
        accounts.push_back(account);
    }

    void display() const override {
        Person::display();
        for (const Account* account : accounts) {
            account->display();
        }
    }
};

class BankEmployee : public Person {
public:
    BankEmployee(std::string name) : Person(name) {}
};

class BankManager : public BankEmployee {
private:
    std::vector<Loan*> loans;

public:
    BankManager(std::string name) : BankEmployee(name) {}

    void add_loan(Loan* loan) {
        loans.push_back(loan);
    }

    void display() const override {
        BankEmployee::display();
        for (const Loan* loan : loans) {
            loan->display();
        }
    }
};

class BankTeller : public BankEmployee {
public:
    BankTeller(std::string name) : BankEmployee(name) {}
};

class Branch {
private:
    std::string name;
    BankManager* manager;
    std::vector<BankTeller*> tellers;

public:
    Branch(std::string name, BankManager* manager)
        : name(name), manager(manager) {}

    void add_teller(BankTeller* teller) {
        tellers.push_back(teller);
    }

    void display() const {
        std::cout << "Branch: " << name << std::endl;
        manager->display();
        for (const BankTeller* teller : tellers) {
            teller->display();
        }
    }
};

class Bank {
private:
    std::string name;
    std::vector<Branch*> branches;

public:
    Bank(std::string name) : name(name) {}

    void add_branch(Branch* branch) {
        branches.push_back(branch);
    }

    void display_all() const {
        std::cout << "Bank: " << name << std::endl;
        for (const Branch* branch : branches) {
            branch->display();
        }
    }
};

int main() {
    Bank bank("Grand Bank");

    Client* client = new Client("John Doe");
    client->add_account(new SavingsAccount("Savings 1", 1000, 1.5));
    client->add_account(new CheckingAccount("Checking 1", 500));

    BankManager* manager = new BankManager("Manager 1");
    manager->add_loan(new Loan(5000, 2.5, client));
    manager->add_loan(new Mortgage(200000, 2, client, 30));

    Branch* branch = new Branch("Downtown", manager);
    branch->add_teller(new BankTeller("Teller 1"));
    branch->add_teller(new BankTeller("Teller 2"));

    bank.add_branch(branch);

    bank.display_all();

    return 0;
}
