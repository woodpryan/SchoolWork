#include <iostream>

#include "Item.h"

using namespace std;

int Item::NUM_ITEMS = 0;

Item::Item()
{
    m_itemNum = NUM_ITEMS;
    NUM_ITEMS++;
}

void Item::setPrice(double iPrice)
{
    m_price = iPrice;
}

double Item::getPrice()
{
	return m_price;
}

int Item::getItemNum()
{
	return m_itemNum;
}

void Item::setItemType(ItemType type)
{
    m_itemType = type;
}

ItemType Item::getItemType()
{
    return m_itemType;
}

void Item::print()
{
    cout << m_itemNum << "\t" << m_price;
}
