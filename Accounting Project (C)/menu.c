#include "menu.h"

#include <stdio.h>

void menu()
{
    printf("1. Input financial data\n");
    printf("2. View financial data\n");
    printf("3. View the activity log\n");
    printf("4. Export financial data\n");
    printf("5. Exit\n");
}

void input_menu()
{
    printf("1. Create a financial account\n");
    printf("2. Edit a financial account\n");
    printf("3. Delete a financial account\n");
    printf("4. Record a financial transaction\n");
    printf("5. View my customers\n");
}

void transactions_menu()
{
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Transfer\n");
    printf("4. Pay\n");
}

void view_menu()
{
    printf("1. View account statement\n");
    printf("2. View my balance\n");
    printf("3. View transaction register\n");
    printf("4. View expense report\n");
}

void business_menu()
{
    printf("Select the operation you want to perform:\n");
    printf("1. Add information about a customer\n");
    printf("2. Exit\n");
}

void export_menu()
{
    printf("Select the file format in which you want to export the financial data: \n");
    printf("1. CSV\n");
    printf("2. TXT\n");
}
