#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    int issued; // 0 = available, 1 = issued
};

struct Book library[100];
int countBooks = 0;

void addBook() {
    if (countBooks >= 100) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[countBooks].id);
    getchar(); // clear buffer

    printf("Enter Book Title: ");
    fgets(library[countBooks].title, sizeof(library[countBooks].title), stdin);

    library[countBooks].title[strcspn(library[countBooks].title, "\n")] = 0;

    library[countBooks].issued = 0;
    countBooks++;

    printf("Book added successfully!\n");
}

void displayBooks() {
    if (countBooks == 0) {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < countBooks; i++) {
        printf("ID: %d | Title: %s | Status: %s\n",
               library[i].id,
               library[i].title,
               library[i].issued ? "Issued" : "Available");
    }
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            if (library[i].issued == 0) {
                library[i].issued = 1;
                printf("Book issued successfully!\n");
            } else {
                printf("Book already issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            if (library[i].issued == 1) {
                library[i].issued = 0;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
