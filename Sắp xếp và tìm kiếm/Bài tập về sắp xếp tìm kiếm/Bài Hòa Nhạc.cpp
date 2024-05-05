#include<bits/stdc++.h>
using namespace std;
/*Bài Hòa Nhạc : có n vé xem hòa nhạc có sẵn với các mức giá khác nhau , sau đó có m khách hàng đến , họ sẽ thông báo mức giá tối đa mà họ sẵn sàng chi trả cho cái vé và họ sẽ nhận được lại vé tương ứng ,.lưu ý 1 vé chỉ được bán cho một khách thôi */
int main()
{
    int n , m  ;
    cin >> n >> m ;
    int a[n] , b[m] ;
    multiset<int> sp ;
    for ( int i = 0 ; i < n ; i++ ){
        cin >> a[i] ;
         sp.insert(a[i]);
    }
    for ( int i = 0 ; i < m ; i ++){
        cin >> b[i] ; 
        auto it = sp.upper_bound(b[i]); // dùng upper theo kiểu này sẽ nhanh hơn 
        if ( it != sp.begin()){
            --it ;
            cout << *it << endl;
            sp.erase(it) ;
        }
        else {
            cout << "-1" ;
        }
    }
   
    return 0;
}
/*
5 3
5 3 8 7 3
3 
8 
-1*/
