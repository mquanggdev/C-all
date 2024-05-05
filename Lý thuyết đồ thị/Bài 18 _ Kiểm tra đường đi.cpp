#include<bits/stdc++.h>
using namespace std;
/*
Bài 18 _ Kiểm tra đường đi : Cho đồ thị vô hướng G = V,E được biểu diễn dưới dạng danh sách cạnh . có Q truy vấn , mối truy vấn yêu cầu trả lời câu hỏi giữa hai đỉnh s và t có được tồn tại dường đi với nhau hay không
*/
int n , m , s  , t;
vector <int> adj[1001] ;
int visited[1001] ;
void init(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y  ;
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) sort(adj[i].begin() , adj[i].end()) ;
}
void dfs(int s ){
    visited[s] = 1 ;
    for ( auto x : adj[s]){
        if (!visited[x]){
            dfs(s + 1);
        }
    }
}
int main(){
    init();
    int q ; cin >> q ;
    while(q--){
        int s , t  ;
        cin >> s >> t ;
        dfs(s);   
        if (!visited[t]) cout << "Not Found!" << endl;
        else cout << "Find" << endl;
    }
    return 0;
}
/*
5 3
5 4
4 1
4 3
3
4 5
4 2
3 4

*/