#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

#define ADMIN_PASS "admin"

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
