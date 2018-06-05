#include "functii.h"

int adjMatrix[MAX][MAX];
int no_nodes;

int breadthFirstSearch()
{
    int aux;
    int iterator_rows;
    int first = 0;
    int last = 0;
    int queue[MAX] = {0};
    int visited[MAX] = {0};
    int start_node = 0;
    queue[first] = start_node;  ///We put the knot in the queue
    visited[start_node] = 1;     ///We mark him as being visited

    while( first <= last )
    {

        for( iterator_rows = 0; iterator_rows < no_nodes; iterator_rows++ ) ///We are going through the knots
        {
            aux = queue[first];
            if( adjMatrix[aux][iterator_rows] == 1 && visited[iterator_rows] == 0 ) ///If there is an edge between the current node and the neighbor node and the neighboring neighbor was not visited then
            {
                last++; ///The queue is growing
                queue[last] = iterator_rows;    ///Add the neighbor node to the queue
                visited[iterator_rows] = 1;     ///We mark the node as being visited
            }

        }
        first++;    ///It goes to the next node in the queue
    }
    for( iterator_rows = 0; iterator_rows <= last; iterator_rows++ )    ///The scroll is displayed

    {
        printf( "%d ", queue[iterator_rows] );
    }
    return last;
}

