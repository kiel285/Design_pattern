#include <iostream>
using namespace std;

class Discount {
public:
    virtual double amount(double input) = 0;
    virtual ~Discount() {}
};

class NoDiscount : public Discount {
public:
    double amount(double input) override {
        return input; 
    }
};

class sampuDiscount : public Discount {
public:
    double amount(double input) override {
        return input * 0.90; 
    }
};

class benteDiscount : public Discount {
public:
    double amount(double input) override {
        return input * 0.80; 
    }
};

class Cart {
private:
    Discount* tempdiscount;
public:
    Cart() : tempdiscount(nullptr) {}

    void setDiscount(Discount* discountStrategy) {
        tempdiscount = discountStrategy;
    }

    double applyDiscount(double amount) {
        return tempdiscount ? tempdiscount->amount(amount) : amount; 
    }

    ~Cart() {
        delete tempdiscount;
    }
};

int main() {
    Cart cart;
    double amount, realamount;
    int choice;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter Discount (1: No Discount, 2: 10%, 3: 20%): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cart.setDiscount(new NoDiscount());
            break;
        case 2:
            cart.setDiscount(new sampuDiscount());
            break;
        case 3:
            cart.setDiscount(new benteDiscount());
            break;
        default:
            cout << "wrong input, terminating code" << endl;
            return 0;
    }

    double finalAmount = cart.applyDiscount(amount);
    
    cout << "Final price after discount: " << finalAmount << endl;

    return 0;
}