#ifndef THROTTLE_H
#define THROTTLE_H

/*  Assignment:     Throttle Class
    Author:         Ryan Wood
    Date Created:   January 13, 2018
    Requirements:   implement the Throttle class from the book 
                    with the addition of a maximum throttle amount
*/
/*Throttle header file*/

class Throttle
{

    public:
        /*  Function:   Throttle()
            Purpose:    default constructor, creates 
                        an instance of Throttle with maxPosition
                        set to 6 and curPosition set to 0
            Return:     the Throttle instance
        */
        Throttle();

        
        /*  Function:   Throttle(int)
            Purpose:    constructor, creates an instance of Throttle with
                        maxPosition set to max ans curPosition set to 0
            Return:     the Throttle instance
        */
        Throttle(int);

        /*  Function:   Throttle(int, int)
            Purpose:    constructor, creates an instance of Throttle with
                        maxPosition set to max and curPosition set to cur
            Parameters: the current position, the max position
            Return:     the Throttle instance
        */
        Throttle(int, int);

        /*  Function:   shutOff()
            Purpose:    sets curPosition to 0
        */
        void shutOff();

        /*  Function:   shift(int)
            Purpose:    increments curPosition by the given amount
            Parameters: the amount to shift
        */
        void shift(int);

        /*  Function:   isOn()
            Purpose:    determines whether the curPosition is
                        greater than zero
            Return:     whether Throttle is on
        */
        bool isOn();

        /*  Function:   flow()
            Purpose:    determines how much throttle there currently
                        is as a percentage of max throttle.
            Return:     the percentage throttle
        */
        double flow();

    private:
        int maxPosition;//maximum throttle
        int curPosition;//current throttle
};

#endif
