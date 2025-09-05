#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(s[i]);
            else if(!st.empty() && st.top() == '('){
                cnt += 2;
                st.pop();
            }
        }
        cout << cnt << "\n";
    }
}
