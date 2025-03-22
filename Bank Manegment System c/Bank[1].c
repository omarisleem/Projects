
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


typedef struct {
    int phone_number;
    char name[50];
    char Lname[50];
    int age;
    double balance;
    int password;
} Account;


void Add_account() {

    system("cls");


    int phone_number, age, password;
    char name[50];
    char Lname[50];
    double balance;

    printf("\n");
    printf("\t\t\tCREATING NEW ACCOUNT\n");
    printf("\t\t\t--------------------\n");

    printf("Enter Phone number: ");
    scanf("%d", &phone_number);
    printf("\n");

    printf("Enter account owner first name: ");
    scanf("%s", name);
    printf("\n");

    printf("Enter account owner last name: ");
    scanf("%s", Lname);
    printf("\n");

    printf("Enter age: ");
    scanf("%d", &age);
    printf("\n");

    if (age < 18) {
        printf("You have to be older than 18 to create a bank account\n");
        return;
    }

    printf("Enter balance: ");
    scanf("%lf", &balance);
    printf("\n");

    printf("Enter password (integer): ");
    scanf("%d", &password);
    printf("\n");

    Account account1;
    account1.phone_number = phone_number;
    strcpy(account1.name, name);
    strcpy(account1.Lname, Lname);
    account1.age = age;
    account1.balance = balance;
    account1.password = password;

    FILE *Myfile = fopen("ctest.txt", "a");
    if (Myfile != NULL) {
        fprintf(Myfile, "Phone number: %d\n", phone_number);
        fprintf(Myfile, "First Name: %s\n", name);
        fprintf(Myfile, "Last Name: %s\n", Lname);
        fprintf(Myfile, "Age: %d\n", age);
        fprintf(Myfile, "Balance: $%.2f\n", balance);
        fprintf(Myfile, "Password: %d\n", password);
        fprintf(Myfile, "\n");
        fclose(Myfile);
        printf("A new account has been made\n");
    } else {
        printf("Error opening file\n");
    }
}


void display_accounts() {
     system("cls");
    FILE *Thefile = fopen("ctest.txt", "r");
    if (Thefile == NULL) {
        printf("File is not found\n");
        return;
    }

    char line[256];
    printf("\t\t\tAccounts\n");
    printf("\t\t\t--------\n");
    while (fgets(line, sizeof(line), Thefile)) {
        printf("%s", line);
    }

    fclose(Thefile);
}

void delete_acc() {
     system("cls");
    printf("\t\t\t\tDELETE ACCOUNT\n");
    printf("\t\t\t\t--------------\n");
    int phone_num, password;
    printf("Please enter your phone number: ");
    scanf("%d", &phone_num);
    printf("Please enter your password: ");
    scanf("%d", &password);

    FILE *Myfile = fopen("ctest.txt", "r");
    if (Myfile == NULL) {
        printf("Error while opening file\n");
        return;
    }

    FILE *tempfile = fopen("temp.txt", "a");
    if (tempfile == NULL) {
        printf("Error while opening temporary file\n");
        fclose(Myfile);
        return;
    }

    Account acc;
    int found = 0;
    while (!feof(Myfile)) {
        if (fscanf(Myfile, "Phone number: %d\n", &acc.phone_number) != 1) break;
        fscanf(Myfile, "First Name: %s\n", acc.name);
        fscanf(Myfile, "Last Name: %s\n", acc.Lname);
        fscanf(Myfile, "Age: %d\n", &acc.age);
        fscanf(Myfile, "Balance: $%lf\n", &acc.balance);
        fscanf(Myfile, "Password: %d\n", &acc.password);

        if (acc.phone_number != phone_num || acc.password != password) {
            fprintf(tempfile, "Phone number: %d\n", acc.phone_number);
            fprintf(tempfile, "First Name: %s\n", acc.name);
            fprintf(tempfile, "Last Name: %s\n", acc.Lname);
            fprintf(tempfile, "Age: %d\n", acc.age);
            fprintf(tempfile, "Balance: $%.2f\n", acc.balance);
            fprintf(tempfile, "Password: %d\n", acc.password);
            fprintf(tempfile, "\n");
        } else {
            found = 1;
        }
    }

    fclose(Myfile);
    fclose(tempfile);

    remove("ctest.txt");
    rename("temp.txt", "ctest.txt");

    if (found) {
        printf("Account with phone number %d deleted.\n", phone_num);
    } else {
        printf("Phone number %d not found or incorrect password.\n", phone_num);
    }
}


