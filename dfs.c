#include "functii.h"

int adjMatrix[MAX][MAX];
int no_nodes;

void DFS( int *nr )
{
	int stack[MAX] = {0};
	int visited[MAX] = {0};
	int iterator_rows;
	int start_node = 0;
	int level = 1;
	int aux;
	stack[1]=start_node;       ///We put the starting node in the stack
	visited[start_node] = 1;    ///We mark the node as being visited

	printf( "%d ", start_node );    ///I was displaying the start node
	( *nr ) = 1;                     ///Number of nodes from scroll

	while( level > 0 )
	{
		aux = stack[level];

		for( iterator_rows = 0; iterator_rows < no_nodes; iterator_rows++ )                   ///We are going through the knots
			if( ( adjMatrix[aux][iterator_rows] == 1 ) && ( visited[iterator_rows] == 0 ) )    ///If there is an edge between the current node and the neighbor node and the neighboring neighbor was not visited then
			{
				level++;                          ///Increase the stack level
				stack[level] = iterator_rows;     ///Add the neighbor node to the stack
				visited[iterator_rows] = 1;       ///It is marked as being visited
				printf( "%d ", iterator_rows );    ///It is displayed
				( *nr )++;                          ///Increases the number of nodes in scroll
				iterator_rows = no_nodes + 1;        ///We get out of the way to get to your neighbor`s neighbor

			}
		if( iterator_rows == no_nodes )    ///If the node has no neighbors, it moves to the previous node
			level--;
    }
}
