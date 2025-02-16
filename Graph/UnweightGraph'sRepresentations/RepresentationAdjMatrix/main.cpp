#include <bits/stdc++.h>

using namespace std;

void addGraphEdges(vector<vector<int>> &Graph, int EdgesStart, int EdgesEnd) {
	Graph[EdgesStart][EdgesEnd] = 1; 
	Graph[EdgesEnd][EdgesStart] = 1;
}

void printGraph (vector<vector<int>> &Graph, int VerticesNumb) {
	for(int EdgesStart = 0; EdgesStart < VerticesNumb; EdgesStart++) {
		for(int EdgesEnd = 0; EdgesEnd < VerticesNumb; EdgesEnd++) {
			cout << Graph[EdgesStart][EdgesEnd] << " ";
		}
		cout << endl;
	}
}

int main() {
	int V = 3;
	vector<vector<int>>	Graph(V, vector<int>(V, 0));
	addGraphEdges(Graph, 0, 1);
	addGraphEdges(Graph, 0, 2);
	addGraphEdges(Graph, 1, 2);
	printGraph(Graph, V);
}
