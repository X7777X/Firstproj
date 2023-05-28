#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

enum TransactionType { Deposit, Withdrawal, Transfer };

class Person {
protected:
    std::string name;
public:
    Person(std::string name) : name(name) {}
    virtual void display_person() {
        std::cout << "Name: " << setw(6) << name << ";";
    }
};

class Transaction {
private:
    string transaction_id;
    TransactionType type;
    double amount;
    time_t timestamp;

public:
    Transaction(std::string id, TransactionType type, double amount)
        : transaction_id(id), type(type), amount(amount) {
        this->timestamp = time(0);
    }

    string getId() const {
        return this->transaction_id;
    }

    TransactionType getType() const {
        return this->type;
    }

    double getAmount() const {
        return this->amount;
    }

    time_t getTimestamp() const {
        return this->timestamp;
    }
};

class Account {
protected:
    std::string account_name;
    double balance;
    vector<Transaction> transactions;
public:
    Account(std::string name, double initial_balance) : account_name(name), balance(initial_balance) {}

    virtual bool deposit(double amount) = 0;

    virtual bool withdraw(double amount) = 0;

    virtual bool transfer(Account* to, double amount) = 0;

    virtual void display_account() const = 0;
};

class SavingsAccount : public Account {
private:
    double interest_rate;
public:
    SavingsAccount(std::string name, double initial_balance, double interest_rate)
        : Account(name, initial_balance), interest_rate(interest_rate) {}

    bool deposit(double amount) override {
        if (amount < 0) {
            return false;
        }
        balance += amount;
        balance += balance * interest_rate;
        return true;
    }
    virtual bool withdraw(double amount){}
    virtual bool transfer(Account* to, double amount){}
    void display_account() const override {
        std::cout << "Savings Account holder: " << account_name << ", Balance: " << balance
            << ", Interest rate: " << interest_rate << std::endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string name, double initial_balance)
        : Account(name, initial_balance) {}

    bool withdraw(double amount) override {
        if (balance - amount >= 0) {
            balance -= amount;
            return true;
        }
        balance -= 20.0; // penalty
        return false;
    }

    void display_account() const override {
        std::cout << "Checking Account holder: " << account_name << ", Balance: " << balance << std::endl;
    }
};

class CreditAccount : public Account {
private:
    double credit_limit;
public:
    CreditAccount(std::string name, double initial_balance, double credit_limit)
        : Account(name, initial_balance), credit_limit(credit_limit) {}

    bool withdraw(double amount) override {
        if (balance + credit_limit - amount >= 0) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void display_account() const override {
        std::cout << "Credit Account holder: " << account_name << ", Balance: " << balance
            << ", Credit limit: " << credit_limit << std::endl;
    }
};

class Customer : public Person {
private:
    std::vector<Account*> accounts;
    int customerid;
public:
    Customer(std::string name,  int customerid) : Person(name), customerid(customerid) {}

    void add_account(Account* account) {
        accounts.push_back(account);
    }

    void display_accounts() {
        for (Account* account : accounts) {
            account->display_account();
        }
    }
    void display_person() override {
        Person::display_person();
        cout << " Customerid: " << customerid << endl;
    }


};
class BankEmployee : public Person {
public:
    BankEmployee(std::string name) : Person(name) {}

    void display_person() override {
        std::cout << "Bank employee name: " << name << std::endl;
    }
};

class BankManager : public BankEmployee {
public:
    BankManager(std::string name) : BankEmployee(name) {}

    void display_person() override {
        std::cout << "Bank manager name: " << name << std::endl;
    }
};

class ATM {
private:
    string name;
public:
    ATM(string name) : name(name) {}
    bool withdraw(Account* account, double amount) {
        return account->withdraw(amount);
    }

    bool deposit(Account* account, double amount) {
        return account->deposit(amount);
    }

    bool transfer(Account* from, Account* to, double amount) {
        return from->transfer(to, amount);
    }
    
    void display_atms()
    {
        cout << "ATM: " << name << endl;
    }
 
};



class Bank {
private:
    std::vector<Customer*> customers;
    std::vector<BankEmployee*> employees;
    BankManager* manager;
    std::vector<ATM*> atms;

public:
    Bank(BankManager* manager) : manager(manager) {}


    Customer& findCustomer(int customerId) {
        // возвращение ссылки на клиента с заданным ID
    }

    Account& findAccount(int accountId, Customer& customer) {
        // возвращение ссылки на счет с заданным ID для заданного клиента
    }
    void add_customer(Person* customer) {
        customers.push_back(dynamic_cast<Customer*>(customer));
    }

    void add_employee(BankEmployee* employee) {
        employees.push_back(employee);
    }

    void add_atm(ATM* atm) {
        atms.push_back(atm);
    }

    void display_customers() {
        for (Customer* customer : customers) {
            customer->display_person();
        }
        
    }

    bool hasCustomers() const {
        return !customers.empty();
    }

    void display_accounts() {
        for (Customer* customer : customers) {
            customer->display_accounts();
        }
    }

    void display_employees() {
        for (BankEmployee* employee : employees) {
            employee->display_person();
        }
    }

    void display_manager() {
        manager->display_person();
    }

    void display_atms() {
        for (ATM* atm : atms) {
            atm->display_atms();
        }
    }

    void display_all() {
        std::cout << "Bank manager:\n";
        display_manager();
        std::cout << "\nBank employees:\n";
        display_employees();
        std::cout << "\nBank customers:\n";
        display_customers();
    }
};

int main() {
    system("chcp 1251");
    Person* cust1 = new Customer("Tom", 1);
    Person* cust2 = new Customer("T", 2);
    Person* cust3 = new Customer("O", 4);
    Bank bank(new BankManager("g"));
 /*   bank.add_customer(cust1);
    bank.add_customer(cust2);
    bank.add_customer(cust3);*/
    bank.add_customer(cust1);
    bank.add_customer(cust2);
    bank.add_customer(cust3);


    cout << "Перевод денег" << endl;
    if (bank.hasCustomers())
    {
        bank.display_customers();
    }
    else
        cout << "В банке нет клиентов.";






   /* Bank bank(new BankManager("Manager"));
    bank.add_employee(new BankEmployee("Employee1"));
    bank.add_employee(new BankEmployee("Employee2"));

    Customer* customer1 = new Customer("Alice");
    customer1->add_account(new SavingsAccount("Alice", 1000.0, 0.02));
    bank.add_customer(customer1);

    Customer* customer2 = new Customer("Bob");
    customer2->add_account(new CheckingAccount("Bob", 500.0));
    bank.add_customer(customer2);

    Customer* customer3 = new Customer("Charlie");
    customer3->add_account(new CreditAccount("Charlie", 500.0, 1000.0));
    bank.add_customer(customer3);

    bank.add_atm(new ATM());

    bank.display_all();*/

    return 0;
}


