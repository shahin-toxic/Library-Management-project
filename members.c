#include <stdio.h>
#include "members.h"

void register_member(){
    FILE *fp=fopen("./data/members.txt","a");
    char e[50],p[20];
    printf("Email: ");scanf("%s",e);
    printf("Pass: ");scanf("%s",p);
    fprintf(fp,"%s %s\n",e,p);
    fclose(fp);
}

void view_members(){
    FILE *fp=fopen("./data/members.txt","r");
    char e[50],p[20];
    while(fp && fscanf(fp,"%s %s",e,p)!=EOF)
        printf("%s\n",e);
    if(fp) fclose(fp);
}
