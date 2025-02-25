#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    FILE *fp;
    char name[20];
    int donation;
    char choice;


    printf("What do u want?\n");
    printf("1. For Read Press R: \n");
    printf("2. For Write Press W: \n");
    printf("3. For Total Donation Press T:\n");
    printf("4. For Clear Terminal Press C:\n");


    while(1) {

        printf("Enter Character: ");
        scanf(" %c", &choice);

        // convert lowercase
        choice = tolower(choice);

        if(choice == 'w'){
            // open file write
            fp = fopen("test.txt", "a");

            printf("Enter Student Name: ");
            scanf("%s", name);

            printf("Enter Student Donation (TK): ");
            scanf("%d", &donation);

            // Write student name and donation to file
            fprintf(fp, "Student Name: %s\n", name);
            fprintf(fp, "Donation (TK): %d\n", donation);

            // close file
            fclose(fp);
            printf("Success! Data saved in test.txt\n");


        }
        else if(choice == 'r'){
            // Open file for read
            fp = fopen("test.txt", "r");

            // Check if exists of not
            if(fp == NULL) {
                printf("Error ! Please open file\n");
                break;
            }

            // Print all text in a file
            char string[1000];
            while (fgets(string, 1000, fp)) {
                // Print the name and donation
                printf(string);
            }

            fclose(fp);
        }
        else if(choice == 't') {
            // Open file for read
            fp = fopen("test.txt", "r");
            char number[1000];
            int totalDonation;

            // Check if exists of not
            if(fp == NULL) {
                printf("Error ! Please open file\n");
                break;
            }

            while(1){
                int code = fscanf(fp, "%s", number);
                if(code == EOF) {
                    break;
                }

                totalDonation += atoi(number);

            }
            printf("Total Donation: %d\n", totalDonation);
            totalDonation = 0;
            fclose(fp);

        }
        else if(choice == 'x') {
            printf("Application Exit!\n");
            break;
        }
        else if(choice == 'c'){
            system("cls");
        }
        else {
            printf("something went wrng");
        }
    }



    return 0;
}
