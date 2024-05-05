#include<bits/stdc++.h>
using namespace std;
/*
Đồ thị có hướng liên thông mạnh : Nếu giữa hai đỉnh đồ thị bất kỳ của đồ thị đều có đường đi. nếu đồ thị không liên thông mạnh nó sẽ chia thành  các thành phần liên thông mạnh.Thành phần liên thông mạnh là thành phần liên thông lớn nhất mà giữa hai đỉnh của nó đều có dường đi
Thuật toán Kosaraju : O(2(V+E)) ->
b1 : tìm thứ tự sắp xếp topo và đưa vào trong ngăn xếp
b2 : đảo ngược đồ thị lại
b3: vơi mỗi đỉnh lấy ra từ ngăn xếp , nếu đỉnh này chưa được duyệt thì gọi đỉnh này làm đỉnh nguồn và gọi dfs đến nó với đồ thị đảo ngược rồi in ra các thành phần liên thông

Thuật toán Tarjan : O(V + E) :
Dùng 2 mảng disc[u] và low[u] :
mảng disc tượng trưng cho thời gian mà bắt đầu thăm đỉnh u theo DFS 
mảng Low tương trưng cho thời gian thăm sớm nhất của một đỉnh có thể đi tới được từ một cây con gốc là u ; 
u -> v -t , d -> u , nếu thời gian ở v > u => low[v] = tu ; td > tv => td = tv = tu -> xong một thành phần liên thông mạnh
*/
int n , m ,timer = 0 , scc = 0 ;
vector<int> ke[1001] ;
vector<int> t_ke[1001] ;
stack<int> st ;
int visited[1001], disc[1001], low[1001], in_stack[1001];
int degree[1001] ;
void init(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ;
        cin >> x >> y;
        ke[x].push_back(y);
    }
}
void DFS(int u ){
    ++ timer ;
    disc[u] = low[u] = timer ;
    visited[u] = true;
    in_stack[u] = true ;
    st.push(u) ;
    for ( auto x : ke[u]){
        if (!visited[x]){
            DFS(x);
            low[u] = min(low[u],low[x]) ;
        }
        else if ( in_stack[x]){
            low[u] = min(low[u],disc[x]) ;
        }
    }
    if ( low[u] == disc[u]){
        ++scc;
        while (st.top() != u){
            cout << st.top() << "  " ;
            in_stack[st.top()] = false ;
            st.pop() ;
        }
        cout << st.top() <<endl;
        in_stack[st.top()] = false ;
        st.pop() ;
    }
}
int main(){
    init();
    for ( int i = 1; i <= n ; i++ ){
        if ( !visited[i]){
            DFS(i) ;
        }
    }
   cout << scc <<endl;
    return 0;
}
/*
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5


7  6  5
4
3  2  1
3
*/