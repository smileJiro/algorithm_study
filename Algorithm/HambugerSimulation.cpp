#include"pch.h"

#include"MyQueue.h"

#define CUSTOM_COME_TERM 15

#define CHE 0
#define BUL 1
#define DUB 2
#define TIME_CHE 12
#define TIME_BUL 15
#define TIME_DUB 24

float computeDemandFactor(int capacity, int launchTime, int simulationCount)
{
	srand(time(nullptr));
	/* 0. 입장 인원 계산 */
	int failedCount = 0;
	for (int i = 0; i < simulationCount; ++i)
	{
		MyQueue q;
		int makeProcess = 0;
		int cheCount = 0;
		int bulCount = 0;
		int dubCount = 0;
		bool isFailed = false;
		for (int j = 0; j < launchTime; ++j)
		{


			/* 2. 버거 주문 */
			if (j % CUSTOM_COME_TERM == 0)
			{
				if (capacity > q.getSize())
				{
					int randOrder = rand() % 3;
					switch (randOrder)
					{
					case CHE:
						q.enqueue(TIME_CHE);
						++cheCount;
						break;
					case BUL:
						q.enqueue(TIME_BUL);
						++bulCount;
						break;
					case DUB:
						q.enqueue(TIME_DUB);
						++dubCount;
						break;
					default:
						break;
					}
				}
				else
				{
					cout << "failed " << "\n";
					cout << "current Time : " << j << "\n";
					++failedCount;
					isFailed = true;
					break;
				}
				
			}

			/* 3. 버거 제작 현황 */
			if (makeProcess <= 0)
			{
				pair<bool, int> pair = q.dequeue();
				if (true == pair.first)
					makeProcess = pair.second;
			}

			if (makeProcess > 0)
				--makeProcess;
		}

		if (false == isFailed)
		{
			cout << "Success" << "\n";
			cout << "CheezeOrder : " << cheCount << "\n";
			cout << "BulgogiOrder : " << bulCount << "\n";
			cout << "DubbleOrder : " << dubCount << "\n";
			cout << "현재 대기인원 : " << q.getSize() << "\n";
		}

	}
	

	return float(simulationCount - failedCount) / float(simulationCount);
}
int main()
{
	int launchTime = 60 * 60;

	float f = computeDemandFactor(30, launchTime, 1000);

	cout << "성공률 : " << f * 100.f << "%\n";
	return 0;
}