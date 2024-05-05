#include<bits/stdc++.h>
/*
Bài 11 : Dãy con tăng dần : Cho dãy a có n phần tử khác nhau. Hãy liệt kê tất cả các dãy con từ 2 phần tử trở lên của dãy a thỏa mãn tính chất tăng dần. Dãy con được tạo bằng cách lấy các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu . Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống , liệt kê theo thứ tự từ điển
-> đây là câu thể hiện mạnh mẽ cách làm đếm tiến theo vị trí
-> nhánh cận của bài này chính là , nếu ta gặp phần tử tiếp theo mà lớn hơn phần tử đứng phía trước nó thì ta mới cho phép nó đi tiếp
*/

using namespace std;
int n , a[1001] , x[1001];
void init(){
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }
}
void in(int i){
    for ( int j = 1 ; j <= i ; j++ ){
        cout << a[x[j]] << " " ;
    }
    cout << endl ;
}
void ql(int i , int start){
    for ( int j = start ; j <= n ; j++ ){
        if ( a[j] > a[x[i - 1]]){
            x[i] = j ;
            cout << "i: " << i  << "     " << "j: " <<  j << "     " << "a[j]: " << a[j] << "     " << "x[i]: " << x[i] << endl ;
            if ( i >= 2){
                in(i) ;
            }
            ql(i + 1, j + 1);
        }
    }
}
int main()
{
    init() ;
    ql(1, 1) ;
    return 0 ;
}
/*
7
4 8 6 7 3 5 2
4 8
4 6
4 6 7
4 7
4 5
6 7
3 5
*/
/*
đây là cách mà nó đệ quy
i: 1     j: 1     a[j]: 4     x[i]: 1
i: 2     j: 2     a[j]: 8     x[i]: 2
4 8
i: 2     j: 3     a[j]: 6     x[i]: 3
4 6
i: 3     j: 4     a[j]: 7     x[i]: 4
4 6 7
i: 2     j: 4     a[j]: 7     x[i]: 4
4 7
i: 2     j: 6     a[j]: 5     x[i]: 6
4 5
i: 1     j: 2     a[j]: 8     x[i]: 2
i: 1     j: 3     a[j]: 6     x[i]: 3
i: 2     j: 4     a[j]: 7     x[i]: 4
6 7
i: 1     j: 4     a[j]: 7     x[i]: 4
i: 1     j: 5     a[j]: 3     x[i]: 5
i: 2     j: 6     a[j]: 5     x[i]: 6
3 5
i: 1     j: 6     a[j]: 5     x[i]: 6
i: 1     j: 7     a[j]: 2     x[i]: 7
*/