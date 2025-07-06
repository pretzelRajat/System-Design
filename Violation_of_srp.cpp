#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
    vector<Product*> products;  // Store pointers
public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    void printInvoice() {
        cout << "The shopping cart invoice is:\n";
        for (auto p : products) {
            cout << p->name << " - ₹" << p->price << endl;
        }
        cout << "Total: ₹" << calculateTotal() << endl;
    }

    void saveToDatabase() {
        cout << "The shopping database has been saved in customer cache memory." << endl;
    }

    ~ShoppingCart() {
        for (auto p : products) delete p; // Clean up heap memory
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 150000));
    cart->addProduct(new Product("Mouse", 5000));

    cart->printInvoice();
    cart->saveToDatabase();

    delete cart; // Avoid memory leak
    return 0;
}
