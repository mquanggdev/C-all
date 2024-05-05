#include<bits/stdc++.h>
using namespace std;
/* Bài khiêu vũ : trong lớp có n bạn nam và m bạn nữ với chiều cao khác nhau , ghép cặp với nhau với điều kiện là trong một đôi khiêu vũ bất kỳ bạn nam phải cao hơn bạn nữ và mỗi bạn không tham gia quá một đôi khiêu vũ .Hãy tính số lượng cặp dôi nhiều nhất thỏa mãn yêu cầu trên
*/
int n, m , a[1001],b[1001];
void init(){
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; i++){
        cin >> a[i]  ;
    }
    for ( int i = 0 ; i < m ; i++ ){
        cin >> b[i] ;
    }
    sort (a, a + n);
    sort (b , b + n);
}
void meg(){
    vector <int> x(a , a + n) ;
    vector<int> y(b , b + m) ;
    vector<pair<int,int>> vec ;
    int l = 0 , r = 0 ;
    while ( l < x.size() && r < y.size()){
        if ( x[l] > y[r]){
            vec.push_back(make_pair(-1,-1));
            r++;
            l++;
        }
        else {
            l++ ;
        }
    }
    cout << vec.size() ;
}
int main()
{
    init() ;
    meg() ;
    return 0;
}
/*
5 5
2668 2965 20933 21199 24224
11621 13084 19673 25628 28958
3
*/