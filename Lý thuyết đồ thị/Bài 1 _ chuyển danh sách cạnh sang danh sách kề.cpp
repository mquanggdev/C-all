#include<bits/stdc++.h>
using namespace std;
/*
Bài tập về Lý thuyết đồ thị : Bài 1: Chuyển danh sách cạnh sang danh sách kề 
*/
 int n , m ;
int a[1001][1001] ;
vector<int> adj[1001];
int main()
{
   
    cin >> n >> m ;
    
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ; cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
        
    }
    for ( int i = 1 ; i <= n ; i++ ){
        cout << i << " : ";
        for ( int j = 0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
5 4

2 5
4 1
4 2
4 3

1 : 4
2 : 5 4
3 : 4
4 : 1 2 3
5 : 2
*/