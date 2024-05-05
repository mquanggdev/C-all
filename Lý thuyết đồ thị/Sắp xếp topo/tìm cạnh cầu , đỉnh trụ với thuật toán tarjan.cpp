#include<bits/stdc++.h>
using namespace std;
/*
xác định cạnh cầu đỉnh trụ với thuật toán tarjan : đỉnh trụ là đỉnh mà khi xóa nó đi khỏi đồ thị thì sẽ làm tăng thành phần liên thông , cạnh cầu là cạnh mà khi xóa nó đi khỏi đồ thị thì nó cũng làm tăng thành phần liên thông?
1 : Bài toán tìm đỉnh trụ
-> cách để tìm nó chính là khi u -> v -> d thì nếu mà low*(v) >= disc(u) thì tức là nếu mà d muốn đi ngược về u thì bắt buộc phải đi qua v , nên nếu xóa v sẽ chia thành 2 thành phần u và d => v là đỉnh trụ
2: Cạnh cầu thì chỉ cần low[v] > disc[u] là được
*/
int n , m ,timer = 0 ;
vector<int> ke[1001] ;
vector<int> t_ke[1001] ;
stack<int> st ;
 int ans  = 0;
int visited[1001], disc[1001], low[1001], in_stack[1001];
int AP[1001] ;
void init(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void DFS(int u , int par ){
    
    disc[u] = low[u] = ++timer ;
    visited[u] = true;
    int cnt= 0 ;
    for ( auto v : ke[u]){
        if ( v == par) continue ;
        if (!visited[v]){
            cnt ++ ;
            DFS(v,u);
            low[u] = min(low[u],low[v]) ;
            // if (par != -1 && low[v] >= disc[u]) {
            //     AP[u] = 1 ;
            // }
            if (low[v] > disc[u]){ 
                ans ++ ;
            }
        }
        else {
            low[u] = min(low[u],disc[v]) ;
        }
    }
    if ( par == - 1 && cnt > 1){
        AP[u] = 1 ;
    }
}
int main(){
     init();
    for ( int i = 1; i <= n ; i++ ){
        if ( !visited[i]){
            DFS(i,-1) ;
        }
    } cout << ans ;

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

2 5 10 (số đỉnh trụ)

6 ( số cạnh cầu)
*/