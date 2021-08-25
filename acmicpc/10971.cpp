#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
//cache[cur][visited(비트마스크 형식으로 들어간다.)]
int cache[17][65536];

//입력받은 노드들의 정보이다. 
int dist[17][17];

//cache에 메모이제이션을 해서 dp로 푼다. cache[][]에 기록 되는 값은 항상 min이기 때문에 그 값을 쓰면 된다. 
int TSP(int cur, int visited) {
	
	//모든 노드를 방문 했으면 
	if(visited == (1 << n) - 1) return dist[cur][0];
	
	//ret 과 cache[cur][visited]는 메모리 공간을 공유 한다. 즉, ret 값을 바꿔 주면 cache값도 바뀐다. 
	int& ret = cache[cur][visited];
	
	//cache[cur][visited]의 값이 들어 있다. 즉, cache[cur][visited]를 메모이제이션 해서 사용하는 부분이다. 
	if(ret != 0) return ret;
	
	//ret을 무한대로 값을 주는 역할을 한다. 
	ret = INT_MAX; 
	for(int next = 0; next < n; next++) {
		//방문한 적이 있으면 검사하지 않고  넘어간다. 
		if(visited&(1 << next))continue;
		//노드가 연결되어 있지 않으면  검사하지 않고 넘어간다. 
		if(dist[cur][next]==0)continue;
		ret = min(ret, TSP(next, visited | (1<<next)) + dist[cur][next]);
	}
	return ret;
	
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &dist[i][j]);
		}
	}
	printf("%d", TSP(0,1));
	return 0;
}
