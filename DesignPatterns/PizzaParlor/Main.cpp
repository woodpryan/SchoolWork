#include <iostream>

#include "OrderManager.h"

using namespace std;

int main()
{
    OrderManager *orderMan = OrderManager::getInstance();
    int iONumA = 0;
    int iONumB = 0;
    int iONumC = 0;
    int iONumD = 0;
    int iINumA = 0;
    int iINumB = 0;
    int iINumC = 0;
    int iINumD = 0;
    int iINumE = 0;
    int iINumF = 0;
    int iINumG = 0;
    
    iONumA = orderMan->createOrder();
    iINumA = orderMan->addPizza(iONumA, FAMILY, MEAT_LOVERS);

    orderMan->addTopping(iONumA, iINumA, GREEN_PEPPER);
    orderMan->addTopping(iONumA, iINumA, ONIONS);

    iINumB = orderMan->addDrink(iONumA, SODA);
    iINumC = orderMan->addDrink(iONumA, BAD_BEER);
    iINumD = orderMan->addDrink(iONumA, BAD_BEER);

    iONumB = orderMan->createOrder();
    iINumE = orderMan->addPizza(iONumB, INDIVIDUAL);
    iINumF = orderMan->addDrink(iONumB, BAD_BEER);
    iINumG = orderMan->addMerch(iONumB, SHIRT);

    orderMan->print();
    cout << endl;

    orderMan->removeItem(iONumA, iINumB);
    orderMan->removeTopping(iONumA, iINumA, ONIONS);

    orderMan->print();
    cout << endl;

    orderMan->closeTicket(iONumA);

    cout << "Open Tickets" << endl;
    orderMan->printOpenTickets();
    cout << endl << endl;

    cout << "Closed Tickets" << endl;
    orderMan->printClosedTickets();
    cout << endl << endl;

    delete(orderMan);

    return 0;
}
