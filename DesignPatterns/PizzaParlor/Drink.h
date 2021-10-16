#ifndef DRINK_H
#define DRINK_H

/** @class      Drink
    @author     Ryan Wood
    @date       November 28, 2020
    @details    this class represents a drink item for a Pizza Parlor,
                implementing the Decorator design pattern and decorating
                the virtual class OrderItem
*/
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ItemDecorator.h"
#include "DrinkType.h"
#include "ItemType.h"
#include "PriceManager.h"

class Drink : public ItemDecorator
{
public:
    /** Function:   Drink() Drink
        @details    constructs a Drink, giving it the given drink type,
                    setting the item member variable of the ItemDecorator
                    to the given item, and setting the price according
                    to the specification of the PriceManger
        @param      item the base item
        @param      type the drink type
        @return     the drink
    */
    Drink(OrderItem *item, DrinkType type) : ItemDecorator(item)
    {
        PriceManager *pm = PriceManager::getInstance();
        m_drinkType = type;
        m_item->setItemType(DRINK);
        m_item->setPrice(pm->getPrice(type));
    }

    /*  Function:   ~Drink()
        @details    default destructor
    */
    ~Drink(){}

    
    /** Function:   setPrice(double)
        @details    this function sets the price of the drink,
                    which is provided as an override to the price
                    that is set by the constructor
        @param      price the price
    */
    void setPrice(double dPrice);
    
    /** Function:   getPrice() double
        @details    gets the price of the drink
        @return     the price
    */
    double getPrice();

    /** Function:   getItemNum() int
        @details    retrieves the unique id of the drink
        @return     the unique id
    */
    int getItemNum();

    /** Function:   print()
        @details    this function prints the item number, drink type, and price
    */
    void print();

    /*  Function:   getDrinkType() DrinkType
        @details    retrieves the drink type
        @return     the drink type as any of enumeration DrinkType
    */
    DrinkType getDrinkType();

    /** Function:   getItemType() ItemType
        @return     retrieves the item type as any of enumeration ItemType
    */
    ItemType  getItemType();

private:
	DrinkType m_drinkType;

    std::string toString(DrinkType type);

    /** Function:   setItemType(ItemType)
        @details    this function is included because this class must implement
                    the setItemType method of the OrderItem class. It sets the
                    item type of the drink
        @param      type the item type as any of enumeration ItemType
    */
    void setItemType(ItemType type);
};
#endif
