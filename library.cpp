#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class LibraryItem
{
public:
    int id;
    string title;
    string author;
    bool issued;

    LibraryItem()
    {
        issued = false;
    }
};

class Book : public LibraryItem
{
};

vector<Book> books;

// Save books to file
void saveToFile()
{
    ofstream file("books.txt");

    for (Book b : books)
    {
        file << b.id << endl;
        file << b.title << endl;
        file << b.author << endl;
        file << b.issued << endl;
    }

    file.close();
}

// Load books from file
void loadFromFile()
{
    ifstream file("books.txt");

    Book b;

    while (file >> b.id)
    {
        file.ignore();
        getline(file, b.title);
        getline(file, b.author);
        file >> b.issued;
        file.ignore();

        books.push_back(b);
    }

    file.close();
}

// Add book
void addBook()
{
    Book b;

    cout << "\nEnter Book ID: ";
    cin >> b.id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    b.issued = false;

    books.push_back(b);

    saveToFile();

    cout << "\nBook Added Successfully!\n";
}

// Display books
void displayBooks()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n----- Book List -----\n";

    for (Book b : books)
    {
        cout << "\nID: " << b.id;
        cout << "\nTitle: " << b.title;
        cout << "\nAuthor: " << b.author;
        cout << "\nStatus: ";

        if (b.issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << "\n--------------------\n";
    }
}

// Search book
void searchBook()
{
    int id;

    cout << "\nEnter Book ID: ";
    cin >> id;

    for (Book b : books)
    {
        if (b.id == id)
        {
            cout << "\nBook Found!\n";
            cout << "Title: " << b.title << endl;
            cout << "Author: " << b.author << endl;
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Issue book
void issueBook()
{
    int id;

    cout << "\nEnter Book ID: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            if (books[i].issued)
            {
                cout << "\nBook Already Issued!\n";
            }
            else
            {
                books[i].issued = true;
                saveToFile();
                cout << "\nBook Issued Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Return book
void returnBook()
{
    int id;

    cout << "\nEnter Book ID: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            books[i].issued = false;
            saveToFile();

            cout << "\nBook Returned Successfully!\n";
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

int main()
{
    loadFromFile();

    int choice;

    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}