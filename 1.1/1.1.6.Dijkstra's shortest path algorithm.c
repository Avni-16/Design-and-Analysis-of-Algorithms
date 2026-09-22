#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	int dist[MAX], visited[MAX], parent[MAX];
int i, j, count, min, next;

for(i = 1; i <= n; i++) {
    dist[i] = INFINITY;
    visited[i] = 0;
    parent[i] = -1;
}

dist[startnode] = 0;

for(count = 1; count <= n - 1; count++) {
    min = INFINITY;
    next = -1;

    for(i = 1; i <= n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            next = i;
        }
    }

    if(next == -1)
        break;

    visited[next] = 1;

    for(i = 1; i <= n; i++) {
        if(!visited[i] && G[next][i] != 0 &&
           dist[next] + G[next][i] < dist[i]) {
            dist[i] = dist[next] + G[next][i];
            parent[i] = next;
        }
    }
}
	printf("Node\tDistance\tPath\n");

for(i = 1; i <= n; i++) {
    if(i == startnode)
        continue;

    if(dist[i] == INFINITY) {
        printf("%4d\t%8s\tNO PATH\n", i, "INF");
    } else {
        printf("%4d\t%8d\t", i, dist[i]);

        j = i;
        while(j != -1) {
            printf("%d", j);
            j = parent[j];
            if(j != -1)
                printf("<-");
        }
        printf("\n");
    }
}
	
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
