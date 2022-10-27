// Problem Statement: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labeled with a distinct integer in the range 0 to V – 1. A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node. You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Example 1:

// Input Format: N = 7, E = 7



// Result: {2 4 5 6}


// Explanation: Here terminal nodes are 5 and 6 as they have no outgoing edges.


// From node 0: two paths are there 0->2->5 and 0->1->3->0. 
// The second path does not end at a terminal node. So it is not 
// a safe node.
// From node 1: two paths exist: 1->3->0->1 and 1->2->5.
// But the first one does not end at a terminal node. So it is not a safe node.


// From node 2: only one path: 2->5 and 5 is a terminal node.
// So it is a safe node.


// From node 3: two paths: 3->0->1->3 and 3->0->2->5 
// but the first path does not end at a terminal node. 
// So it is not a safe node.


// From node 4: Only one path: 4->5 and 5 is a terminal node. 
// So it is also a safe node.


// From node 5: It is a terminal node. 
// So it is a safe node as well.


// From node 6: It is a terminal node. 
// So it is a safe node as well.


// Example 2:

// Input Format: N = 4, E = 4



// Result: {3}


// Explanation: Node 3 itself is a terminal node and it 
// is a safe node as well. But all the paths 
// from other nodes do not lead to a terminal node. So they are 
// excluded from the answer.

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[],
 int pathVis[], 
        int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;
				return true;
			}
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;
	}
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}
};


int main() {

	//V = 12;
	vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, 
        {8},{9}};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}
