#include<bits/stdc++.h>
using namespace std;
/*
Bài tập về Lý thuyết đồ thị : Bài 2: Chuyển danh sách kề sang danh sách cạnh 
*/
 int n , m ;
int a[1001][1001] ;
vector<int> adj[1001];
int main()
{
    cin >> n;
    cin.ignore();
    for ( int i = 1 ; i <= n ; i++ ){
        string s , num ;
        getline(cin,s);
        stringstream ss(s) ;
        while ( ss >> num){
            if(stoi(num) > i){
                adj[i].push_back(stoi(num));
            }
        }

    }
    for ( int i = 1 ; i <= n ; i++){
        for ( auto it : adj[i]){
            cout << i << " " << it << endl;
        }
    }
    return 0;
}
/*
5
4 
3 4 5
2 5
1 2
2 3

1 4
2 3
2 4
2 5
3 5
*/