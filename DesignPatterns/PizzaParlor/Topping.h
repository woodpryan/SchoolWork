#ifndef TOPPING_H
#define TOPPING_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "OrderItem.h"
#include "ItemDecorator.h"
#include "ToppingType.h"
#include "PriceManager.h"

/** @class      Topping
    @author     Ryan Wood
    @date       November 28, 2020
    @details    This class represents a Topping on a pizza. A topping is
                an Order item in a pizza parlor order as well as a topping
                on a pizza. This class implements the OrderItem interface
                and decorates the Item class, implementing the decorator pattern
*/


class Topping : public ItemDecorator
{
public:
    
    /** Function:   Topping(OrderItem*, ToppingType) Topping
        @details    this constructor sets the Item decorator's Item member
                    to the given item and sets the topping type as the
                    given type, as well as setting the price according
                    to the PriceManager's specification
        @param      item* the order item
        @param      type the topping type as any of enum ToppingType
        @return     the specified topping
    */
    Topping(OrderItem *item, ToppingType type) : ItemDecorator(item)
    {
        m_toppingType = type;
        m_item->setItemType(TOPPING);
        PriceManager *pm = PriceManager::getInstance();
        m_item->setPrice(pm->getPrice(type));
    }

    /** Function:   ~Topping
        @details    default destructor
    */
    ~Topping(){}

    /** Function:   setPrice(double)
        @details    sets the price of the topping, overriding the price
                    set in the constructor
        @param      price the price
    */
	void setPrice(double dPrice);

    /** Functino:   getPrice()
        @details    gets the price of the topping
        @return     the price
    */
	double getPrice();

    /** Function:   getItemNum() int
        @details    this function returns the unique id of the topping
        @return     the item num
    */
    int         getItemNum();

    /** Function:   print()
        @details    prints the topping's item number, topping type, and price
    */
    void        print();

    /** Function:   getPrice()
        @details    retrieves the type of topping
        @return     the topping type as one of ToppingType enum
    */
	ToppingType getType();

    /** Function:   getItemType()
        @details    this function retreives the item type
        @return     the item type as one of ItemType enum
    */
    ItemType    getItemType();

private:
	ToppingType m_toppingType;

    /** Function:   setItemType(ItemType)
        @details    this function sets the item type. It is necessary in order
                    to implement the OrderItem interface
        @param      type the item type as any of ItemType enum
    */
    void setItemType(ItemType type);

};
#endif
