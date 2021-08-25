#include <iostream>
#include <queue>
#include <vector>
#define max_int 21
#define max_val 401

using namespace std;

/*
 �ð� ���⵵: O(n^4)
 ���� ���⵵: O(n^2)
 ����� �˰���: BFS(���� Ž��)
 BFS�� ����� ������ ������ �����ϴ�.
 1. �ִ� ��θ� ã�� �����Դϴ�.
 2. BFS�� ��� ������ ����ġ�� 1�϶� �ִܰ�θ� ã���ݴϴ�.
 3. BFS�� �ð� ���⵵: 1) ��������ƮƲ ����� ��� O(v+e), 2) ��������� ����� ���(v^2)
 
 �� �������� �׷����� �����ϴ� �ڷᱸ���� 2���� �迭..��������Ʈ��, ������ĵ� �ƴ�
 ������ �� n^2 + ������ �� 4*n^2 = O(5n^2), ��� ���� O(n^2)
 ����� �ڷᱸ��: 2���� �迭, ť
 */


// a �迭�� ������ ������ �����մϴ�. check �迭�� �̵��Ÿ��� �����մϴ�.
int n, a[max_int][max_int], check[max_int][max_int], shark_x, shark_y, eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

// ��� �Ǵ� ������ ��ǥ(x, y)�� ������ ������ ����
// ���� ��, ���� ���� �񱳰� ���� ������
// pair�� ����ص� �����ϴ�. (pair�� �񱳸� ���ֱ� �����Դϴ�.)
struct info{
    int x, y;
};

// BFS ������ ���� ���� �ʱ�ȭ
void init_check(){
    min_dist = max_val;
    min_x = max_int;
    min_y = max_int;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            check[i][j] = -1;
        }
    }
}

// ���� Ž��(BFS) ����
void bfs(int x, int y){
    // BFS�� ����� ť�� �����մϴ�.
    queue<info> q;
    // ����� ù ��ġ�� �ð��� 0���� �ʱ�ȭ�մϴ�.
    check[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()){
        // ť���� ���� �տ� �ִ� ��ü�� �����ϴ�.
        info cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        
        // 4������ Ž���մϴ�.
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // ���� ������ �Ѿ�� ��� �ǳʶݴϴ�.
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            // 1) �̹� �湮�߰ų�, 2) ����� ũ�⺸�� ū ������ ��� �ǳ� �ݴϴ�.
            if(check[nx][ny] != -1 || a[nx][ny] > shark_size) continue;
            
            // (nx, ny)�� �ִ� ���������� �̵��Ÿ��� �������ݴϴ�.
            check[nx][ny] = check[x][y] + 1;
            
            // ���� �� �ִ� ������� ���
            if(a[nx][ny] != 0 && a[nx][ny] < shark_size){
                
                // �� �κ��� pair�� ��, ��ü�� ������ �����ε��� ���� <= �񱳷� �� �����ϰ� �ۼ��� �� �ֽ��ϴ�.
                // ���� ���� ����� ������ �̵��ð��� �� ª�� ���
                if(min_dist > check[nx][ny]){
                    min_x = nx;
                    min_y = ny;
                    min_dist = check[nx][ny];
                }
                // ���� ���� ����� ������ �̵��ð��� ������ 1) ���� ����, ���� ������ ã���ϴ�.
                else if(min_dist == check[nx][ny]){
                    if(min_x == nx){
                        if(min_y > ny){
                            min_x = nx;
                            min_y = ny;
                        }
                    }else if(min_x > nx){
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            
            // ������� ��ġ�� ť�� �־��ݴϴ�.
            q.push({nx, ny});
        }
    }
}

int main(){
    // 1. �Է�
    // ���� ũ�⸦ �Է¹޽��ϴ�.
    scanf("%d", &n);
    
    // ���� ������ �Է¹޽��ϴ�.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            
            // �Ʊ� ����� ���
            if(a[i][j] == 9){
                // x, y ��ǥ�� ���� �������ְ�
                shark_x = i;
                shark_y = j;
                // �����󿡼� 0���� ����ݴϴ�.
                a[i][j] = 0;
            }
        }
    }
    
    // 2. �ݺ��� ����
    // �� n^2(������� �� ����)�� ����˴ϴ�.
    while(true){
        // BFS ������ ���� ���� �ʱ�ȭ
        init_check();

        // ���� Ž������ ���� �� �ִ� ����⸦ ã���ϴ�.
        bfs(shark_x, shark_y);
        
        // ���� �� �ִ� ����⸦ ã�� ���
        if(min_x != max_int && min_y != max_int){
            // �̵��ð��� �����ݴϴ�.
            result += check[min_x][min_y];
            
            // ����� ���� ���� 1 ������ŵ�ϴ�.
            eat_cnt++;
            
            // ���� ���� ����� ���� ����� ũ��� ���ٸ�
            if(eat_cnt == shark_size){
                // ����� ũ�⸦ 1 ������Ű��, ���� ����� ���� 0���� �ʱ�ȭ�����ݴϴ�.
                shark_size++;
                eat_cnt = 0;
            }
            
            // ���� ������� ��ġ�� 0���� �������ݴϴ�.
            a[min_x][min_y] = 0;
            
            // ����� ��ġ�� �������ݴϴ�.
            shark_x = min_x;
            shark_y = min_y;
        }
        
        // ���� �� �ִ� ����Ⱑ ���� ��� �ݺ����� �����ϴ�.
        else{
            break;
        }
    }
    
    // 3. ���
    // �̵��� �ɸ� �ð��� ����մϴ�.
    printf("%d\n", result);
}
