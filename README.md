# Book Management System

A comprehensive console-based book management application built in C++ that allows users to efficiently manage a collection of books with various operations like adding, updating, searching, removing, and sorting.

## Features

### Core Functionalities
- **Add Books**: Add new books with unique IDs, names, authors, categories, prices, and ratings
- **Display Books**: View all books in the collection with formatted details
- **Update Books**: Modify book information (price and rating) by ID or name
- **Search Books**: Find books using multiple criteria:
  - Book ID
  - Book Name (substring search)
  - Author Name (substring search)
  - Category (substring search)
- **Remove Books**: Delete books from the collection by ID or name
- **Sort Books**: Display books sorted by:
  - Price (ascending/descending)
  - Rating (ascending/descending)

### Additional Features
- **Pre-loaded Data**: Comes with 15 hardcoded books across multiple categories
- **Input Validation**: Ensures data integrity with validation for IDs, prices, and ratings
- **Case-Insensitive Search**: Flexible searching that ignores case sensitivity
- **Duplicate Prevention**: Prevents duplicate book IDs
- **Dynamic Memory Management**: Uses C++ vectors for efficient memory handling

## Project Structure

```
Book-Management-System/
├── main.cpp           # Main program with menu and user interface
├── declaration.h      # Header file with class and function declarations
├── definition.cpp     # Implementation of all functions
└── README.md         # Project documentation
```

## Pre-loaded Books

The system comes with 15 pre-loaded books covering various categories:

| Category | Examples |
|----------|----------|
| Programming | The Pragmatic Programmer, Clean Code, Introduction to Algorithms |
| Romance | Pride and Prejudice, The Fault in Our Stars |
| Fantasy | The Hobbit, Harry Potter, The Lord of the Rings |
| Classic | To Kill a Mockingbird, 1984, The Great Gatsby |
| Electronics | Embedded Systems, Electronics for Dummies |

## Requirements

- **Compiler**: C++11 or higher
- **Operating System**: Windows, Linux, or macOS
- **Standard Libraries Used**:
  - `<iostream>` - Input/output operations
  - `<vector>` - Dynamic array management
  - `<string>` - String handling
  - `<algorithm>` - Sorting operations
  - `<iomanip>` - Output formatting
  - `<cctype>` - Character operations

## Installation & Compilation

### Using g++ (Linux/macOS)
```bash
# Compile the project
g++ -std=c++11 main.cpp -o book_management

# Run the program
./book_management
```

### Using g++ (Windows)
```bash
# Compile the project
g++ -std=c++11 main.cpp -o book_management.exe

# Run the program
book_management.exe
```

### Using Visual Studio (Windows)
1. Create a new C++ Console Application project
2. Add all `.cpp` and `.h` files to the project
3. Build and run the project (F5)

## Usage Guide

### Menu Options

When you run the program, you'll see the following menu:

```
--------------- Book Management System ---------------
1 -> Add Book
2 -> Display Books
3 -> Update Book
4 -> Search Book
5 -> Remove Book
6 -> Display Sorted Books
7 -> Exit...
```

### Example Workflow

1. **Adding a Book**
   - Enter book ID (must be unique)
   - Enter book name, author, category
   - Enter price (non-negative)
   - Enter rating (0-5)

2. **Searching for a Book**
   - Choose search criteria (ID, Name, Author, or Category)
   - Enter search term
   - View matching results

3. **Updating a Book**
   - Choose to search by ID or Name
   - Select whether to update price, rating, or both
   - Enter new values

4. **Sorting Books**
   - Choose sort criteria (Price or Rating)
   - Choose order (Ascending or Descending)
   - View sorted list

## Code Highlights

### Book Class
```cpp
class Book {
public:
    int bookID;
    string name;
    string author;
    string category;
    double price;
    float rating;
};
```

### Key Functions
- `getBooksDetail()` - Collects and validates book information
- `findBookByID()` - Locates books by their unique ID
- `substringCaseSensitive()` - Enables flexible searching
- `displaySortedBooks()` - Sorts and displays books by criteria
- `updateBookByNameOrID()` - Modifies existing book details
- `removeBookByNameOrID()` - Removes books from the collection

## Input Validation

The system includes robust input validation:
- **Book ID**: Must be unique
- **Price**: Must be non-negative number
- **Rating**: Must be between 0.0 and 5.0
- **Invalid input handling**: Clears error flags and prompts for re-entry

## Future Enhancements

Potential improvements for the project:
- [ ] File I/O for persistent storage (save/load from file)
- [ ] Advanced search with multiple filters
- [ ] Book availability tracking (in-stock/out-of-stock)
- [ ] User authentication system
- [ ] Book borrowing/return functionality
- [ ] ISBN support
- [ ] Genre-based recommendations
- [ ] Database integration (SQLite/MySQL)

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

## License

This project is open source and available for educational purposes.

## Author

Developed as a C++ learning project demonstrating:
- Object-Oriented Programming concepts
- Dynamic memory management with vectors
- Menu-driven console applications
- Input validation and error handling
- Algorithm implementation (searching and sorting)

## Acknowledgments

- Built using standard C++ libraries
- Designed for educational purposes and portfolio demonstration

---

**Note**: This is a console-based application. For best experience, run in a terminal with adequate width for formatted output display.
