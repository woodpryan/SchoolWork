/*  Assignment:     Tree Work Out
 *  Author:         Ryan Wood
 *  Date Created:   4/14/2017
 *  Last Modified:  4/1/2018
 *  Requirements:   Create a binary tree class that includes the functions
 *                  specified in Tree Work Out program specification
 */
/*Binary Tree implementation file*/


#include "BinaryTree.h"
#include <iostream>
#include <fstream>

using namespace std;
//private:
//TreeNode *root;

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if(NULL == nodePtr)
    {
        nodePtr = newNode;//base case, insert the node
    }
    else if(newNode->val < nodePtr->val)//case left, call insert on left
    {
        insert(nodePtr->left, newNode);
    }
    else//otherwise call insert on node right
    {
        insert(nodePtr->right, newNode);
    }
}

void BinaryTree::destroySubTree(TreeNode *tn)
{
    if(NULL != tn)
    {
        destroySubTree(tn->left);
        destroySubTree(tn->right);
        delete(tn);
    }
}

//public:
BinaryTree::BinaryTree()
{
    root = NULL;
}

TreeNode *BinaryTree::newNode()
{
    TreeNode *tn = new TreeNode;
    tn->left = NULL;
    tn->right = NULL;
    tn->val = 0;

    return tn;
}

TreeNode *BinaryTree::newNode(int val)
{
    TreeNode *tn = newNode();
    
    tn->val = val;
    
    return tn;
}

void BinaryTree::insert(int val)
{
    TreeNode *node = newNode(val);

    insert(root, node);
}

TreeNode *BinaryTree::remove(TreeNode *root, int val)
{
    TreeNode *tmp = NULL;
    if(root == NULL)
        return tmp;

    if(val < root->val)// data is in the left sub tree.
        root->left = remove(root->left, val);
    else if(val > root->val)//data is in the right sub tree.
        root->right = remove(root->right, val);
    else
    {
        //case 1: the node has no children
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //case 2: node has one right child
        else if(root->left == NULL)
        {
            tmp  = root;
            root = root->right;
            delete tmp;
        }
        //case 3: node has one left child
        else if(root->right == NULL)
        {
            tmp  = root;
            root = root->left;
            delete tmp;
        }
        //case 4: the node has two children
        else
        {
            //find the maximum of the left subtree
            tmp         = getRightmostNode(root->left, NULL);
            root->val   = tmp->val;//duplicate the node
            root->left = remove(root->left, tmp->val);//delete the duplicate node
        }
    }
    return root;//parent node can update reference
}

TreeNode *BinaryTree::remove(int val)
{
    return remove(root, val);
}

TreeNode *BinaryTree::search(TreeNode *tn, int val)
{
    if(NULL == tn)
        return tn;//base case 1, never found
    else if(tn->val == val)
        return tn;//base case 2, found match
    else if(val < tn->val)
        return search(tn->left, val);
    else //if(val > tn->val)
        return search(tn->right, val);
}

TreeNode *BinaryTree::search(int val)
{
    return search(root, val);
}

void BinaryTree::printInOrder(TreeNode *tn, ofstream &out)
{
    if(NULL != tn)
    {
        printInOrder(tn->left, out);
        out << tn->val << endl;
        printInOrder(tn->right, out);
    }
}

void BinaryTree::printPreOrder(TreeNode *tn, ofstream &out)
{
    if(NULL != tn)
    {
        out << tn->val << endl;
        printPreOrder(tn->left, out);
        printPreOrder(tn->right, out);
    }
}

void BinaryTree::printPostOrder(TreeNode *tn, ofstream &out)
{
    if(NULL != tn)
    {
        printPostOrder(tn->left, out);
        printPostOrder(tn->right, out);
        out << tn->val << endl;
    }
}

int BinaryTree::getNumNodes(TreeNode *node)
{
    if(NULL == node)
    {
        return 0;
    }
    else
    {
        return 1 + getNumNodes(node->left) + getNumNodes(node->right);
    }
}

