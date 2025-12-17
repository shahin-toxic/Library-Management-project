#include <stdio.h>
#include <string.h>
#include "issue.h"

void issueBook(char member[]) {
    FILE *fp = fopen("data/transactions.txt", "a");
    char book[50];

    printf("Book Name: "); scanf("%s", book);
    fprintf(fp, "%s ISSUED %s\n", member, book);
    fclose(fp);
}

void returnBook(char member[]) {
    FILE *fp = fopen("data/transactions.txt", "a");
    char book[50];

    printf("Book Name: "); scanf("%s", book);
    fprintf(fp, "%s RETURNED %s\n", member, book);
    fclose(fp);
}

void viewIssuedBooks(char member[]) {
    FILE *fp = fopen("data/transactions.txt", "r");
    char user[50], status[20], book[50];

    while (fscanf(fp, "%s %s %s", user, status, book) != EOF)
        if (!strcmp(user, member))
            printf("%s - %s\n", book, status);

    fclose(fp);
}
