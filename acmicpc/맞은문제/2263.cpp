#include <cstdio>
#include <iostream>

using namespace std;

int inorder[100000];
int postorder[100000];
int position[100001];

//postorder 에서 루트를 찾은 뒤, inorder에서 왼쪽 자식 노드의 개수와 오른쪽 자식 노드의 개수를
//구한뒤, 루트 출력, 왼쪽 solve, 오른쪽 solve 이런식으로 풀어간다.  
void solve(int in_start, int in_end, int post_start, int post_end) {
	//탈출 조건
	if(in_start > in_end || post_start > post_end) return;
	
	//root출력 
	int root = postorder[post_end];
	printf("%d", root);
	//inorder에서 root의 위치 
	int p = position[root];
	
	//왼쪽 자식의 노드의 개수 
	int left = p - in_start;
	
	//왼쪽 solve
	solve(in_start, p - 1, post_start, post_start + left - 1);
	
	//오른쪽 solve 
	solve(p + 1, in_end, post_start + left, post_end - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
	//position[i] i 의 인오더에서 위치 
	//인오더에서 어떠한 노드 i가 위치하는 곳은 position[i]이다.  
	for (int i = 0; i < n; i++) {
		position[inorder[i]] = i;
	}
	solve(0, n - 1, 0, n - 1);
	return 0;
}
