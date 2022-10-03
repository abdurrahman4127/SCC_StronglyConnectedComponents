#include <bits/stdc++.h>
using namespace std;

// scanning: src -> dst
void addEdge(vector<int> graph[], int u, int v){
    graph[u].push_back(v);
}

// runnng dfs on the transposed graph
void dfs(int node, vector<int> &visited, vector<int> transpose[]){
    cout << node << " ";
    visited[node] = 1;
    
    for(auto i : transpose[node]){
        if(visited[i] == 0){
            dfs(i, visited, transpose);
        }
    }
}


// transposing the graph (dist -> src)
void findTranspose(vector<int> transpose[], int V, vector<int> graph[], vector<int> &visited){
    for(int u=0; u<V; u++){
        visited[u] = 0;
        for(auto v : graph[u]){
            transpose[v].push_back(u);
        }
    }
}


// finding finish time
void dfs_topologicalSort(int node, stack<int> &stk, vector<int> &visited, vector<int> graph[]){
    visited[node] = 1;
    for(auto i : graph[node]){
        if(visited[i] == 0){
            dfs_topologicalSort(i, stk, visited, graph);
        }
    }
 
    stk.push(node);
}


// printing SCC
void printSCC(stack<int> &stk, vector<int> &visited, vector<int> transpose[]){
    int count = 0; 
    
    cout << "strongly connected components: \n";
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();

        if(visited[node] == 0){
            count++; 
            dfs(node, visited, transpose); // dfs on each popped unvisited node 
            cout << endl;
        }
    }

    cout << "number of SCC: " << count << endl;
}

// main function
int main(){
    int V, E;
    cin >> V >> E;

    vector<int> graph[V];
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        addEdge(graph, u, v);
    }

    // to store the order
    stack<int> stk;

    // to track un/visited nodes
    vector<int> visited(V, 0); 
    
    // topological sort (DFS) on (unvisited) nodes 
    for(int i=0; i<V; i++){
        if(visited[i] == 0){
            dfs_topologicalSort(i, stk, visited, graph);  
        }
    }

    // transposing the graph
    vector<int> transpose[V];
    findTranspose(transpose, V, graph, visited);

    printSCC(stk, visited, transpose);
    
    return 0;
}

/* test inputs:
9 10
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
7 6
7 8
*/
