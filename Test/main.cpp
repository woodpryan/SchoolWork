#include <iostream>

using namespace std;

class Test
{
    int *m_val;
    int m_length;

    public:

        Test()
        {
            m_val = new int;
        }

        //parameterized constructor
        Test(int *val, int len)
        {
            setVal(val, len);
        }

        void deepCopy(const Test &other)
        {
            setVal(other.getVal(), other.getLen());
        }

        ~Test()
        {
            if(m_val)
            {
                delete[] m_val;
                m_val = NULL;
            }
        }
        //get the value
        int *getVal() const
        {
            return m_val;
        }

        int getLen() const
        {
            return m_length;
        }

        //set the value
        void setVal(int *val, int len)
        {
            if(m_val)
            {
                delete[] m_val;
                m_val = NULL;
            }

            m_length = len;
            m_val    = new int[m_length];

            for(int i = 0; i < m_length; ++i)
            {
                m_val[i] = val[i];
            }
        }

        void print()
        {
            for(int i = 0; i < m_length; ++i)
            {
                cout << m_val[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    int i[]  = {3, 2};
    int i2[] = {5, 6, 7, 8};

    Test tstA(i, 2);
    Test tstB(tstA);
    Test tstC;

    tstC.deepCopy(tstA);

    tstA.setVal(i2, 4);
    tstA.print();
    tstB.print();
    tstC.print();

    return 0;
}
