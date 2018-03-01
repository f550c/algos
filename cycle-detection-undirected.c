#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge{
	int src,des;
};
struct Graph{
	int V,E; 
	struct Edge* edge; 
};
struct Graph* createGraph(int V,int E){
	struct Graph* graph =(struct Graph* )malloc( sizeof(struct Graph));
	graph ->E=E;
	graph->V=V;
	graph->edge=(struct Edge* )malloc( graph->E * (sizeof(struct Edge)));
	return graph;
}
int Find(int parent[],int i){
	if(parent[i]==  -1) return i;
	return(Find(parent,parent[i]));
}
void Union(int parent[],int x,int y){
	int xset=Find(parent,x);
	int yset=Find(parent,y);
	parent[xset]=yset;
}
int isCycle(struct Graph* graph){
	int *parent = (int*)malloc(graph->V *( sizeof(int)));
	memset(parent,-1,(sizeof(int)) * graph->V); 
	for(int i = 0; i < graph->E; ++i) {
		int x = Find(parent, graph->edge[i].src);
		int y = Find(parent, graph->edge[i].des);
		if (x == y)return 1;
		Union(parent, x, y);
	}
	return 0;
}
int main()
{   int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].des = 1;
    graph->edge[1].src = 1;
    graph->edge[1].des = 2;
    graph->edge[2].src = 0;
    graph->edge[2].des = 2;
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
    return 0;
}
