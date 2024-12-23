/* Develop a Warehouse Inventory Management System using C++ to simulate how industries manage and track their inventory. 
The program should enable users to add new items to the inventory, update stock levels, track inventory movement, and generate reports. 
Each item in the inventory should be represented as an object with attributes like a unique item ID, name, category, quantity, and reorder level.
The system should include functionality to alert the user when stock levels fall below the reorder threshold. A menu-driven interface should allow 
users to perform operations such as viewing inventory, searching for items by name or category, and exporting inventory data to a file for record-keeping.
This assignment is designed to mirror real-world inventory management systems used in industries like retail, manufacturing, and logistics,
providing hands-on experience with object-oriented design, file handling, and user interaction in C++.


Input:

1.Add item details like item ID, name, category, quantity, and reorder level.
2.Update stock levels for existing items.
3.Search for items by name or category.


Output:
1.Display the current inventory with all item details.
2.Alert the user when an item's stock is below its reorder level.
3.Export inventory data to a file for record-keeping.


*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Item {
public:
    int id, quantity, reorderLevel;
    string name, category;
    Item(int id, string name, string category, int quantity, int reorderLevel)
        : id(id), name(name), category(category), quantity(quantity), reorderLevel(reorderLevel) {}
    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Category: " << category
             << " | Quantity: " << quantity << " | Reorder Level: " << reorderLevel;
        if (quantity < reorderLevel) cout << " | *Reorder Alert!*";
        cout << endl;
    }
};

class Inventory {
    vector<Item> items;
    int nextID = 1;
public:
    void addItem(string name, string category, int quantity, int reorderLevel) {
        items.emplace_back(nextID++, name, category, quantity, reorderLevel);
    }
    void updateStock(int id, int qty, bool add) {
        for (auto &item : items) {
            if (item.id == id) {
                item.quantity += (add ? qty : -qty);
                return;
            }
        }
        cout << "Item not found!\n";
    }
    void displayItems() {
        if (items.empty()) cout << "Inventory is empty!\n";
        else for (auto &item : items) item.display();
    }
    void searchItems(string key, bool byCategory) {
        for (auto &item : items)
            if ((byCategory && item.category == key) || (!byCategory && item.name == key))
                item.display();
    }
    void exportToFile(string filename) {
        ofstream file(filename);
        for (auto &item : items)
            file << item.id << "," << item.name << "," << item.category
                 << "," << item.quantity << "," << item.reorderLevel << "\n";
        file.close();
    }
};

int main() {
    Inventory inv;
    int choice;
    do {
        cout << "\n1. Add Item\n2. Update Stock\n3. View Items\n4. Search by Name\n5. Search by Category\n6. Export to File\n7. Exit\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            string name, category; int qty, reorder;
            cout << "Name: "; cin >> name;
            cout << "Category: "; cin >> category;
            cout << "Quantity: "; cin >> qty;
            cout << "Reorder Level: "; cin >> reorder;
            inv.addItem(name, category, qty, reorder);
        } else if (choice == 2) {
            int id, qty; char op;
            cout << "ID: "; cin >> id;
            cout << "Quantity: "; cin >> qty;
            cout << "Add (a) or Remove (r): "; cin >> op;
            inv.updateStock(id, qty, op == 'a');
        } else if (choice == 3) {
            inv.displayItems();
        } else if (choice == 4) {
            string name; cout << "Name: "; cin >> name;
            inv.searchItems(name, false);
        } else if (choice == 5) {
            string category; cout << "Category: "; cin >> category;
            inv.searchItems(category, true);
        } else if (choice == 6) {
            string file; cout << "Filename: "; cin >> file;
            inv.exportToFile(file);
        }
    } while (choice != 7);
    return 0;
}
