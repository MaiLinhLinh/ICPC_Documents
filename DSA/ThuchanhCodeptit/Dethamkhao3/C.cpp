#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> so;
void Calc(){
    queue<pair<string, int>> q;
    for(int i = 1; i <= 9; i++)
        q.push({to_string(i),i});
    while(!q.empty()){
        auto[num, sum] = q.front();
        q.pop();
        if(sum == 10)
            so.push_back(stoll(num));
        if(so.size() > 2*1e5)
            return;
        for(int i = 0; i <= 10 - sum; i++){// dam bao new sum khong qua 10
            int newsum = sum + i;
            string newnum = num + to_string(i);
            q.push({newnum, newsum});
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Calc();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << so[n-1] << "\n";
    }


}
