//Graph Execution in C with some of the algorithms
#define MAX 20
typedef int BOOL;

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

#define MAX 20
#define inf INT_MAX
typedef int BOOL;
void traverse(int adj_matrix[MAX][MAX], int i,int n, BOOL visited[MAX]);
void dfs(int adj_matrix[MAX][MAX], int n)
{
	BOOL visited[MAX];
	int i;
	for(i = 0; i < n ;i ++)
	{
		visited[i] = FALSE;
	}
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		{
			traverse(adj_matrix,i,n,visited);
		}
	}	
}
//helper function for dfs
void traverse(int adj_matrix[MAX][MAX], int i,int n, BOOL visited[MAX])
{
	int j;
	visited[i]= TRUE;
	//printf("%d\t", j);
	for(j = 0 ; j<n ;j++)
	{
		if(adj_matrix[i][j] != 0)
		{
			if(visited[j] == FALSE)
			{
				traverse(adj_matrix,j,n,visited);	
			}
		}
	}
}
//fucntion to find the mother vertex of a given directed graph 
int motherVertex(int adj_matrix[MAX][MAX], int n)
{
	int v;
	

	//performing dfs for the first run to find the last finished vertex
	BOOL visited[MAX];
	int i;
	for(i = 0; i < n ;i ++)
	{
		visited[i] = FALSE;
	}
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		{	
			traverse(adj_matrix,i,n,visited);
			v=i;
		}
		
	}
	//printf("\n%d",v);
	//making the check if the last finished vertex is the mother vertex
	for(i = 0; i < n ;i ++)
	{
		visited[i] = FALSE;
	}
	traverse(adj_matrix,v,n,visited);
	for(i=0; i<n; i++)
	{
		if(visited[i]!=TRUE)
		{return -1;}
		
	}
	return v;
}


/* A thing to note in BFS algorithm is that a node can enter the queue 2 times. However, it will not 
be printed two times because it will already be marked as visited node when its first entry in the 
queue is popped. */
BOOL isCyclicHelp(int adj_matrix[MAX][MAX],int v,int n, BOOL visited[MAX], BOOL array[MAX] )
{	int i;
	if(visited[v]==FALSE)
	{
		visited[v]=TRUE;
		array[v]=TRUE;;
		for(i = 0; i<n; i++)
		{if(adj_matrix[v][i]!= 0)
			{
			if((!visited[i])&&isCyclicHelp(adj_matrix, i,n,visited,array))
			{return TRUE;}
			else
			{
				if(array[i]==TRUE)
				{return TRUE;}
			}
			
			}
		}

	}
	array[v]=FALSE;
	return FALSE;

	
}
// function to check if aa given graph is cyclic 
BOOL isCyclic(int adj_matrix[MAX][MAX], int n)
{
	BOOL visited[MAX];
	BOOL array[MAX];
	int i;
	for(i = 0; i < n ;i ++)
	{
		visited[i] = FALSE;
		array[i]=FALSE;
	}

	for(int i = 0; i < n; i++) 
        if (isCyclicHelp(adj_matrix,i, n,visited, array)) 
            return TRUE; 
  
    return FALSE; 
}





//void dijkstra(int adj_matrix[MAX][MAX], int dist_table[], int n);




