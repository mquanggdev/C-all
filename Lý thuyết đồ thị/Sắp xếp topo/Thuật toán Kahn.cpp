#include<bits/stdc++.h>
using namespace std;
/*
Thuật toán Kahn
*/
int n , m  ;
vector<int> ke[1001] ;
int visited[1001];
stack<int> st ;

int degree[1001] ;
void init(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ;
        cin >> x >> y;
        ke[x].push_back(y);
        degree[y] ++ ;
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
void Kahn(){
    queue<int> q ;
    for ( int i = 1 ; i <= n ; i++ ){
        if ( degree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo ;
    while (!q.empty()){
        int top = q.front() ; q.pop();
        topo.push_back(top);
        for ( auto v : ke[top]){
            degree[v]--;
            if ( degree[v] == 0){
                q.push(v);
            }
        }
    }
    for ( auto x : topo){
        cout << x << " " ;
    }
}
int main(){
    init();
    Kahn();
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
1 2 5 3 4 6
*/