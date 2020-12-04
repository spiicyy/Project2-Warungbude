struct Dish
{
    char name[255];
    int price, quantity;
};

struct Order
{
    char name[255];
    int quantity, price;
};

struct Customer
{
    char name[255];
};

struct NodeDish
{
    struct Dish Dish;
    NodeDish *prev, *next;
} * headDish, *tailDish, *currDish, *newDish, *delDish;

struct NodeOrder
{
    struct Order Order;
    NodeOrder *prev, *next;
} * newOrder, *currOrder, *delOrder;

struct NodeCustomer
{
    struct Customer Customer;
    NodeCustomer *prev, *next;
} * headCustomer[26], *tailCustomer[26], *currCustomer, *newCustomer, *delCustomer;

void main_menu();