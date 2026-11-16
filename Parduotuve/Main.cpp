#include <iostream>
#include <vector>
#include <iomanip>
#include "Product.h"

void showProducts(const std::vector<Product>& products) {
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "   quantity: " << products[i].quantity << "\n";
    }
}

void AtsarguVerte(const std::vector<Product>& products) {
    float galutine_kaina = 0;
    float produkto_visa_kaina = 0;
    for (size_t i = 0; i < products.size(); i++) {
        produkto_visa_kaina += products[i].price * products[i].quantity;
    }
    galutine_kaina += produkto_visa_kaina;
    std::cout << std::fixed << "Dabartine atsargu verte: " << std::setprecision(2) << galutine_kaina << " EUR" << std::endl;
}

int main() {
    std::vector<Product> products = {
        { "Pienas", 1.20, 30 },
        { "Duona", 0.95, 15 },
        { "Suris", 4.50, 8 }
    };

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== Parduotuve ===\n";
        std::cout << "2. Parodyti Atsargu Verte\n";
        std::cout << "1. Show products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showProducts(products);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        case 2:
            AtsarguVerte(products);
            break;
        default:
            std::cout << "Unknown option.\n";
        }
    }
    return 0;
}