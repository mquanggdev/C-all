#include<bits/stdc++.h>
using namespace std;
/*
Sắp xếp topo : áp dụng cho đồ thị có hướng không có chu trình là một thứ tự các đỉnh sao cho với mọi u > v  thì u sẽ xuất hiện trước v trong thứ tự topo . Một đồ thị có thể tồn tại nhiều thứ tự topo khác nhau 

ý tưởng : kết hợp dfs và stack
cứ mỗi lần duyệt một đỉnh thì push nó vào stack và  gọi dfs tới đỉnh dó , đến khi không duyệt được nữa thì pop ra và push vào stack đó . stack đó chính là đáp án ;
*/
int n , m  ;
vector<int> ke[1001] ;
int visited[1001];
stack<int> st ;
void init(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ;
        cin >> x >> y;
        ke[x].push_back(y);
    }
}
void DFS(int i ){
    visited[i] = true;
    for ( auto x : ke[i]){
        if (!visited[x]){
            DFS(x);
        }
    }
    st.push(i) ;
}
int main(){
    init();
    for ( int i = 1 ; i <= n ; i++ ){
        if ( !visited[i]){
            DFS(i) ;
        }
    }
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop() ; 
    }
    return 0;
}
/*
6 6
1 2
2 3
2 4
3 6
4 6
1 5
1 5 2 4 3 6
*/