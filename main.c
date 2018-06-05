#include "functii.h"

int adjMatrix[MAX][MAX];
int no_nodes;

int main()
{

    int iterator_rows;
    int iterator_columns;
    int x;
    int cC;
    int meth;
    int nr;

    time_t t;
    srand((unsigned) time(&t));
    no_nodes = rand() % 10 + 2;

    for( iterator_rows = 0; iterator_rows < no_nodes; iterator_rows++ )
        for( iterator_columns = 0; iterator_columns < no_nodes; iterator_columns++ )
            adjMatrix[iterator_rows][iterator_columns] = 0;

    for( iterator_rows = 0 ; iterator_rows < no_nodes; iterator_rows++ )
        for( iterator_columns = 0; iterator_columns < no_nodes; iterator_columns++ )
        {
            if( iterator_rows == iterator_columns )
                continue;
            x = rand() % 10 + 1;
            if( x % 2 == 1 && adjMatrix[iterator_rows][iterator_columns] == 0 )
            {
                adjMatrix[iterator_rows][iterator_columns] = 1;
                adjMatrix[iterator_columns][iterator_rows] = 1;
            }
        }

    for( iterator_rows = 0; iterator_rows < no_nodes; iterator_rows++ )
    {
        for( iterator_columns = 0; iterator_columns < no_nodes; iterator_columns++ )
            printf( "%d ", adjMatrix[iterator_rows][iterator_columns] );
        printf( "\n" );

    }

    while( 1 > 0 )
    {

        printf( "\nPress 1 for BFS : " );
        printf( "\nPress 2 for DFS : " );
        printf( "\nPress 3 to exit : " );


        printf( "\nEnter your choice: " );
        scanf( "%d", &meth );

        switch( meth ){
            case 1:
                    {
                        printf( "\nThe order in which the graph is crossed using BFS is : \n" );

                        cC = breadthFirstSearch();

                        if( cC == no_nodes-1 )
                            {
                                printf( "\nThe graph is connected" );
                                printf( "\n" );
                            }
                        else
                            {
                                printf( "\nThe graph is not connected" );
                                printf( "\n" );
                            }
                        break;
                    }

            case 2:
                   {

                    printf( "\nThe order in which the graph is crossed using DFS is : \n" );
                    DFS( &nr );

                    if( nr == no_nodes )
                        {
                            printf( "\nThe graph is connected" );
                            printf( "\n" );
                        }
                    else
                         {
                            printf( "\nThe graph is not connected" );
                            printf( "\n" );
                        }

                   break;
                   }

            case 3: exit(0);
                break;

            default:
                printf( "\nYou have entered an invalid choice. Please try again" );
                break;
        }
    }


    return 0;
}
