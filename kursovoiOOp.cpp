#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    std::string name;
public:
    Person(std::string name) : name(name) {}
    virtual void display() {
        std::cout << "Name: " << name << std::endl;
    }


    std::string get_name() const {
        return name;
    }

};

class Transaction {
private:
    std::string sender_id;
    std::string receiver_id;
    std::string account_number;
    std::string type;
    double amount;

public:
    Transaction(const std::string& account_number, const std::string& type, double amount, const std::string& receiver_id = "")
        : account_number(account_number), type(type), amount(amount) {}

    void display() const {
        std::cout << "Account number: " << account_number << ", Type: " << type << ", Amount: " << amount << std::endl;
    }

    void set_receiver_id(const std::string& receiver_id) {
        this->receiver_id = receiver_id;
    }


};

class Account {
protected:
    std::string account_name, account_id;
    double balance;
    std::vector<Transaction> transaction_history;
public:
    Account(std::string name, double initial_balance, string account_id) : account_name(name), balance(initial_balance), account_id(account_id) {}

    virtual bool deposit(double amount) {
        if (amount < 0) {
            return false;
        }
        balance += amount;
        add_transaction("Deposit", amount);
        return true;
    }

    virtual bool withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
            add_transaction("Deposit", amount);
            return true;
        }
        return false;
    }


    bool transfer(Account* to, double amount) {
        if (withdraw(amount)) {
            to->deposit(amount);

            add_transaction("Transfer", amount);
            to->add_transaction("Transfer", amount, to->get_account_ID());

            return true;
        }
        return false;
    }



    double get_balance() {
        return balance;
    }

    std::string get_name() {
        return account_name;
    }

    string get_account_ID()
    {
        return account_id;
    }

    virtual void display() {
        std::cout << "Account holder: " << account_name << ", Balance: " << balance << std::endl;
    }

    void add_transaction(const std::string& type, double amount, const std::string& receiver_id = "") {
        Transaction transaction(account_id, type, amount);

        if (type == "Transfer" && !receiver_id.empty()) {
            transaction.set_receiver_id(receiver_id);
        }

        transaction_history.push_back(transaction);
    }


    bool has_transactions() const {
        return !transaction_history.empty();
    }

    void display_transaction_history() const {
        std::cout << "Transaction history for account: " << account_id << std::endl;
        for (const Transaction& transaction : transaction_history) {
            transaction.display();
        }
    }
};

class SavingsAccount : public Account {
private:
    double interest_rate;
public:
    SavingsAccount(std::string name, double initial_balance, string account_id, double interest_rate)
        : Account(name, initial_balance, account_id), interest_rate(interest_rate) {}

    bool deposit(double amount) override {
        if (amount < 0) {
            return false;
        }
        balance += amount;
        balance += balance * interest_rate;
        add_transaction("Deposit", amount);
        return true;
    }

    void display() override {
        std::cout << "Savings Account holder: " << account_name << ", Balance: " << balance  << ", AccountID: " << account_id
            << ", Interest rate: " << interest_rate << std::endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string name, double initial_balance, string account_id)
        : Account(name, initial_balance, account_id) {}

    bool withdraw(double amount) override {
        if (balance - amount >= 0) {
            balance -= amount;
            add_transaction("Withdrawal", amount);
            return true;
        }
        balance -= 20.0; // penalty
        return false;
    }

    void display() override {
        std::cout << "Checking Account holder: " << account_name << ", Balance: " << balance <<  ", AccountID: " << account_id << std::endl;
    }
};

class CreditAccount : public Account {
private:
    double credit_limit;
public:
    CreditAccount(std::string name, double initial_balance, string account_id, double credit_limit)
        : Account(name, initial_balance, account_id), credit_limit(credit_limit) {}

    bool withdraw(double amount) override {
        if (balance + credit_limit - amount >= 0) {
            balance -= amount;
            add_transaction("Withdrawal", amount);
            return true;
        }
        return false;
    }

