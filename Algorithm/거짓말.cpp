#include <bits/stdc++.h>

using namespace std;

int N, M;

bool danger[51];
int roots[51];

int findRoot(int idx)
{
	if (roots[idx] == idx)
		return idx;

	return roots[idx] = findRoot(roots[idx]);
}
void addEdge(int s, int e)
{
	int sRoot = findRoot(s);
	int eRoot = findRoot(e);

	if (sRoot < eRoot)
		roots[eRoot] = sRoot;
	else
		roots[sRoot] = eRoot;
}
bool isCycle(int n1, int n2)
{
	return findRoot(n1) == findRoot(n2);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	// rootTable 초기화
	for (int i = 1; i <= N; ++i)
		roots[i] = i;

	// 진실을 아는사람 리스트 입력
	int numTruth;
	cin >> numTruth;
	vector<int> truthList(numTruth);
	for (int i = 0; i < numTruth; ++i)
		cin >> truthList[i];

	// 파티 리스트 입력
	vector<vector<int>> partyList(M);
	for (int i = 0; i < M; ++i)
	{
		int num;
		cin >> num;
		partyList[i].resize(num);
		for (int j = 0; j < num; ++j)
			cin >> partyList[i][j];
		
		for (int j = 1; j < num; ++j)
			addEdge(partyList[i][0], partyList[i][j]);
	}

	set<int> dangerList;
	for (int truth : truthList)
		dangerList.insert(findRoot(truth)); // 최상위 루트만 넣어두면 돼


	int answer = M;
	for (auto& list : partyList)
	{
		for (int idx : list) // 파티원 검사
		{
			if (dangerList.count(findRoot(idx)))
			{
				--answer; // 안되는 파티
				break;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}