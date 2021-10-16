#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "OrderManager.h"

OrderManager* OrderManager::m_orderManager = nullptr;

OrderManager::~OrderManager()
{
    Order *order = nullptr;
    map<int, Order*>::iterator it;

    for(it = m_orders.begin(); it != m_orders.end(); ++it)
    {
        order = it->second;
        if(nullptr == order)
            continue;
        delete(order);
    }
}

OrderManager::OrderManager()
{
}

OrderManager* OrderManager::getInstance()
{
    if(m_orderManager == nullptr)
        m_orderManager = new OrderManager();

    return m_orderManager;
}

int OrderManager::createOrder()
{
    Order *order = new Order();
    m_orders[order->getOrderNum()] = order;

    return order->getOrderNum();
}

Order *OrderManager::getOrder(int orderNum)
{
    Order *order = nullptr;
    map<int, Order*>::iterator it;

    it = m_orders.find(orderNum);
    if(it == m_orders.end())
        return order;

    order = it->second;
    return order;
}

int OrderManager::addPizza(int iOrderNum, PizzaSize size)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return -1;

    return order->addPizza(size, NONE);
}

int OrderManager::addPizza(int iOrderNum, PizzaSize size, SpecialtyType special)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return -1;

    return order->addPizza(size, special);
}

void OrderManager::addTopping(int orderNum, int itemNum, ToppingType type)
{
    Order *order = nullptr;
    
    order = getOrder(orderNum);
    if(nullptr == order)
        return;

    order->addTopping(itemNum, type);
}

int OrderManager::addDrink(int iOrderNum, DrinkType type)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return -1;

    return order->addDrink(type);
}

int OrderManager::addMerch(int iOrderNum, MerchType type)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return -1;

    return order->addMerch(type);
}

bool OrderManager::removeItem(int iOrderNum, int iItemNum)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return false;

    return order->removeItem(iItemNum);
}

bool OrderManager::removeTopping(int iOrderNum, int iItemNum, ToppingType topType)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return false;

    order->removeTopping(iItemNum, topType);
    return true;
}

void OrderManager::printTicket(int iOrderNum)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return;

    order->printTicket();
}

void OrderManager::closeTicket(int iOrderNum)
{
    Order *order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return;

    order->closeTicket();
}

void OrderManager::printClosedTickets()
{
    map<int, Order*>::iterator it;
    Order *order = nullptr;

    for(it = m_orders.begin(); it != m_orders.end(); ++it)
    {
        order = it->second;
        if(nullptr == order)
            continue;

        if(order->isOpen())
            continue;

        if(it != m_orders.begin())
            std::cout << endl;
        order->printTicket();
    }
}

void OrderManager::printOpenTickets()
{
    map<int, Order*>::iterator it;
    Order *order = nullptr;

    for(it = m_orders.begin(); it != m_orders.end(); ++it)
    {
        order = it->second;
        if(nullptr == order)
            continue;

        if(order->isOpen() == false)
            continue;

        if(it != m_orders.begin())
            std::cout << endl;
        order->printTicket();
    }
}

void OrderManager::print()
{
    map<int, Order*>::iterator it;
    Order *order = nullptr;

    for(it = m_orders.begin(); it != m_orders.end(); ++it)
    {
        order = it->second;
        if(nullptr == order)
            continue;

        if(it != m_orders.begin())
            std::cout << endl;
        order->printTicket();
    }
}

double OrderManager::getTotal(int iOrderNum)
{
    Order* order = nullptr;

    order = getOrder(iOrderNum);
    if(nullptr == order)
        return 0.0;

    return order->getTotal();
}
