#include <bits/stdc++.h>
using namespace std;


void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}

int main() {
    // int n=6, m=7;
    int n, m;
    cin >> n >> m;

	vector<int> adj[n+1]; 
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

	// adj[1].push_back(3);
	// adj[2].push_back(1);
	// adj[3].push_back(2);
	// adj[3].push_back(5);
	// adj[4].push_back(6);
	// adj[5].push_back(4);
	// adj[6].push_back(5);
	
	stack<int> st;
	vector<int> vis(n+1, 0); 
	for(int i = 1;i<=n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n+1]; 
	
	for(int i = 1;i<=n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}

/*
6 7
1 3
2 1
3 2
3 5
4 6
5 4
6 5
*/

/*
0 based means graph node numbering starts from 0 to n-1, so you 
need at max an adjacency index of n-1, 
thereby adj[n] will suffice
1 based means graph node numbering starts from 1 to n, 
so you need at max an adjacency index of n, 
thereby adj[n+1] will suffice
*/

7 8
1 2
2 3
3 4
4 1
3 5
5 7
7 6
6 5