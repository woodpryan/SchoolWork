#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Drink.h"

void Drink::setPrice(double dPrice)
{
    m_item->setPrice(dPrice);
}

double Drink::getPrice()
{
    return m_item->getPrice();
}

int Drink::getItemNum()
{
    return m_item->getItemNum();
}

void Drink::print()
{
    std::cout << getItemNum() << "\t";
    std::cout << toString(getDrinkType()) << "\t";
    std::cout << getPrice();
}

std::string Drink::toString(DrinkType type)
{
    switch(type)
    {
        case SODA:
            return "Soda";
        case DIET_SODA:
            return "Diet Soda";
        case BAD_BEER:
            return "Bad beer";
        default:
            return "";
    }
    return "";
}

DrinkType Drink::getDrinkType()
{
    return m_drinkType;
}

ItemType Drink::getItemType()
{
    return m_item->getItemType();
}

void Drink::setItemType(ItemType type)
{
    m_item->setItemType(type);
}