void update_info() {
     system("cls");


    printf("\t\t\tUpdate information\n");
    printf("\t\t\t------------------\n");

    int phone_number, new_age, password, new_password, ch;
    char new_name[50];
    char new_Lname[50];
    printf("\nEnter your phone number to update: ");
    scanf("%d", &phone_number);
    printf("Enter your password: ");
    scanf("%d", &password);
    printf("\t\t\tUpdating Menu\n");
    printf("\t\t\t-------------\n");
    printf("1. First Name\n");
    printf("2. Lase Name\n");
    printf("3. Password\n");
    printf("4. Age\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
            case 1:
                printf("\nEnter new first name: ");
                scanf("%s", new_name);
                break;
            case 2:
                printf("\nEnter new last name: ");
                scanf("%s", new_Lname);
                break;
            case 3:
                printf("\nEnter new password: ");
                scanf("%d", &new_password);
                break;
            case 4:
                printf("\nEnter new age: ");
                scanf("%d", &new_age);
                break;
            default:
                printf("-_- Please try again.\n");
        }



    FILE *Thefile = fopen("ctest.txt", "r");
    FILE *Tempfile = fopen("temp.txt", "w");
    if (Thefile == NULL) {
        printf("File is not found\n");
        return;
    }

    Account acc;
    int found = 0;
    while (!feof(Thefile)) {
        if (fscanf(Thefile, "Phone number: %d\n", &acc.phone_number) != 1) break;
        fscanf(Thefile, "First Name: %s\n", acc.name);
        fscanf(Thefile, "Last Name: %s\n", acc.Lname);
        fscanf(Thefile, "Age: %d\n", &acc.age);
        fscanf(Thefile, "Balance: $%lf\n", &acc.balance);
        fscanf(Thefile, "Password: %d\n", &acc.password);
        if (acc.phone_number == phone_number && acc.password == password) {
            found = 1;
            switch (ch) {
                case 1:
                    strcpy(acc.name, new_name);
                    break;
                case 2:
                    strcpy(acc.Lname, new_Lname);
                    break;
                case 3:
                    acc.password = new_password;
                    break;
                case 4:
                    acc.age = new_age;
                    break;
                default:
                    printf("-_- Please try again.\n");
            }
        }
        fprintf(Tempfile, "Phone number: %d\n", acc.phone_number);
        fprintf(Tempfile, "First Name: %s\n", acc.name);
        fprintf(Tempfile, "Last Name: %s\n", acc.Lname);
        fprintf(Tempfile, "Age: %d\n", acc.age);
        fprintf(Tempfile, "Balance: $%.2f\n", acc.balance);
        fprintf(Tempfile, "Password: %d\n", acc.password);
        fprintf(Tempfile, "\n");
    }

    fclose(Thefile);
    fclose(Tempfile);

    remove("ctest.txt");
    rename("temp.txt", "ctest.txt");

    if (found) {
        printf("Account updated successfully.\n");
    } else {
        printf("Phone number %d not found or incorrect password.\n", phone_number);
    }
}


