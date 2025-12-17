#include <stdio.h>
#include <string.h>
#include "books.h"

void addBook() {
    FILE *fp = fopen("data/books.txt", "a");
    char name[50], author[50], cat[20]; int qty;

    printf("Book Name: "); scanf("%s", name);
    printf("Author: "); scanf("%s", author);
    printf("Category: "); scanf("%s", cat);
    printf("Quantity: "); scanf("%d", &qty);

    fprintf(fp, "%s %s %s %d\n", name, author, cat, qty);
    fclose(fp);
}

void displayBooks() {
    FILE *fp = fopen("data/books.txt", "r");
    char name[50], author[50], cat[20]; int qty;

    printf("--- Book List ---\n");
    while (fscanf(fp, "%s %s %s %d", name, author, cat, &qty) != EOF)
        printf("%s | %s | %s | Qty:%d\n", name, author, cat, qty);

    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("data/books.txt", "r");
    char key[50], name[50], author[50], cat[20]; int qty;

    printf("Search: "); scanf("%s", key);
    while (fscanf(fp, "%s %s %s %d", name, author, cat, &qty) != EOF)
        if (!strcmp(key, name) || !strcmp(key, author) || !strcmp(key, cat))
            printf("%s | %s | %s | Qty:%d\n", name, author, cat, qty);

    fclose(fp);
}
