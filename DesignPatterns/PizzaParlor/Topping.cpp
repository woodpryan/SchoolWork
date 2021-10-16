#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Topping.h"

ToppingType Topping::getType()
{
    return m_toppingType;
}

void Topping::setPrice(double dPrice)
{
    m_item->setPrice(dPrice);
}

double Topping::getPrice()
{
    return m_item->getPrice();
}

int Topping::getItemNum()
{
    return m_item->getItemNum();
}

std::string toString(ToppingType type)
{
    switch(type)
    {
        case CHEESE:
            return "Cheese";
            break;
        case HAM:
            return "Ham";
            break;
        case PEPPERONI:
            return "Pepperoni";
            break;
        case GREEN_PEPPER:
            return "Green Pepper";
            break;
        case ONIONS:
            return "Onions";
            break;
        case MUSHROOMS:
            return "Mushrooms";
            break;
        case PINEAPPLE:
            return "Pineapple";
            break;
    }
    return "";
}

void Topping::print()
{
    std::cout << getItemNum() << "\t";
    std::cout << toString(m_toppingType) << "\t";
    std::cout << m_item->getPrice();
}

ItemType Topping::getItemType()
{
    return m_item->getItemType();
}

void Topping::setItemType(ItemType type)
{
    m_item->setItemType(type);
}