void transaction() {
     system("cls");

    printf("\t\t\t\tTRANSACTIONS\n");
    printf("\t\t\t\t------------\n");

    int phone_number, password, ch, amount, phone_number2;
    char new_name[50];
    char new_Lname[50];
    printf("\nEnter your phone number: ");
    scanf("%d", &phone_number);
    printf("Enter your password: ");
    scanf("%d", &password);
    printf("\n");
    printf("\t\t\tTransaction Menu\n");
    printf("\t\t\t----------------\n");
    printf("1. Deposit\n");
    printf("2. Withdrawal\n");
    printf("3. Transfer Money\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    printf("\nEnter the amount of money: ");
    scanf("%d", &amount);
    if(ch==3)
    {
        printf("Enter the recipient's phone number: ");
        scanf("%d", &phone_number2);
    }


    FILE *Thefile = fopen("ctest.txt", "r");
    FILE *Tempfile = fopen("temp.txt", "w");
    if (Thefile == NULL) {
        printf("File is not found\n");
        return;
    }

    Account acc;
    int found = 0, updated=1, found2=0;
    char fName[50], lName[50], fName2[50], lName2[50];
    while (!feof(Thefile)) {
        if (fscanf(Thefile, "Phone number: %d\n", &acc.phone_number) != 1) break;
        fscanf(Thefile, "First Name: %s\n", acc.name);
        fscanf(Thefile, "Last Name: %s\n", acc.Lname);
        fscanf(Thefile, "Age: %d\n", &acc.age);
        fscanf(Thefile, "Balance: $%lf\n", &acc.balance);
        fscanf(Thefile, "Password: %d\n", &acc.password);
        if (acc.phone_number == phone_number && acc.password == password) {
            found = 1;
            strcpy(fName, acc.name);
            strcpy(lName, acc.Lname);
            switch (ch) {
                case 1:
                    acc.balance+=amount;
                    break;
                case 2:
                    if(acc.balance<amount){
                        printf("Insufficient Balance!\n");
                        updated=0;
                    }else
                        acc.balance-=amount;
                    break;
                case 3:
                    if(acc.balance<amount){
                        printf("Insufficient Balance!\n");
                        updated=0;
                    }else
                        acc.balance-=amount;
                    break;
                default:
                    printf("-_- Please try again.\n");
            }
        }

        fprintf(Tempfile, "Phone number: %d\n", acc.phone_number);
        fprintf(Tempfile, "First Name: %s\n", acc.name);
        fprintf(Tempfile, "Last Name: %s\n", acc.Lname);
        fprintf(Tempfile, "Age: %d\n", acc.age);
        fprintf(Tempfile, "Balance: $%.2f\n", acc.balance);
        fprintf(Tempfile, "Password: %d\n", acc.password);
        fprintf(Tempfile, "\n");
    }

    fclose(Thefile);
    fclose(Tempfile);

    remove("ctest.txt");
    rename("temp.txt", "ctest.txt");

    if(ch==3&&updated)
    {
        FILE *Thefile = fopen("ctest.txt", "r");
        FILE *Tempfile = fopen("temp.txt", "w");
        if (Thefile == NULL) {
            printf("File is not found\n");
            return;
        }

        Account acc2;
        while (!feof(Thefile)) {
            if (fscanf(Thefile, "Phone number: %d\n", &acc2.phone_number) != 1) break;
            fscanf(Thefile, "First Name: %s\n", acc2.name);
            fscanf(Thefile, "Last Name: %s\n", acc2.Lname);
            fscanf(Thefile, "Age: %d\n", &acc2.age);
            fscanf(Thefile, "Balance: $%lf\n", &acc2.balance);
            fscanf(Thefile, "Password: %d\n", &acc2.password);
            if (acc2.phone_number == phone_number2) {
                found2 = 1;
                acc2.balance+=amount;
                strcpy(fName2, acc.name);
                strcpy(lName2, acc.Lname);
            }

            fprintf(Tempfile, "Phone number: %d\n", acc2.phone_number);
            fprintf(Tempfile, "First Name: %s\n", acc2.name);
            fprintf(Tempfile, "Last Name: %s\n", acc2.Lname);
            fprintf(Tempfile, "Age: %d\n", acc2.age);
            fprintf(Tempfile, "Balance: $%.2f\n", acc2.balance);
            fprintf(Tempfile, "Password: %d\n", acc2.password);
            fprintf(Tempfile, "\n");
        }

        fclose(Thefile);
        fclose(Tempfile);

        remove("ctest.txt");
        rename("temp.txt", "ctest.txt");
    }
    if (found&&updated)
    {
        if(ch==1)
        {
            printf("Money deposited successfully.\n");

            FILE* ftransactions = fopen("transactions.txt", "a");

            if (ftransactions != NULL)
            {
                time_t current_time = time(NULL);
                char* time_string = ctime(&current_time);
                fprintf(ftransactions, "$%d Deposited by (%s %s), phone number (%d), time %s\n", amount, fName, lName, phone_number, time_string);
                fclose(ftransactions);
            }
        }
        if(ch==2)
        {
            printf("Money Withdrown successfully.\n");

            FILE* ftransactions = fopen("transactions.txt", "a");

            if (ftransactions != NULL)
            {
                time_t current_time = time(NULL);
                char* time_string = ctime(&current_time);
                fprintf(ftransactions, "$%d Withdrown by (%s %s), phone number (%d), time %s\n", amount, fName, lName, phone_number, time_string);
                fclose(ftransactions);
            }
        }
        if(ch==3&&found2)
        {
            printf("Money Transferred successfully.\n");

            FILE* ftransactions = fopen("transactions.txt", "a");

            if (ftransactions != NULL)
            {
                time_t current_time = time(NULL);
                char* time_string = ctime(&current_time);
                fprintf(ftransactions, "$%d Transferred by (%s %s), phone number (%d), to (%s %s), phone number (%d) at time %s\n", amount, fName, lName, phone_number, fName2, lName2, phone_number2, time_string);
                fclose(ftransactions);
            }
        }
    }
    else if(updated){
        printf("Wrong Data. Please try again.\n", phone_number);
    }


}



void display_specific_account() {

     system("cls");
    printf("\t\t\t\tDISPLAY ACCOUNT\n");
    printf("\t\t\t\t---------------\n");

    int phone_number , password;
    printf("\nEnter your phone number to display your account: ");
    scanf("%d", &phone_number);
    printf("\nEnter Password to display your account: ");
    scanf("%d", &password);




    FILE *Thefile = fopen("ctest.txt", "r");
    if (Thefile == NULL) {
        printf("File is not found\n");
        return;
    }

    Account acc;
    int found = 0;
    while (!feof(Thefile)) {
        if (fscanf(Thefile, "Phone number: %d\n", &acc.phone_number) != 1) break;
        fscanf(Thefile, "First Name: %s\n", acc.name);
        fscanf(Thefile, "Last Name: %s\n", acc.Lname);
        fscanf(Thefile, "Age: %d\n", &acc.age);
        fscanf(Thefile, "Balance: $%lf\n", &acc.balance);
        fscanf(Thefile, "Password: %d\n", &acc.password);
        if (acc.phone_number == phone_number && acc.password == password) {
            found = 1;
            printf("\t\t\t\t\nAccount Details:\n");
            printf("Phone number: %d\n", acc.phone_number);
            printf("First Name: %s\n", acc.name);
            printf("Last Name: %s\n", acc.Lname);
            printf("Age: %d\n", acc.age);
            printf("Balance: $%.2f\n", acc.balance);
            printf("Password: %d\n", acc.password);
            break;
        }
    }

    if (!found) {
        printf("Phone number: %d not found or incorrect password\n", phone_number);
    }
        fclose(Thefile);
}


void transactions_his(){

    system("cls");

    FILE *Thefile = fopen("transactions.txt", "r");
    if (Thefile == NULL) {
        printf("File is not found\n");
        return;
    }

    char line[256];
    printf("\t\t\tTRANSACTIONS HISTORY\n");
    printf("\t\t\t--------------------\n");
    while (fgets(line, sizeof(line), Thefile)) {
        printf("%s", line);
    }

    fclose(Thefile);
}


void welcome_screen(){

    system("cls");


    printf("\n");
    printf("\t\t\t_______________________________________\n\n");
    printf("\t\t\t           Welcome To Our Bank        \n\n");
    printf("\t\t\t---------------------------------------\n\n");
    printf("\t\t\t                 Made by:\n");
    printf("\t\t\t               Ahmed Khaled\n");
    printf("\t\t\t               Nadeem Diaa\n");
    printf("\t\t\t               Omar Sholkamy\n");
    printf("\t\t\t               Omar Salama\n");
    printf("\t\t\t               Youssef Amir\n");
    printf("\t\t\t________________________________________\n\n\n");
    printf("Press any key to enter the bank ");
    getch();

    system("cls");
}


void exit_screen() {
    system("cls");

    printf("\n");
    printf("\t\t\t*****************************\n\n");
    printf("\t\t\t Thank you for using our Bank\n");
    printf("\t\t\t Have a great day!\n\n");
    printf("\t\t\t*****************************\n\n");
}

int main() {

    welcome_screen();

    int choice;

    while (1) {
        printf("\n");
        printf("\t\t\t\tMain Menu\n");
        printf("\t\t\t\t---------\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Display Specific Account\n");
        printf("4. Delete Account\n");
        printf("5. Update account information\n");
        printf("6. Perform Transaction\n");
        printf("7. Transactions history\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Add_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                display_specific_account();
                break;
            case 4:
                delete_acc();
                break;
            case 5:
                update_info();
                    break;
            case 6:
                transaction();
                break;
            case 7:
                transactions_his();
                break;
            case 8:
                exit_screen();
                exit(0);
            default:
                printf("-_- Please try again.\n");
        }
    }

    return 0;
}