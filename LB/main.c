#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define ADMIN_PASS "admin"
#define MAX_DAYS 7
#define FINE_PER_DAY 5


void passwordScreen();
void startMenu();
void registerMember();
int memberLogin(char loggedUser[]);
int librarianLogin();
void displayBooks();
void searchBook();
void addBook();
void updateBook();
void deleteBook();
void issueBook(char member[]);
void returnBook(char member[]);
void viewIssuedBooks(char member[]);
void viewMembers();
void viewTransactions();


int main() {
    passwordScreen();
    startMenu();
    return 0;
}

void passwordScreen() {
    char pass[20];
    int attempts = 0;

    while (attempts < 3) {
        system("cls");
        printf("===== Library Management System =====\n");
        printf("Enter System Password: ");
        scanf("%s", pass);

        if (strcmp(pass, ADMIN_PASS) == 0) {
            printf("Access Granted!\n");
            system("pause");
            return;
        } else {
            printf("Wrong Password!\n");
            attempts++;
            system("pause");
        }
    }
    printf("Too many attempts. Exiting...\n");
    exit(0);
}


void startMenu() {
    int choice;
    char loggedUser[50];

    while (1) {
        system("cls");
        printf("===== Start Menu =====\n");
        printf("1. Register Member\n");
        printf("2. Login as Member\n");
        printf("3. Login as Librarian\n");
        printf("4. Search Book\n");
        printf("5. Display All Books\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerMember(); break;
        case 2:
            if (memberLogin(loggedUser)) {
                int ch;
                do {
                    system("cls");
                    printf("=== Member Panel (%s) ===\n", loggedUser);
                    printf("1. Display Books\n2. Search Book\n3. Issue Book\n4. Return Book\n5. View Issued Books\n6. Logout\n");
                    scanf("%d", &ch);
                    switch (ch) {
                        case 1: displayBooks(); break;
                        case 2: searchBook(); break;
                        case 3: issueBook(loggedUser); break;
                        case 4: returnBook(loggedUser); break;
                        case 5: viewIssuedBooks(loggedUser); break;
                    }
                } while (ch != 6);
            }
            break;
        case 3:
            if (librarianLogin()) {
                int ch;
                do {
                    system("cls");
                    printf("=== Librarian Panel ===\n");
                    printf("1. Display Books\n2. Search Book\n3. Add Book\n4. Update Book\n5. Delete Book\n6. View Members\n7. View Transactions\n8. Logout\n");
                    scanf("%d", &ch);
                    switch (ch) {
                        case 1: displayBooks(); break;
                        case 2: searchBook(); break;
                        case 3: addBook(); break;
                        case 4: updateBook(); break;
                        case 5: deleteBook(); break;
                        case 6: viewMembers(); break;
                        case 7: viewTransactions(); break;
                    }
                } while (ch != 8);
            }
            break;
        case 4: searchBook(); break;
        case 5: displayBooks(); break;
        case 6: exit(0);
        }
    }
}


void registerMember() {
    FILE *fp = fopen("members.txt", "a");
    char email[50], pass[20];
    system("cls");
    printf("Enter Email/Phone: "); scanf("%s", email);
    printf("Create Password: "); scanf("%s", pass);
    fprintf(fp, "%s %s\n", email, pass);
    fclose(fp);
    printf("Registration Successful!\n");
    system("pause");
}


