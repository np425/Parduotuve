#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "Cheapest.h"
#include "product.h"
#include "addproduct.h"
#include "sortByQuantity.h"
#include "dicount.h"
#include "changeprice.h"

void showProducts(const std::vector<Product>& products) {
    std::string lowQuantity = "";
    for (size_t i = 0; i < products.size(); i++) {
		if(products[i].quantity != 0 && products[i].quantity < 5) lowQuantity = " MAZAI";
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "quantity: " << (products[i].quantity == 0 ? "IŠPARDUOTA" : std::to_string(products[i].quantity)) << lowQuantity << "\n";
		lowQuantity = "";
    }
}

void showMostExpensiveProduct(const std::vector<Product>& products) {
    if (products.empty()) {
        std::cout << "Prekiu nera\n";
        return;
    }

    Product mostExpensive = products[0];
    for (size_t i = 1; i < products.size(); i++) {
        if (products[i].price > mostExpensive.price) {
            mostExpensive = products[i];
        }
    }

    std::cout << "Brangiausia preke: " << mostExpensive.name
        << " (" << std::fixed << std::setprecision(2) << mostExpensive.price << " EUR)\n";
}

void AtsarguVerte(const std::vector<Product>& products) {
    double galutineKaina = 0;
    for (size_t i = 0; i < products.size(); i++) {
        galutineKaina += products[i].price * products[i].quantity;
    }
    std::cout << std::fixed << "Dabartine atsargu verte: " << std::setprecision(2) << galutineKaina << " EUR" << std::endl;
}

void MazosAtsargos(const std::vector<Product>& products) {
    int kiekis;

    std::cout << "Enter quantity: ";

    cin >> kiekis;

    for (size_t i = 0; i < products.size(); i++) {
        if (kiekis > products[i].quantity) std::cout << products[i].name << " " << products[i].quantity << std::endl;

    }
}
    

void sortProducts(std::vector<Product>& products) {
    for (size_t i = 0; i < products.size() - 1;i++) {
        for (size_t j = i + 1; j < products.size();j++) {
            if (products[i].price > products[j].price) {
                std::swap(products[i], products[j]);
            }
        }
    }
    for (size_t i = 0; i < products.size();i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR\n";
    }
}
int main() {
    std::ofstream outputFile("products.txt");

    std::vector<Product> products =
    {
        { "Pienas", 1.20, 30 },
        { "Duona", 0.95, 4 },
        { "Suris", 4.50, 0 }
    };

    if (outputFile.is_open())
    {
        for (size_t i = 0; i < products.size(); i++)
        {
            outputFile << products[i].name << " " << products[i].price << " " << products[i].quantity << "\n";
        }
        outputFile << "Issaugota prekiu " << products.size() << "\n";
        outputFile.close();
        std::cout << "Duomenys sekmingai issaugoti i products.txt\n";
    }
    else
    {
        std::cout << "Nepavyko atidaryti failo products.txt\n";
    }

    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\n=== Parduotuve ===\n";
        std::cout << "1. Show products\n";
        std::cout << "2. Show most expensive product\n";
        std::cout << "3. Add product\n";
		std::cout << "4. Apply discount\n";
        std::cout << "5. Show stock value\n";
        std::cout << "6. Show cheapest product\n";
        std::cout << "9. Show products with less quantity\n";
        std::cout << "7. Show sorted products\n";
        std::cout << "8. Change product price\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showProducts(products);
            break;
        case 4:
			 pritaikytiNuolaida(products);
			 break;
        case 5:
            AtsarguVerte(products);
            break;
        case 2:
            showMostExpensiveProduct(products);
            break;
        case 6:
            showCheapestProduct(products);
            break;
        case 3:
            AddProduct(products);
            break;
        case 7:
            sortProducts(products);
            break;
          case 8:
            changePrice(products);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        case 9:
            MazosAtsargos(products);
            break;
        default:
            std::cout << "Unknown option.\n";
        }
    }
    return 0;
}