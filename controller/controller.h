#include <stdio.h>

struct NodeDish *createDish(char *name, int price, int quantity)
{
    struct NodeDish *temp = (NodeDish *)malloc(sizeof(NodeDish));
    strcpy(temp->Dish.name, name);
    temp->Dish.price = price;
    temp->Dish.quantity = quantity;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushNodeDish(struct NodeDish *temp)
{
    if (!headDish)
    {
        headDish = tailDish = temp;
    }
    else
    {
        tailDish->next = temp;
        temp->prev = tailDish;
        tailDish = temp;
    }
}

// struct NodeCustomer *createCustomer(char *name)
// {
//     struct NodeCustomer *temp = (NodeCustomer *)malloc(sizeof(NodeCustomer));
//     strcpy(temp->Customer.name, name);
//     temp->next = temp->prev = NULL;
//     return temp;
// }

// void pushNodeCustomer(struct NodeCustomer *temp)
// {
//     if (!headCustomer[i])
//     {
//         headCustomer[i] = tailCustomer[i] = temp;
//     }
//     else
//     {
//         tailCustomer[i]->next = temp;
//         temp->prev = tailCustomer[i];
//         tailCustomer[i] = temp;
//     }
// }

void addDish()
{
    char tempName[255];
    int tempPrice, tempQuantity;
    system("cls || clear");
    do
    {
        puts("Insert the name of the dish [Lowercase letters]: ");
        scanf("%[^\n]", tempName);
        getchar();
    } while (!validDish(tempName));
    do
    {
        puts("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &tempPrice);
        getchar();
    } while (!validDishPrice(tempPrice));
    do
    {
        puts("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &tempQuantity);
        getchar();
    } while (!validDishQuantity(tempQuantity));
    pushNodeDish(createDish(tempName, tempPrice, tempQuantity));
    puts("The dish has been added!");
    puts("Press enter to continue...");
    getchar();
    main_menu();
}

void popHead()
{
    if (headDish && headDish == tailDish)
    {
        headDish = tailDish = NULL;
        free(headDish);
    }
    else
    {
        NodeDish *temp = headDish->next;
        headDish->next = temp->prev = NULL;
        free(headDish);
        headDish = temp;
    }
}

void popTail()
{
    if (headDish && headDish == tailDish)
    {
        headDish = tailDish = NULL;
        free(headDish);
    }
    else
    {
        NodeDish *temp = tailDish->prev;
        tailDish->prev = temp->next = NULL;
        free(tailDish);
        tailDish = temp;
    }
}

void removeDish()
{
    int i = 1;

    char S[255];
    puts("==============================\n");
    printf("No. Name Quantity Price \n");
    currDish = headDish;
    while (currDish)
    {
        printf("%d  %s %03d Rp%d\n", i, currDish->Dish.name, currDish->Dish.quantity, currDish->Dish.price);
        currDish = currDish->next;
        i++;
    }
    puts("==============================\n");
    do
    {
        puts("Insert dish's name to be deleted: ");
        scanf("%[^\n]", S);
        getchar();
    } while (!validRemoveDish(S));
    puts("The dish has been removed!");
    puts("Press enter to continue...");
    getchar();
    main_menu();
}

// unsigned long DJB2(char *str)
// {
//     unsigned long hash = 5381;
//     int c;
//     while ((c = *str++))
//         hash = ((hash << 5) + hash) + c;
//     return hash % 26;
// }

// void addCustomer()
// {
//     char tempCustomer[255];
//     do
//     {
//         puts("Insert the customer's name [Without space]: ");
//         getchar();
//         scanf("%[^\n]", tempCustomer);
//     } while (!validAddCustomer(tempCustomer));
//     pushNodeCustomer(createCustomer(tempCustomer));
// }

void exit_menu()
{
    FILE *splash = fopen("../controller/splash-screen.txt", "r");

    char s[10000];
    while (!feof(splash))
    {
        fscanf(splash, "%[^\n]%*c", s);
        printf("%s\n", s);
    }

    fclose(splash);
    puts("Press enter to continue...");
    getchar();
}