int memberLogin(char loggedUser[]) {
    FILE *fp = fopen("members.txt", "r");
    char email[50], pass[20], fe[50], fpw[20];
    system("cls");
    printf("Email: "); scanf("%s", email);
    printf("Password: "); scanf("%s", pass);
    while (fscanf(fp, "%s %s", fe, fpw) != EOF) {
        if (!strcmp(email, fe) && !strcmp(pass, fpw)) {
            strcpy(loggedUser, email);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    printf("Login Failed!\n");
    system("pause");
    return 0;
}


int librarianLogin() {
    char id[20], pass[20];
    system("cls");
    printf("Librarian ID: "); scanf("%s", id);
    printf("Password: "); scanf("%s", pass);
    if (!strcmp(id, "251-35-444") && !strcmp(pass, "shahin")) return 1;
    printf("Invalid Librarian Login!\n");
    system("pause");
    return 0;
}


void addBook() {
    FILE *fp = fopen("books.txt", "a");
    char name[50], author[50], cat[20]; int qty;
    system("cls");
    printf("Book Name: "); scanf("%s", name);
    printf("Author: "); scanf("%s", author);
    printf("Category: "); scanf("%s", cat);
    printf("Quantity: "); scanf("%d", &qty);
    fprintf(fp, "%s %s %s %d\n", name, author, cat, qty);
    fclose(fp);
    printf("Book Added!\n"); system("pause");
}

void displayBooks() {
    FILE *fp = fopen("books.txt", "r");
    char name[50], author[50], cat[20]; int qty;
    system("cls");
    printf("--- Book List ---\n");
    while (fscanf(fp, "%s %s %s %d", name, author, cat, &qty) != EOF)
        printf("%s | %s | %s | Qty:%d\n", name, author, cat, qty);
    fclose(fp);
    system("pause");
}

void searchBook() {
    FILE *fp = fopen("books.txt", "r");
    char key[50], name[50], author[50], cat[20]; int qty;
    system("cls");
    printf("Search: "); scanf("%s", key);
    while (fscanf(fp, "%s %s %s %d", name, author, cat, &qty) != EOF) {
        if (!strcmp(key, name) || !strcmp(key, author) || !strcmp(key, cat))
            printf("%s | %s | %s | Qty:%d\n", name, author, cat, qty);
    }
    fclose(fp);
    system("pause");
}


void issueBook(char member[]) {
    FILE *fp = fopen("transactions.txt", "a");
    char book[50];
    system("cls");
    printf("Book Name: "); scanf("%s", book);
    fprintf(fp, "%s ISSUED %s\n", member, book);
    fclose(fp);
    printf("Book Issued!\n"); system("pause");
}

void returnBook(char member[]) {
    FILE *fp = fopen("transactions.txt", "a");
    char book[50];
    system("cls");
    printf("Book Name: "); scanf("%s", book);
    fprintf(fp, "%s RETURNED %s\n", member, book);
    fclose(fp);
    printf("Book Returned!\n"); system("pause");
}

void viewIssuedBooks(char member[]) {
    FILE *fp = fopen("transactions.txt", "r");
    char user[50], status[20], book[50];
    system("cls");
    while (fscanf(fp, "%s %s %s", user, status, book) != EOF)
        if (!strcmp(user, member)) printf("%s - %s\n", book, status);
    fclose(fp);
    system("pause");
}

void viewMembers() {
    FILE *fp = fopen("members.txt", "r");
    char e[50], p[20];
    system("cls");
    while (fscanf(fp, "%s %s", e, p) != EOF) printf("%s\n", e);
    fclose(fp);
    system("pause");
}

void viewTransactions() {
    FILE *fp = fopen("transactions.txt", "r");
    char u[50], s[20], b[50];
    system("cls");
    while (fscanf(fp, "%s %s %s", u, s, b) != EOF)
        printf("%s %s %s\n", u, s, b);
    fclose(fp);
    system("pause");
}

void updateBook() {
    FILE *fp = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char name[50], author[50], cat[20];
    char newName[50], newAuthor[50], newCat[20];
    int qty, newQty;
    char search[50];
    int found = 0;

    system("cls");
    printf("Enter Book Name to Update: ");
    scanf("%s", search);

    while (fscanf(fp, "%s %s %s %d", name, author, cat, &qty) != EOF) {
        if (strcmp(name, search) == 0) {
            found = 1;
            printf("New Book Name: "); scanf("%s", newName);
            printf("New Author: "); scanf("%s", newAuthor);
            printf("New Category: "); scanf("%s", newCat);
            printf("New Quantity: "); scanf("%d", &newQty);
            fprintf(temp, "%s %s %s %d", newName, newAuthor, newCat, newQty);
        } else {
            fprintf(temp, "%s %s %s %d", name, author, cat, qty);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        printf("Book Updated Successfully!");
    else
        printf("Book Not Found!");

    system("pause");
}
void deleteBook() {
    FILE *fp = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char name[50], author[50], cat[20];
    int qty;
    char search[50];
    int found = 0;

    system("cls");
    printf("Enter Book Name to Delete: ");
    scanf("%s", search);

    while (fscanf(fp, "%s %s %s %d", name, author, cat, &qty) != EOF) {
        if (strcmp(name, search) == 0) {
            found = 1;
        } else {
            fprintf(temp, "%s %s %s %d", name, author, cat, qty);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        printf("Book Deleted Successfully!");
    else
        printf("Book Not Found!");

    system("pause");
}

