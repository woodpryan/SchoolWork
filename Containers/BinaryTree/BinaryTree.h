/*  Assignment:     Tree Work Out
 *  Author:         Ryan Wood
 *  Date Created:   4/14/2017
 *  Last Modified:  4/1/2018
 *  Requirements:   Create a binary tree class that includes the functions
 *                  specified in Tree Work Out program specification
 */
/*Binary Tree Header file*/

#include <iostream>
#include <fstream>

using namespace std;

/*TreeNode structure. One value. One left leaf and on right leaf*/
struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTree
{
    private:
        TreeNode *root;

        /*  Function:   insert(TreeNode*&, TreeNode *&)
         *  Purpos:     inserts the given new node to the left
         *              or to the right of the given node.
         *              Recursive function, calls itself until
         *              it finds a null node left or right
         *  Parameters: the node after which the new node should be placed,
         *              the new node with a value and null left and right nodes
         */
        void insert(TreeNode *&node, TreeNode *&newNode);
        
        /*  Function:   getLeftmostNode(TreeNode*, TreeNode*)
            Purpose:    For the given node, this function determines which
                        node of the subtree has no left link, the final
                        left value in the subtree
            Parameters: the node, the parent of the node if it is to be considered
                                    or a NULL TreeeNode
            Return:     the leftmost node of the subtree
        */
        TreeNode *getLeftmostNode(TreeNode *tn, TreeNode *prev);

        /*  Function:   getRightmostNode(TreeNode*, TreeNode*)
            Purpose:    for the given subtree, this function determines
                        what is the node with the largest value, in
                        other words the rightmost node in the subtree
            Parameters: the node, the parent if it is to be considered
                                    or a NULL TreeNode
            Return:     The rightmost node of the subtree
        */
        TreeNode *getRightmostNode(TreeNode *tn, TreeNode *prev);

        /*  Function:   remove(TreeNode*, int val)
            Purpose:    for the given node (subtree), searches the tree for the given
                        value and removes that node from the tree
            Parameters: the node, the value
            Return:     a copy of the node that is replaced
        */
        TreeNode *remove(TreeNode* tn, int val);

        /*  Function:   destroySubTree(TreeNode*)
         *  Purpose:    deletes all members of the tree from the given node
         *              through all of its children. Recursive
         *  Parameters: the sub tree root node
         */
        void destroySubTree(TreeNode *tn);

        /*  Function:   numValsLeft(TreeNode*)
         *  Purpose:    calculates the number of values to the left
         *              of the given subtree node. Recursive
         *  Parameters: the subtree root node
         *  Return:     the number of values in the tree's left subtree
         */
        int numValsLeft(TreeNode *tn);

        /*  Function:   numValsRight(TreeNode*)
         *  Purpose:    calculates the number of values to the right of
         *              the given subree node. Recursive
         *  Parameters: the subtree root node
         *  Return:     the number of values in the tree's right subtree
         */
        int numValsRight(TreeNode *tn);

        /*  Function:   getNumNodes(TreeNode*)
         *  Purpose:    calculates the number of nodes in the
         *              given subtree. Recursive
         *  Parameters: the subtree root node
         *  Return:     The number of nodes of the subtree
         */
        int getNumNodes(TreeNode *tn);

        /*  Function:   sumValues(TreeNode*)
         *  Purpose:    Adds up all the values in the
         *              given subtree. Recursive
         *  Parameters: the root node of the sub tree
         *  Return:     the sum of the values in the sub tree
         */
        int sumValues(TreeNode *tn);

        /*  Function:   getAverage(TreeNode*)
         *  Purpose:    calculates the average of all the values
         *              in the given subtree
         *  Parameters: the subtree root node
         *  Return:     the average value in the subtree
         */
        double getAverage(TreeNode *tn);

        /*  Function:   *search(TreeNode*, int)TreeNode
         *  Purpose:    searches the given subtree for the
         *              given value recursively. Gives back
         *              the node having the value if it is found.
         *  Parameters: the root node of the sub tree
         *  Return:     the node having the value or NULL if not found
         */
        TreeNode *search(TreeNode *tn, int val);

        /*  Function:   getDeepestTreeValueLeft(TreeNode*, TreeNode*, int&)
         *  Purpose:    Determines the value on the given subtree's left
         *              subtree that is at the deepest level of the subtree.
         *              Sets the given level value to the level where it finds
         *              this value. Recursive
         *  Parameters: the root node of the subtree, the previous root node (or NULL),
         *              the level value, starting at zero
         *  Return:     the value at the deepest level of the subtree
         */
        int getDeepestTreeValueLeft(TreeNode *tn, TreeNode *prev, int &level);

        /*  Function:   getDeepestTreeValueRight(TreeNode*, TreeNode*, int&)
         *  Purpose:    Determines the value on the given subtree's right 
         *              subtree that is at the deepest level of the subtree.
         *              Sets the given level value to the level where it finds
         *              this value. Recursive
         *  Parameters: the root node of the subtree, the previous root node (or NULL),
         *              the level value, starting at zero
         *  Return:     the value at the deepest level of the subtree
         */
        int getDeepestTreeValueRight(TreeNode *tn, TreeNode *prev, int &level);

        /*  Function:   numLeaves(TreeNode*)
         *  Purpose:    gets the number of leaves of the subtree. Recursive
         *  Parameters: the root node of the subtree
         *  Return:     the number of nodes in the subtree
         */
        int numLeaves(TreeNode *node);

        /*  Function:   numSingleChildren(TreeNode*)
         *  Purpose:    determines the number of parents in the tree that
         *              have only one child. In other words, determines the
         *              number of nodes in the sub tree having no siblings
         *              Recursive function
         *  Parameters: the root node of the sub tree
         *  Return:     the number of children with no siblings
         */
        int numSingleChildren(TreeNode *node);

    public:
        /*  Function:   BinaryTree()
         *  Purpose:    default constructor of the BinaryTree class.
         *              Sets the root of the tree to NULL
         */
        BinaryTree();

        /*  Function:   ~BinaryTree()
         *  Purpose:    destructor for the BinaryTree class.
         *              Simply calls destroySubTree on the tree root
         */
        ~BinaryTree()
        {destroySubTree(root);}

        /*  Function:   *newNode()
         *  Purpose:    creates a new node with NULL left and right
         *              leaves and a zero value.
         *  Return:     an empty TreeNode pointer
         */
        TreeNode *newNode();

        /*  Function:   *newNode(int)
         *  Purpose:    creates a new node with NULL left and right
         *              leaves and the given integer for the value.
         *  Parameters: the value
         *  Return:     a TreeNode pointer having the given value
         */
        TreeNode *newNode(int val);

        /*  Function:   insert(int)
         *  Purpose:    creates a new node in the tree with the given
         *              value and inserts it into the appropriate location
         *              of the tree.
         *  Parameters: the value
         */
        void insert(int val);

        /*  Function:   remove(int)
            Purpose:    finds the given value in the tree and removes that
                        node, shifting values as necessary
            Parameters: the value
            Return:     a copy of the replaced node
        */
        TreeNode *remove(int val);

        /*  Function:   *search(int)
         *  Purpose:    finds the node in the tree having the given value
         *              and returns the node if the value is found.
         *  Parameters: the value
         *  Return:     The node having the value or NULL if not found
         */
        TreeNode *search(int val);

        /*  Function:   printInOrder(TreeNode*, oftream&)
         *  Purpose:    prints the given subtree using the given
         *              reference to an output stream in order
         *              from smallest to largest value
         *  Parameters: the root node of the sub tree,
         *              a reference to an output stream
         */
        void printInOrder(TreeNode *tn, ofstream &out);

        /*  Function:   printInOrder(oftream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream in order
         *              from smallest to largest value
         *  Parameters: a reference to an output stream
         */
        void printInOrder(ofstream &out)
        {printInOrder(root, out);}

        /*  Function:   printPreOrder(TreeNode*, oftream&)
         *  Purpose:    prints the given subtree using the given
         *              reference to an output stream
         *              in preOrder form
         *  Parameters: the root node of the sub tree,
         *              a reference to an output stream
         */
        void printPreOrder(TreeNode *tn, ofstream &out);

        /*  Function:   printPreOrder(oftream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream
         *              in PreOrder form
         *  Parameters: a reference to an output stream
         */
        void printPreOrder(ofstream &out)
        {printPreOrder(root, out);}

        /*  Function:   printPostOrder(TreeNode*, oftream&)
         *  Purpose:    prints the given subtree using the given
         *              reference to an output stream
         *              in postOrder form
         *  Parameters: the root node of the sub tree,
         *              a reference to an output stream
         */
        void printPostOrder(TreeNode *tn, ofstream &out);
 
        /*  Function:   printPostOrder(oftream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream
         *              in PostOrder form
         *  Parameters: a reference to an output stream
         */       
        void printPostOrder(ofstream &out)
        {printPostOrder(root, out);}

        /*  Function:   getNumNdes()
         *  Purpose:    determines the number of nodes in the tree
         *  Return:     the number of nodes
         */
        int getNumNodes();

        /*  Function:   sumValues()
         *  Purpose:    adds up the values of the tree
         *  Return:     the sum of all values in the tree
         */
        int sumValues();

        /*  Function:   numLeaves()
         *  Purpose:    determines the number of nodes in the tree
         *              that have no children (leaves)
         *  Return:     the number of nodes that are leaves
         */
        int numLeaves();

        /*  Function:   getAverage()
         *  Purpose:    determines the average of the values in the tree
         *  Return:     The average value of the tree
         */
        double getAverage();

        /*  Function:   numValsLeft()
         *  Purpose:    Determines the number of values that are on the left
         *              side of the tree
         *  Return:     The number of values on the left side of the tree
         */
        int numValsLeft();

        /*  Function:   numValsRight()
         *  Purpose:    determines the number of values that are to the right
         *              side of the tree
         *  Return:     The number of nodes on the right
         */
        int numValsRight();

        /*  Function:   getDeepestTreeValue()
         *  Purpose:    determines the value that is at the deepest
         *              level of the tree. If there are multiple values
         *              at the deepest level, the one on the left is returned
         */
        int getDeepestTreeValue();

        /*  Function:   numSingleChildren()
         *  Purpose:    determines the number of nodes in the tree that
         *              have no siblings or the number of parents
         *              that have only one child
         *  Return:     the number of nodes with no sibling
         */
        int numSingleChildren();
};
