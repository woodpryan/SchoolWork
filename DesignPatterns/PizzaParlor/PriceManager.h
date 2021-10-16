#ifndef PRICE_MANAGER_H
#define PRICE_MANAGER_H

/** @class      PriceManger
    @author     Ryan Wood
    @date       November 28, 2020
    @details    this class serves as a central place to put price
                details for the pizza parlor. A future improvement
                could be to read the pricing from a file. For now,
                the prices are all hard-coded here in static constants.
                Implements the singleton design pattern
*/

#include "SpecialtyType.h"
#include "PizzaSize.h"
#include "DrinkType.h"
#include "MerchType.h"
#include "ToppingType.h"

static const double PIZZA_MARGHARITA =  7.99;
static const double PIZZA_HAWAIIN    =  8.99;
static const double PIZZA_MEAT       =  9.99;
static const double PIZZA_FAMILY     =  5.99;
static const double PIZZA_INDIVIDUAL = -3.99;

static const double TOPPING_CHEESE       = 0.0;
static const double TOPPING_HAM          = 0.75;
static const double TOPPING_PEPPERONI    = 0.99;
static const double TOPPING_GREEN_PEPPER = 0.89;
static const double TOPPING_ONIONS       = 0.89;
static const double TOPPING_MUSHROOMS    = 0.89;
static const double TOPPING_PINEAPPLE    = 0.99;

static const double DRINK_SODA      = 1.29;
static const double DRINK_DIET_SODA = 1.29;
static const double DRINK_BAD_BEER  = 4.99;

static const double MERCH_SHIRT = 21.99;
static const double MERCH_MUG   = 4.99;

class PriceManager
{
    public:
        /** Function:   getInstance() static PriceManger*
            @details    this function returns the PriceManager instance
                        or creates an instance and returns it
            @return     the price manager
        */
        static PriceManager* getInstance();

        /** Functino:   getPrice(SpecialtyType, PizzaSize) double
            @details    returns the price of a pizza having the given type and size
            @param      type the Specialty type as any of enum SpecialtyType
            @param      size the pizza size as any of enum PizzaSize
            @return     the pizza price
        */
        double getPrice(SpecialtyType type, PizzaSize size);

        /** Function:   getPrice(MerchType) double
            @details    this function returns the price of a Merchandise
                        item having the given type
            @param      type the merch type as any of enum MerchType
            @return     the price
        */
        double getPrice(MerchType type);

        /** Function:   getPrice(DrinkType) double
            @details    this function returns the price of a drink having the
                        given type
            @param      type the drink type as any of enum DrinkType
            @return     the price
        */
        double getPrice(DrinkType type);

        /** Function:   getPrice(ToppingType) double
            @details    this function returns the price of a topping having the given
                        topping type
            @param      type the topping type as any of enum ToppingType
            @return     the price
        */
        double getPrice(ToppingType type);
    private:
        /** Function:   PriceManager()  PriceManager
            @details    default constructor
        */
        PriceManager();
        static PriceManager *priceManager;
};

#endif
