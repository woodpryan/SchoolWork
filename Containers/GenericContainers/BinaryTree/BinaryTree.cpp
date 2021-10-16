/**
    @class:     BinaryTree
    Purpose:    This class demonstrates an implementation of the
                binary tree Abstract Data Type. This version is
                templated so that the value stored in a TreeNode
                can be anything the user would like it to be, so
                long as the class they construct it with has
                overloaded the comparison and insertion operators.
    @author     Ryan Wood
    @date       8/29/2020
*/
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class BinaryTree
{
    /**TreeNode structure. One value. One left leaf and on right leaf*/
    struct TreeNode
    {
        T         val;
        TreeNode *left;
        TreeNode *right;
    };

    typedef TreeNode* nodePtr;//This will make the pointers easier
    private:

        nodePtr root;

        /** Function:      insert(nodePtr&, nodePtr &)
         *  Purpos:        inserts the given new node to the left
         *                 or to the right of the given node.
         *                 Recursive function, calls itself until
         *                 it finds a null node left or right
         *  @param node    the node after which the new node should be placed,
         *  @param newNode the new node with a value and null left and right nodes
         */
        void insert(nodePtr &node, nodePtr &newNode)
        {
            if(NULL == node)
            {
                node = newNode;//base case, insert the node
            }
            else if(newNode->val < node->val)//case left, call insert on left
            {
                insert(node->left, newNode);
            }
            else//otherwise call insert on node right
            {
                insert(node->right, newNode);
            }
        }
        
        /** Function:   getLeftmostNode(nodePtr, nodePtr)
            Purpose:    For the given node, this function determines which
                        node of the subtree has no left link, the final
                        left value in the subtree
            @param node the node
            @param prev the parent of the node if it is to be considered or a NULL TreeeNode
            @return     the leftmost node of the subtree
        */
        nodePtr getLeftmostNode(nodePtr node, nodePtr prev)
        {
            if(NULL == node)
                return prev;
            else
            {
                prev = node;
                return getLeftmostNode(node->left, prev);
            }
        }

        /** Function:   getRightmostNode(nodePtr, nodePtr)
            Purpose:    for the given subtree, this function determines
                        what is the node with the largest value, in
                        other words the rightmost node in the subtree
            @param node the node
            @param prev the parent if it is to be considered or a NULL node
            @return     The rightmost node of the subtree
        */
        nodePtr getRightmostNode(nodePtr node, nodePtr prev)
        {
            if(NULL == node)
                return prev;
            else
            {
                prev = node;
                return getRightmostNode(node->right, prev);
            }
        }

        /** Function:   remove(nodePtr, T val)
            Purpose:    for the given node (subtree), searches the tree for the given
                        value and removes that node from the tree
            @param root the node
            @param val  the value
            @return     a copy of the node that is replaced
        */
        nodePtr remove(nodePtr root, T val)
        {
            nodePtr tmp = NULL;
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

        /** Function:   destroySubTree(nodePtr)
         *  Purpose:    deletes all members of the tree from the given node
         *              through all of its children. Recursive
         *  @param tn   the sub tree root node
         */
        void destroySubTree(nodePtr tn)
        {
            if(NULL != tn)
            {
                destroySubTree(tn->left);
                destroySubTree(tn->right);
                delete(tn);
            }
        }

        /** Function:   numValsLeft(nodePtr)
         *  Purpose:    calculates the number of values to the left
         *              of the given subtree node. Recursive
         *  @param tn   the subtree root node
         *  @return     the number of values in the tree's left subtree
         */
        int numValsLeft(nodePtr tn)
        {
            if(NULL != tn && NULL != tn->left)
            {
                cout << "numValsLeft" << endl;
                return getNumNodes(tn->left);
            }
            else
            {
                return 0;
            }
        }

        /** Function:   numValsRight(nodePtr)
         *  Purpose:    calculates the number of values to the right of
         *              the given subree node. Recursive
         *  @param tn   the subtree root node
         *  @return     the number of values in the tree's right subtree
         */
        int numValsRight(nodePtr tn)
        {
            if(NULL != tn && NULL != tn->right)
            {
                return getNumNodes(tn->right);
            }
            else
            {
                return 0;
            }
        }

        /** Function:   getNumNodes(nodePtr)
         *  Purpose:    calculates the number of nodes in the
         *              given subtree. Recursive
         *  @param node the subtree root node
         *  @return     The number of nodes of the subtree
         */
        int getNumNodes(nodePtr node)
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

        /** Function:   *find(nodePtr, T) nodePtr
         *  Purpose:    searches the given subtree for the
         *              given value recursively. Gives back
         *              the node having the value if it is found.
         *  @param tn  the root node of the sub tree
         *  @param val the value to search the tree for
         *  @return     the node having the value or NULL if not found
         */
        nodePtr *find(nodePtr tn, T val)
        {
            if(NULL == tn)
                return tn;//base case 1, never found
            else if(tn->val == val)
                return tn;//base case 2, found match
            else if(val < tn->val)
                return find(tn->left, val);
            else //if(val > tn->val)
                return find(tn->right, val);
        }

        /** Function:    getDeepestTreeValueLeft(nodePtr, nodePtr, T&)
         *  Purpose:     Determines the value on the given subtree's left
         *               subtree that is at the deepest level of the subtree.
         *               Sets the given level value to the level where it finds
         *               this value. Recursive
         *  @param node  the root node of the subtree
         *  @param prev  the previous root node (or NULL)
         *  @param level the level value, starting at zero
         *  @return      the value at the deepest level of the subtree
         */
        T getDeepestTreeValueLeft(nodePtr node, nodePtr prev, int &level)
        {
            T *valReturn = NULL;
            if(NULL == node)
            {
                if(NULL == prev)
                {
                    return *valReturn;
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

        /** Function:    getDeepestTreeValueRight(nodePtr, nodePtr, T&)
         *  Purpose:     Determines the value on the given subtree's right 
         *               subtree that is at the deepest level of the subtree.
         *               Sets the given level value to the level where it finds
         *               this value. Recursive
         *  @param node  the root node of the subtree
         *  @param prev  the previous root node (or NULL)
         *  @param level the level value, starting at zero
         *  @return      the value at the deepest level of the subtree
         */
        T getDeepestTreeValueRight(nodePtr node, nodePtr prev, int &level)
        {
            T *valReturn = NULL;
            if(NULL == node)
            {
                if(NULL == prev)
                {
                    return *valReturn;
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

        /** Function:   numLeaves(nodePtr)
         *  Purpose:    gets the number of leaves of the subtree. Recursive
         *  @param node the root node of the subtree
         *  @return     the number of nodes in the subtree
         */
        int numLeaves(nodePtr node)
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

        /** Function:   numSingleChildren(nodePtr)
         *  Purpose:    determines the number of parents in the tree that
         *              have only one child. In other words, determines the
         *              number of nodes in the sub tree having no siblings
         *              Recursive function
         *  @param node the root node of the sub tree
         *  @return     the number of children with no siblings
         */
        int numSingleChildren(nodePtr node)
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

        /** Function:   copySubTree(nodePtr)
         *  Purpose:    performs a deep copy on the given subtree,
         *              inserting all the values left and right.
         *  @param tn   the subtree or root to copy a whole tree
         */
        void copySubTree(nodePtr tn)
        {
            if(NULL != tn)
            {
                copySubTree(tn->left);
                copySubTree(tn->right);
                insert(tn->val);
            }
        }

        /** Function:   inorder(nodePtr, oftream&)
         *  Purpose:    prints the given subtree using the given
         *              reference to an output stream in order
         *              from smallest to largest value
         *  @param tn   the root node of the sub tree
         *  @param out  a reference to an output stream
         */
        void inorder(nodePtr tn, ofstream &out)
        {
            if(NULL != tn)
            {
                inorder(tn->left, out);
                out << tn->val << endl;
                inorder(tn->right, out);
            }
        }

        /** Function:   inorder(nodePtr, ostream&)
         *  Purpose:    prints the values of the given subtree using the 
         *              given output stream
        */
        void inorder(nodePtr tn, ostream &out)
        {
            if(NULL != tn)
            {
                inorder(tn->left, out);
                out << tn->val << endl;
                inorder(tn->right, out);
            }
        }

    public:

        /** Function:   BinaryTree()
         *  Purpose:    default constructor of the BinaryTree class.
         *              Sets the root of the tree to NULL
         */
        BinaryTree()
        {
            root = NULL;
        }

        /** Function:   BinaryTree(T)
            Purpose:    creates a binary tree and inserts the given
                        value as the first value of the tree
            @param val  the first root value
            @return     The new tree
        */
        BinaryTree(T val)
        {
            insert(val, root);
        }

        /** Function:   BinaryTree(BinaryTree<T>&)
            Purpose:    copy constructor. Uses the given Binary Tree's
                        getRoot function to copy the given tree from the
                        root onward
            @param bt   the tree to copy
        */
        BinaryTree(BinaryTree<T> &bt)
        {
            copySubTree(bt.getRoot());
        }

        /** Function:   getRoot()
            Purpose:    this function returns the root node of the Binary Tree
            @return     the root tree
        */
        nodePtr getRoot()
        {
            return root;
        }

        /** Function:   ~BinaryTree()
         *  Purpose:    destructor for the BinaryTree class.
         *              Simply calls destroySubTree on the tree root
         */
        ~BinaryTree()
        {
            destroySubTree(root);
        }

        /** Function:   *newNode()
         *  Purpose:    creates a new node with NULL left and right leaves
         *  @return     an empty TreeNode pointer
         */
        nodePtr newNode()
        {
            nodePtr tn = new TreeNode;
        
            tn->left  = NULL;
            tn->right = NULL;
        
            return tn;
        }

        /** Function:   *newNode(T)
         *  Purpose:    creates a new node with NULL left and right
         *              leaves and the given value.
         *  @param val  the value
         *  @return     a TreeNode pointer having the given value
         */
        nodePtr newNode(T val)
        {
            nodePtr tn = newNode();
    
            tn->val = val;
    
            return tn;
        }

        /** Function:   insert(T)
         *  Purpose:    creates a new node in the tree with the given
         *              value and inserts it into the appropriate location
         *              of the tree.
         *  @param val  the value
         */
        void insert(T val)
        {
            nodePtr node = newNode(val);

            insert(root, node);
            cout << "inserting " << val << endl;
        }

        /** Function:   remove(T)
            Purpose:    finds the given value in the tree and removes that
                        node, shifting values as necessary
            @param val  the value
            @return     a copy of the replaced node
        */
        nodePtr remove(T val)
        {
            return remove(root, val);
        }

        /** Function:   *find(T)
         *  Purpose:    finds the node in the tree having the given value
         *              and returns the node if the value is found.
         *  @param val  the value
         *  @return     The node having the value or NULL if not found
         */
        nodePtr find(T val)
        {
            return find(root, val);
        }

        /** Function:   printInOrder(oftream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream in order
         *              from smallest to largest value
         *  @param out  a reference to an output stream
         */
        void inorder(ofstream &out)
        {
            inorder(root, out);
        }

        /** Function:   printInOrder(otream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream in order
         *              from smallest to largest value
         *  @param out  a reference to an output stream
         */
        void inorder(ostream &out)
        {
            inorder(root, out);
        }

        /** Function:   inorder()
         *  Purpose:    prints the tree to the standard out in order
         */
        void inorder()
        {
            inorder(std::cout);
        }

        /** Function:   preorder(nodePtr, oftream&)
         *  Purpose:    prints the given subtree using the given
         *              reference to an output stream
         *              in preOrder form
         *  @param tn   the root node of the sub tree,
         *  @param out  a reference to an output stream
         */
        void preorder(nodePtr tn, ofstream &out)
        {
            if(NULL != tn)
            {
                out << tn->val << endl;
                preorder(tn->left, out);
                preorder(tn->right, out);
            }
        }

        /** Function:   preorder(oftream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream
         *              in PreOrder form
         *  @param out  a reference to an output stream
         */
        void preorder(ofstream &out)
        {
            preorder(root, out);
        }

        /** Function:   preorder()
            Purpose:    prints the binary tree to the standard output stream
                        using preorder method
         */
        void preorder()
        {
            preorder(cout);
        }

        /** Function:   postorder(nodePtr, oftream&)
         *  Purpose:    prints the given subtree using the given
         *              reference to an output stream
         *              in postOrder form
         *  @param tn   the root node of the sub tree,
         *  @param out  a reference to an output stream
         */
        void postorder(nodePtr tn, ofstream &out)
        {
            if(NULL != tn)
            {
                postorder(tn->left, out);
                postorder(tn->right, out);
                out << tn->val << endl;
            }
        }
 
        /** Function:   postorder(oftream&)
         *  Purpose:    prints the tree using the given
         *              reference to an output stream
         *              in PostOrder form
         *  @param out  a reference to an output stream
         */       
        void postorder(ofstream &out)
        {
            postorder(root, out);
        }

        /** Function:   postorder()
         *  Purpose:    prints the tree using the
         *              standard output stream
         *              in PostOrder form
         */       
        void postorder()
        {
            postorder(cout);
        }


        /** Function:   getNumNdes()
         *  Purpose:    determines the number of nodes in the tree
         *  @return     the number of nodes
         */
        int getNumNodes()
        {
            return getNumNodes(root);
        }

        /** Function:   numLeaves()
         *  Purpose:    determines the number of nodes in the tree
         *              that have no children (leaves)
         *  @return     the number of nodes that are leaves
         */
        int numLeaves()
        {
            return numLeaves(root);
        }

        /** Function:   numValsLeft()
         *  Purpose:    Determines the number of values that are on the left
         *              side of the tree
         *  @return     The number of values on the left side of the tree
         */
        int numValsLeft()
        {
            return numValsLeft(root);
        }

        /** Function:   numValsRight()
         *  Purpose:    determines the number of values that are to the right
         *              side of the tree
         *  @return     The number of nodes on the right
         */
        int numValsRight()
        {
            return numValsRight(root);
        }

        /** Function:   getDeepestTreeValue()
         *  Purpose:    determines the value that is at the deepest
         *              level of the tree. If there are multiple values
         *              at the deepest level, the one on the left is returned
         */
        T getDeepestTreeValue()
        {
            int levelLeft  = 0;
            int levelRight = 0;
            T   valLeft;
            T   valRight;

            valLeft  = getDeepestTreeValueLeft(root, NULL, levelLeft);
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

        /** Function:   numSingleChildren()
         *  Purpose:    determines the number of nodes in the tree that
         *              have no siblings or the number of parents
         *              that have only one child
         *  @return     the number of nodes with no sibling
         */
        int numSingleChildren()
        {
            return numSingleChildren(root);
        }
};
