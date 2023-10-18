// C++ implementation to demonstrate 
// the above mentioned approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the distance 
// from the source to other nodes 
void BFS(int curr, int N, vector<bool>& vis, 
		vector<int>& dp, vector<int>& v, 
		vector<vector<int> >& adj) 
{ 

	while (curr <= N) { 

		// Current node 
		int node = v[curr - 1]; 
		cout << node << ", "; 

		for (int i = 0; i < adj[node].size(); i++) { 

			// Adjacent node 
			int next = adj[node][i]; 

			if ((!vis[next]) 
				&& (dp[next] < dp[node] + 1)) { 

				// Stores the adjacent node 
				v.push_back(next); 

				// Increases the distance 
				dp[next] = dp[node] + 1; 

				// Mark it as visited 
				vis[next] = true; 
			} 
		} 
		curr += 1; 
	} 
} 

// Function to print the distance 
// from source to other nodes 
void bfsTraversal( 
	vector<vector<int> >& adj, 
	int N, int source) 
{ 
	// Initially mark all nodes as false 
	vector<bool> vis(N + 1, false); 

	// Initialize distance array with 0 
	vector<int> dp(N + 1, 0), v; 

	v.push_back(source); 

	// Initially mark the starting 
	// source as 0 and visited as true 
	dp = 0; 
	vis = true; 

	// Call the BFS function 
	BFS(1, N, vis, dp, v, adj); 
} 

// Driver code 
int main() 
{ 
	// No. of nodes in graph 
	int N = 4; 

	// Creating adjacency list 
	// for representing graph 
	vector<vector<int> > adj(N + 1); 
	adj[0].push_back(1); 
	adj[0].push_back(2); 
	adj[1].push_back(2); 
	adj[2].push_back(0); 
	adj[2].push_back(3); 
	adj[3].push_back(3); 

	// Following is BFS Traversal 
	// starting from vertex 2 
	bfsTraversal(adj, N, 2); 

	return 0; 
} 
