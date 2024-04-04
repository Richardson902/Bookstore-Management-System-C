#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Dynamic array for storing books
Book *books; //Array to hold Book objects
size_t bookSize; //Size of the array

//Function to grab user input and clear buffer to fix error handling issues
void userInput(char *clearBuffer, size_t length) {
    fgets(clearBuffer, length, stdin);
    clearBuffer[strcspn(clearBuffer, "\n")] = 0;
}

//Operation to add a book
void addBook(){
    //Allocate memory for new book
    bookSize += 1;
    books = realloc(books, sizeof(Book) * bookSize);

    Book book; //Temp book object to hold user input
    char title[256]; //Array to hold book title
    char author[100]; //Array to hold book author
    char year [50]; //Array to hold book year
    char isbn[50]; //Array to hold book ISBN

    //Get book details from user
    printf("Enter book title: ");
    userInput(title, 256);

    //Check for validity of title input
    if (strlen(title) == 0) {
        printf("Must include title.\n");
        return;
    }
    else if (strlen(title) > 256) {
        printf("Title too long\n");
        return;
    }
    else {
        strcpy(book.title, title); //Copy title to book object
    }

    printf("Enter book author: ");
    userInput(author, 100);

    //Check for validity of author input
    if(strlen(author) == 0){
        printf("Must include author.\n");
        return;
    }
    else if (strlen(author) > 100) {
        printf("Author name too long.\n");
        return;
    }
    else {
        strcpy(book.author, author); //Copy author to book object
    }

    printf("Enter book ISBN: ");
    userInput(isbn, 50);

    //Check for validity of ISBN input
    if (strlen(isbn) == 0) {
        printf("Must include ISBN.\n");
        return;
    }
    
    else if (strlen(isbn) != 13) {
        printf("ISBN must be 13 characters long.\n");
        return;
    }
    else {
        strcpy(book.isbn, isbn); //Copy ISBN to book object
    }

    
    printf("Enter book year: ");
    userInput(year, 50);

    //Check for validity of year input
    if(strlen(year) == 0){
        printf("Must include year.\n");
        return;
    }
    else if (strlen(year) != 4) {
        printf("Year must be 4 digits.\n");
        return;
    }
    else {
        book.year = strtol(year, (char **)NULL, 10); //Convert year to integer and copy to book object
    }

    size_t i = bookSize -1;
    books[i] = book; //Add book object to array
}

//Operation to delete a book
void deleteBook(){
    //Get book ISBN from user
    char isbn[50];
    printf("Enter ISBN: ");
    fgets(isbn, 50, stdin);
    isbn[strcspn(isbn, "\n")] = 0; //Remove newline character

    //Search for book in the array
    int index = -1;
    for (int i = 0; i < bookSize; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            index = i;
            break;
        }
    }

    //Delete book if found
    if (index != -1) {
        for (int i = index; i < bookSize - 1; i++) {
            books[i] = books[i + 1];
        }
        bookSize -= 1;
        books = realloc(books, sizeof(Book) * bookSize);
        printf("Book deleted\n");
    } else {
        printf("Book not found\n");
    }
}

//Operation to search for a book
void searchBook(){
    //Get book ISBN from user
    char isbn[50];
    printf("Enter ISBN: ");
    fgets(isbn, 50, stdin);
    isbn[strcspn(isbn, "\n")] = 0; //Remove newline character

    //Search for book in the array
    int index = -1;
    for (int i = 0; i < bookSize; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            index = i;
            break;
        }
    }

    //Display book details if found
    if (index != -1) {
        printf("Book details:\n");
        printf("Title: %s\n", books[index].title);
        printf("Author: %s\n", books[index].author);
        printf("ISBN: %s\n", books[index].isbn);
        printf("Year: %d\n", books[index].year);
    } else {
        printf("Book not found\n");
    }
}

//Operation to list all books
int listBooks(){
    //Display all books in the array
    for (int i = 0; i < bookSize; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %s\n", books[i].isbn);
        printf("Year: %d\n", books[i].year);
    }
    return 0;
}

//Operation to save book data to file
int saveBooks() {
    if (write_data("books.dat", books, bookSize)) { //Call function to write data to file
        printf("Books saved.\n");
        return 0;
    }
    else {
        printf("Failed to save books.\n");
        return 1;
    }
    free(books); //Free memory allocated for books
}

//Operation to load book data from file
int loadBooks() {
    books = read_data("books.dat", &bookSize); //Call function to read data from file
    if (books == NULL) {
        fprintf(stderr, "Failed to load books.\n");
        return 1;
    }
    else {
        return 0;
    }
}

//Function to write data to file
bool write_data(char *filename, Book *data, size_t size) {
    FILE *file = fopen(filename, "wb"); //Open file in write binary mode

    if (file == NULL) { //Check if file opening failed
        return false;
    }

    if (fwrite(&size, sizeof(size_t), 1, file) != 1) { //Write size of data to file
        return false;
    }

    if( fwrite(data, sizeof(Book), size, file) != size) { //Write data to file
        return false;
    }

    if (fclose(file) == EOF) { //Close file
        return false;
    }

    return true;
}

//Function to read data from file
Book *read_data(char *filename, size_t *size) {
    FILE *file = fopen(filename, "rb"); //Open file in read binary mode

    if (file == NULL) { //Check if file opening failed
        return NULL;
    }

    if (fread(size, sizeof(size_t), 1, file) != 1) { //Read size of data from file
        return NULL;
    }

    Book *data = malloc(sizeof(Book) * (*size)); //Allocate memory for data

    if (fread(data, sizeof(Book), *size, file) != *size) { //Read data from file
        free(data);
        return NULL;
    }

    if (fclose(file) == EOF) { //Close file
        free(data);
        return false;
    }

    return data;
}