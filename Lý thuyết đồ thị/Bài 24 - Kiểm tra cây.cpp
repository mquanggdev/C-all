#include<bits/stdc++.h>
using namespace std;
/*
Bài 24 : một đồ thị N đỉnh là một cây , nếu như nó có đún N - 1 cạnh và giữa hai đỉnh bất kỳ , chỉ tồn tại duy nhất một đường đi giữa chúng . Cho một đồ thị vô hướng N đỉnh và M cạnh , hãy kiểm tra đồ thị đã cho có phải một cây hay không 
*/
int n , m ;
vector<int> adj[1001] ;
int visited[1001] ;
int ans = 0 ;
void init(){
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y  ;
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
}
void DFS( int i ){
    visited[i] = true ;
    for ( auto v : adj[i]){
        if ( !visited[v]){
            DFS(v);
        }
    }
}
int main(){
    init();
    for ( int i = 1 ; i <= n ; i++ ){
        if (!visited[i]) {
            DFS(i);
            ans ++ ;
        }
    }
    if (m == n - 1 && ans == 1  ) cout << 1 << endl;
    else cout << 0 ;
    return 0;
}

/*
6 5
4 3
2 1
6 5
5 4
3 2
1
*/