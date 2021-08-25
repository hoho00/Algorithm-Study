#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef struct point {
	double x;
	double y;
}Point;

typedef struct kruskal {
	int from;
	int to;
	double val;
}KS;

vector <Point> points;
vector <KS> edge;

int parent[1001];
bool chk;
double res = 0;

double distancePoints(int i, int j) {
	return sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y));
}

bool comp(KS d1, KS d2) {
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

int main ()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Point p;
		scanf("%lf %lf", &p.x, &p.y);
		points.push_back(p);
	}
	
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < points.size(); i++) {
		for (int j = i + 1; j < points.size(); j++) {
			KS k;
			k.from = i;
			k.to = j;
			k.val = distancePoints(i, j);
			edge.push_back(k);
		}
	}
	
//	for (int i = 0; i < points.size(); i++) {
//		cout << points[i].x << points[i].y << endl;
//	}
	sort(edge.begin(), edge.end(), comp);
	
//	for (int i = 0; i < edge.size(); i++) {
//		printf("%d %d %lf\n", edge[i].from, edge[i].to, edge[i].val);
//	}
	
	
	
	for (int i = 0; i < edge.size(); i++) {
		merge(edge[i].from, edge[i].to);
		if(chk) res += edge[i].val;
	}
	
	printf("%0.2f", res);
	
	return 0;
}
