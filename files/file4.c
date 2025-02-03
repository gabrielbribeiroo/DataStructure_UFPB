/*
Separating the dataset information into two files.
The first file should contain the cpf and name of the people.
The second file should contain the name and age of the people.
The dataset contains 15 rows and the information is separated by a space.
*/

#include <stdio.h>
#include <string.h>

#define SIZE_LINE 100
#define SIZE_NAME 50
#define SIZE_CPF 15


int main() {
    // variable declarations
    FILE *db, *db1, *db2;
    char line[SIZE_LINE], name[SIZE_NAME], cpf[SIZE_CPF];
    int age, i;

    // request to open file
    db = fopen("full.txt", "r");
    if (db == NULL) {
        printf("Error opening full.txt\n");
        return 1;
    }

    db1 = fopen("db1.txt", "w");
    if (db1 == NULL) {
        printf("Error opening db1.txt\n");
        fclose(db);
        return 1;
    }

    db2 = fopen("db2.txt", "w");
    if (db2 == NULL) {
        printf("Error opening db2.txt\n");
        fclose(db);
        fclose(db1);
        return 1;
    }

    // read file
    for (i = 0; i < 15; i++) {
        /*
        if (fscanf(db, "%14s %[^\n] %d", cpf, name, &age) == 3) {
            fprintf(db1, "%s %s\n", cpf, name);
            fprintf(db2, "%s %d\n", name, age);
        } 
        */
         if (fgets(line, sizeof(line), db) != NULL) {
            // Quebra a linha nos três campos
            if (sscanf(line, "%14s %49[^0-9] %d", cpf, name, &age) == 3) {
                // Remove espaços extras do nome
                size_t len = strlen(name);
                if (len > 0 && name[len - 1] == ' ') {
                    name[len - 1] = '\0';
                }

                fprintf(db1, "%s %s\n", cpf, name);
                fprintf(db2, "%s %d\n", name, age);
            } else {
                printf("Error processing line %d: %s\n", i + 1, line);
            }
        }
        else {
            printf("Error reading line %d\n", i + 1);
            break;
        }
    }

    // close files
    fclose(db);
    fclose(db1);
    fclose(db2);

    printf("Data successfully separated into db1.txt and db2.txt\n");

    return 0;
}