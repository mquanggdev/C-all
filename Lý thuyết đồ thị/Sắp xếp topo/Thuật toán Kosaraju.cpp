#include<bits/stdc++.h>
using namespace std;
/*
Đồ thị có hướng liên thông mạnh : Nếu giữa hai đỉnh đồ thị bất kỳ của đồ thị đều có đường đi. nếu đồ thị không liên thông mạnh nó sẽ chia thành  các thành phần liên thông mạnh.Thành phần liên thông mạnh là thành phần liên thông lớn nhất mà giữa hai đỉnh của nó đều có dường đi
Thuật toán Kosaraju : O(V+E) ->
b1 : tìm thứ tự sắp xếp topo và đưa vào trong ngăn xếp
b2 : đảo ngược đồ thị lại
b3: vơi mỗi đỉnh lấy ra từ ngăn xếp , nếu đỉnh này chưa được duyệt thì gọi đỉnh này làm đỉnh nguồn và gọi dfs đến nó với đồ thị đảo ngược rồi in ra các thành phần liên thông
*/
#include<bits/stdc++.h>
using namespace std;
/*
Thuật toán Kahn
*/
int n , m  ;
vector<int> ke[1001] ;
vector<int> t_ke[1001] ;
int visited[1001];
stack<int> st ;

int degree[1001] ;
void init(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ;
        cin >> x >> y;
        ke[x].push_back(y);
        t_ke[y].push_back(x) ;
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
void DFST(int i){
    cout << i << " " ;
    visited[i] = true ;
    for ( auto x : t_ke[i]){
        if ( !visited[x] ){
            DFST(x) ;
        }
    }
}
int main(){
    init();
    for ( int i = 1; i <= n ; i++ ){
        if ( !visited[i]){
            DFS(i) ;
        }
    }
    memset(visited,0,sizeof(visited));
    while(!st.empty()){
        int u = st.top(); st.pop();
        if ( !visited[u]){
            DFST(u) ;
            cout << endl;
        }
        
    }
    return 0;
}