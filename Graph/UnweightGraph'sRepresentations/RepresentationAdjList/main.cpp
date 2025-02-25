#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &Graph, int StartVertice, int EndVertice) {
	Graph[StartVertice].push_back(EndVertice);
	Graph[EndVertice].push_back(StartVertice);
}

void printGraph(vector<vector<int>> &Graph, int VerticesNumber) {
	for(int startVertice = 0; startVertice < VerticesNumber; startVertice++) {
		cout << startVertice << " ->";
		for(int endVertice = 0; endVertice < Graph[startVertice].size(); endVertice++) {
			cout << Graph[startVertice][endVertice] << " ";
		}
		cout << endl;
	}
}

int main() {
	int Vertices = 4;
	vector<vector<int>> Graph(Vertices);
	addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 2);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 2, 3);
	printGraph(Graph, Vertices);
	return 0;
}

