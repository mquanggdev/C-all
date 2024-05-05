#include<bits/stdc++.h>
using namespace std;
/*
Bài 19 _ Đỉnh trụ : Cho đồ thị vô hướng được biểu diễn dưới dạng danh sách cạnh . hãy đếm số lượng đỉnh trụ của đồ thì 

đỉnh trụ là đỉnh mà khi xóa nó đi sẽ làm tăng thành phần liên thông!
*/
int n , m ;
vector <int> adj[1001] ;
int visited[1001] ;
int parent[1001] ;
void init(){
    cin >> n >> m ;
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
    int cnt  = 0 ;
    for ( int i = 1 ; i <= n ; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++ ;
        }
    }
    int tru = 0;
    for ( int i = 1 ; i <= n ; i ++) {
        memset(visited , 0 , sizeof(visited)) ;
        int dem = 0 ;
        visited[i] = 1 ;
         for ( int j = 1 ; j <= n ; j ++) {
                if (!visited[j]) {
                dfs(j);
                dem ++ ;
            }
          }
          if (dem > cnt) ++tru;
    }
    cout << tru << endl;
    return 0;
}
/*
10 6 
5 4 
5 2
10 2
10 7 
5 3
10 1

3
*/