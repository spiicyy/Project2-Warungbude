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