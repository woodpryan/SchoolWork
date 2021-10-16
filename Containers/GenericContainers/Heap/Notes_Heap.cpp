/*** Heap notes *****/

/*
            90
          /     \
         40       30
        /   \     /  \
       20    15  20   25
      / \    /
     10  9  12

*/

//only useful when you only care about the biggest value
//priority queue is another word for it

//always insert at the bottom, left to right
//parent is always bigger than the child

//inserting
//after inserting while(!isHeap) walk the value up
//move the value up, swapping it with it's parent
//big O of a heap is log2N

//deleting from a heap is always done on the largest value
// after deleting, pull the last value inserted up to the top of the heap
// then walk the value down, swapping the value with its biggest child until its children are smaller than it
// memory allocation in the operating system utilizes a heap
/*
__________________________________________
|13 | 9 | 2 | 3 | 4 | 6
------------------------------------------
        P
    /       \
  2n        2n+1

parentIndex = nodeIndex/2

*/
