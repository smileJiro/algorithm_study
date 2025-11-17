#include <stdio.h>
#include<stdlib.h>
#include"ArrayGraph.h"
#include"LinkedGraph.h"
#include"MySort.h"
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;
// 문자열
void func(char* str, char r)
{
	int readIndex = 0;
	int writeIndex = 0;

	while ('\0' != str[readIndex])
	{
		if (r != str[readIndex])
		{
			str[writeIndex++] = str[readIndex];
		}

		++readIndex;
	}

	str[writeIndex] = '\0';

}

bool samestr(char* src, char* dst)
{
	unordered_map<char, int> umap;
	int i = 0;
	while ('\0' != src[i])
	{
		umap[src[i]] += 1;

		++i;
	}
	i = 0;
	while ('\0' != dst[i])
	{
		umap[dst[i]] -= 1;
		++i;
	}

	i = 0;
	int size = umap.size();
	for (auto& iter : umap)
	{
		if (iter.second != 0)
			return false;
	}
	return true;
}


vector<vector<int>> graph;
vector<bool> visited;
void dfs(int idx)
{
	visited[idx] = true;
	
	for (int i = 0; i < graph[idx].size(); ++i)
	{
		int next = graph[idx][i];
		if (false == visited[next])
			dfs(next);
	}
}

vector<vector<int>> mapData = {
	{0, 0, 1, 1},
	{0, 1, 0, 0},
	{0, 0, 0, 1},
	{1, 1, 1, 0}
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void Fill(int x, int y, int size)
{
	/* 범위를 벗어나거나, 0이 아닌 경우 return */
	if (0 > x || size <= x || 0 > y || size <= y)
		return;
	if (0 != mapData[y][x])
		return;

	mapData[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		Fill(x + dx[i], y + dy[i], size);
	}
}

int main(int argc, char* argv[])
{

	int n = 4;

	Fill(0,0,4);

	int a = 0;



	//int n = 5; // 예시 노드 수
	//graph.resize(n);
	//visited.resize(n, false);

	//// 예시 그래프 구성 (무방향 그래프)
	//graph[0].push_back(1);
	//graph[1].push_back(0);
	//graph[1].push_back(2);
	//graph[2].push_back(1);
	//graph[2].push_back(3);
	//graph[3].push_back(2);
	//graph[3].push_back(4);
	//graph[4].push_back(3);

	//dfs(0); // 0번 노드부터 탐색 시작
	











	//int i = 0;
	//ArrayGraph* pG1 = nullptr;
	//ArrayGraph* pG2 = nullptr;
	//ArrayGraph* pG4 = nullptr;

	//// 그래프 생성

	//pG1 = createArrayGraph(6); // 노드 6개인 무방향성 그래프 생성
	//pG2 = createArrayDirectedGraph(6); // 노드 6개인 방향성 그래프 생성
	//pG4 = createArrayDirectedGraph(6);

	//if (nullptr != pG1 && nullptr != pG2 && nullptr != pG4)
	//{
	//	// 그래프 초기화 : 노드 추가 
	//	for (int i = 0; i < 6; ++i)
	//	{
	//		addVertexAG(pG1, i);
	//		addVertexAG(pG2, i);
	//		addVertexAG(pG4, i);
	//	}
	//	// 그래프 초기화 : 간선 추가
	//	addEdgeAG(pG1, 0, 1);
	//	addEdgeAG(pG1, 0, 2);
	//	addEdgeAG(pG1, 1, 2);
	//	addEdgeAG(pG1, 2, 3);
	//	addEdgeAG(pG1, 3, 4);
	//	addEdgeAG(pG1, 3, 5);
	//	addEdgeAG(pG1, 4, 5);

	//	addEdgeAG(pG2, 0, 1);
	//	addEdgeAG(pG2, 1, 2);
	//	addEdgeAG(pG2, 2, 0);
	//	addEdgeAG(pG2, 2, 1);
	//	addEdgeAG(pG2, 2, 3);
	//	addEdgeAG(pG2, 3, 2);
	//	addEdgeAG(pG2, 3, 4);
	//	addEdgeAG(pG2, 4, 5);
	//	addEdgeAG(pG2, 5, 3);
	//	
	//	addEdgewithWeightAG(pG4, 0, 1, 4);
	//	addEdgewithWeightAG(pG4, 1, 2, 1);
	//	addEdgewithWeightAG(pG4, 2, 0, 2);
	//	addEdgewithWeightAG(pG4, 2, 1, 3);
	//	addEdgewithWeightAG(pG4, 2, 3, 2);
	//	addEdgewithWeightAG(pG4, 3, 2, 1);
	//	addEdgewithWeightAG(pG4, 3, 4, 1);
	//	addEdgewithWeightAG(pG4, 4, 5, 1);
	//	addEdgewithWeightAG(pG4, 5, 3, 2);

	//	// 그래프 정보 출력
	//	printf("G1 : Undirected \n");
	//	displayArrayGraph(pG1);
	//	printf("G2 : Directed\n");
	//	displayArrayGraph(pG2);
	//	printf("G4 : Directed Weighted\n");
	//	displayArrayGraph(pG4);

	//	// 그래프 삭제
	//	deleteArrayGraph(pG1);
	//	deleteArrayGraph(pG2);
	//	deleteArrayGraph(pG4);
	//}

	//LinkedGraph G(GRAPH_TYPE::UNDIRECTED);
	//// 노드 추가
	//// 노드 1~20 추가
	//for (int i = 1; i <= 20; ++i) {
	//	G.addVertex(i);
	//}

	//// 임의의 가중치 간선 추가 (랜덤 느낌으로 구성)
	//G.addEdgeWithWeight(1, 2, 4);
	//G.addEdgeWithWeight(1, 3, 1);
	//G.addEdgeWithWeight(2, 4, 7);
	//G.addEdgeWithWeight(2, 5, 3);
	//G.addEdgeWithWeight(3, 5, 2);
	//G.addEdgeWithWeight(3, 6, 5);
	//G.addEdgeWithWeight(4, 7, 1);
	//G.addEdgeWithWeight(5, 7, 8);
	//G.addEdgeWithWeight(5, 8, 10);
	//G.addEdgeWithWeight(6, 8, 2);
	//G.addEdgeWithWeight(7, 9, 6);
	//G.addEdgeWithWeight(8, 9, 3);
	//G.addEdgeWithWeight(8, 10, 1);
	//G.addEdgeWithWeight(9, 11, 7);
	//G.addEdgeWithWeight(10, 12, 2);
	//G.addEdgeWithWeight(11, 13, 4);
	//G.addEdgeWithWeight(12, 14, 5);
	//G.addEdgeWithWeight(13, 15, 1);
	//G.addEdgeWithWeight(14, 15, 3);
	//G.addEdgeWithWeight(14, 16, 7);
	//G.addEdgeWithWeight(15, 17, 8);
	//G.addEdgeWithWeight(16, 18, 6);
	//G.addEdgeWithWeight(17, 19, 2);
	//G.addEdgeWithWeight(18, 20, 4);
	//G.addEdgeWithWeight(19, 20, 1);
	//int distance = G.getDistanceFromStart(20, 18);

	//vector<int> array;

	//array.push_back(80);
	//array.push_back(50);
	//array.push_back(70);
	//array.push_back(10);
	//array.push_back(60);
	//array.push_back(20);
	//array.push_back(40);
	//array.push_back(30);

	//MySort sort;
	//sort.sort(array, MySort::MERGE);
	char str[] = "Hello World";
	func(str, 'r');

	char src[] = "apple";
	char dst[] = "palepd";
	bool result = samestr(src, dst);
	return 0;
}