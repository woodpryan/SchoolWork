#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ItemFactory.h"
#include "Pizza.h"
#include "Drink.h"
#include "Merch.h"
#include "Topping.h"

Pizza* ItemFactory::createPizza(PizzaSize size)
{
    return new Pizza(new Item(), size);
}

Pizza* ItemFactory::createPizza(PizzaSize size, SpecialtyType special)
{
    return new Pizza(new Item(), size, special);
}

Drink* ItemFactory::createDrink(DrinkType type)
{
    return new Drink(new Item(), type);
}

Merch* ItemFactory::createMerch(MerchType type)
{
    return new Merch(new Item(), type);
}

Topping* ItemFactory::createTopping(ToppingType type)
{
    return new Topping(new Item(), type);
}