    void display() override {
        std::cout << "Credit Account holder: " << account_name << ", Balance: " << balance  << ", AccountID: " << account_id
            << ", Credit limit: " << credit_limit << std::endl;
    }
};

class Customer : public Person {
private:
    std::vector<Account*> accounts;
public:
    Customer(std::string name) : Person(name) {}

    void add_account(Account* account) {
        accounts.push_back(account);
    }

    void display_accounts() {
        for (Account* account : accounts) {
            account->display();

        }
    }
    
    void display() override {
        Person::display();
    }

    vector<Account*> get_accounts() const {
        return accounts;
    }

    void displayTransactionHistory() const {
        std::cout << "Transaction history for customer: " << name << std::endl;
        for (Account* account : accounts) {
            if (account->has_transactions()) {
                account->display_transaction_history();
            }
            else {
                std::cout << "No transactions found for account: " << account->get_account_ID() << std::endl;
            }
        }
    }

};

class BankEmployee : public Person {
public:
    BankEmployee(std::string name) : Person(name) {}

    void display() override {
        std::cout << "Bank employee name: " << name << std::endl;
    }
};



class Bank {
private:
    std::vector<Customer*> customers;
    std::vector<BankEmployee*> employees;
    std::string bankmanager;

public:
    Bank(string bankmanager) : bankmanager(bankmanager) {}
    void add_customer(Customer* customer) {
        customers.push_back(customer);
    }

    void add_employee(BankEmployee* employee) {
        employees.push_back(employee);
    }

    void display_customers() {
        for (Customer* customer : customers) {
            customer->display();
        }
    }

    void display_employees() {
        for (BankEmployee* employee : employees) {
            employee->display();
        }
    }

    void display_accounts() {
        for (Customer* customer : customers) {
            customer->display_accounts();
        }
    }

    void display_all() {
        std::cout << "Bank manager:\n";
        std::cout << "\nBank employees:\n";
        display_employees();
        std::cout << "\nBank customers:\n";
        display_customers();
    }

  
    void display_customer_accounts(const std::string& name) {
        int customerIndex = find_customer_index(name);
        if (customerIndex != -1) {
            Customer* customer = customers[customerIndex];
            customer->display_accounts();
        }
        else {
            std::cout << "Клиент не найден." << std::endl;
        }
    }


    void display_account_transaction_history(const std::string& account_number) {
        for (Customer* customer : customers) {
            for (Account* account : customer->get_accounts()) {
                if (account->get_account_ID() == account_number) {
                    if (account->has_transactions()) {
                        std::cout << "Transaction history for account: " << account_number << std::endl;
                        account->display_transaction_history();
                    }
                    else {
                        std::cout << "No transactions found for account: " << account_number << std::endl;
                    }
                    return;
                }
            }
        }
        std::cout << "Account not found: " << account_number << std::endl;
    }