void dijkstra(int adj_matrix[MAX][MAX], int dist_table[MAX], int n)
{
	int visited_flag[n];
	int i,j,v;
	int min;
	visited_flag[0] = 1;
	
	for(i=0;i<n;i++)
	{
		visited_flag[i]=0;
		if(adj_matrix[0][i]>0)
		{dist_table[i]= adj_matrix[0][i];}
		else
		{
			dist_table[i]= inf;
		}
			
	}	
	dist_table[0] = 0;
	for(i=0;i<n;i++)
	{
		min = inf;
		for(j = 0; j<n ;j++)
		{
			if(visited_flag[j]==0)
			{
				if(dist_table[j]<min)
				{
					min = dist_table[j];
					v = j;
				}
			}
		}
		visited_flag[v]= 1;
		for(j = 1; j <n ; j++)
		{
			if(!visited_flag[j]&&adj_matrix[v][j]>0)
			{
				if(min + adj_matrix[v][j] < dist_table[j])
				{
					dist_table[j]= min + adj_matrix[v][j]; 
				}
			}
		}
	}
}
// helper function for topological sort of graphs
void topoHelp(int adj_matrix[MAX][MAX], int v, int *i, int n, int visited[], int topo[])
{
	visited[v]=TRUE;
	int j;
	for(j=0;j<n;j++)
	{
		if(adj_matrix[v][j]>0 && !visited[j])
		{topoHelp(adj_matrix, j,i,n,visited,topo);}
	}

	topo[n-*i-1]=v;
	(*i)++;

}
void topologicalSort(int adj_matrix[MAX][MAX], int n, int topo[])
{
	int *i, j;
	i = (int*)malloc(sizeof(int));
	*i = 0;
	//int topo[n] ;
	int visited[n];
	//mark all vertices as not visited
	for(j=0;j<n;j++)
	{
		visited[j]=FALSE;
	}
	//topological sort using recursive helper function
	//using pointer variable i to store the values of nodes into the array "topo"
	for(j=0;j<n;j++)
	{
		if(!visited[j])
		{topoHelp(adj_matrix, j,i,n,visited,topo);}
	}
	for (j=0;j<n;j++)
	{
		printf("\t %d \n",topo[j]);
	}
}

int maximumEdgeAddtion(int adj_matrix[MAX][MAX], int n) 
{ 
  /*The maximum number of edges in a DAG are equal to n*(n-1),
  the given graph is given to be a DAG , therefore the number of edges that can be added
  to still keep the graph as a DAG would be N(N-1) - no. of edges already existing*/
  int edges = 0;
  for(int i = 0; i<n; i ++)
  {
	  for(int j=0; j<n; j++)
	  {
		  if(adj_matrix[i][j]>0)
		  {
			  edges++;
		  }
	  }
  }
 
  int max = 0;
  max = (n*(n-1))/2;
		max = max - edges;

return max;
		
} 
// function to make a cost matrix from a goven adjacency matrix
void costMatrix(int adj_matrix[MAX][MAX], int cost[MAX][MAX], int n)
{
	for(int i = 0; i<n ; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(adj_matrix[i][j]>0)
				{cost[i][j]=adj_matrix[i][j];}
				else
				{
					cost[i][j] = inf;
				}
				
			}
		}
}



// Find set of vertex i 
int find(int i, int parent[MAX]) 
{ 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 
  
// Does union of i and j. It returns 
// false if i and j are already in same 
// set. 
void union1(int i, int j, int parent[MAX]) 
{ 
    int a = find(i, parent); 
    int b = find(j, parent); 
    parent[a] = b; 
} 
  
// Finds MST using Kruskal's algorithm 
void kruskalMST(int cost[MAX][MAX], int n, int parent[MAX]) 
{ 
    int mincost = 0; // Cost of min MST. 
  
    // Initialize sets of disjoint sets. 
    for (int i = 0; i < n; i++) 
        parent[i] = i; 
  
    // Include minimum weight edges one by one 
    int edge_count = 0; 
    while (edge_count < n - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (find(i,parent) != find(j,parent) && cost[i][j] < min) { 
                    min = cost[i][j]; 
                    a = i; 
                    b = j; 
                } 
            } 
        } 
  
        union1(a, b, parent); 
        printf("Edge %d:(%d, %d) cost:%d \n", 
               edge_count++, a, b, min); 
        mincost += min; 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
} 

BOOL isValidEdge(int u, int v, BOOL inMST[]) 
{ 
   if (u == v) 
       return FALSE; 
   if (inMST[u] == FALSE && inMST[v] == FALSE) 
        return FALSE; 
   else if (inMST[u] == TRUE && inMST[v] == TRUE) 
        return FALSE; 
   return TRUE; 
} 
//prims algorithm for minimum spanning tree
  
