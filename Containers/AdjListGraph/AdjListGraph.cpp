#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class AdjListGraph
{
    struct Node
    {
        T val;
    };

    private:
        vector<Node>       m_nodes;//an edge exists between the numbered node and another edge
        vector<list<int> > m_edges;

        Node newNode(T val)
        {
            Node node;
            node.val = val;

            return node;
        }

        int  addNode(Node x)//Append a new Node to the node list
        {
            list<int> edgeList;

            m_nodes.push_back(x);//add the node
            m_edges.push_back(edgeList);//create a edge list for the node

            return m_nodes.size()-1;//return the index to the array of nodes
        }

        void deleteNode(Node x)//Delete a node from the node list, removing any edges that come into this node
        {
            Node tmpNode;
            int  y         = 0;
            int  index     = 0;
            bool foundNode = false;
            
            for(index = 0; (index < m_nodes.size() && !foundNode); index++)
            {
                tmpNode = m_nodes[index];
                if(tmpNode.val == x.val)
                {
                    foundNode = true;
                }
            }

            if(foundNode)
            {
                //if there are edges from other nodes to here, delete them
                for(y = 0; y < m_edges.size(); y++)
                {
                    deleteEdge(y, index);
                }
                //delete the node and its edges to others
                m_nodes.erase(m_nodes.begin() + index);
                m_edges.erase(m_edges.begin() + index);
            }
        }

    public:

        void addEdge(int x, int y)//Add an edge from x to y if none exists
        {
            int       index  = 0;
            bool      foundY = false;
            list<int> edgeList;
            list<int>::iterator iter;

            if(m_edges.size() < x)
                return;

            edgeList = m_edges[x];
            //determine is y is in here
            for(iter = edgeList.begin(); (iter != edgeList.end() && !foundY); ++iter)
            {
                if(*iter == y)
                    foundY = true;
            }
            if(!foundY)
            {
                edgeList.push_back(y);
            }

            m_edges[x] = edgeList;
        }

        void deleteEdge(int x, int y)// Delete an edge from x to y if one exists
        {
            list<int> edgeList;

            if(m_edges.size() < x)
                return;

            edgeList = m_edges[x];
            edgeList.remove(y);
        }


        void printNodes()//print the node values
        {
            int  index = 0;
            Node tmpNode;
            
            for(index = 0; index < m_nodes.size(); index++)
            {
                tmpNode = m_nodes[index];
                if(index > 0)
                    cout << ", ";
                cout << tmpNode.val;
            }
            cout << endl;
        }

        void printEdges()//print the edges
        {
            int index  = 0;
            int yIndex = 0;
            list<int> edgeList;
            list<int>::iterator iter;
            
            for(index = 0; index < m_edges.size(); index++)
            {
                edgeList = m_edges[index];
                cout << "Node index " << index << ": ";
                for(iter = edgeList.begin(); iter != edgeList.end(); ++iter)
                {
                    if(yIndex == 0)
                        cout << "Edges with: ";
                    if(yIndex > 0)
                        cout << ", ";
                    cout << *iter;
                    yIndex++;
                }
                yIndex = 0;
                cout << endl;
            }
        }

        int addNode(T val)
        {
            Node tmp;
            tmp.val = val;
            return addNode(tmp);
        }

        void deleteNode(T val)
        {
            Node tmp;
            tmp.val = val;
            deleteNode(tmp);
        }

        bool containsPath(list<int> path)
        {
            int  xIndex = -1;
            int  yIndex =  0;
            bool inPath =  true;

            list<int>           edgeList;
            list<int>::iterator iter;
            
            if(path.size() == 0)
                return false;

            xIndex = path.front();
            path.pop_front();

            edgeList = m_edges[xIndex];
            for(iter = edgeList.begin(); iter != edgeList.end(); ++iter)
            {
                yIndex = path.front();
                path.pop_front();
                if(*iter != yIndex)
                {
                    inPath = false;
                    break;
                }
                yIndex++;
            }
            return inPath;
        }
};
