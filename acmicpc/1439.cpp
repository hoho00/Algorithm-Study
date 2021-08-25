#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    int zero = 0, one = 0;

    cin >> s;

    if(s[0] == '0') zero++;
    else one++;

    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i-1]){
            if(s[i] == '0') zero++;
            else one++;
        }
    }
    cout << min(zero, one);
    return 0;
}
