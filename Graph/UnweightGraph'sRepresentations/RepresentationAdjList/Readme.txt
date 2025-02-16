									AdjList Graph

Overview:
	For Graph that use AdjList to represent you can use a vector of list
	(maybe liek this: vector<list<int>>)

	But in this example I use a new way that represent AdjList Graph is: using vector of vector to represent it(vector<vector<int>>)

	Unlike AdjMatrix we push 1 for two connected vertices and 0 for Unconnected vertices
	Now we push vertices number in Graph vector, for example:

Example:
we want to present that  vertice 0 connect to vertice 4 we can use this

	vector<vector<int>> Graph;
	Graph[0].push_back(4);   // start edge is 0
	Graph[4].push_back(0); 	 // start edge is 4
		
	0 -> 4
	4 -> 0

Additional:
	for weighted Graph we can use AdjList like this;

	vector<vector<pair<int, int>>> Graph;
	
	pair,first is vertice Number in the graph,
	pair.second	is weigth of edge that from start edges to pair.first vertice.

