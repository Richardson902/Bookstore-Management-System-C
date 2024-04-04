# Book Management System

## Overview

This project implements a simple Book Management System in C. It allows users to perform various operations such as adding a book, deleting a book, searching for a book, listing all books, and saving books data to a file.

## Features

- **Add Book**: Users can add new books to the system by providing details such as title, author, ISBN, and publication year.
- **Delete Book**: Users can delete a book from the system by providing its ISBN.
- **Search Book**: Users can search for a book by its ISBN and view its details.
- **List All Books**: Users can view a list of all books stored in the system.
- **Save Books**: Users can save the current state of the book library to a file.
- **Load Books**: Upon starting the program, it loads existing book data from a file.

## How to Compile and Run

To compile the program, use the following command:
```bash
gcc main.c book.c -o book_management_system
```

To run the program, execute the compiled binary:
```bash
book_management_system
```

## Usage

1. Upon running the program, you'll be presented with a menu displaying various options.
2. Choose an option by entering the corresponding number.
3. Follow the prompts to perform the selected operation.
4. To exit the program, choose the "Exit" option.
