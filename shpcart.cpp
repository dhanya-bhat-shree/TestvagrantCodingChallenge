#include <iostream>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double unitPrice;
    double gstPercent;
    int quantity;
};

double calGSTAmnt(const Product& product) {
    return (product.unitPrice * product.gstPercent / 100) * product.quantity;
}

int main() {
    
    Product products[] = {
        {"Leather Wallet", 1100, 18, 1},
        {"Umbrella", 900, 12, 4},
        {"Cigarette", 200, 28, 3},
        {"Honey", 100, 0, 2}
    };

    
    double maxGSTAmnt = 0;
    string maxGSTPrdct;

    double totalAmnt = 0;

    for (const auto& product : products) {
        double gstAmount = calGSTAmnt(product);

        
        if (gstAmount > maxGSTAmnt) {
            maxGSTAmnt = gstAmount;
            maxGSTPrdct = product.name;
        }

        
        double discountedPrice = (product.unitPrice >= 500) ? (product.unitPrice * 0.95) : product.unitPrice;

        
        totalAmnt += discountedPrice * product.quantity;
    }

    
    cout << "Product with maximum GST amount: " << maxGSTPrdct << endl;
    cout << "Maximum GST amount: " << fixed << setprecision(2) << maxGSTAmnt << endl;
    cout << "Total amount to be paid to the shopkeeper: " << fixed << setprecision(2) << totalAmnt << endl;

    return 0;
}
