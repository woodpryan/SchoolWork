#ifndef PIZZA_H
#define PIZZA_H

/** @class      Pizza
    @author     Ryan Wood
    @date       November 28, 2020
    @details    this class represents a pizza item, which is an order item
                on an order at a pizza parlor. It implements the OrderItem
                interface and decorates the Item class using the Decorator
                design pattern. This class contains members and methods 
                necessary for adding and retrieving toppings, setting/getting
                price, printing, etc.
*/

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <vector>

#include "ItemType.h"
#include "ItemDecorator.h"
#include "Topping.h"
#include "PizzaSize.h"
#include "SpecialtyType.h"
#include "Item.h"
#include "PriceManager.h"

using namespace std;

class Pizza : public ItemDecorator
{
public:
    /** Function:   Pizza(OrderItem, PizzaSize, SpecialtyType) Pizza
        @details    this constructor takes the base item, the size of the pizza,
                    and the specialty type of the pizza and constructs a pizza,
                    setting the item member of the ItemDecorator, setting the price
                    according to the PriceManager's specification, and setting the
                    specialty type
        @param      item the base item
        @param      size the size of the pizza as any of enum PizzaSize
        @param      specialty the specialty type as any of enum SpeciatyType
        @return     the specified pizza
    */
    Pizza(OrderItem *item, PizzaSize size, SpecialtyType special) : ItemDecorator(item)
    {
        PriceManager *pm = PriceManager::getInstance();
        m_size = size;
        m_item->setItemType(PIZZA);
        m_item->setPrice(pm->getPrice(special, size));
    }

    /** Function:   Pizza(OrderItem, PizzaSize) Pizza
        @details    this constructor takes the base item and the size of the pizza,
                    and constructs a pizza, setting the item member of the ItemDecorator,
                    setting the price according to the PriceManager's specification, and setting the
                    specialty type to NONE
        @param      item the base item
        @param      size the size of the pizza as any of enum PizzaSize
        @param      specialty the specialty type as any of enum SpeciatyType
        @return     the specified pizza
    */
    Pizza(OrderItem *item, PizzaSize size) : ItemDecorator(item)
    {
        PriceManager *pm = PriceManager::getInstance();

        m_size          = size;
        m_specialtyType = NONE;
        m_item->setPrice(pm->getPrice(NONE, size));
        m_item->setItemType(PIZZA);
    }

    /** Function:   ~Pizza()
        @details    this destructor deletes all of the toppings in
                    the topping list
    */
    ~Pizza();

    /** Function:   getSize()
        @details    this function retrieves the size of the pizza
        @return     the size as any of PizzaSize enum
    */
    PizzaSize     getSize();

    /** Function:   getSpecialty()
        @details    thisfunction retrieves the specialty type of the pizza
        @return     the specialty type as one of SpecialtyType enum
    */
    SpecialtyType getSpecialty();

    /** Function:   getItemNum()
        @details    this function retrieves the unique ID of the pizza
        @return     the pizza number
    */
    int getItemNum();

    /** Functino:   numToppings() int
        @details    determines the number of toppings that have been added
                    to this pizza
        @return     the number of toppings on the pizza that are not specialty
    */
    int numToppings();

    /** Function:   getPrice() double
        @details    this function retreives the price of the pizza,
                    which is the pizza plus the price of each topping
        @return     the price
    */
    double getPrice();

    /** Functino:   setPrice(double)
        @details    this function overrides the price set in the constructor,
                    which is the price of the base pizza. The toppings all
                    still have their own individual prices.
        @param      price the price
    */
    void     setPrice(double iPrice);

    /** Function:   addTopping(ToppingType)
        @details    adds a topping having the given type to the pizza's list
        @param      type the topping type as any of enum ToppingType
    */
    void     addTopping(ToppingType type);

    /** Function:   addTopping(Topping*)
        @details    this function adds the given topping to the list of toppings
                    on this pizza
        @param      topping the topping
    */
    void     addTopping(Topping *topping);

    /** Function:   removeTopping(ToppingType) bool
        @details    removes the topping having the given type from the pizza if
                    it is found in the list of toppings. Only removes one topping.
                    If multipple toppings of one type are to be removed, must be
                    called as many times as that topping has been added
        @param      type the topping type as any of enum ToppingType
        @return     whether the topping was on the pizza and removed
    */
    bool     removeTopping(ToppingType type);

    /** Function:   printToppings()
        @details    prints the list of toppings and their prices
    */
    void     printToppings();

    /** Function:   print()
        @details    prints the pizza's number, type, size, toppings and price
    */
    void     print();

    /** Function:   getItemType()
        @details    this function returns the type of this item
        @return     ItemType::PIZZA
    */
    ItemType getItemType();
    
private:
    vector<Topping*>   m_toppings;
    PizzaSize          m_size;
    SpecialtyType      m_specialtyType;

    /** Function:   getToppingPrices()
        @details    this function totals the price of all the toppings on the pizza
        @return     the topping price total
    */
    double getToppingPrices();

    /** Function:   toString(PizzaSize) string
        @details    returns the given pizza size as a printble string
        @param      size the pizza size as any of PizzaSize enum
        @return     the name of the size
    */
    string toString(PizzaSize size);
    
    /** Function:   setItemType(ItemType)
        @details    this class must implement this function because it implements the
                    OrderItem interface, but this class functino can't be used outside
                    this class. sets the item type
        @param      type the item type as any of ItemType
    */
    void setItemType(ItemType type);
};
#endif
