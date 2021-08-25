#include<iostream>
#include<algorithm>


using namespace std;

int line[10001][101];
int trans[10001];
int DP[10001][101];

int main(int argc, char** argv)
{      
        int N, K;
        cin >> N >> K;
        for(int i = 1; i < K; i++ ){
                for(int j = 1; j <= N; j++){
                        cin >> line[i][j];
                }
                cin >> trans[i];
        }
        
                for(int j = 1; j <= N; j++){
                        cin >> line[K][j];
                }

        for(int i = 1; i <=N; i++){
            DP[1][i] = line[1][i];
        }
   
        for(int i = 2; i <= K; i++ ){
            for(int j = 1; j <= N; j++){
                int minRes = 987654321;
                for(int k =1; k <= N; k++){
                	if(minRes <= DP[i-1][k] + line[i][k] + trans[i-1]) {
                		minRes = DP[i-1][k] + line[i][k] + trans[i-1];
					}
                }
                DP[i][j] = min(DP[i - 1][j] + line[i][j], minRes);
                //cout << DP[i][j] << " ";
            }
            //cout << endl;
        }

        for (int i = 1; i <= K; i++) {
                cout << DP[i][N] << endl;
        }
 return 0;
}
