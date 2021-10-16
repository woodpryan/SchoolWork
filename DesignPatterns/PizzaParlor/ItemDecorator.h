#ifndef ITEM_DECORATOR
#define ITEM_DECORATOR

/*  @class      ItemDecorator
    @author     Ryan Wood
    @date       November 28, 2020
    @details    this class holds an Order Item
                to be decorated. Classes inheriting this
                class implement the OrderItem interface
                and decorates the Item class
*/

#include "OrderItem.h"

class ItemDecorator : public OrderItem
{
    public:
        /** Function:   ItemDecorator(OrderItem*)
            @details    this constructor takes an OrderItem and sets
                        its OrderItem member to it
        */
        ItemDecorator(OrderItem *item):m_item(item){}

        /** Function:   ~ItemDecorator()
            @details    this destructor deletes the OrderItem member
        */
        ~ItemDecorator(){delete(m_item);}
    protected:
        OrderItem *m_item;
};

#endif
