#include<bits/stdc++.h>
#include<queue>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        
        float costA = (float)a.first / (float)a.second;
        float costB = (float)b.first / (float)b.second;
        if(costA == costB)
        { 
            // 만약 확률이 같은 경우 b cost가 더 큰 것이 우선순위 상위
            return a.second < b.second;
        }

        return costA > costB;
    }

};

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    // 1. A의 흔적 별 B의 흔적을 저장하는 데이터를 구성한다.
    // 2. 이때 B의 흔적은 민 힙으로 구성한다.
    // 3. A의 흔적이 큰  
    // pair<a, costB>
    int costA = n - 1;
    int costB = m - 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap; // 최소힙 3개를 사용한다.
    for (int i = 0; i < info.size(); ++i)
    {
        minHeap.push(make_pair(info[i][0], info[i][1]));
    }

    while (0 < costB)
    {
        int useB = minHeap.top().second;
        while (useB > costB)
        {
            pair<int, int> tmp = minHeap.top();
            minHeap.pop();
            useB = minHeap.top().second;
            minHeap.push(tmp);
        }

        if (0 > costB - useB)
        {
            break;
        }
        else
        {
            minHeap.pop();
            costB -= useB;
        }

    }

    while (!minHeap.empty())
    {
        costA -= minHeap.top().first;
        minHeap.pop();
    }

    if (0 > costA)
        return -1;
    answer = n - 1 - costA;
    return answer;
}

int main()
{
    vector<vector<int>> info(2);
    info[0].push_back(3);
    info[0].push_back(3);

    info[1].push_back(3);
    info[1].push_back(3);

    //info[2].push_back(2);
    //info[2].push_back(1);
    int i = solution(info, 7, 1);
	return 0;
}