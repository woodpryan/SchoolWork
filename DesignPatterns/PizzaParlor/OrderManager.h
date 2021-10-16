#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

/**
    @class      OrderManager
    @author     Ryan Wood
    @date       November 11, 2020
    @details    This class provides an interface for a Pizza parlor to
                manage orders, adding or removing items, printing tickets
                or closing them, etc. This class implements the singleton
                design pattern.
*/

#include <string>
#include <iostream>
#include <map>

#include "OrderItem.h"
#include "Pizza.h"
#include "ItemDecorator.h"
#include "Topping.h"
#include "Merch.h"
#include "Drink.h"
#include "Order.h"

class OrderManager
{
public:
    /** Function:   getInstance() OrderManager static* 
        @details    this function creates an instance of OrderManager if there
                    is not one currently and returns it. Returns the previously
                    created instance if there is already one.
        @return     the OrderManager
    */
	OrderManager static* getInstance();

    ~OrderManager();

    /** Function:   createOrder() int
        @details    this function creates a new order and returns the order number
                    which is used to access the order
        @return     the order number unique id
    */
	int createOrder();

    /** Function:   addPizza(int, PizzaSize) int
        @details    this function adds a pizza to the order having the given
                    unique id. The pizza will have the given pizza size.
                    the Pizza item's unique ID is returned
        @param      iOrderNum the order number
        @param      size the pizza size as any of enumeration PizzaSize
        @return     the pizza item id
    */
	int addPizza(int iOrderNum, PizzaSize size);

    /** Function:   addPizza(int, PizzaSize, SpecialtyType) int
        @details    this function adds a pizza to the order having the given
                    unique id. The pizza will have the given pizza size and
                    will be of the given specialty type.
                    The Pizza item's unique ID is returned
        @param      iOrderNum the order number
        @param      size the pizza size as any of enumeration PizzaSize
        @param      specialty the specialty type as any of enumeration SpecialtyType
        @return     the pizza item id
    */
	int addPizza(int iOrderNum, PizzaSize size, SpecialtyType special);

    /** Function:   addTopping(int, int, ToppingType)
        @detals     This function adds a topping to a pizza having the given item
                    number in the order having the given order number. The topping
                    will be of the given topping type.
        @param      iOrderNum the order number
        @param      iPizzaId the pizza id
        @param      toppingType the topping type as any of enumeration ToppingType
    */
	void addTopping(int orderNum, int itemNum, ToppingType type);

    /** Function:   addDrink(int, DrinkType) int
        @details    this function adds a drink to the order having the given order
                    number. The drink will be of the given type.
                    The drink items unique id is returned.
        @param      iOrderNum the order number
        @param      type the drink type as any of enumeration DrinkType
        @return     the item id of the drink
    */
	int addDrink(int iOrderNum, DrinkType type);

    /** Function:   addMerch(int, MerchType) int
        @details    this function adds merchandise to the order having the given
                    order number. The merchandise will be of the given type,
                    and its unique item ID is returned
        @param      iOrderNum the order number
        @param      type the merch type as any of enumeration MerchType
        @return     the item id of the merch
    */
    int addMerch(int iOrderNum, MerchType type);

    /** Function:   removeItem(int, int) bool
        @details    this function removes the item having the given item number
                    from the order having the given order number
        @param      iOrderNum the order number
        @param      iItemNum the item number
        @return     whether the item was found in the order and removed
    */
	bool removeItem(int iOrderNum, int iItemNum);

    /** Function:   removeTopping(int, int, ToppingType) bool
        @details    this function removes the topping of the given
                    topping type from the pizza having the given item
                    number from the order having the given order number.
        @param      iOrderNum the order number
        @param      iPizzaId the pizza id
        @param      toppingType the topping type as any of enumeration ToppingType
        @return     whether the topping was found and removed
    */
	bool removeTopping(int iOrderNum, int iItemNum, ToppingType topTyp);
    
    /** Function:   printTicket(int)
        @details    this function prints the order having the
                    given order number, listing all of the
                    items on the order, the order number
                    and the total of the order
    */
	void printTicket(int iOrderNum);

    /** Funtion:    getTotal(int) double
        @details    this function retrieves the total of all items in the
                    order having the given order number.
        @param      iOrderNum the order number
        @return     the order total
    */
    double getTotal(int iOrderNum);

    /** Function:   closeTicket(int)
        @details    this function closes the order having the given number,
                    which disallows any further modification of the order
        @param      iOrderNum the order number
    */
    void closeTicket(int iOrderNum);

    /** Function:   printClosedTickets()
        @details    this function prints all of the orders having a status of closed
    */
    void printClosedTickets();
    
    /** Function:   printOpenTickets()
        @details    this function prints the orders having a status of open
    */
    void printOpenTickets();

    /** Function:   print()
        @details    this function prints all of the tickets, open or closed
    */
    void print();

private:
	map<int, Order*> m_orders;

    Order *getOrder(int orderNum);
    OrderManager();
	static OrderManager* m_orderManager;
};
#endif
