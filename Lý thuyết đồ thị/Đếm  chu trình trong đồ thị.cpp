#include<bits/stdc++.h>
using namespace std;
/*
Bài 21 : Kiểm tra chu trình trên đồ thị vô hướng : 
*/
int n , m , check = 0;
vector <int> adj[1001] ;
int visited[1001] = {0} ;
int parent[1001] ;
vector<pair<int,int> > dscanh; 
void init(){
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y  ;
        cin >> x >> y ;
        dscanh.push_back({x,y});
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
   memset(visited,0,sizeof(visited));
}
void dfs(int s ){
    visited[s] = true ;
    for ( auto x : adj[s]){
       if ( visited[x] == 1 && v != parent[s]){
        check = 1 ;
       }
       if ( !visited[x] ){
         parent[x] = s ;
         dfs(x) ;
       }
    }
}
int main(){
    init() ;
    for ( int i = 1 ; i <= n ; i++ ){
        if (!visited[i]){
            dfs(1) ;
        }
    }
    if ( check ) cout << 1 << endl ;
    else cout << 0 << endl;
    return 0;
}
