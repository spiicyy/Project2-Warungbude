#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../models/VariablesType.h"
#include "../controller/utils.h"
#include "../controller/validation.h"
#include "../controller/controller.h"

void main_dis()
{
    printf("System: %s\n", detectOS());
    printTime();
    printf("1. Add Dish\n");
    printf("2. Remove Dish\n");
    printf("3. Add Customer\n");
    printf("4. Search Customer\n");
    printf("5. View Warteg\n");
    printf("6. Order\n");
    printf("7. Payment\n");
    printf("8. Exit Warteg\n");
}

int main_input()
{
    int option;
    scanf("%d", &option);
    getchar();
    return option;
}

void main_menu()
{
    int input;
    system("cls || clear");
    main_dis();
    do
    {
        printf(">> ");
        input = main_input();
        switch (input)
        {
        case 1:
            addDish();
            break;
        case 2:
            removeDish();
            break;
        //case 3:
        //addCustomer();
        //break;
        case 8:
            exit_menu();
            break;
        }
    } while (input < 1 || input > 8);
}

int main()
{
    main_menu();

    return 0;
}