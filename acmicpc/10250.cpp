#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int H, W, N;
		cin >> H >> W >> N;
		int X =  N%H;
		int Y =  N/H + 1;
		if(N%H == 0) {
			cout << H;
			printf("%02d\n", Y - 1);
		}
		else {
			cout << X;
			printf("%02d\n", Y);
		}
		
	}
	return 0;
}
