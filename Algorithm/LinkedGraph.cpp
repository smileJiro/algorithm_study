#include"LinkedGraph.h"

LinkedGraph::LinkedGraph(GRAPH_TYPE type)
	: m_type(type)
{

}

LinkedGraph::~LinkedGraph()
{

}

bool LinkedGraph::addVertex(int vertexID)
{
	if (m_adj.end() != m_adj.find(vertexID))
		return false;

	ListNode addNode;
	addNode.data.vertexID = vertexID;
	addNode.data.weight = 0;
	m_adj.emplace(vertexID, addNode);

	return true;
}

bool LinkedGraph::addEdge(int fromVertexID, int toVertexID)
{
	return addEdgeWithWeight(fromVertexID, toVertexID, 1);
}

bool LinkedGraph::addEdgeWithWeight(int fromVertexID, int toVertexID, int weight)
{
	ListNode* fromNode = findNode(fromVertexID);
	ListNode* toNode = findNode(toVertexID);
	if (nullptr == fromNode || nullptr == toNode)
		return false;

	/* 가중치 추가 */
	fromNode->data.weight = weight;
	toNode->data.weight = weight;

	/* 간선 연결 */
	fromNode->listAdjacent.push_back(toNode->data);
	
	/* 대칭 맞춰주기 */
	if (GRAPH_TYPE::UNDIRECTED == m_type)
	{
		toNode->listAdjacent.push_back(fromNode->data);
	}

	return true;
}



ListNode* LinkedGraph::findNode(int vertexID)
{
	auto iter = m_adj.find(vertexID);

	if (m_adj.end() == iter)
		return nullptr;

	return &(iter->second);
}

bool LinkedGraph::dijkstra(int toVertexID)
{
	ListNode* toVertex = findNode(toVertexID);
	if (nullptr == toVertex)
		return false;

	m_StartNodeIndex = toVertexID;
	// 1. 모든 노드 전부 INF 삽입
	for (auto& node : m_adj)
	{
		m_distanceFromStart[node.first] = INF;
	}
	// 2. 자기 자신 노드만 0 삽입
	m_distanceFromStart[toVertexID] = 0;



	unordered_set<int> visited;
	// <vertexID, shortestdistance>
	priority_queue <pair<int, int>, vector<std::pair<int, int>>, Compare> minHeap;
	// 3. 시작 노드 삽입
	minHeap.push(make_pair(toVertexID, 0));
	while (!minHeap.empty())
	{
		pair<int, int> curNodeInfo = minHeap.top();
		minHeap.pop();

		if (visited.count(curNodeInfo.first))
			continue;
		visited.insert(curNodeInfo.first);

		ListNode* pCurNode = findNode(curNodeInfo.first);
		if (nullptr != pCurNode)
		{
			for (auto& adjNode : pCurNode->listAdjacent)
			{
				// 현재 노드의 최단거리 + 인접 노드로의 거리 < 인접 노드의 최단거리
				int newDistance = m_distanceFromStart[curNodeInfo.first] + adjNode.weight;
				if (newDistance < m_distanceFromStart[adjNode.vertexID])
				{
					m_distanceFromStart[adjNode.vertexID] = newDistance;
				}

				// 큐에 들어가는건 여러번 들어가도 괜찮아.
				minHeap.push(make_pair(adjNode.vertexID, m_distanceFromStart[adjNode.vertexID]));
			}
		}

	}

	return true;
}

