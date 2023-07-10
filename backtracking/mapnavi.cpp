#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

const int INF = numeric_limits<int>::max();

// Graph class to represent the map
class Graph
{
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    vector<int> dijkstra(int src)
    {
        vector<int> dist(V, INF);                          // distances from the source
        vector<bool> visited(V, false);                    // visited nodes
        priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

        // Distance from source to itself is 0
        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // Visit the node only once
            if (visited[u])
            {
                continue;
            }

            visited[u] = true;

            // Update the distances of adjacent nodes
            for (const auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v] && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

int main()
{
    int numVertices = 6;
    Graph graph(numVertices);

    // Add edges to represent the map
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 1, 2);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 2);

    int source = 0;
    vector<int> shortestDistances = graph.dijkstra(source);

    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
