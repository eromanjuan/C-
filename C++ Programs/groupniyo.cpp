#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author, bool isIssued = false)
        : id(id), title(title), author(author), isIssued(isIssued) {}

    string toString() const {
        return to_string(id) + ";" + title + ";" + author + ";" + (isIssued ? "1" : "0") + "\n";
    }
    
    static Book fromString(const string& line) {
        stringstream ss(line);
        string idStr, title, author, issuedStr;
        getline(ss, idStr, ';');
        getline(ss, title, ';');
        getline(ss, author, ';');
        getline(ss, issuedStr, ';');
        return Book(stoi(idStr), title, author, issuedStr == "1");
    }
};

class Member {
public:
    int id;
    string name;

    Member(int id, string name) : id(id), name(name) {}

    string toString() const {
        return to_string(id) + ";" + name + "\n";
    }

    static Member fromString(const string& line) {
        stringstream ss(line);
        string idStr, name;
        getline(ss, idStr, ';');
        getline(ss, name, ';');
        return Member(stoi(idStr), name);
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void loadData() {
        ifstream bookFile("books.txt");
        ifstream memberFile("members.txt");

        string line;
        
        while (getline(bookFile, line)) {
            books.push_back(Book::fromString(line));
        }
        
        while (getline(memberFile, line)) {
            members.push_back(Member::fromString(line));
        }

        bookFile.close();
        memberFile.close();
    }

    void saveData() {
        ofstream bookFile("books.txt");
        ofstream memberFile("members.txt");

        for (const auto& book : books) {
            bookFile << book.toString();
        }
        
        for (const auto& member : members) {
            memberFile << member.toString();
        }

        bookFile.close();
        memberFile.close();
    }

    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }

    void addMember() {
        int id;
        string name;
        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Member Name: ";
        getline(cin, name);
        members.push_back(Member(id, name));
        cout << "Member added successfully.\n";
    }

    void issueBook() {
        int bookId, memberId;
        cout << "Enter Book ID to issue: ";
        cin >> bookId;
        cout << "Enter Member ID to issue to: ";
        cin >> memberId;

        for (auto& book : books) {
            if (book.id == bookId) {
                if (book.isIssued) {
                    cout << "Book is already issued.\n";
                    return;
                }
                book.isIssued = true;
                cout << "Book issued to member ID " << memberId << " successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int bookId;
        cout << "Enter Book ID to return: ";
        cin >> bookId;

        for (auto& book : books) {
            if (book.id == bookId) {
                if (!book.isIssued) {
                    cout << "Book is already available in the library.\n";
                    return;
                }
                book.isIssued = false;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void displayBooks() const {
        cout << "\nBooks in the Library:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Status: " << (book.isIssued ? "Issued" : "Available") << endl;
        }
    }

    void displayMembers() const {
        cout << "\nLibrary Members:\n";
        for (const auto& member : members) {
            cout << "Member ID: " << member.id << ", Name: " << member.name << endl;
        }
    }
};

int main() {
    Library library;
    library.loadData();

    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Display All Members\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addMember();
                break;
            case 3:
                library.issueBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 5:
                library.displayBooks();
                break;
            case 6:
                library.displayMembers();
                break;
            case 0:
                library.saveData();
                cout << "Data saved. Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
