#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sorting
#include <iomanip>   // for formatting output
#include "definition.cpp" // Include the header file with function prototypes and Book struct

using namespace std;

int main() {
    vector<Book> books; // Use vector for dynamic array
    hardcodedBooks(books); // Add hardcoded books to the vector

    int choice;

    do {
        // Display the menu before processing any input
        cout << "\n--------------- Book Management System ---------------\n";
        cout << "1 -> Add Book \n";
        cout << "2 -> Display Books \n";
        cout << "3 -> Update Book \n";
        cout << "4 -> Search Book \n";
        cout << "5 -> Remove Book \n";
        cout << "6 -> Display Sorted Books \n";
        cout << "7 -> Exit... \n";

        cout << "Enter your choice for operations: ";
        cin >> choice;

        switch (choice) {
            case 1: 
            {
                cout << "\n You have selected the option - Add Books. \n";
                Book newBook;
                getBooksDetail(newBook, books);
                books.push_back(newBook); // Add the new book to the vector
                break;
            }

            case 2:
                cout << "\n You have selected the option - Display Books. \n";
                if (books.empty()) 
                {
                    cout << "No books available to display.\n";
                } 
                else 
                {
                    displayBooks(books);
                }
                break;

            case 3:
                cout << "\n You have selected the option - Update Books. \n";
                if (books.empty()) 
                {
                    cout << "No books available to update.\n";
                } 
                else 
                {
                    int searchBy;
                    cout << "Update by:\n1. ID\n2. Name\nEnter your choice: ";
                    cin >> searchBy;
                    updateBookByNameOrID(books, searchBy);
                }
                break;

            case 4:
                cout << "\n You have selected the option - Search Books. \n";
                if (books.empty()) 
                {
                    cout << "No books available to search.\n";
                } 
                else 
                {
                    int searchChoice;
                    cout << "Search by:\n1. ID\n2. Name\n3. Author\n4. Category\nEnter your choice: ";
                    cin >> searchChoice;
                    searchBook(books, searchChoice);
                }
                break;

            case 5:
                cout << "\n You have selected the option - Remove Books. \n";
                if (books.empty()) 
                {
                    cout << "No books available to remove.\n";
                } 
                else
                {
                    int searchBy;
                    cout << "Remove by:\n1. ID\n2. Name\nEnter your choice: ";
                    cin >> searchBy;
                    removeBookByNameOrID(books, searchBy);
                }
                break;

            case 6:
                cout << "\n You have selected the option - Sort the books. \n";
                if (books.empty()) 
                {
                    cout << "No books available to sort.\n";
                } 
                else 
                {
                    int sortBy;
                    cout << "Sort by:\n1. Price\n2. Rating\nEnter your choice: ";
                    cin >> sortBy;
                    displaySortedBooks(books, sortBy);
                }
                break;

            case 7:
                cout << "\n You have selected the option - Exit. \n";
                cout << "Thank you sir... You have done with all !!!\n";
                cout << "Chal ab bahar nikal....\n";
                break;

            default:
                cout << "\n Invalid option selected. Please select a valid option.\n";
                break;
        }

    } while (choice != 7);

    return 0;
}