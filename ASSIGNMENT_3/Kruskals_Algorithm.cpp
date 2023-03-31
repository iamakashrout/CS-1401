// QUESTION-4
// KRUSKAL'S ALGORITHM FOR MINIMUM SPANNING TREE

#include<bits/stdc++.h>
using namespace std;

class DSU { // Disjoint Set Union data structure class
    int *parent; // parent of every element
    int *rank; // rank to decide which element will be parent when union is done

public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++){ // initializing parent and rank with -1
            parent[i] = -1;
            rank[i] = -1;
        }
    }

    int find(int i){ // function to find parent of an elemnt
        if(parent[i]==-1){
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int x, int y){ // function for union of two elements
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1]>rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph{ // class for Graph data structure
    vector<vector<int>> edgeList; // representation in Edge List format
    int V;

public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int x, int y, int w){ // function to insert edges with weights in graph
        edgeList.push_back({w, x, y});
    }

    void kruskals(){ // function for Kruskal's Algorithm
        sort(edgeList.begin(), edgeList.end()); // sorting all the edges according to weights
        DSU s(V);
        int ans = 0; // weight of tree
        for(auto edge: edgeList){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if(s.find(x)!=s.find(y)){ // cheecking if no cycle formation takes place
                s.unite(x, y); // merging different components into single tree
                ans += w;
            }
        }
        cout << "Total weight of minimum spanning tree is: " << ans << endl;
    }
};

int main(){
    Graph g(8); // initializing the graph
    // adding edges with their vertices and weights;
    g.addEdge(0, 1, 8);
    g.addEdge(0, 5, 10);
    g.addEdge(0, 7, 4);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 4, 10);
    g.addEdge(1, 5, 7);
    g.addEdge(1, 7, 9);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 3);
    g.addEdge(3, 4, 25);
    g.addEdge(3, 5, 18);
    g.addEdge(3, 6, 2);
    g.addEdge(4, 5, 2);
    g.addEdge(4, 6, 7);
    g.addEdge(6, 7, 3);

    // calling Kruskal's Algorithm function
    g.kruskals();
    return 0;
}