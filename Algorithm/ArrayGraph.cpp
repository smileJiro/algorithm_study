#include"ArrayGraph.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount || NOT_USED == pGraph->pVertex[vertexID])
	{
		printf("오류, 노드 정보[%d]\n", vertexID);
		ret = FAIL;
	}

	return ret;
}

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	int i = 0, j = 0;
	ArrayGraph* pReturn = nullptr;

	if (0 < maxVertexCount)
	{
		pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph)); // 그래프 동적할당

		if (nullptr == pReturn)
		{
			printf("오류, 메모리 할당(1), in createArrayGraph() \n");
			return nullptr;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
		pReturn->currentVertexCount = 0;
	}
	else
	{
		printf("오류, 최대 노드 개수는 0보다 커야합니다.\n");
		return nullptr;
	}

	pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount); // 노드 포인터 할당, 노드 개수만큼
	
	if (nullptr == pReturn->pVertex)
	{
		printf("오류, 메모리 할당(2), in createArrayGraph()\n");
		if (nullptr != pReturn)
			free(pReturn);

		return nullptr;
	}

	pReturn->ppAdjEdge = (int**)malloc(sizeof(int*) * maxVertexCount);
	if (nullptr == pReturn->ppAdjEdge)
	{
		printf("오류, 메모리 할당(3), in createArrayGraph()\n");
		if (nullptr != pReturn->pVertex)
			free(pReturn->pVertex);
		if (nullptr != pReturn)
			free(pReturn);

		return nullptr;
	}

	for (i = 0; i < maxVertexCount; ++i)
	{
		pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int) * maxVertexCount); // 각 행마다 열 개수만큼 1차원 배열 할당
		if(nullptr == pReturn->ppAdjEdge[i])
		{
			printf("오류, 메모리 할당(4), in createArrayGraph()\n");
			for (j = 0; j < i - 1; ++j)
			{
				if (nullptr != pReturn->ppAdjEdge[j])
					free(pReturn->ppAdjEdge[j]);
				if (nullptr != pReturn->ppAdjEdge)
					free(pReturn->ppAdjEdge);
				if (nullptr != pReturn->pVertex)
					free(pReturn->pVertex);
				if (nullptr != pReturn)
					free(pReturn);

				return nullptr;
			}
		}
	}

	memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
	for (i = 0; i < maxVertexCount; ++i)
	{
		memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
	}

	return pReturn;
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph* pReturn = nullptr;

	pReturn = createArrayGraph(maxVertexCount);

	if (nullptr != pReturn)
		pReturn->graphType = GRAPH_DIRECTED;

	return pReturn;
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
}

int isEmpthAG(ArrayGraph* pGraph)
{
	return 0;
}

int addVertexAG(ArrayGraph* pGraph, int vertexID) /* 추가하려는 노드 인덱스 유효성 검사, 이미 존재하지 않는지 여부 체크 후 add*/
{
	int ret = SUCCESS;

	if (nullptr != pGraph)
	{
		if (vertexID < pGraph->maxVertexCount) // 추가하려는 노드의 id가 최대 노드의 수보다 작다면, (유효 범위 체크)
		{
			if(NOT_USED == pGraph->pVertex[vertexID]) // 해당 노드가 존재하지 않을때,
			{
				pGraph->pVertex[vertexID] = USED; // 존재로 변경
				pGraph->currentVertexCount++;
			}
			else // 해당 노드가 이미 존재하는 경우
			{
				printf("오류, 이미 존재하는 노드[%d], in addVertexAG()\n", vertexID);
				ret = FAIL;
			}
		}
		else
		{
			printf("오류, 최대 노드 개수 초과 [%d], in addVertexAG()\n", pGraph->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	/* 일반 간선 추가는 가중치가 없으니 그냥 1 주는거고, 가중치 그래프는 내가 weight값을 지정하는거네 */
	return addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	int ret = SUCCESS;

	if (nullptr != pGraph)
	{
		if (SUCCESS != checkVertexValid(pGraph, fromVertexID))
		{
			ret = FAIL;
			return ret;
		}

		if (SUCCESS != checkVertexValid(pGraph, toVertexID))
		{
			ret = FAIL;
			return ret;
		}

		// 그래프의 간선에 가중치 추가 >>> 가중치 그래프가 아니라면 1 or 0
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;

		if (GRAPH_UNDIRECTED == pGraph->graphType)
		{
			/* 무방향성 그래프라면 대칭이니까 대칭을 맞춰준다. */
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
	}
	return ret;
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int ret = SUCCESS;
	int i = 0;


	// Graph 유효성 체크
	if (nullptr != pGraph)
	{
		// 노드 유효성 체크 
		if (SUCCESS != checkVertexValid(pGraph, vertexID))
		{
			ret = FAIL;
			return ret;
		}

		// vetexID가 포함된 모든 간선 제거
		for (i = 0; i < pGraph->maxVertexCount; ++i)
		{
			
			removeEdgeAG(pGraph, vertexID, i);
			removeEdgeAG(pGraph, i, vertexID);
		}
		// 해당 노드 정보 초기화 
		pGraph->pVertex[vertexID] = NOT_USED; 
	}

	return 0;
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	int ret = SUCCESS;

	if (nullptr != pGraph)
	{
		if (SUCCESS != checkVertexValid(pGraph, fromVertexID))
		{
			/* 애당초 지울 노드가 유효하지 않다면, */
			ret = FAIL;
			return ret;
		}

		if (SUCCESS != checkVertexValid(pGraph, toVertexID))
		{
			/* 애당초 지울 노드가 유효하지 않다면, */
			ret = FAIL;
			return ret;
		}

		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;

		if (GRAPH_UNDIRECTED == pGraph->graphType)
		{
			/* 무방향성 그래프라면, 대칭성 처리 */
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
		}
	}

	return ret;
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; ++i)
	{
		for (int j = 0; j < pGraph->maxVertexCount; ++j)
		{
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}

