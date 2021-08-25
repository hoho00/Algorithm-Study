#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
//cache[cur][visited(��Ʈ����ũ �������� ����.)]
int cache[17][65536];

//�Է¹��� ������ �����̴�. 
int dist[17][17];

//cache�� �޸������̼��� �ؼ� dp�� Ǭ��. cache[][]�� ��� �Ǵ� ���� �׻� min�̱� ������ �� ���� ���� �ȴ�. 
int TSP(int cur, int visited) {
	
	//��� ��带 �湮 ������ 
	if(visited == (1 << n) - 1) return dist[cur][0];
	
	//ret �� cache[cur][visited]�� �޸� ������ ���� �Ѵ�. ��, ret ���� �ٲ� �ָ� cache���� �ٲ��. 
	int& ret = cache[cur][visited];
	
	//cache[cur][visited]�� ���� ��� �ִ�. ��, cache[cur][visited]�� �޸������̼� �ؼ� ����ϴ� �κ��̴�. 
	if(ret != 0) return ret;
	
	//ret�� ���Ѵ�� ���� �ִ� ������ �Ѵ�. 
	ret = INT_MAX; 
	for(int next = 0; next < n; next++) {
		//�湮�� ���� ������ �˻����� �ʰ�  �Ѿ��. 
		if(visited&(1 << next))continue;
		//��尡 ����Ǿ� ���� ������  �˻����� �ʰ� �Ѿ��. 
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