void primMST(int cost[MAX][MAX], int n) 
{   
    BOOL inMST[n]; 
	for(int i=0; i<n; i++)
	{
		inMST[i]=FALSE;
	}
  
    // Include first vertex in MST 
    inMST[0] = TRUE; 
  
    // Keep adding edges while number of included 
    // edges does not become V-1. 
    int edge_count = 0, mincost = 0; 
    while (edge_count < n - 1) { 
  
        // Find minimum weight valid edge.   
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {                
                if (cost[i][j] < min) { 
                    if (isValidEdge(i, j, inMST)) { 
                        min = cost[i][j]; 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
        if (a != -1 && b != -1) { 
            printf("Edge %d:(%d, %d) cost: %d \n",  
                         edge_count++, a, b, min); 
            mincost = mincost + min; 
            inMST[b] = TRUE;
			inMST[a] = TRUE; 
        } 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
}
//to find the shortest distance between two given vertices 
int dijkstrapair(int cost[MAX][MAX],int n,int startnode,int endnode)
{
  //int n = graph->V;
	int distance[MAX],pred[MAX],distance2[MAX],pred2[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=inf;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
	if(endnode!=startnode)
		{
      if(distance[endnode]==9999){
        printf("node %d not approachable",endnode);
		return inf;
      }
      else{
			  printf("\nDistance of node%d=%d",endnode,distance[endnode]);
			  printf("\nPath=%d",endnode);
			  return (distance[endnode]);
      }
	//print the path and distance of each node
	/*
		if(endnode!=startnode)
		{
      if(distance[endnode]==9999){
        printf("node %d not approachable",endnode);
      }
      else{
			  printf("\nDistance of node%d=%d",endnode,distance[endnode]);
			  printf("\nPath=%d",endnode);
      }
			j=endnode;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);*/
	  }

}
int main()
{
//	int adj_matrix[MAX][MAX];
	int dist_table[MAX];
	int n, i, j;
	int topo[MAX];
	int parent[MAX], cost[MAX][MAX];
	printf("Enter the number of vertices in the graph");
	scanf("%d", &n);
	printf("\n Enter the adjacency matrix\n ");
int adj_matrix[MAX][MAX] = { 
        { 0, 2, 0, 6, 0 }, 
        { 2, 0, 3, 8, 5 }, 
        { 0, 3, 0, 0, 7 }, 
        { 6, 8, 0, 0, 9 }, 
        { 0, 5, 7, 9, 0 }, 
    }; 









/*int adj_matrix[MAX][MAX]= {  { 0, 1, 1, 0, 0, 0, 0 },  // 0
			{ 0, 0, 0, 1, 0, 0, 0 },  // 1
			{ 0, 0, 0, 0, 0, 0, 0 },  // 2
			{ 0, 0, 0, 0, 0, 0, 0 },  // 3
			{ 0, 1, 0, 0, 0, 0, 0 },  // 4
			{ 0, 0, 1, 0, 0, 0, 1 },  // 5
			{ 1, 0, 0, 0, 1, 0, 0 }};  // 6
		//	{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },  // 7
		//	{ 1, 0, 0, 0, 1, 0, 0, 0, 0}};// 8       */

/*	for(i=0;i<n;i++)
	{
		for(j = 0; j< n; j++)
		{
			scanf("%d", &adj_matrix[i][j]);
		}
	} */
	printf("\n The adjacency matrix entered is :\n");
	for(i=0;i<n;i++)
	{
		for(j = 0; j< n; j++)
		{
			printf("%d\t", adj_matrix[i][j]);
		}
		printf("\n");
	}
	//dijkstra(adj_matrix, dist_table, n);
	printf("\nThe shortest distances of each vertex from the source vertex 0 are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n ", dist_table[i]);
	}
	if( isCyclic(adj_matrix,n))
	{
		printf("\n The following graph is a CYCLIC graph");
	}
	else
	{
		printf("\n The following graph is an ACYCLIC graph");
	}

	printf("\n The mother vertex of the following graph is: %d\n", motherVertex(adj_matrix,n));
	//topologicalSort(adj_matrix,n,topo);
	printf("\n the numeber of edges that can be added keeping it a DAG are: %d", maximumEdgeAddtion(adj_matrix,n));
	costMatrix(adj_matrix, cost, n);
	//kruskalMST(cost,n,parent);
	primMST(cost,n);
	return(0);
	
}
