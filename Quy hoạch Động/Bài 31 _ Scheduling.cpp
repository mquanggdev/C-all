#include<bits/stdc++.h>
using namespace std;
/*
Bài 31 : Scheduling: Có n dự án bạn có thể tham dự . Đối với mỗi dự án , bạn biết ngày bắt đầu và ngày kết thúc của dự án và số tiền bạn sẽ nhận được khi hoàn thành dự án đó . Bạn chỉ có thể tham gia một dự án trong một ngày . Số tiền tối đa bạn có thể kiếm được là bao nhiêu ? . 
*/
struct Job{
    int st , ed , profit ;
};

bool cmp (Job a , Job b){
    return a.ed < b.ed ;
}
// đi tìm vị trí đầu tiên có thời gian kết thúc nhỏ hơn thời gian bắt đầu
int tim (Job a[] , int l , int r , int st){
    int res = -1  ;
    while( l <= r){
        int mid = ( l + r) / 2 ;
        if ( a[mid].ed < st){
            res = mid ;
            l = mid + 1 ;
        }
        else r = mid - 1 ;
    }
    return res;
}
int n ; 
int F[10001] ;
int main(){
    cin >> n ;
    Job a[n] ;
    for ( int i = 0 ; i < n ; i++ ) cin >> a[i].st >> a[i].ed >> a[i].profit ;
    sort( a , a + n , cmp) ;
    F[0] = a[0].profit ;
    for ( int i = 1 ; i < n ; i++ ){
        int t = tim(a,0 , i - 1 ,a[i].st);
        if ( t != -1 ){
            F[i] = max ( a[i].profit + F[t] , F[i - 1]);
            
        }
        else {
            F[i] = max (a[i].profit , F[i - 1]) ;
        }
        
    }
    cout << F[n - 1] ;
    return 0;
}
