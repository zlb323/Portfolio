#pragma once
class Graph {
private:
	int** adjacencyMatrix;
	int vertexCount;
public:
	int getvertcount()
	{
		return vertexCount;
	}

	Graph(int vertexCount)
	{
	this->vertexCount = vertexCount; 
	adjacencyMatrix = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		adjacencyMatrix[i] = new int[vertexCount]; 

	for (int j = 0; j < vertexCount; j++) adjacencyMatrix[i][j] =0;
	}
	}
	
	void addEdge(int i, int j, int weight)
	{
	if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) 
	{
		adjacencyMatrix[i][j] = weight;
		adjacencyMatrix[j][i] = weight;//delete this line if directed graph
	}
	} 
	
	void removeEdge(int i, int j)
	{ 
		if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) 
		{
			adjacencyMatrix[i][j] = 0; adjacencyMatrix[j][i] = 0; //delete this line if directed graph 
		}
	}
	
	bool isEdge(int i, int j)
	{
		if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) return true;
		else return false;
	}
	int edgeWeight(int i, int j)
	{
		if (isEdge (i, j)) return adjacencyMatrix[i][j];
		else return 0;
	}
	//printGraph below has not been debugged so it may not work as shown. I.e., you may need to modify it. //Also it only works for graphs with 25 nodes or fewer. Assume weights are integers ranging from 0 to 99. 
	void printGraph (ofstream& fout) 
	{
		int i;
		fout << setw(3) << " ";
		for (i = 0; i < vertexCount; i++) fout << setw(3) << i;
		fout << endl;
		for (i = 0; i < vertexCount; i++)
		{
			fout << setw(3) << i;
			for (int j = 0; j < vertexCount; j++) fout << setw(3) << adjacencyMatrix[i][j];
			fout << endl;
		}
	}
	~Graph() 
	{
		for (int i = 0; i < vertexCount; i++) 
			delete[] adjacencyMatrix[i];
		delete[] adjacencyMatrix; 
	}
};

struct pathNode {
	int i;
	pathNode* next;
};
