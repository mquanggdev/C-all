#include<bits/stdc++.h>
using namespace std;
/*
Bài 9 : Nối dây 
*/
int main()
{
    int n ; cin >> n ;
    vector <int> a(n) ;
    for (int &x : a ) cin >> x ;
    priority_queue <int , vector<int> , greater<int> > q ; // phải sử dụng hàng đợi vì sau khi nối dây nó thành một sợi mới mà ta cũng phải nối sợi mới đó với một sợi khác nên ta cần dùng queue để sắp xếp nó theo thứ tự tăng dần
    for ( int x : a ){
        q.push(x) ;
    }
    int ans =  0;
    while (q.size() >= 2){
        int x = q.top() ; q.pop() ;
        int y = q.top() ; q.pop() ;
         ans += (x + y) ;
         q.push(x + y);
    }
    cout << ans << endl; 
    return 0 ;
}
/*
7
7 7 6 10 4 8 3
124

4 
4 3 2 6
29
*/