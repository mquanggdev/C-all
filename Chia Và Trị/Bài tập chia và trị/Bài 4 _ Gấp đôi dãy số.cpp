#include<bits./stdc++.h>
using namespace std;
/*
Bài 4: Gấp đôi dãy số : một dãy tự nhiên bắt đầu từ con số 1 và được thực hiện N - 1 pheps biến đổi gấp đôi dãy số như sau : Với dãy số A hiên tại dãy số mới có dạng A , x  , A trong đó x là số tự nhiên bé nhất chưa từng xuất hiện trong A
*/
int n , k ;
long long F[10001] ; // độ dài của chuỗi hiện tại : bởi vì số mới thêm vào chính là n luôn , như ở n = 3 thì số thêm vào là 3 nên ta chỉ cần so sánh cái k muốn tìm nằm trong khoảng nào , nếu nó nằm đúng vị trí mới thêm vào return n là xong
int dv(int i , int k){
    if ( i == 1){
        return 1 ;
    }
    if ( k == F[i]/2 + 1) return i ;
    else if ( k < F[i / 2] + 1) return  dv(i - 1,k) ;
    else  return   dv(i - 1,k - ((F[i] / 2) + 1)) ;
}
int main()
{
    cin >> n >> k ;
    cout << dv(n , k) ;
    return 0;
}
/*
3 2 
2
*/