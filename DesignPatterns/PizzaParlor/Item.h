#ifndef ITEM_H
#define ITEM_H

/*  @class      Item
    @author     Ryan Wood
    @date       November 28, 2020
    @details    This is the base case for a pizza parlor item.
                All Pizza parlor items will decorate this Item,
                which implements the OrderItem interface
                This class contains methods and variables pertinant
                to any item in a Pizza Parlor order
*/

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "OrderItem.h"
#include "ItemType.h"

class Item : public OrderItem
{
public:
    /** Functino:   Item() Item
        @details    constructs a pizza paror item,
                    setting the item number as a unique id
    */
    Item();
    
    /** Functino:   ~Item()
        @details    default destructor
    */
    ~Item(){}

    /** Function:   setPrice(double)
        @details    this function sets the price of the item to
                    the given value
        @param      price the price
    */
	void     setPrice(double iPrice);

    /** Function:   getPrice() double
        @details    this function retrieves the price of the item
        @return     the price
    */
	double   getPrice();

    /** Function:   getItemNum() int
        @details    This function retrieves the unique id of the item
        @return     the item number
    */
	int      getItemNum();

    /** Function:   getItemType() ItemType
        @details    this function retrieves the item type
        @return     the item type as any of enumeration ItemType
    */
    ItemType getItemType();

    /** Functino:   setItemType(ItemType)
        @details    this function sets the item type as the given value
        @param      type the item type as any of enumeration ItemType
    */
    void     setItemType(ItemType type);

    /** Function:   print()
        @details    default print method, prints the item number and price
    */
    void     print();

private:
    static int NUM_ITEMS;
    double     m_price;
    int        m_itemNum;
    ItemType   m_itemType;

};
#endif
