#include <string>
#include <iostream>
#include <ctime>

#include "Order.h"

int Order::NUM_ORDERS = 0;

Order::Order()
{
    time_t dt;

    dt = time(0);
    m_orderDate   = ctime(&dt);
    m_isOpen      = true;
    m_orderNum    = NUM_ORDERS++;
}

Order::~Order()
{
    map<int, OrderItem*>::iterator it;
    OrderItem* item = nullptr;

    for(it = m_items.begin(); it != m_items.end(); ++it)
    {
        item = it->second;
        if(nullptr != item)
            delete(item);
    }
}

int Order::addPizza(PizzaSize size, SpecialtyType special)
{
    if(false == m_isOpen)
        return -1;

    Pizza *pizza = ItemFactory::createPizza(size, special);
    m_items[pizza->getItemNum()] = pizza;

    return pizza->getItemNum();
}

int Order::addDrink(DrinkType type)
{
    if(false == m_isOpen)
        return -1;

    Drink *drink = ItemFactory::createDrink(type);
    m_items[drink->getItemNum()] = drink;

    return drink->getItemNum();
}

int Order::addMerch(MerchType type)
{
    if(false == m_isOpen)
        return -1;

    Merch *merch = ItemFactory::createMerch(type);
    m_items[merch->getItemNum()] = merch;

    return merch->getItemNum();
}

void Order::addTopping(int pizzaNum, ToppingType type)
{
    if(false == m_isOpen)
        return;

    map<int, OrderItem*>::iterator it;
    Pizza *pizza = nullptr;

    it = m_items.find(pizzaNum);
    if(it == m_items.end())
    {
        return;
    }

    pizza = dynamic_cast<Pizza*>(it->second);
    pizza->addTopping(type);
}

double Order::getTotal()
{
    map<int, OrderItem*>::iterator it;
    double                         price = 0.0;

    for(it = m_items.begin(); it != m_items.end(); ++it)
    {
        if(nullptr != it->second)
            price+= it->second->getPrice();
    }
    return price;
}

char* Order::getOrderDate()
{
    return m_orderDate;
}

bool Order::removeItem(int itemNum)
{
    if(false == m_isOpen)
        return false;

    map<int, OrderItem*>::iterator it;

    it = m_items.find(itemNum);
    if(it == m_items.end())
    {
        return false;
    }
    OrderItem *item = it->second;
    delete(item);

    m_items.erase(itemNum);
    return true;
}

bool Order::removeTopping(int pizzaNum, ToppingType type)
{
    if(false == m_isOpen)
        return -1;

    map<int, OrderItem*>::iterator it;
    Pizza *pizza = nullptr;

    it = m_items.find(pizzaNum);
    if(it == m_items.end())
    {
        return false;
    }

    pizza = dynamic_cast<Pizza*>(it->second);
    return pizza->removeTopping(type);
}

void Order::printTicket()
{
    map<int, OrderItem*>::iterator it;
    ItemType type;

    std::cout << "Order " << getOrderNum() << "\t" << getOrderDate() << std::endl;
    for(it = m_items.begin(); it != m_items.end(); ++it)
    {
        if(nullptr != it->second)
        {
            it->second->print();
            std::cout << std::endl;
        }
    }
    std::cout << "Total:\t" << getTotal();
}

void Order::closeTicket()
{
    m_isOpen = false;
}

int Order::getOrderNum()
{
    return m_orderNum;
}

bool Order::isOpen()
{
    return m_isOpen;
}


