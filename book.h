#ifndef BOOK_H
#define BOOK_H
#include <stdbool.h>
#include <stdlib.h>

//Struct definition for Book
typedef struct {
    char title[256];
    char author[100];
    char isbn[15];
    int year;
} Book;

//Function declarations
void addBook();
void deleteBook();
void searchBook();
int listBooks();
int saveBooks();
int loadBooks();
bool write_data(char *filename, Book *data, size_t size);
Book *read_data(char *filename, size_t *size);
void userInput(char *clearBuffer, size_t length);

#endif //Book_H