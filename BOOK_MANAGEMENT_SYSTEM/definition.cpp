#include "declaration.h"

// Hardcoded Books:
void hardcodedBooks(vector<Book>& books) 
{
    books.push_back({1, "The Pragmatic Programmer", "Andrew Hunt", "Programming", 15.99, 4.8});
    books.push_back({2, "Pride and Prejudice", "Jane Austen", "Romance", 9.99, 4.8});
    books.push_back({3, "The Hobbit", "J.R.R. Tolkien", "Fantasy", 14.99, 4.9});
    books.push_back({4, "Clean Code", "Robert C. Martin", "Programming", 21.99, 4.7});
    books.push_back({5, "To Kill a Mockingbird", "Harper Lee", "Classic", 10.99, 4.9});
    books.push_back({6, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", 12.99, 4.8});
    books.push_back({7, "Introduction to Algorithms", "Thomas H. Cormen", "Programming", 35.99, 4.9});
    books.push_back({8, "1984", "George Orwell", "Classic", 12.99, 4.8});
    books.push_back({9, "Embedded Systems", "Michael J. Pont", "Electronics", 22.99, 4.5});
    books.push_back({10, "Eloquent JavaScript", "Dennis Rit", "Programming", 16.99, 4.5});
    books.push_back({11, "The Fault in Our Stars", "John Green", "Romance", 12.99, 4.8});
    books.push_back({12, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 18.99, 4.9});
    books.push_back({13, "You Dont Know JS", "Kyle Simpson", "Programming", 19.99, 4.6});
    books.push_back({14, "The Great Gatsby", "F. Scott Fitzgerald", "Classic", 11.99, 4.7});
    books.push_back({15, "Electronics for Dummies", "Cathleen Sham", "Electronics", 17.99, 4.3});
}

// Function to find a book by its ID
int findBookByID(const vector<Book>& books, int bookID) 
{
    for (int i = 0; i < books.size(); i++) 
    {
        if (books[i].bookID == bookID) 
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to get book details
void getBooksDetail(Book& book, const vector<Book>& books) 
{
    while (true) 
    {
        cout << "Enter the book ID: ";
        cin >> book.bookID;
        cin.ignore(); // Clear the buffer

        if (findBookByID(books, book.bookID) != -1) 
        {
            cout << "Book ID " << book.bookID << " already exists. Please enter a unique ID.\n";
        } 
        else 
        {
            break; // Unique ID, exit the loop
        }
    }

    cout << "Enter the book name: ";
    getline(cin, book.name);
    cout << "Enter the author name: ";
    getline(cin, book.author);
    cout << "Enter the book category: ";
    getline(cin, book.category);

    while (true) 
    {
        cout << "Enter the price: ";
        if (cin >> book.price) 
        {
            if (book.price >= 0) break;
            else cout << "Price cannot be negative. Please enter a valid price.\n";
        } 
        else 
        {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Invalid input. Please enter a valid number for the price.\n";
        }
    }

    while (true) 
    {
        cout << "Enter the rating (0 to 5): ";
        if (cin >> book.rating) 
        {
            if (book.rating >= 0.0 && book.rating <= 5.0) break;
            else cout << "Please enter a valid rating between 0 and 5.\n";
        } 
        else 
        {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Invalid input. Please enter a valid number for the rating.\n";
        }
    }
}

// Function to display details of a book
void displayBookDetails(const Book& book) 
{
    cout << "Book ID: " << book.bookID << "\n";
    cout << "Book name: " << book.name << "\n";
    cout << "Author name: " << book.author << "\n";
    cout << "Category: " << book.category << "\n";
    cout << "Price: " << fixed << setprecision(2) << book.price << "\n";
    cout << "Rating: " << fixed << setprecision(1) << book.rating << "\n\n";
}

// Function to display details of multiple books
void displayBooks(const vector<Book>& books) 
{
    cout << "\n--------------- Book Details ---------------\n";

    if (books.empty()) {
        cout << "No books available.\n";
        cout << "You can add by using the menu options below.\n";
        return;
    }

    for (const auto& book : books) {
        displayBookDetails(book);
    }
}

// Function to convert a string to lowercase
void toLowerCase(string& str) 
{
    for (char& c : str) 
    {
        c = tolower(c);
    }
}

// Function to check if a substring exists in a string in a case-insensitive way
bool substringCaseSensitive(const string& str, const string& substr) 
{
    string lowerStr = str;
    string lowerSubstr = substr;
    toLowerCase(lowerStr);
    toLowerCase(lowerSubstr);
    return lowerStr.find(lowerSubstr) != string::npos;
}

// Function to update a book's details by ID or name
void updateBookByNameOrID(vector<Book>& books, int searchBy) 
{
    cout << "\n--------------- Update Book by Name or ID ---------------\n";

    if (books.empty()) 
    {
        cout << "No books available to update.\n";
        return;
    }

    if (searchBy == 1) 
    {
        int bookID;
        cout << "Enter the book ID to update: ";
        cin >> bookID;

        int index = findBookByID(books, bookID);
        if (index == -1) 
        {
            cout << "No book found with the ID: " << bookID << "\n";
            return;
        }

        cout << "Book found. Now update it ....\n";
        cout << "Want to update the price?\n1. If yes (1)\n2. If No (2)\n";
        cout << "Enter the choice: ";
        int priceChoice;
        cin >> priceChoice;
        if (priceChoice == 1) 
        {
            cout << "Enter updated Price: ";
            cin >> books[index].price;
        }

        cout << "Want to update the rating?\n1. If yes (1)\n2. If No (2)\n";
        cout << "Enter the choice: ";
        int ratingChoice;
        cin >> ratingChoice;
        if (ratingChoice == 1) 
        {
            cout << "Enter updated rating: ";
            cin >> books[index].rating;
        }

        cout << "Book updated Successfully!!!\n";
    } 
    else if (searchBy == 2) 
    {
        string bookName;
        cout << "Enter the book name to update: ";
        cin.ignore();
        getline(cin, bookName);

        bool found = false;
        for (auto& book : books) 
        {
            if (substringCaseSensitive(book.name, bookName)) 
            {
                found = true;
                cout << "Book found. Now update it ....\n";

                cout << "Want to update the price?\n1. Yes \n2. No\n";
                cout << "Enter the choice: ";
                int priceChoice;
                cin >> priceChoice;
                if (priceChoice == 1) 
                {
                    cout << "Enter updated Price: ";
                    cin >> book.price;
                }

                cout << "Want to update the rating?\n1. Yes \n2. No\n";
                cout << "Enter the choice: ";
                int ratingChoice;
                cin >> ratingChoice;
                if (ratingChoice == 1) 
                {
                    cout << "Enter updated rating: ";
                    cin >> book.rating;
                }

                cout << "Book updated Successfully!!!\n";
                break;
            }
        }

        if (!found) 
        {
            cout << "No book found with the name: " << bookName << "\n";
        }
    } 
    else 
    {
        cout << "Invalid choice for updating.\n";
    }
}

// Function to search a book by ID, name, author, or category
void searchBook(const vector<Book>& books, int searchChoice) 
{
    if (books.empty()) 
    {
        cout << "No books available to search.\n";
        return;
    }

    switch (searchChoice) 
    {
        case 1: 
        { // Search by ID
            int searchID;
            cout << "Enter Book ID to search: ";
            cin >> searchID;

            int index = findBookByID(books, searchID);
            if (index != -1) 
            {
                cout << "\nBook found:\n";
                displayBookDetails(books[index]);
            } 
            else 
            {
                cout << "Book with ID " << searchID << " not found.\n";
            }
            break;
        }

        case 2: 
        { // Search by Name
            string searchName;
            cout << "Enter a substring to search in Book Names: ";
            cin.ignore();
            getline(cin, searchName);

            bool found = false;
            for (const auto& book : books) 
            {
                if (substringCaseSensitive(book.name, searchName)) 
                {
                    displayBookDetails(book);
                    found = true;
                }
            }

            if (!found) 
            {
                cout << "No books found matching \"" << searchName << "\".\n";
            }
            break;
        }

        case 3: 
        { // Search by Author
            string searchAuthor;
            cout << "Enter a substring to search in Author Names: ";
            cin.ignore();
            getline(cin, searchAuthor);

            bool found = false;
            for (const auto& book : books)
            {
                if (substringCaseSensitive(book.author, searchAuthor)) 
                {
                    displayBookDetails(book);
                    found = true;
                }
            }

            if (!found) 
            {
                cout << "No books found matching \"" << searchAuthor << "\".\n";
            }
            break;
        }

        case 4: 
        { // Search by Category
            string searchCategory;
            cout << "Enter a substring category to search: ";
            cin.ignore();
            getline(cin, searchCategory);

            bool found = false;
            for (const auto& book : books) 
            {
                if (substringCaseSensitive(book.category, searchCategory)) 
                {
                    displayBookDetails(book);
                    found = true;
                }
            }

            if (!found) 
            {
                cout << "No books found matching \"" << searchCategory << "\".\n";
            }
            break;
        }

        default:
            cout << "Invalid search option.\n";
            break;
    }
}

// Function to remove a book by ID or name
void removeBookByNameOrID(vector<Book>& books, int searchBy) {
    cout << "\n--------------- Remove Book by Name or ID ---------------\n";

    if (books.empty()) 
    {
        cout << "No books available to remove.\n";
        return;
    }

    if (searchBy == 1) 
    {
        int bookID;
        cout << "Enter the book ID to remove: ";
        cin >> bookID;

        int index = findBookByID(books, bookID);
        if (index == -1) 
        {
            cout << "No book found with the ID: " << bookID << "\n";
            return;
        }

        books.erase(books.begin() + index); // Remove the book
        cout << "Book with ID '" << bookID << "' removed successfully!\n";
    } 
    else if (searchBy == 2) 
    {
        string bookName;
        cout << "Enter the book name to remove: ";
        cin.ignore();
        getline(cin, bookName);

        bool found = false;
        for (auto it = books.begin(); it != books.end(); ++it) 
        {
            if (substringCaseSensitive(it->name, bookName)) 
            {
                books.erase(it); // Remove the book
                found = true;
                cout << "Book '" << bookName << "' removed successfully!\n";
                break;
            }
        }

        if (!found) 
        {
            cout << "No book found with the name: " << bookName << "\n";
        }
    } 
    else 
    {
        cout << "Invalid choice for removal.\n";
    }
}

// Function to display sorted books by price or rating
void displaySortedBooks(vector<Book>& books, int sortBy) 
{
    cout << "\n--------------- Display sorted books ---------------\n";

    if (books.empty()) 
    {
        cout << "No books available.\n";
        return;
    }

    int pattern;
    cout << "Choose the pattern:\n1. Ascending\n2. Descending\nEnter your choice: ";
    cin >> pattern;

    if (pattern != 1 && pattern != 2) 
    {
        cout << "Invalid choice.....\n";
        return;
    }

    // Sort by price or rating
    if (sortBy == 1) 
    { // Sort by price
        if (pattern == 1) 
        {
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
            {
                return a.price < b.price;
            });
        } 
        else 
        {
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
            {
                return a.price > b.price;
            });
        }
    } 
    else if (sortBy == 2) 
    { // Sort by rating
        if (pattern == 1) 
        {
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
            {
                return a.rating < b.rating;
            });
        } 
        else 
        {
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
            {
                return a.rating > b.rating;
            });
        }
    }

    displayBooks(books);
}