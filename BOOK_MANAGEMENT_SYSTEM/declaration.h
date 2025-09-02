#ifndef DECLARATION_H
#define DECLARATION_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sorting
#include <iomanip>   // for formatting output
#include <cctype>    // for tolower

using namespace std;

// Book Class
class Book {
public:
    int bookID;
    string name;
    string author;
    string category;
    double price;
    float rating;

    // Constructor to initialize a Book object
    Book(int id = 0, string n = "", string a = "", string c = "", double p = 0.0, float r = 0.0)
    {
        this -> bookID = 0;
        this -> name = n;
        this -> author = a;
        this -> category = c;
        this -> price = p;
        this -> rating = r;
        
    }

    // Function to display book details
    void displayBookDetails() const 
    {
        cout << "Book ID: " << bookID << "\n";
        cout << "Book name: " << name << "\n";
        cout << "Author name: " << author << "\n";
        cout << "Category: " << category << "\n";
        cout << "Price: " << fixed << setprecision(2) << price << "\n";
        cout << "Rating: " << fixed << setprecision(1) << rating << "\n\n";
    }
};

// Hardcoded Books
void hardcodedBooks(vector<Book>& books);

// Function prototypes
void getBooksDetail(Book& book, const vector<Book>& books);
void displayBooks(const vector<Book>& books);
int findBookByID(const vector<Book>& books, int bookID);
void toLowerCase(string& str);
bool substringCaseSensitive(const string& str, const string& substr);
void updateBookByNameOrID(vector<Book>& books, int searchBy);
void searchBook(const vector<Book>& books, int searchChoice);
void removeBookByNameOrID(vector<Book>& books, int searchBy);
void displaySortedBooks(vector<Book>& books, int sortBy);

#endif // DECLARATION_H


