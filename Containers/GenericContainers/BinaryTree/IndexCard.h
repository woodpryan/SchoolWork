/*  @class     IndexCard.h
    Purpose    Defines the IndexCard class,
               which has a unique id, a keyword
               and a bit of text
    @author    Ryan Wood
    @date      8/28/2020
*/

#include <string>
#include <iostream>

using namespace std;

class IndexCard
{
    private:
        //keep track of how many IndexCards have been created
        static int NUM_CARDS;

        //member variables
        int    m_id;
        string m_keyword;
        string m_text;

    public:
        /** Function:   IndexCard()
            Purpose:    default constructor. Creates an empty Index Card
            @return     a blank card with a key
        */
        IndexCard();

        /** Function:      IndexCard(string, string)
            Purpose:       creates an index card with the given keyword and
                           text. The uinique ID depends on how many cards have
                           been created at this moment in program execution
            @param keyword the keyword
            @param text    the text
            @return        the index card
        */
        IndexCard(string strKeyword, string strText);

        /** Function:    IndexCard(IndexCard)
            Purpose:     copies the values of the given index card
                         into the member variables of this one
            @param other the index card to copy
            @return      the copy of the other card
        */
        IndexCard(const IndexCard &otherCard);

        /** Function:   ~IndexCard()
            Purpose:    destroys the index card, releaseing RAM
        */
        ~IndexCard();

        /** Function:    operator >(IndexCard)
            Purpose:     overloads the greater relational operator,
                         determining whether the
                         given Index Card is greater than this one by
                         the unique ID of the cards
            @param other the other card
            @return      whether the other card is greater
        */
        bool operator >(const IndexCard otherCard) const;

        /** Function:    operator >(IndexCard)
            Purpose:     overloads the less then relational operator,
                         determining whether the given Index Card
                         is less then than this one by the unique ID
                         of the cards
            @param other the other card
            @return      whether the other card is less then
        */
        bool operator < (const IndexCard otherCard) const;

        /** Function:    operator ==(IndexCard)
            Purpose:     overloads the equality relational operator,
                         determining whether the identifier of the
                         given index card is the same as this one
            @param other the other card
            @return      wehther the other card is equal
        */
        bool operator == (const IndexCard otherCard) const;

        /** Function:    operator =(IndexCard)
            Purpose:     overloads the copy operator,
                         calling the copy constructor of the
                         given other index
            @param other the other index card
        */
        void operator =(const IndexCard &otherCard);

        /** Function:   getId()
            Purpose:    retruns the unique identifier of the index card
            @return     the id
        */
        uint32_t getId() const;

        /** Function:   getKeyword()
            Purpose:    gets the value of the keyword
            @return     the keyword
        */
        string getKeyword() const;

        /** Function:   getText()
            Purpose:    retrieves the text of the index card
            @return     the text
        */
        string getText() const;

        /** Function:      setKeyword(string)
            Purpose:       sets the keyword of the index card to be the
                           given keyword string
            @param keyword the keyword
        */
        void setKeyword(string strKeyword);

        /** Function:   setText(string)
            Purpose:    sets the text of the index card to the given string
            @param text the text
        */
        void setText(string strText);

        /** Function:   operator<<(ostream, IndexCard)
            Purpose:    overloads the output stream operator and writes the Index Card
                        value to the given file or standard output stream
        */
        friend ostream &operator <<(ostream &out, const IndexCard &card);
};

