#include <iostream>
#include <string>
#include "IndexCard.h"

using namespace std;

int IndexCard::NUM_CARDS = 0;

IndexCard::IndexCard()
{
    IndexCard("", "");
}

IndexCard::IndexCard(string strKeyword, string strText)
{
    m_id      = NUM_CARDS++;
    m_keyword = strKeyword;
    m_text    = strText;
}

IndexCard::IndexCard(const IndexCard &otherCard)
{
    m_id      = otherCard.getId();
    m_keyword = otherCard.getKeyword();
    m_text    = otherCard.getText();
}

IndexCard::~IndexCard()
{
}

bool IndexCard::operator >(const IndexCard otherCard) const
{
    return (m_id > otherCard.getId());
}

bool IndexCard::operator <(const IndexCard otherCard) const
{
    return (m_id < otherCard.getId());
}

void IndexCard::operator =(const IndexCard &otherCard)
{
    m_id      = otherCard.getId();
    m_keyword = otherCard.getKeyword();
    m_text    = otherCard.getText();
}

bool IndexCard::operator == (const IndexCard otherCard) const
{
    return m_id == otherCard.getId();
}

uint32_t IndexCard::getId() const
{
    return m_id;
}

string IndexCard::getKeyword() const
{
    return m_keyword;
}

string IndexCard::getText() const
{
    return m_text;
}

void IndexCard::setKeyword(string strKeyword)
{
    m_keyword = strKeyword;
}

void IndexCard::setText(string strText)
{
    m_text = strText;
}

ostream& operator <<(ostream &out, const IndexCard &card)
{
    out << card.getId() << ":" << card.getKeyword() << "\t" << card.getText();
    return out;
}

