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

class real {
private:
    Discount* tempdiscount;
public:
    real() : tempdiscount(nullptr) {}

    void setDiscount(Discount* discountStrategy) {
        tempdiscount = discountStrategy;
    }

    double applyDiscount(double amount) {
        return tempdiscount ? tempdiscount->amount(amount) : amount; 
    }

    ~real() {
        delete tempdiscount;
    }
};

int main() {
    real r1;
    double amount, discount;
    int choice;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter Discount (1: No Discount, 2: 10%, 3: 20%): ";
    cin >> choice;

    switch (choice) {
        case 1:
            r1.setDiscount(new NoDiscount());
            break;
        case 2:
            r1.setDiscount(new sampuDiscount());
            break;
        case 3:
            r1.setDiscount(new benteDiscount());
            break;
        default:
            cout << "wrong input, terminating code" << endl;
            return 0;
    }

    double finalAmount = r1.applyDiscount(amount);
    discount = amount - finalAmount; 
    cout <<"Discount:"<< discount<<endl;
    cout << "Total: " << finalAmount << endl;

    return 0;
}