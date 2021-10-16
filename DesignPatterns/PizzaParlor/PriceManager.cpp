#include "PriceManager.h"

/*static const double PIZZA_MARGHARITA =  7.99;
static const double PIZZA_HAWAIIN    =  8.99;
static const double PIZZA_MEAT       =  9.99;
static const double PIZZA_FAMILY     =  5.99;
static const double PIZZA_INDIVIDUAL = -3.99;

static const double TOPPING_CHEESE       = 0.0;
static const double TOPPING_HAM          = 0.75;
static const double TOPPING_PEPPERONI    = 0.99;
static const double TOPPING_GREEN_PEPPER = 0.89;
static const double TOPPING_ONIONS       = 0.89;
static const double TOPPING_MUSHROOMS    = 0.89;
static const double TOPPING_PINEAPPLE    = 0.99;

static const double DRINK_SODA      = 1.29;
static const double DRINK_DIET_SODA = 1.29;
static const double DRINK_BAD_BEER  = 4.99;

static const double MERCH_SHIRT = 21.99;
static const double MERCH_MUG   = 4.99;*/

PriceManager* PriceManager::priceManager = nullptr;

PriceManager::PriceManager()
{
}

PriceManager* PriceManager::getInstance()
{
    if(priceManager == nullptr)
    {
        priceManager = new PriceManager();
    }
    return priceManager;
}

double PriceManager::getPrice(SpecialtyType type, PizzaSize size)
{
    double price = 0.0;

    switch(type)
    {
        case NONE:
        case MARGHERITA:
            price = PIZZA_MARGHARITA;
            break;
        case HAWAIIN:
            price = PIZZA_HAWAIIN;
            break;
        case MEAT_LOVERS:
            price = PIZZA_MEAT;
            break;
    }

    switch(size)
    {
        case INDIVIDUAL:
            price += PIZZA_INDIVIDUAL;
            break;
        case REGULAR:
            break;
        case FAMILY:
            price += PIZZA_FAMILY;
            break;
    }
    return price;
}

double PriceManager::getPrice(MerchType type)
{
    double price = 0.0;

    switch(type)
    {
        case SHIRT:
            price = 21.99;
            break;
        case MUG:
            price = 4.99;
            break;
    }
    return price;
}

double PriceManager::getPrice(DrinkType type)
{
    double price = 0.0;
    switch(type)
    {
        case SODA:
            price = DRINK_SODA;
            break;
        case DIET_SODA:
            price = DRINK_DIET_SODA;
            break;
        case BAD_BEER:
            price = DRINK_BAD_BEER;
            break;
    }
    return price;
}

double PriceManager::getPrice(ToppingType type)
{
    double price = 0.0;

    switch(type)
    {
        case CHEESE:
            price = TOPPING_CHEESE;
            break;
        case HAM:
            price = TOPPING_HAM;
            break;
        case PEPPERONI:
            price = TOPPING_PEPPERONI;
            break;
        case GREEN_PEPPER:
            price = TOPPING_GREEN_PEPPER;
            break;
        case ONIONS:
            price = TOPPING_ONIONS;
            break;
        case MUSHROOMS:
            price = TOPPING_MUSHROOMS;
            break;
        case PINEAPPLE:
            price = TOPPING_PINEAPPLE;
            break;
    }
    return price;
}

