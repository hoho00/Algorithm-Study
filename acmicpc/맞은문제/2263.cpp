#include <cstdio>
#include <iostream>

using namespace std;

int inorder[100000];
int postorder[100000];
int position[100001];

//postorder ���� ��Ʈ�� ã�� ��, inorder���� ���� �ڽ� ����� ������ ������ �ڽ� ����� ������
//���ѵ�, ��Ʈ ���, ���� solve, ������ solve �̷������� Ǯ���.  
void solve(int in_start, int in_end, int post_start, int post_end) {
	//Ż�� ����
	if(in_start > in_end || post_start > post_end) return;
	
	//root��� 
	int root = postorder[post_end];
	printf("%d", root);
	//inorder���� root�� ��ġ 
	int p = position[root];
	
	//���� �ڽ��� ����� ���� 
	int left = p - in_start;
	
	//���� solve
	solve(in_start, p - 1, post_start, post_start + left - 1);
	
	//������ solve 
	solve(p + 1, in_end, post_start + left, post_end - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
	//position[i] i �� �ο������� ��ġ 
	//�ο������� ��� ��� i�� ��ġ�ϴ� ���� position[i]�̴�.  
	for (int i = 0; i < n; i++) {
		position[inorder[i]] = i;
	}
	solve(0, n - 1, 0, n - 1);
	return 0;
}
