#include <string>

#include "Merch.h"

void Merch::setPrice(double dPrice)
{
    m_item->setPrice(dPrice);
}

double Merch::getPrice()
{
    return m_item->getPrice();
}

MerchType Merch::getType()
{
	return m_merchType;
}

int Merch::getItemNum()
{
	return m_item->getItemNum();
}

std::string Merch::toString(MerchType mType)
{
    switch(mType)
    {
        case MUG:
            return "Mug";
        case SHIRT:
            return "Shirt";
        default:
            return "";
    }
}

void Merch::print()
{
    std::cout << m_item->getItemNum() << "\t";
    std::cout << toString(m_merchType) << "\t";
    std::cout << m_item->getPrice();
}

void Merch::setItemType(ItemType type)
{
    m_item->setItemType(type);
}

ItemType Merch::getItemType()
{
    return m_item->getItemType();
}
