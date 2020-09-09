#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITCAPACITY 3
#define BUFFER_SIZE 20
char **names, **option;
char **numbers;
int capacity = INITCAPACITY;
int n = 0;
int oN = 0;
int pN = 0;
char delim[] = " ";
int *pData;
void add(char*name, char*number);
void find(char*name, bool bl);
void status();
void remove(char*name, bool bl);
void load(char*fileName);
void save(char *fileName);
int search(char*name);
void initDirectory();
void processCommand();
int readLine(char str[], int limit);
void reallocate();
void searchP();
void insert(char *name);
void sort();
int main()
{
    initDirectory();
    processCommand();
    return 0;
}
void initDirectory() {
    names = (char**)malloc(INITCAPACITY * sizeof(char*));
    numbers = (char**)malloc(INITCAPACITY * sizeof(char*));
    option = (char**)malloc(INITCAPACITY * sizeof(char*));
    pData = (int*)malloc(INITCAPACITY * sizeof(int));
}
void processCommand() {
    char commandLine[BUFFER_SIZE];
    char *command, *argument1, *argument2;

    while (1) {
        pN = 0; oN = 0;
        printf("$ ");
        if (readLine(commandLine, BUFFER_SIZE) <= 0) continue;
        command = strtok(commandLine, delim);
        if (command == NULL) continue;
        if (strcmp(command, "read") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("File name required.\n");
                continue;
            }
            load(argument1);
        }
        else if (strcmp(command, "add") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);
            if (argument1 == NULL || argument2 == NULL) {
                printf("Invalid arguments\n");
                continue;
            }
            add(argument1, argument2);
        }
        else if (strcmp(command, "find") == 0) {
            bool bl = false;
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("Invalid arguments\n");
                continue;
            }
            else if (strcmp(argument1, "-p") == 0) {
                bl = true;
                argument1 = strtok(NULL, delim);
                while (argument1 != NULL) {
                    insert(argument1);
                    argument1 = strtok(NULL, delim);
                }
                find(argument1, bl);
                printf("%d persons found.\n", pN);
                continue;
            }
            find(argument1, bl);
        }
        else if (strcmp(command, "status") == 0) {
            status();
        }
        else if (strcmp(command, "delete") == 0) {
            bool bl = false;
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("Invalid arguments\n");
                continue;
            }
            else if (strcmp(argument1, "-p") == 0) {
                bl = true;
                argument1 = strtok(NULL, delim);
                while (argument1 != NULL) {
                    option[oN++] = strdup(argument1);
                    argument1 = strtok(NULL, delim);
                }
                remove(argument1, bl);
                continue;
            }
            remove(argument1, bl);
        }
        else if (strcmp(command, "save") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);
            if (argument1 == NULL || strcmp("as", argument1) || argument2 == NULL) {
                printf("Invalid command format\n");
                continue;
            }
            save(argument2);
        }
        else if (strcmp(command, "exit") == 0)
            break;

    }
}
void insert(char *name) {
    int i = oN - 1;
    while (i >= 0 && strcmp(option[i], name)>0) {
        option[i + 1] = option[i];
        i--;
    }
    option[i + 1] = strdup(name);
    oN++;
}
int readLine(char str[], int limit) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < limit - 1) str[i++] = ch;
    str[i] = '\0';
    return i;
}
void load(char*fileName) {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        add(buf1, buf2);
    }
    fclose(fp);
}
void add(char*name, char*number) {
    if (n >= capacity) reallocate();
    int i = n - 1;
    while (i >= 0 && strcmp(names[i], name)>0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(name);
    numbers[i + 1] = strdup(number);
    n++;
    printf("%s was added successfully.\n", name);
}
void reallocate() {
    capacity *= 2;
    char **tmp1 = (char **)malloc(capacity * sizeof(char*));
    char **tmp2 = (char **)malloc(capacity * sizeof(char*));
    for (int i = 0; i < n; i++) {
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }
    free(names); free(numbers);
    names = tmp1;
    numbers = tmp2;
}
void find(char *name, bool bl) {
    if (!bl) {
        int index = search(name);
        if (index == -1)
            printf("No person named '%s' exists.\n", name);
        else
            printf("%s\n", numbers[index]);
        return;
    }
    else {
        searchP();
        if (pN > 0) {
            for (int i = 0; i < pN; i++)
                printf("%s %s\n", names[pData[i]], numbers[pData[i]]);
        }
        else
            printf("No person named exists.\n");
    }
}
void status() {
    for (int i = 0; i < n; i++)
        printf("%s %s\n", names[i], numbers[i]);
    printf("Total %d persons.\n", n);
}
void remove(char *name,bool bl) {
    if (!bl) {
        int i = search(name);
        if (i == -1) {
            printf("No person named '%s' exists.\n", name);
            return;
        }
        for (int j = i; j < n - 1; j++) {
            names[j] = names[j + 1];
            numbers[j] = numbers[j + 1];
        }
        n--;
        printf("'%s' was deleted successfully.\n", name);
        return;
    }
    else {
        searchP();
        int count = 0;
        if (pN > 0) {
            for (int i = 0; i < pN; i++) {
                char answer[BUFFER_SIZE];
                printf("Do you want to delete '%s'??", names[pData[i]]);
                fgets(answer, BUFFER_SIZE, stdin);
                if (strcmp(answer, "yes\n") == 0) {
                    printf("%s was deleted.\n", names[pData[i]]);
                    names[pData[i]] = names[n - 1];
                    numbers[pData[i]] = numbers[n - 1];
                    n--; count++;
                }
                else
                    printf("%s was not deleted.\n", names[pData[i]]);
            }
            sort();
            printf("%d person deleted.\n", count);
        }
        else
            printf("No person named exists.\n");
    }
}
void save(char *fileName) {
    FILE * fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    fclose(fp);
}
int search(char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(name, names[i]) == 0)
            return i;
    }
    return -1;
}
void searchP() {
    pN = 0;
    for (int i = 0; i < oN; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < strlen(option[i]); k++) {
                if (names[j][k] != option[i][k]) {
                    flag = false;
                }
            }
            if (flag) {
                pData[pN++] = j;
            }
        }
    }
}
void sort() {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(names[j], names[i]) > 0) {
                char *tmp = names[i];
                names[i] = names[j];
                names[j] = tmp;
                char *tamp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tamp;
            }
        }
    }
}
