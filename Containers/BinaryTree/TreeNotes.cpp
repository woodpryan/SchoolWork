//Tree is a linked data structure with nodes that have links to the left and right
//binary data structure, called so because it has two links
//
//There are three types of trees
//1. Hiearchy tree not generally useful in CS
//2. Ordered tree / search tree. Data has some order
//3. Heap, first value is biggest value.
//

//all values to the right of a given node are greater
//all values to the left are less than the node

//node - a struct that is a member of the tree
//root - the parent that has no parents. The start of the tree
//leaves - the children of the tree that has no children
//child - the node that is to the left or right of a parent. May also be a parent
//siblings - given two children, they have the same parent node
//ansestors - the parent of the parent of the node
//descendants - grand children of a node

//sub-tree - a subset of a tree. a node that may have children and descendants

//depth/level - is how many levels of nodes in a tree until the leaves are reached
//depth of tree is max number of probes an algorithm will take to find a value
//Data is always inserted at the bottom of the tree
//
//searching a binary tree is done at log2n speed

struct tNode
{
    int value;
    tNode *lChild;
    tNode *rChild;
};

class BinaryTree
{
    private:
        tNode *root;
    public:
        tNode *newNode()
        {
            tNode *tmpNode = NULL;
            tmpNode = new tNode;

            tmpNode->value = 0;
            tmp->lChild = NULL;
            tmp->rChild = NULL;

            return tmpNode;
        }

        tNode *newNode(int num)
        {
            tNode *tmpNode = NULL;
            tmpNode = new tNode;

            tmpNode->value = num;
            tmp->lChild = NULL;
            tmp->rChild = NULL;

            return tmpNode;
        }

        void insert(tNode* current, int num)
        {
            tNode *previous;
            tNode *tmp;
            
            if(NULL == root)
            {
                tmp = newNode(num);
                root = tmp;
                return;
            }

            while(NULL != current)
            {
                previous = current;
                if(val < current->value)//if less, get left child
                {
                    current = current->lChild;
                }
                else if(val > current->value)//if greater, right child
                {
                    current = current->rChild;
                }
            }

            tmp = newNode();
            tmp->value = num;

            if(val < previous->value)
                previous->lChild = tmp;
            else
                previous->rChild = tmp;
        }

        tNode *search(tNode *current, int val)
        {
            tNode * tmp = NULL;
            while(current != NULL && val != current->val)
            {
                if(val < current->value)
                    current = current->lChild;
                else
                    current = current->rChild;
            }
        }

        void print(tNode *current)
        {
            if(NULL == current)
                return;
            else
            {
                print(current->lChild);
                cout << current->value << " ";
                print(current->rChild)
            }
        }
};


int main()
{
    BinaryTree bt;

    bt.insert(root, val);
    if(search(root, val))
    return 0;
}








