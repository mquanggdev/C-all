#include<bits/stdc++.h>
using namespace std;
/*
Bài tập về Lý thuyết đồ thị : Bài 7 : chuyển từ danh sách cạnh sang ma trận kề 
*/
 int n , m ;
int a[1001][1001] ;
int main()
{
   
    cin >> n >> m ;
    
    for ( int i = 0 ; i < m ; i++ ){
        int x , y ; cin >> x >> y ;
        a[x][y] = a[y][x] = 1;
        
    }
    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ; j <= n ; j++ ){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
5 4

4 3
3 1
4 2
5 4
0 0 1 0 0
0 0 0 1 0
1 0 0 1 0
0 1 1 0 1
0 0 0 1 0
*/