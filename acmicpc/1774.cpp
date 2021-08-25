#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct {
	long long x;
	long long y;
}Point;

typedef struct {
	int from;
	int to;
	double val;
}Edge;

int parent[10001];
double res;
bool chk;

vector<Edge> e;
vector<Point> p;

double distancePoints(int i, int j) {
	long long xx = (p[i].x - p[j].x) * (p[i].x - p[j].x);
	long long yy = (p[i].y - p[j].y) * (p[i].y - p[j].y);
	long long xyxy = xx + yy;
	return (double) sqrt(xyxy);
	//return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}

bool comp(Edge d1, Edge d2) {
	return d1.val < d2.val;
}

int find(int u) {
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	chk = false;
	u = find(u);
	v = find(v);
	
	if(u == v) return;
	parent[u] = v;
	
	chk = true;
}


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		Point tmp;
		scanf("%d %d", &tmp.x, &tmp.y);
		p.push_back(tmp);
	}
	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size(); j++) {
			Edge tmp;
			tmp.from = i + 1;
			tmp.to = j + 1;
			tmp.val = distancePoints(i, j);
			e.push_back(tmp);
		}
	}
	
	
	
//	for (int i = 0; i < e.size(); i++) {
//		printf("%0.2f\n", e[i].val);
//	}
	
	
	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		merge(from, to);
		//res += distancePoints(from, to);
//		for (int j = 0; j < e.size(); j++) {
//			if((e[j].from == from && e[j].to == to) || (e[j].from == to && e[j].to == from)) {
//				//printf("%d %d %f\n", e[j].from, e[j].to, e[j].val);
//				//e[j].val = 0;
//			}
//		}
	}
	
	sort(e.begin(), e.end(), comp);
	
	
	for (int i = 0; i < e.size(); i++) {
		merge(e[i].from, e[i].to);
		if(chk) {
			//printf("%d %d %f\n", e[i].from, e[i].to, e[i].val);
			res += e[i].val;
		}
	}
	
	printf("%0.2f", res);
	return 0;
}
