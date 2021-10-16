#ifndef ORDER_H
#define ORDER_H

/** @class      Order
    @author     Ryan Wood
    @date       November 28, 2020
    @details    This class represents a Pizza Parlor order. It contains a list of
                order items and the means by which they may be added to or removed
                from an order. Order items may be pizza, drink, or merch.
*/

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <ctime>

#include "ItemFactory.h"
#include "OrderItem.h"
#include "Pizza.h"
#include "ItemDecorator.h"
#include "Topping.h"
#include "Merch.h"
#include "Drink.h"

class Order
{
public:
    /** Function:   Order() Order
        @details    constructs an order, setting the order number
                    as a unique ID
        @return     the order
    */
    Order();
    
    /** Function:   ~Order()
        @details    this function deletes all of the orders in 
                    the order list. destructor
    */
    ~Order();

    /** Function:   addPizza(PizzaSize, SpecialtyType) int
        @details    this function adds a pizza to the order having the
                    given size and specialty type.
        @param      size the size as any of enumeration PizzaSize
        @param      specialty the specialty type as any of enumeration SpecialtyType
        @return     the item unique id of the pizza
    */
    int addPizza(PizzaSize size, SpecialtyType special);
    
    /** Function:   addDrink(DrinkType) int
        @details    this function adds a drink to the order having the given drink type
        @param      type the drink type as any of enumeration DrinkType
        @return     the item unique ID of the drink
    */
    int addDrink(DrinkType type);

    /** Function:   addMerch(MerchType) int
        @details    this function adds merchandise to the order
                    having the given merch type
        @param      type the merch type as any of enumeration MerchType
        @return     the unique id of the merch item
    */
    int addMerch(MerchType type);

    /** Function:   addTopping(int, ToppingType)
        @details    this function adds a topping having the given topping type
                    to the pizza having the given unique id
        @param      pizzaId the pizza id
        @param      toppingType the topping type as any of enumeration ToppingType
    */
    void addTopping(int pizzaNum, ToppingType type);

    /** Functino:   getTotal() double
        @details    this function returns the total of the prices of all
                    of the items on this order
        @return     the order total
    */
    double getTotal();

    /** Function:   getOrderDate() char*
        @details    this function retrieves the date and time at which the order
                    was created, formatted as a c-string
        @return     the date and time
    */
    char* getOrderDate();

    /** Function:   getOrderNum() int
        @details    this function retrieves the unique id of this order
        @return     the order number
    */
    int getOrderNum();

    /** Function:   isOpen() bool
        @details    this funtion returns whether the order is open. If the
                    order is closed, it can no longer be modified
        @return     whether the order is open
    */
    bool isOpen();

    /** Function:   removeItem(int) bool
        @details    this function removes the item from the order having the
                    given item number if the order is open and the item
                    exists in the list of items
        @param      itenNum the item unique id
        @return     whether the item was found and deleted
    */
    bool removeItem(int itemNum);

    /** Function:   removeTopping(int, ToppingType) bool
        @details    This function removes the pizza topping having the given topping
                    type from the pizza on this order having the given item id
        @param      pizzaNum the pizza number
        @param      type the topping type as any of enumeration ToppingType
        @return     whether the topping was successfully removed
    */
    bool removeTopping(int pizzaNum, ToppingType type);

    /** Function:   printTicket()
        @details    this function prints all of the items in this order
                    as well as the order number, date and total
    */
    void printTicket();
    
    /** Function:   closeTicket()
        @details    this function closes the order for modifcation.
                    after this function is called, no items can be
                    added or removed from the ticket
    */
    void closeTicket();

private:
    static int NUM_ORDERS;

    map<int, OrderItem*> m_items;
    char*                m_orderDate;
    bool                 m_isOpen;
    int                  m_orderNum;

};
#endif
