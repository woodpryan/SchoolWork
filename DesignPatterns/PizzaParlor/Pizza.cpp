#include <string>
#include <iostream>

#include "ItemFactory.h"
#include "Pizza.h"

Pizza::~Pizza()
{
    vector<Topping*>::iterator it;
    Topping *topping = nullptr;

    for(it = m_toppings.begin(); it != m_toppings.end(); ++it)
    {
        m_toppings.erase(it);
        topping = *it;
        if(nullptr != topping)
            delete(topping);
    }
}

PizzaSize Pizza::getSize()
{
    return m_size;
}

SpecialtyType Pizza::getSpecialty()
{
    return m_specialtyType;
}

void Pizza::setPrice(double iPrice)
{
    m_item->setPrice(iPrice);
}

double Pizza::getPrice()
{
    return getToppingPrices() + m_item->getPrice();
}

int Pizza::getItemNum()
{
    return m_item->getItemNum();
}

void Pizza::addTopping(Topping* topping)
{
    if(topping)
        m_toppings.push_back(topping);
}

void Pizza::addTopping(ToppingType type)
{
    Topping *topping = ItemFactory::createTopping(type);
    addTopping(topping);
}

bool Pizza::removeTopping(ToppingType type)
{
    vector<Topping*>::iterator it;

    for(it = m_toppings.begin(); it != m_toppings.end(); ++it)
    {
        if((*it)->getType() == type)
        {
            m_toppings.erase(it);
            Topping *t = *it;
            delete(t);
            return true;//don't need to delete all of this type, just one
        }
    }
    return false;
}

double Pizza::getToppingPrices()
{
    OrderItem *item;
    double     total = 0.0;
    int        index = 0;

    for(index = 0; index < m_toppings.size(); index++)
    {
        item   = m_toppings[index];
        total += item->getPrice();
    }

    return total;
}

void Pizza::printToppings()
{
    Topping *topping;
    int      index = 0;

    for(index = 0; index < m_toppings.size(); index++)
    {
        topping = m_toppings[index];
        if(index > 0)
            std::cout << endl;
        topping->print();
    }
}

int Pizza::numToppings()
{
    return m_toppings.size();
}

void Pizza::print()
{
    std::cout << getItemNum() << "\t";
    std::cout << toString(getSize()) << "\t";
    std::cout << getPrice();

    if(numToppings() > 0)
    {
        std::cout << endl;
        std::cout << "Toppings\n";
        printToppings();
    }
}

string Pizza::toString(PizzaSize size)
{
    switch(size)
    {
        case INDIVIDUAL:
            return "Individual";
        case REGULAR:
            return "Regular";
        case FAMILY:
            return "Family";
    }
}

ItemType Pizza::getItemType()
{
    return m_item->getItemType();
}

void Pizza::setItemType(ItemType type)
{
    m_item->setItemType(type);
}

