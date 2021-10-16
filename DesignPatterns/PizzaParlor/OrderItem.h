#ifndef ORDER_ITEM_H
#define ORDER_ITEM_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ItemType.h"

class OrderItem
{
public:
    virtual ~OrderItem(){}
    virtual void     setPrice(double iPrice) = 0;
    virtual double   getPrice() = 0;
    virtual int      getItemNum() = 0;
    virtual ItemType getItemType() = 0;
    virtual void     setItemType(ItemType type) = 0;
    virtual void     print() = 0;
};
#endif
