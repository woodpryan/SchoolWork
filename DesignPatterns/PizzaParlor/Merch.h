#ifndef MERCH_H
#define MERCH_H

/** @class      Merch
    @author     Ryan Wood
    @date       November 28, 2020
    @details    this class implements the OrderItem interface and
                decorates the Item class using the Decorator design pattern.
                It represents an item of merchandise to be purchased at a pizza
                parlor
*/

#include <string>
#include <list>
#include <iostream>

#include "ItemDecorator.h"
#include "MerchType.h"
#include "PriceManager.h"

class Merch : public ItemDecorator
{
public:

    /** Function:   Merch(OrderItem*, MerchType) Merch
        @details    this constructor sets the ItemDecorator's Item member to
                    the given item, sets this item's Merch type as the given type,
                    and sets the price of the item according to the price manager's
                    specifications
        @param      item the base item
        @param      type the merch type as any of enum MerchType
        @return     the merch class instance
    */
    Merch(OrderItem *item, MerchType type) : ItemDecorator(item)
    {
        PriceManager* pm = PriceManager::getInstance();
        m_merchType = type;
        m_item->setPrice(pm->getPrice(type));
        m_item->setItemType(MERCHANDISE);
    }

    /** Function:   ~Merch()
        @details    default destructor
    */
    ~Merch(){}

    /** Function:   setPrice(double)
        @details    this function overrides the price that was set in the
                    constructor to be the given price
        @param      price the new price
    */
    void      setPrice(double dPrice);

    /** Function:   print()
        @details    this function prints the merch instance's unique id,
                    its merch type, and its price
    */
    void      print();

    /** Function:   getPrice() double
        @details    this function retrieves the price of the merch item
        @return     the price
    */
    double    getPrice();

    /** Function:   getType() MerchType
        @details    this function retrieves the merch type
        @return     the merch type as one of enum MerchType
    */
    MerchType getType();

    /** Function:   getItemNum() int
        @details    this function retrieves the item unique id for the merch item
        @return     the item number
    */
    int       getItemNum();

    /** Function:   getItemType() ItemType
        @details    this function retreives the type of this item
        @return     ItemType::MERCH
    */
    ItemType  getItemType();

private:
    MerchType m_merchType;

    /** Function:   toString(MerchType) string
        @details    this function returns a string representation
                    of the given merch type so it is printable
        @param      type the merch type as any of MerchType
        @return     the name of the value
    */
    std::string toString(MerchType mType);

    /** Function:   setItemType(ItemType)
        @details    this function is included because we must implement the OrderItem interface,
                    but shouldn't be used outside the class. sets the item type
        @param      type the item type as any of enum ItemType
    */
    void setItemType(ItemType type);

};
#endif
