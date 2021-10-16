/*  Assignment:     Binary Tree
 *  Author:         Ryan Wood
 *  Date Created:   8/29/2020
 */
/*Binary Tree Main file*/

#include <iostream>
#include <fstream>
#include <string>

#include "BinaryTree.cpp"
#include "IndexCard.h"

using namespace std;

ifstream inFile("TreeRandNbrs.dat");
ofstream outFile("TreeOutput.out");

/*  Function:   buildTree(BinaryTree&)
 *  Purpose:    builds the binary tree using the values
 *              stored in the input file
 *  Parameters: a reference to a binary tree
 */
void buildTree(BinaryTree<IndexCard> &bt)
{
    IndexCard *iCard      = NULL;
    string     strKeyword = "";
    string     strValue   = "";
    int        count      = 0;

    while(inFile >> strKeyword)
    {
        inFile >> strValue;
        iCard = new IndexCard(strKeyword, strValue);
        bt.insert(*iCard);
        count++;
    }
    cout << "found " << count << " index cards in the file." << endl;
}

/*  Function:   testBinaryTreeFunctions(BinaryTree&)
 *  Purpose:    tests all the binary tree functions besides
 *              insert.
 *  Parameters: the Binary Tree
 */
void testBinaryTreeFunctions(BinaryTree<IndexCard> &bt)
{
    outFile << "printInOrder" << endl;
    bt.inorder(outFile);
    outFile << endl;

    outFile << "printPreOrder" << endl;
    bt.preorder(outFile);
    outFile << endl;

    outFile << "printPostOrder" << endl;
    bt.postorder(outFile);
    outFile << endl;

    outFile << "NumNodesLeft ";
    outFile << bt.numValsLeft();
    outFile << endl;

    outFile << "numNodesRight ";
    outFile << bt.numValsRight();
    outFile << endl;

    outFile << "numNodes" << endl;
    outFile << bt.getNumNodes() << endl << endl;

    outFile << "numLeaves" << endl;
    outFile << bt.numLeaves();
    outFile << endl;

    outFile << "deepest level value" << endl;
    outFile << bt.getDeepestTreeValue();
    outFile << endl;

    outFile << "Number of parents with only one child" << endl;
    outFile << bt.numSingleChildren();
    outFile << endl;

}

int main()
{
    BinaryTree<IndexCard> bt;

    if(!inFile)
    {
        cout << "No input file!" << endl;
        outFile.close();
        return -1;
    }

    buildTree(bt);
    testBinaryTreeFunctions(bt);

    return 0;
}