    int find_customer_index(const std::string& name) {
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i]->get_name() == name) {
                return i; // Возвращаем индекс найденного клиента
            }
        }
        return -1;
    }

    void perform_account_action(const std::string& customer_name, const std::string& account_number, int action, double amount) {
        int customerIndex = find_customer_index(customer_name);
        if (customerIndex != -1) {
            Customer* customer = customers[customerIndex];
            vector<Account*> accounts = customer->get_accounts();
            for (Account* account : accounts) {
                if (account->get_account_ID() == account_number) {
                    // Выполнение операций с выбранным аккаунтом
                    if (action == 1) {
                        bool success = account->deposit(amount);
                        if (success) {
                            std::cout << "Деньги успешно положены на счет." << std::endl;
                        }
                        else {
                            std::cout << "Не удалось положить деньги на счет." << std::endl;
                        }
                    }
                    else if (action == 2) {
                        bool success = account->withdraw(amount);
                        if (success) {
                            std::cout << "Деньги успешно сняты со счета." << std::endl;
                        }
                        else {
                            std::cout << "Не удалось снять деньги со счета." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Некорректное действие." << std::endl;
                    }

                    account->display();
                    return;
                }
            }
            std::cout << "Счет с указанным номером не найден." << std::endl;
        }
        else {
            std::cout << "Клиент не найден." << std::endl;
        }
    }

    void perform_money_transfer(const std::string& sender_name, const std::string& receiver_name, double amount, const std::string& sender_account_number, const std::string& receiver_account_number) {
        int sender_index = find_customer_index(sender_name);
        if (sender_index == -1) {
            std::cout << "Sender not found: " << sender_name << std::endl;
            return;
        }
        Customer* sender = customers[sender_index];

        int receiver_index = find_customer_index(receiver_name);
        if (receiver_index == -1) {
            std::cout << "Receiver not found: " << receiver_name << std::endl;
            return;
        }
        Customer* receiver = customers[receiver_index];

        // Находим аккаунт отправителя
        Account* sender_account = nullptr;
        for (Account* account : sender->get_accounts()) {
            if (account->get_account_ID() == sender_account_number) {
                sender_account = account;
                break;
            }
        }
        if (sender_account == nullptr) {
            std::cout << "Sender account not found: " << sender_account_number << std::endl;
            return;
        }

        // Находим аккаунт получателя
        Account* receiver_account = nullptr;
        for (Account* account : receiver->get_accounts()) {
            if (account->get_account_ID() == receiver_account_number) {
                receiver_account = account;
                break;
            }
        }
        if (receiver_account == nullptr) {
            std::cout << "Receiver account not found: " << receiver_account_number << std::endl;
            return;
        }

        bool transfer_success = sender_account->transfer(receiver_account, amount);
        if (transfer_success) {
            std::cout << "Money transfer successful." << std::endl;
        }
        else {
            std::cout << "Money transfer failed." << std::endl;
        }
    }

};

int main() {
    string name_of_client, name_of_client2;
    string input_number_of_account, input_number_of_account2;
    int input_function;

    system("chcp 1251");

    Bank bank("Tom");


    bank.add_employee(new BankEmployee("Employee1"));
    bank.add_employee(new BankEmployee("Employee2"));

    Customer* customer1 = new Customer("Alice");
    customer1->add_account(new SavingsAccount("Alice", 1000.0, "44", 0.02));


    bank.add_customer(customer1);

    customer1 = new Customer("Bob");
    customer1->add_account(new CheckingAccount("Bob", 500.0, "11"));
    customer1->add_account(new CheckingAccount("Bob", 1500.0, "22"));
    customer1->add_account(new SavingsAccount("Bob", 1000, "33", 0.02));
    bank.add_customer(customer1);

      /*  cout << "Вывод всех клиентов" << endl;
        bank.display_customers();
        cout << "Введите имя клиента: " << endl;
        cin >> name_of_client;
        cout << "Вывод аккаунтов пользователя:" << endl;
        bank.display_customer_accounts(name_of_client);
        cout << "Выберите аккаунт: " << endl;
        cin >> input_number_of_account;
        cout << "Операции с деньгами" << endl;
        cout << "1. Положить; 2. Снять; 3. Перевести" << endl;
        cin >> input_function;
        bank.perform_account_action(name_of_client, input_number_of_account, input_function, 100);
        cout << "Вывод истории транзакций: " << endl;
        bank.display_account_transaction_history(input_number_of_account);*/

 
    cout << "Перевод" << endl;
    cout << "Вывод всех клиентов" << endl;
    bank.display_customers();
    cout << "выберите отправителя: ";
    cin >> name_of_client;
    bank.display_customer_accounts(name_of_client);
    cout << "Выберите аккаунт отправителя:" << endl;
    cin >> input_number_of_account;
    cout << "выберите получателя: ";
    cin >> name_of_client2;
    bank.display_customer_accounts(name_of_client2);
    cout << "Выберите аккаунт получателя:" << endl;
    cin >> input_number_of_account2;
    bank.perform_money_transfer(name_of_client, name_of_client2, 100, input_number_of_account, input_number_of_account2);
    bank.display_accounts();

  



   // cout << "Перевод деняк" << endl;



    return 0;
}
