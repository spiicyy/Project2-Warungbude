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
