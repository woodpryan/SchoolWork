#ifndef STATISTIC_H
#define STATISTIC_H

/*  Assignment:     Statistician Program
    Author:         Ryan Wood
    Date Created:   January  14, 2018
    Requirements:   Create a Statistic class that recieves numerical input
                    and calculates how many values have been input, the average
                    of all the values, the total of all the values, the largest
                    and smallest values, and allows the statistic to be cleared
                    for reuse
*/
/*Statistic Header file*/

class Statistic
{

    public:
        /*  Function:   Statistic()
            Purpose:    default constructor. Initializes the Statistic object
                        and creates an instant of the Statistic.
            Return:     the Statistic instance
        */
        Statistic();

        /*  Function:   initStat()
            Purpose:    initializes the member variables of the Statistic
                        to zero, clearing any previous values held
        */
        void initStat();

        /*  Function:   add(double)
            Purpose:    adds the given value to the statistics, adding the
                        value to the sum, incrementing the number of
                        values that have been added by one, and determining
                        a new largest or smallest as necessary
            Parameters: the value to add
        */
        void add(double val);

        /*  Function:   getLength()
            Purpose:    retrieves the number of values that have been added
            Return:     the number of values added
        */
        int getLength();

        /*  Function:   getSum()
            Purpose:    gets the sum of all values that 
                        have been added
            Return:     the sum
        */
        double getSum();

        /*  Function:   getAverage()
            Purpose:    retrieves the average of all the values 
                        that have been added
            Return:     the average
        */
        double getAverage();

        /*  Function:   getLargest()
            Purpose:    retrieves the largest value that has been
                        added to the statistics
            Return:     the largest value
        */
        double getLargest();

        /*  Function:   getSmallest()
            Purpose:    retrieves the smallest value that has been added to
                        the statistic
            Return:     the smallest
        */
        double getSmallest();


    private:
        /*  Function:   largest(double, double)
            Purpose:    determines which of the given values
                        is the largest
            Return:     the largest of the two values
        */
        double largest(double, double);

        /*  Function:   smallest(double, double)
            Purpose:    determines which of the given values
                        is the smaller value
            Return:     the smallest value
       */
        double smallest(double, double);

        double m_smallest;//the smallest value entered
        double m_largest;//the largest value entered
        double m_valTotal;//the total values entered
        int    m_numVals;//the number of values entered
};
#endif
