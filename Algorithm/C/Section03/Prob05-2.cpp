//
// Created by 강대원 on 2018. 4. 6..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define SIZE 300

typedef struct contact {
    char *name;
    char *address;
    char *company;
    char *zipcode;
    char *phone;
    char *email;
} Contact;

void process();
int readLine (FILE*fp, char command[], int size);
void load (char *book);
void compress(char *ptr);
void print ();
int compare_name(const void *p, const void*q);
int compare_address(const void* p, const void* q);
int compare_zipcode(const void* p, const void* q);
int compare_phone(const void* p, const void* q);
int compare_company(const void* p, const void* q);
int compare_email(const void* p, const void* q);

Contact contact[MAX];
int n=0;

int main() {
    process();
    return 0;
}
// input command

// read file..
// sort by ~~~
// print
// exit -- break
void process() {
    char commandLine[SIZE];
    char delim[] = " ";
    char *cmd, *argument1, *argument2;

    while (1) {
        printf("$ ");
        if( readLine(stdin,commandLine, SIZE) <= 0)
            continue;
        cmd = strtok (commandLine, delim);
        if ( cmd == NULL ) continue;

        if (strcmp(cmd, "read") == 0) {
            argument1 = strtok(NULL, delim);
            if ( argument1 == NULL) {
                printf("File name required.\n");
                continue;
            }
            load(argument1);
        }
        else if (strcmp(cmd, "sort") == 0) {
            argument1 = strtok (NULL, delim);
            argument2 = strtok (NULL, delim);

            if ( argument1 == NULL || argument2 == NULL ) {
                printf("Invalid arguments.\n");
                continue;
            }
            if ( strcmp(argument1, "by") == 0 ) {
                if ( strcmp(argument2, "name") == 0 )
                    qsort (contact, n, sizeof (Contact),compare_name);
                else if ( strcmp(argument2, "company") == 0 )
                    qsort (contact, n, sizeof (Contact),compare_company);
                else if ( strcmp(argument2, "address") == 0 )
                    qsort (contact, n, sizeof (Contact),compare_address);
                else if ( strcmp(argument2, "zipcode") == 0 )
                    qsort (contact, n, sizeof (Contact),compare_zipcode);
                else if ( strcmp(argument2, "phone") == 0 )
                    qsort (contact, n, sizeof (Contact),compare_phone);
                else if ( strcmp(argument2, "email") == 0 )
                    qsort (contact, n, sizeof (Contact),compare_email);
            }
        }
        else if (strcmp (cmd, "print") == 0 )
            print();
        else if (strcmp (cmd, "exit") == 0 )
            break;
    }
}

void print () {
    for (int i = 0; i < n; i++) {
        printf("%s\n", contact[i].name);
        printf("\tCompany: %s\n", contact[i].company);
        printf("\tAddress: %s\n", contact[i].address);
        printf("\tZipcode: %s\n", contact[i].zipcode);
        printf("\tPhones : %s\n", contact[i].phone);
        printf("\tEmail  : %s\n", contact[i].email);
    }
}

void load (char *book) {
    char buffer[SIZE];
    char *name, *company, *address, *phone, *email,*zipcode;
    char delim[] = "|";

    FILE* fp = fopen(book, "r");
    if ( fp == NULL ) {
        printf("Open failed.\n");
        return;
    }

    while ( fgets (buffer,SIZE,fp) != NULL) {
        name = strtok (buffer, delim);
        compress(name);
        contact[n].name = strdup (name);

        company = strtok (NULL, delim);
        compress(company);
        contact[n].company = strdup (company);

        address = strtok (NULL, delim);
        compress(address);
        contact[n].address = strdup (address);

        zipcode = strtok (NULL, delim);
        compress(zipcode);
        contact[n].zipcode = strdup (zipcode);

        phone = strtok (NULL, delim);
        compress(phone);
        contact[n].phone = strdup (phone);

        email = strtok (NULL, delim);
        compress(email);
        contact[n++].email = strdup (email);
    }
    fclose (fp);
}

void compress(char *ptr) {
    ptr[strlen(ptr) - 1] = ' ';
    int i = 0, j = 0;
    char compressed[SIZE];
    char prev = '\0';

    while (ptr[i] == ' ')
        i++;//skip the leading blanks
    while (ptr[i] != '\0') {
        if (ptr[i] != ' ' || prev != ' ')
            compressed[j++] = ptr[i];

        prev = ptr[i];
        i++;
    }
    if (prev == ' ' || prev == '\n')
        compressed[--j] = '\0';
    else
        compressed[j] = '\0';
    strcpy(ptr, compressed);
}

int readLine ( FILE*fp, char command[], int size) {
    int ch, i=0;

    while ( (ch = getchar ()) != '\n' )
        if (i < size)
            command[i++] = ch;

    command[i] = '\0';
    return i;

}
int compare_name(const void *p, const void*q) {
    return strcmp(((Contact*)p)->name, ((Contact*)q)->name);
}

int compare_address(const void* p, const void* q) {
    return strcmp(((Contact*)p)->address, ((Contact*)q)->address);
}

int compare_zipcode(const void* p, const void* q) {
    return strcmp(((Contact*)p)->zipcode, ((Contact*)q)->zipcode);
}

int compare_phone(const void* p, const void* q) {
    return strcmp(((Contact*)p)->phone, ((Contact*)q)->phone);
}
int compare_company(const void* p, const void* q) {
    return strcmp(((Contact*)p)->company, ((Contact*)q)->company);
}
int compare_email(const void* p, const void* q) {
    return strcmp(((Contact*)p)->email, ((Contact*)q)->email);
}

