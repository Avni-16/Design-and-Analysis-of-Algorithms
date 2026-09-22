#include <stdio.h>
#define INF 99999
#define MAX 100

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, source;
    struct Edge edge[MAX];

    scanf("%d", &V);
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edge[i].src, &edge[i].dest, &edge[i].weight);
    }

    scanf("%d", &source);

    int dist[MAX], parent[MAX];

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < E; j++) {
        int u = edge[j].src;
        int v = edge[j].dest;
        int w = edge[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    // Print paths
    for (int i = 1; i <= V; i++) {
        if (i == source)
            continue;

        if (dist[i] == INF) {
            printf("%d INF None\n", i);
        } else {
            int path[MAX], count = 0;
            int current = i;

            while (current != -1) {
                path[count++] = current;
                current = parent[current];
            }

            printf("%d %d ", i, dist[i]);

            for (int j = count - 1; j >= 0; j--) {
                printf("%d", path[j]);
                if (j > 0)
                    printf("->");
            }

            printf("\n");
        }
    }

    return 0;
}
