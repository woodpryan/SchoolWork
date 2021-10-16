/*  Assignment:     Tree Work Out
 *  Author:         Ryan Wood
 *  Date Created:   4/14/2017
 *  Last Modified:  4/1/2018
 *  Requirements:   Create a binary tree class that includes the functions
 *                  specified in Tree Work Out program specification
 */
/*Binary Tree Main file*/

#include <iostream>
#include <fstream>

#include "BinaryTree.h"

using namespace std;

ifstream inFile("TreeRandNbrs.dat");
ofstream outFile("TreeOutput.out");

int values[150];

/*  Function:   buildTree(BinaryTree&)
 *  Purpose:    builds the binary tree using the values
 *              stored in the input file
 *  Parameters: a reference to a binary tree
 */
void buildTree(BinaryTree &bt)
{
    int num   = 0;
    int count = 0;

    while(inFile >> num)
    {
        values[count] = num;
        bt.insert(num);
        count++;
    }
}

/*  Function:   sumOfDigits(int)
    Purpose:    recursive function that takes each digit of the
                given number and adds them up, returning the
                resulting sum of the digits
    Parameters: the number
    Return:     the sum of the digits of the number
*/
int sumOfDigits(int num)
{
    if(num <= 0)
        return 0;
    else
        return (num % 10) + sumOfDigits(num/10);
}

/*  Function:   testBinaryTreeFunctions(BinaryTree&)
 *  Purpose:    tests all the binary tree functions besides
 *              insert. Satisfies the requirements of the
 *              requirements specification
 *  Parameters: the Binary Tree
 */
void testBinaryTreeFunctions(BinaryTree &bt)
{
    int count = 0;
    int val   = 0;

    /*Satisfies requirement a.*/
    outFile << "printInOrder" << endl;
    bt.printInOrder(outFile);
    outFile << endl;

    /*Satisfies requirement b.*/
    outFile << "printPreOrder" << endl;
    bt.printPreOrder(outFile);
    outFile << endl;

    /*Satisfies requirement c.*/
    outFile << "printPostOrder" << endl;
    bt.printPostOrder(outFile);
    outFile << endl;

    /*Satisfies requirement d.*/
    outFile << "numNodes" << endl;
    outFile << bt.getNumNodes() << endl << endl;

    /*Satisfies requirement e.*/
    outFile << "sumNodes" << endl;
    outFile << bt.sumValues();
    outFile << endl;

    /*Satisfies requirement f.*/
    outFile << "numLeaves" << endl;
    outFile << bt.numLeaves();
    outFile << endl;

    /*satisfies requirement g.*/
    outFile << "deepest level value" << endl;
    outFile << bt.getDeepestTreeValue();
    outFile << endl;

    /*Satisfies requirement h.*/
    outFile << "Number of parents with only one child" << endl;
    outFile << bt.numSingleChildren();
    outFile << endl;

    /*Satisfies requirement i.*/
    outFile << "SubTree of node value 299 " << endl;
    bt.printInOrder(bt.search(299), outFile);
    outFile << endl;

    /*Satisfies requirement j.*/
    outFile << "Right subtree of node with value of 253 in postOrder." << endl;
    TreeNode *node = bt.search(253);
    if(NULL != node)
    {
        bt.printPostOrder(node->right, outFile);
    }
    outFile << endl;

    /*Satisfies requirement k*/
    outFile << "NumNodesLeft ";
    outFile << bt.numValsLeft();
    outFile << endl;

    outFile << "numNodesRight ";
    outFile << bt.numValsRight();
    outFile << endl;

    outFile << "Removing values: ";
    /*Satisfy requirements creep for deltions*/
    for(count = 0; count < 150; count++)
    {
        val = values[count];
        if(sumOfDigits(val) < 10)
        {
            bt.remove(val);
            outFile << val << " ";
        }
    }
    outFile << "After deleting all values with a digit sum less than ten "
            << "there are " << bt.getNumNodes() << " remaining." << endl;

    bt.printInOrder(outFile);
    outFile << endl;
}

int main()
{
    BinaryTree bt;

    if(!inFile)
    {
        cout << "No input file!" << endl;
        outFile.close();
        return -1;
    }

    buildTree(bt);
    testBinaryTreeFunctions(bt);

    inFile.close();
    outFile.close();
    
    return 0;
}
