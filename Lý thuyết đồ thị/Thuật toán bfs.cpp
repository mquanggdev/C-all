#include<bits/stdc++.h>
using namespace std;
/*
Thuật toán BFS : 
*/
int n , m ;
vector<int> adj[1001];
int visited[1001];
void init(){
     cin >> n >> m ;
     for ( int i = 0 ; i < m ; i++ ){
        int x , y ;
        cin >> x >> y ;
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     for ( int i = 1 ;i <= n ; i++ ) sort(adj[i].begin() , adj[i].end());
}
void bfs( int  i){
    queue<int> q ;
    q.push(i) ;
    visited[i] = 1 ;
    
    while (!q.empty()){
        int top = q.front(); q.pop();
        cout << top << " " ;
        for ( auto x : adj[top]){
            if (visited[x] != 1){
                visited[x] = 1 ;
                q.push(x) ;
            }
        }
    }
}
int main(){
    init();
    bfs(1) ;
    return 0;
}
/*
5 7   

4 1 
5 3
4 3
5 1
3 2
4 2
2 1
1 2 4 5 3
*/