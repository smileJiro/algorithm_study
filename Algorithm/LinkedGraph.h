#pragma once
#include <list>
#include <vector>
#include <map>
#include <set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

#define INF 100000000
enum class GRAPH_TYPE { UNDIRECTED, DIRECTED, LAST};


typedef struct GraphVertex
{
	int vertexID;
	int weight;
};

typedef struct ListNode // 노드와 인접 리스트
{
	GraphVertex data = { -1, 0 };
	list<GraphVertex> listAdjacent;
};



class LinkedGraph
{
public:
	LinkedGraph() = delete;
	LinkedGraph(GRAPH_TYPE type);
	~LinkedGraph();

public:
	bool addVertex(int vertexID); // 노드 추가
	bool addEdge(int fromVertexID, int toVertexID); // 간선 추가
	bool addEdgeWithWeight(int fromVertexID, int toVertexID, int weight); // 간선 + 가중치 추가
	ListNode* findNode(int vertexID);

public:
	int getDistanceFromStart(int startVertexID, int fromVertexID)
	{
		if (startVertexID != m_StartNodeIndex)
			dijkstra(startVertexID);

		return m_distanceFromStart[fromVertexID];
	}

public:
	bool dijkstra(int toVertexID); // 최단 경로의 길이



private:
	unordered_map <int, ListNode> m_adj;
	GRAPH_TYPE m_type;

	int m_StartNodeIndex = -1;
	unordered_map<int, int> m_distanceFromStart;
	
};

struct Compare
{
	bool operator()(pair<int,int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}

};
