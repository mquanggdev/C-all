#include<bits/stdc++.h>
using namespace std;
/* bài 14 _ Đường đi trên đồ thị vô hướng bằng dfs : Cho đồ thị vô hướng G được biểu diện dưới dạng danh sách cạnh . Hãy tìm đường đi theo thuật toán DFS từ đỉnh s tới đỉnh t . Trong quá trình mở rộng của thuật toán DFS , luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn*/
int n , m , s  , t;
vector <int> adj[1001] ;
int visited[1001] ;
int parent[1001] ;
void init(){
    cin >> n >> m >> s >> t;
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
        parent[x] = s ;
        if (visited[x] != 1){
            dfs(s + 1);
        }
    }
}
int main(){
    init() ;
    dfs(s) ;
    if (visited[t] != 1) cout << " No \n" ;
    else {
        vector<int> kq ;
        while ( t != s ){
            kq.push_back(t) ;
            t = parent[t] ;
        }
        kq.push_back(s) ;
        reverse(kq.begin(),kq.end());
        for ( auto x : kq) cout << x << " " ;
    }
 
    return 0;
}
/*
5 3 4 3
4 2
2 1
3 1

*/