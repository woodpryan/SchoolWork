#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

/** @class      ItemFactory
    @author     Ryan Wood
    @date       November 28, 2020
    @details    ItemFactory contains member functions to create Pizza Parlor
                items - pizzas, drinks, merchandise, and toppings.
                The methods are all static, called as ItemFactory::createItem().
*/

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Pizza.h"
#include "Drink.h"
#include "Merch.h"
#include "Topping.h"

class ItemFactory
{
public:
        /** Function:   *createPizza(PizzaSize) Pizza
            @details    creates a Pizza having the given size, returning the Pizza item
            @param      size the pizza size as any of PizzaSize
            @return     the specified pizza
        */
        static Pizza   *createPizza(PizzaSize size);

        /** Function:   *createPizza(PizzaSize, SpecialtyType) Pizza
            @details    creates a Pizza having the given size and specialty
                        type, returning the Pizza item
            @param      size the pizza size as any of PizzaSize
            @param      specialty the specialty type
            @return     the specified pizza
        */
        static Pizza   *createPizza(PizzaSize size, SpecialtyType special);

        /** Function:   *createDrink(DrinkType) Drink
            @details    creates a drink of the given type, returning the Drink
            @return     the specified drink as any of enumberation DrinkType
        */
        static Drink   *createDrink(DrinkType type);

        /** Function:   *createMerch(MerchType) Merch
            @param      type the merchandise type as any of enumeration MerchType
            @return     the specified merch
        */
        static Merch   *createMerch(MerchType type);

        /** Functino:   *createTopping(ToppingType) Topping
            @details    creates a topping having the given topping type
            @param      type the topping type as any of ToppingType enum
            @return     the specified topping
        */
        static Topping *createTopping(ToppingType type);
private:
    /** Function:   ItemFactory() ItemFactory
        @details    private default constructor, ensuring class cannot be enstantiated
    */
    ItemFactory();

    /** Function:   ItemFactory(ItemFactory&) ItemFactory
        @details    private default copy constructor, ensuring class cannot be enstantiated
    */
    ItemFactory(const ItemFactory&);

    /** Function:   &operator=(ItemFactory&) ItemFactory
        @details    private default assignment operator override,
                    ensuring class cannot be enstantiated
    */
    ItemFactory &operator=(const ItemFactory&);
};
#endif
