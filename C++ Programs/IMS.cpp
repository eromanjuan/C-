#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        cout << "Inventory is full!\n";
        return;
    }
    Item newItem;
    cout << "Enter item ID: ";
    cin >> newItem.id;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, newItem.name);
    cout << "Enter item quantity: ";
    cin >> newItem.quantity;
    cout << "Enter item price: ";
    cin >> newItem.price;
    inventory[itemCount++] = newItem;
    cout << "Item added successfully!\n";
}

void editItem() {
    int id;
    cout << "Enter item ID to edit: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (inventory[i].id == id) {
            cout << "Enter new item name: ";
            cin.ignore();
            getline(cin, inventory[i].name);
            cout << "Enter new item quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new item price: ";
            cin >> inventory[i].price;
            cout << "Item updated successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found!\n";
    }
}

void deleteItem() {
    int id;
    cout << "Enter item ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (inventory[i].id == id) {
            for (int j = i; j < itemCount - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            --itemCount;
            cout << "Item deleted successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found!\n";
    }
}

void viewItems() {
    cout << "Inventory:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name 
                  << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << "\n";
    }
}

int main() {
    int choice;
    do {
		cout << "\n------------MANG ROMAN SARI SARI'S STORE------------\n\t    INVENTORY MANAGEMENT SYSTEM\n";
        cout << "1. Add Item\n2. Edit Item\n3. Delete Item\n4. View Items\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
    	system("cls");
        switch (choice) {
            case 1: addItem(); break;
            case 2: editItem(); break;
            case 3: deleteItem(); break;
            case 4: viewItems(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}

