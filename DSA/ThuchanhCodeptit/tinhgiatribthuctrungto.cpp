#include<bits/stdc++.h>
using namespace std;
int precedence(char x){
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    // chuyen tu trung to sang tien to
    stack<char> st;
    string ans[105];
    int n = 1;
    string num = "";
    for(int i = s.size() - 1; i >= 0; i--){
        char x = s[i];
        if(isdigit(x)){
            num = x + num;
            //cout << num << "\n";
        }
        else{
            //cout<< num << "\n";
            ans[n] = num;
            //cout << n << " " << ans[n] << "\n";
            n++;
            num = "";
            if(x == ')')
                st.push(x);
            else if(x == '('){
                while(!st.empty() && st.top() != ')'){
                    ans[n] = st.top();
                    //cout << n << " " << ans[n] << "\n";
                    n++;
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(st.top())>= precedence(x)){
                    ans[n] = st.top();
                    //cout << n << " " << ans[n] << "\n";
                    n++;
                    st.pop();
                }
                st.push(x);
            }
        }
    }
    if(num != ""){
        ans[n] = num;
        //cout << n << " " << ans[n] << "\n";
        n++;
    }
    while(!st.empty() && st.top() != ')'){
        ans[n] = st.top();
        //cout << n << " " << ans[n] << "\n";
        n++;
        st.pop();
    }
    for(int i = n; i >= 1 ; i--)
        cout << ans[i] << " ";
    //tinh gia tri bieu thuc tien to
    stack <int
}