int BinaryTree::sumValues(TreeNode *node)
{
    if(NULL == node)
    {
        return 0;
    }
    else
    {
        return node->val + sumValues(node->left) + sumValues(node->right);
    }
}

int BinaryTree::sumValues()
{
    return sumValues(root);
}

int BinaryTree::getNumNodes()
{
    return getNumNodes(root);
}

double BinaryTree::getAverage()
{
    int sum   = sumValues(root);
    int count = getNumNodes();

    if(count == 0)
    {
        return 0;
    }
    else
    {
        return (double) sum / count;
    }
    
}

TreeNode *BinaryTree::getLeftmostNode(TreeNode *node, TreeNode *prev)
{
    if(NULL == node)
        return prev;
    else
    {
        prev = node;
        return getLeftmostNode(node->left, prev);
    }
}

TreeNode *BinaryTree::getRightmostNode(TreeNode *node, TreeNode *prev)
{
    if(NULL == node)
        return prev;
    else
    {
        prev = node;
        return getRightmostNode(node->right, prev);
    }
}


int BinaryTree::getDeepestTreeValueLeft(TreeNode *node, TreeNode *prev, int &level)
{
    if(NULL == node)
    {
        if(NULL == prev)
        {
            return 0;
        }
        else
        {
            return prev->val;
        }
    }
    else
    {
        level++;
        prev = node;
        return getDeepestTreeValueLeft(node->left, prev, level);
    }
}

int BinaryTree::getDeepestTreeValueRight(TreeNode *node, TreeNode *prev, int &level)
{
    if(NULL == node)
    {
        if(NULL == prev)
        {
            return 0;
        }
        else
        {
            return prev->val;
        }
    }
    else
    {
        level++;
        prev = node;
        return getDeepestTreeValueRight(node->right, prev, level);
    }
}
int BinaryTree::getDeepestTreeValue()
{
    int levelLeft  = 0;
    int levelRight = 0;
    int valLeft    = 0;
    int valRight   = 0;

    valLeft = getDeepestTreeValueLeft(root, NULL, levelLeft);
    valRight = getDeepestTreeValueRight(root, NULL, levelRight);

    if(levelLeft > levelRight)
    {
        return valLeft;
    }
    else if(levelRight > levelLeft)
    {
        return valRight;
    }
    else
    {
        return valLeft;//if levels are equal, return one of the values
    }

}

int BinaryTree::numValsLeft(TreeNode *tn)
{
    if(NULL != tn && NULL != tn->left)
    {
        return getNumNodes(tn->left);
    }
    else
    {
        return 0;
    }
}

int BinaryTree::numValsRight(TreeNode *tn)
{
    if(NULL != tn && NULL != tn->left)
    {
        return getNumNodes(tn->right);
    }
    else
    {
        return 0;
    }
    
}

int BinaryTree::numValsLeft()
{
    return numValsLeft(root);
}

int BinaryTree::numValsRight()
{
    return numValsRight(root);
}

int BinaryTree::numLeaves(TreeNode *node)
{
    if(NULL == node)
    {
        return 0;
    }
    if(node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    else
    {
        return numLeaves(node->left) + numLeaves(node->right);
    }
}

int BinaryTree::numLeaves()
{
    return numLeaves(root);
}

int BinaryTree::numSingleChildren(TreeNode *node)
{
    if(NULL == node)
    {
        return 0;
    }
    else if(NULL == node->left && NULL != node->right)
    {
        return 1 + numSingleChildren(node->right);
    }
    else if(NULL == node->right && NULL != node->left)
    {
        return 1 + numSingleChildren(node->left);
    }
    else
    {
        return numSingleChildren(node->left) + numSingleChildren(node->right);
    }
}

int BinaryTree::numSingleChildren()
{
    return numSingleChildren(root);
}
