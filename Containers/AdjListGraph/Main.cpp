#include <iostream>

#include "AdjListGraph.cpp"

using namespace std;

int main()
{
    AdjListGraph<int> aGraph;
    list<int>         path;
    int               nodeIndex = 0;
    int               count     = 0;

    for(nodeIndex = 0; nodeIndex < 10; nodeIndex++)
    {
        count = aGraph.addNode(nodeIndex*2);
    }

    aGraph.addEdge(0, 2);
    aGraph.addEdge(2, 1);
    aGraph.addEdge(6, 1);
    aGraph.addEdge(7, 2);
    aGraph.addEdge(9, 1);
    aGraph.addEdge(8, 4);
    aGraph.addEdge(8, 5);
    aGraph.addEdge(8, 6);
    
    aGraph.printNodes();
    aGraph.printEdges();
    aGraph.deleteNode(9);

    path.push_back(8);
    path.push_back(4);
    path.push_back(5);
    path.push_back(6);

    aGraph.printNodes();

    cout << aGraph.containsPath(path) << endl;
    
    return 0;
}

