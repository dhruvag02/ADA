
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int V;
bool a[30][30];
bool isSafe (int v, bool a[][30], int color[], int c) 
{ 
    int i;
    for (i = 0; i < V; i++) 
        if (a[v][i] && c == color[i]) 
            return false; 
    return true; 
} 

void printSolution(int color[]) 
{ 
    int i;
    printf("The assigned colors are: ");
    for (i = 0; i < V; i++) 
      printf("%d ",color[i]);
} 
  
bool graphColor(bool a[][30], int m, int color[], int v) 
{ 
    
    int c;
    if (v == V) 
        return true; 
  
    
    for (c = 1; c <= m; c++) 
    { 
        
        if (isSafe(v, a, color, c)) 
        { 
           color[v] = c; 
  
           if (graphColor(a, m, color, v+1) == true) 
             return true; 
  
           color[v] = 0; 
        } 
    } 
  
    return false; 
} 

int main()
{
	int m;
	int i,j;
	printf("Enter the no.of colors: "); 
	scanf("%d",&m);
	printf("Enter the no.of vertices: "); 
	scanf("%d",&V);
	int color[V];
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}

    	for (i = 0; i < V; i++) 
       		color[i] = 0; 
  
    
    	if (graphColor(a, m, color, 0) == false) 
    	{ 
      		printf("Solution does not exist"); 
      
    	} 
  
   	else
    		printSolution(color); 
    	return 0;
}

OUTPUT
Enter the no.of colors: 3                                                                                                              
Enter the no.of vertices: 4                                                                                                            
Enter the adjacency matrix:                                                                                                            
0 1 1 1                                                                                                                                
1 0 1 0                                                                                                                                
1 1 0 1                                                                                                                                
1 0 1 0                                                                                                                                
The assigned colors are: 1 2 3 2
*****	
Enter the no.of colors: 2                                                                                                              
Enter the no.of vertices: 4                                                                                                            
Enter the adjacency matrix:                                                                                                            
0 1  1 1                                                                                                                               
1 0 1 0                                                                                                                                
1 1 0 1                                                                                                                                
1 0 1 0                                                                                                                                
Solution does not exist
