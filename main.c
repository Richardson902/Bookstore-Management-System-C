#include <stdio.h>
#include "book.h"

int main() {
    int choice;
    loadBooks(); //Load books data from file

    while(1) {
        printf("\n---Book Management System---\n");
        printf("1. Add Book\n2. Delete Book\n3. Search Book\n4. List All Books\n5. Save Books\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //Read user choice
        getchar(); //Consume newline character

        switch (choice) {
            case 1:
                addBook(); //Call function to add a book
                break;
            case 2:
                deleteBook(); //Call function to delete a book
                break;
            case 3:
                searchBook(); //Call function to search for a book
                break;
            case 4:
                listBooks(); //Call function to list all books
                break;
            case 5:
                saveBooks(); //Call function to save books data to file
                return 0;
            case 6:
                return 0; //Exit program
            default:
                printf("Invalid choice. Please try again.\n"); //Error message for invalid choice
        }
    }

}
