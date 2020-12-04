#include <stdio.h>
bool validDish(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            return false;
        }
    }
    return true;
}

bool validDishPrice(int range)
{
    if (range < 1000 || range > 50000)
    {
        return false;
    }

    return true;
}

bool validDishQuantity(int amount)
{
    if (amount < 1 || amount > 999)
    {
        return false;
    }

    return true;
}

void popHead();
void popTail();

bool validRemoveDish(char *str)
{
    if (strcmp(headDish->Dish.name, str) == 0)
    {
        popHead();
        return true;
    }
    else if (strcmp(tailDish->Dish.name, str) == 0)
    {
        popTail();
        return true;
    }
    else
    {
        currDish = headDish;
        while (currDish)
        {
            if (strcmp(currDish->Dish.name, str) == 0)
            {
                currDish->prev->next = currDish->next;
                currDish->next->prev = currDish->prev;
                currDish->prev = currDish->next = NULL;
                free(currDish);
                return true;
            }
            currDish = currDish->next;
        }
        return false;
    }
}

// bool validAddCustomer(char *str)
// {
//     for (int i = 0; i < str[i] != '\0'; i++)
//     {
//         if (str[i] == " ")
//         {
//             return false;
//         }
//     }
//     return true;
// }