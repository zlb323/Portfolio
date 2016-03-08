#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

#include "Header.h"

int i = 0;

void inputGraph(Graph& c, ifstream& fin) //self explanatory
{
	int current;
	for (int i = 0; i < c.getvertcount(); i++)
		for (int j = 0; j < c.getvertcount(); j++)
		{
			fin >> current;
			c.addEdge(i, j, current);
		}
}

bool checktree(bool* t, int c) //checks if node is already in the tree
{
	for (int i = 0; i < c; i++)
	{
		if (t[i] == false) return false;
	}
	return true;
}

Graph minSpanningTree(Graph G)
{
	int c = G.getvertcount(); //save the value of the size of this graph
	int temp = 0, saved = 100, savednode1 = 0,savednode2 = 0, i; //temp variables
	Graph min(c); 
	bool* intree; 
	intree = new bool[c]; //create an array of the size of the graph to keep track of which nodes are in the min spanning tree already
	for (i = 0; i < c; i++) intree[i] = false;
	intree[0] = true;
	while (!checktree(intree, c))
	{
		saved = 100;
		for (i = 0; i < c; i++)
		{
			if (intree[i] == true)
			{
				for (int j = 0; j < c; j++)
				{
					temp = G.edgeWeight(i, j);
					if ((temp > 0) && (temp < saved) && (intree[j] == false)) //find the next smallest node to add
					{
						saved = temp;
						savednode1 = j;
						savednode2 = i;
					}
				}
			}
		}
		min.addEdge(savednode2, savednode1, saved);//add the node to the tree
		intree[savednode1] = true;
	}
	return min;
}

int treesum(Graph G)
{
	int total = 0;
	int count = G.getvertcount();
	for (int i = 0; i < count; i++)
		for (int j = i; j < count; j++) total += G.edgeWeight(i, j);
	return total;
}

bool check(vector<int> x, int i)//check if node in tree for print path function
{
	for (int o = 0; o < x.size(); o++)
		if (x.at(o) == i) return true;
	return false;
}

bool check2(vector<bool> in)//djikstra check
{
	for (int i = 0; i < in.size(); i++) if (in.at(i) == false) return false;
	return true;
}

Graph dijkstra(Graph G, int m)
{
	int size = G.getvertcount();
	int smallval, smalli, smallj;
	Graph spt(size);
	vector<int> paths(size, 0);
	vector<bool> in(size, false);
	in.at(m) = true;
	while (!check2(in))
	{
		smallval = 9999;
		for (int i = 0; i < size; i++)
			if (in.at(i) == true)
				for (int j = 0; j < size; j++)
				{
					if ((G.edgeWeight(i, j) != 0) && (!in.at(j)))
						if ((paths.at(i) + G.edgeWeight(i, j)) < smallval)
						{
							smallval = G.edgeWeight(i, j);
							smalli = i;
							smallj = j;
						}
				}
		if (smallval != 9999) {
			paths.at(smallj) = smallval;
			in.at(smallj) = true;
			spt.addEdge(smalli, smallj, smallval);
		}
	}
	return spt;
}

void rec2(Graph G, int m, int& n, vector<int>& ans, bool* in)
{
	ans.push_back(m);
	for (int i = 0; i < G.getvertcount(); i++)
	{
		if (G.edgeWeight(m, i) != 0)
		{
			if (!check(ans, i))
			{
				if (i == n) {
					ans.push_back(i);
				}
				else rec2(G, i, n, ans, in);
				if (i == n)
				{
					ans.at(0);
					n = m;
					in[m] = false;
					return;
				}
			}
		}
	}
	ans.pop_back();
}

void printpath(Graph G, int m, int n, ofstream& fout)
{
	int k = n;
	vector<int> ans;
	bool* in;
	in = new bool[G.getvertcount()];
	for (int i = 0; i < G.getvertcount(); i++) in[i] = false;
	rec2(G, m, n, ans, in);
	if (!ans.empty()) 
	{
		fout << "The path from " << m << " to " << k << " is: ";
		for (int i = 0; i < ans.size(); i++)
		{
			fout << ans.at(i) << ", ";
		}
		fout << endl;
	}
}

void printpathlength(Graph G, int m, int n, ofstream& fout)
{
	int k = n;
	vector<int> ans;
	bool* in;
	in = new bool[G.getvertcount()];
	for (int i = 0; i < G.getvertcount(); i++) in[i] = false;
	rec2(G, m, n, ans, in);
	int temp = 0;
	if (!ans.empty())
	{
		for (int i = 0; i < ans.size()-1; i++)
		{
			fout << G.edgeWeight(ans.at(i +1), ans.at(i)) << ", ";
			temp += G.edgeWeight(ans.at(i + 1), ans.at(i));
		}
		fout << "Total weight from " << m << " to " << k << " is: " << temp << endl;
	}
}

void main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	Graph G(10);
	Graph G2(25);
	Graph min(10), min2(25);
	Graph SPT(10), SPT2(25);
	inputGraph(G, fin);
	inputGraph(G2, fin);
	min = minSpanningTree(G);
	min.printGraph(fout);
	fout << "Sum of the min spanning tree of the above graph is " << treesum(min) << endl;
	SPT = dijkstra(G, 1);
	fout << "the above graph shortest path from node 1 to all:" << endl;
	SPT.printGraph(fout);
	printpath(SPT, 1, 8, fout);
	printpathlength(SPT, 1, 8, fout);
	min2 = minSpanningTree(G2);
	min2.printGraph(fout);
	fout << "sum of the min spanning tree of the above graph is: " << treesum(min2) << endl;
	SPT2 = dijkstra(G2, 0);
	printpath(SPT2, 0, 24, fout);
	printpathlength(SPT2, 0, 24, fout);
	printpath(SPT2, 0, 23, fout);
	printpathlength(SPT2, 0, 23, fout);
	system("pause");
}
