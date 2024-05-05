#include<bits/stdc++.h>
using namespace std;
/*
Cạnh cầu : là những cạnh mà khi xóa đi sẽ làm tăng thành phần liên thông
*/
int n , m ;
set <int> adj[1001] ;
int visited[1001] = {0} ;
int parent[1001] ;
vector<pair<int,int> > dscanh; 
void init(){
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y  ;
        cin >> x >> y ;
        dscanh.push_back({x,y});
        adj[x].insert(y) ;
        adj[y].insert(x) ;
    }
   memset(visited,0,sizeof(visited));
}
void dfs(int s ){
    visited[s] = true ;
    for ( auto x : adj[s]){
        parent[x] = s ;
        if (!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    init() ;
    int cnt  = 0 ;
    for ( int i = 1 ; i <= n ; i ++) {
        if (!visited[i]) {
            dfs(i);
            cnt ++ ;
        }
    }
    int cau = 0;
    for ( auto it : dscanh){
        int x = it.first , y = it.second;
        adj[x].erase(y) ;
        adj[y].erase(x) ;
        int dem = 0 ;
        memset(visited,0,sizeof(visited));
        for ( int i = 1 ; i <= n ; i++ ){
            if ( !visited[i]){
                dem++;
                dfs(i) ;
            }
        }
        adj[x].insert(y) ;
        adj[y].insert(x) ;
        if ( dem > cnt) ++cau ;
    }
    cout << cau << endl;
    return 0;
}
/*
10 6 
10 1
5 2
10 5
10 6
5 3
10 4

6
*/