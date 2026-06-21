#include <iostream>// input and output 
#include <fstream> // file handling
#include <string> // for string
#include <windows.h>// for delay

using namespace std;

const int MAX_ITEMS = 100; // max item that the file can save

struct Item { // related variables of different data types
    int id;
    string name;
    int quantity;
    double price;
};

Item inventory[MAX_ITEMS]; 
int itemCount = 0;

//prototype function
void loadInventory();
void saveInventory();
void addItem();
void editItem();
void viewItems();
void deleteItem();

int main() { // main function
    loadInventory();
   // int choice;
    
    	cout<<"\n-------Mang Roman's Stock-----\n     Inventory Management System\n";
        cout << "\n[1] Add Item\n[2] Edit Item\n[3] Delete Item\n[4] View Items\n[5] Exit\n";
        //cout << "\nEnter your choice: ";
 
        while(true){
        	if (GetAsyncKeyState(0x31)) {
        		addItem();
            break;
        	}
			if (GetAsyncKeyState(0x32)) {
        		editItem(); 
            break;
        	}
        	if (GetAsyncKeyState(0x33)) {
        		deleteItem();
            break;
        	}
        	if (GetAsyncKeyState(0x34)) {
        		viewItems();
            break;
        	}
        	if (GetAsyncKeyState(0x35)) {
        		cout << "Exiting...\n";
            break;
        	}
		}
}

void saveInventory() {
    ofstream file("inventory.txt"); // save the data here in text file
    if (file.is_open()) {
        for (int i = 0; i < itemCount; ++i) {
            file << inventory[i].id << " " << inventory[i].name << " " 
                 << inventory[i].quantity << " " << inventory[i].price << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file for writing.\n";
    }
}

void loadInventory() {
    ifstream file("inventory.txt");
    if (file.is_open()) {
        itemCount = 0;
        while (file >> inventory[itemCount].id >> inventory[itemCount].name 
                    >> inventory[itemCount].quantity >> inventory[itemCount].price) {
            ++itemCount;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }
}

void addItem() {
	system("cls");
	int it;
    cout << "\n\n------ADD ITEM------[+]\n\n";
    
    cout<<"How many Items do you want to save? :";
    cin>>it;
    if (itemCount >= MAX_ITEMS) {
        cout << "Inventory is full!\n";
        return;
    }
    for(int i = 1 ; i<=it ; i++){
    system("cls");
    cout << "\n\n------ADD ITEM------[+]\n\n";
    Item newItem;
    cout << "Entry no. :"<<i;
    cout << "\n\nEnter item ID: ";
    cin >> newItem.id;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, newItem.name);
    cout << "Enter item quantity: ";
    cin >> newItem.quantity;
    cout << "Enter item price: ";
    cin >> newItem.price;
    inventory[itemCount++] = newItem;
	}
	char sel;
    cout << "\n\n[S] Save\n[B] Back\n\nEnter your choice: ";
    cin>>sel;
	if(sel=='s' || sel=='S'){
    saveInventory();
    cout << "Item added successfully!\n";
    Sleep(1000);
	system("cls");
	}
	else{
	system("cls");
	}
}

void editItem() {
	system("cls");
    int id,sel;
    e:
    cout << "\n\n------EDIT ITEM------[/]\n\n";

    cout<<"--------------------------------------------------\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name 
                  << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << "\n";
   
	}
    cout<<"--------------------------------------------------\n";
    cout << "\n\nEnter item ID to edit: ";
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
            
            cout << "\n\n[1] Save\n[2] Back\n\nEnter your choice: ";
		    cin>>sel;
			if(sel==1){
		    saveInventory();
		    cout << "Item updated successfully!\n";
		    Sleep(1000);
			system("cls");
			goto e;
			}
			else{
			system("cls");
			}
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found!\n";                                                                                                                                                                                //Roman Juan G. Eugeni I
    	Sleep(1000);
		system("cls");
		goto e;
    }
}

void deleteItem() {
	system("cls");
    int id;
    string sel;
    d:
    cout << "\n\n------DELETE ITEM------[-]\n\n";
    cout<<"--------------------------------------------------\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name 
                  << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << "\n";
	}
	
    cout<<"--------------------------------------------------\n";

    
    cout<<"\n[Delete] [Back] :";
        while (true) {
        if (GetAsyncKeyState(VK_DELETE)) {
            cout << "\n\nEnter item ID to delete: ";
		    cin >> id;
			bool found = false;
		    for (int i = 0; i < itemCount; ++i) {
		        if (inventory[i].id == id) {
		            for (int j = i; j < itemCount - 1; ++j) {
		                inventory[j] = inventory[j + 1];
		            }
		            --itemCount;
		            saveInventory();
		            system("cls");
		            cout << "Item deleted successfully!\n";
		            found = true;
		            
		            goto d;
		            break;
        }
    }
    if (!found) {
        cout << "Item not found!\n";
    	Sleep(1000);
		system("cls");
		goto d;
    }
    }
		if (GetAsyncKeyState(VK_BACK)) {
		cout<<"\nBack to main";
		Sleep(1000);
		system("cls");
            break;
        }
    	}

}

void viewItems() {
	system("cls");
	int sel;
	
    cout << "\n\n------INVENTORY------[=]\n\n";
    cout<<"--------------------------------------------------\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name 
                  << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << "\n";
    }
    cout<<"--------------------------------------------------\n";
    cout<<"\n[1] Back: ";
    cin>>sel;
    system("cls");
}



