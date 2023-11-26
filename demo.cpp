#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Product {
    string itemId, itemName;
    int itemQuantity, itemPrice;

public:
    void addProduct();
    void viewProducts();
    void buyProducts();
};

// Function to add a new product to the inventory
void Product::addProduct() {
    cout << "Enter Product ID: ";
    cin >> itemId;
    cout << "Enter Product Name: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, itemName);
    cout << "Enter Product Quantity: ";
    cin >> itemQuantity;
    cout << "Enter Product Price: ";
    cin >> itemPrice;

    // Open the file in append mode
    ofstream file("data.txt", ios::app);
    // Write product details to the file
    file << itemId << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
    // Close the file
    file.close();

    cout << "Product added successfully!" << endl;
}

// Function to view available products in the inventory
void Product::viewProducts() {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Inventory is empty." << endl;
        return;
    }

    cout << "Product ID\tProduct Name\tQuantity\tPrice" << endl;
    // Read and display product details from the file
    while (file >> itemId >> itemName >> itemQuantity >> itemPrice) {
        cout << setw(8) << itemId << "\t" << setw(15) << itemName << "\t" << setw(8) << itemQuantity << "\t" << setw(8) << itemPrice << endl;
    }

    file.close();
}

// Function to purchase products from the inventory
void Product::buyProducts() {
    ifstream file("data.txt");
    ofstream file1("temp.txt", ios::app);

    int totalAmount = 0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        string search;
        cout << "Enter Product ID to buy: ";
        cin >> search;

        int quantity;
        cout << "Enter Quantity: ";
        cin >> quantity;

        bool found = false;

        // Read and update product details in the inventory
        while (file >> itemId >> itemName >> itemQuantity >> itemPrice) {
            if (itemId == search) {
                found = true;
                if (itemQuantity >= quantity) {
                    itemQuantity -= quantity;
                    file1 << itemId << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;

                    int itemRate = quantity * itemPrice;
                    totalAmount += itemRate;

                    cout << "------Payment Bill-----" << endl;
                    cout << "Total Purchase Amount: " << totalAmount << endl;
                    cout << "------------------------" << endl;

                    // Add a thank you message after the shopping process
                    cout << "Thank you for shopping with us! We hope to see you again soon." << endl;
                } else {
                    cout << "Not enough stock available for the selected product." << endl;
                }
            } else {
                file1 << itemId << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
            }
        }

        if (!found) {
            cout << "Product not found." << endl;
        }

        file.close();
        file1.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

        cout << "\n Continue? (Y/N): ";
        cin >> choice;
    }
}

int main() {
    Product obj;

    cout << "Welcome to the Product Management System!" << endl;

    char choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Buy Products" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                obj.addProduct();
                break;
            case '2':
                obj.viewProducts();
                break;
            case '3':
                obj.buyProducts();
                break;
            case '0':
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Selection. Please try again." << endl;
        }

    } while (choice != '0');

    return 0;
}
