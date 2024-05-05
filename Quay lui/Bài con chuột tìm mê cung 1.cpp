#include<bits/stdc++.h>
using namespace std;
/* Bài toán con chuôt đi trong mê cung : cho ma trận NxN được biểu diễn bởi các số 0 và 1  ,con chuột đi theo số 1 , tìm đường đi cho con chuột từ điểm 00 tới điểm nn , nếu mà đi xuống in ra D , đi bên phải in ra R , 
Hãy in ra tất cả con đường có thể đi được của con chuột
*/
int n , a[1001][1001] , check = 0;
string s = "" ;
void Try(int i ,int j){
    if ( i == n && j == n){ // nếu mà đã đến điểm đích thì nó in ra
        check = 1 ;
        cout << s << endl;
        return;
    }
    /* Đầu tiên ta phải kiểm tra xem ô tiếp theo đi xuống hoặc sang phải nó còn nằm trong ma trận và ô đó có là số 1 hay không mới được đi tiếp , nếu có tồn tại thì ta sẽ cho xâu S + với hành động tương ứng , và đánh dấu điểm đó bằng 0 lại để không bị đi trúng nữa và gọi đến ô tiếp theo
    */
   // đi xuống
    if ( i + 1 <= n && a[i+1][j] == 1){
        s += "D" ;
        a[i + 1][j] = 0 ;
        Try(i + 1, j) ;
        s.pop_back() ; // cái này là rất quan trọng bởi vì khi mà quay lui lại và đi con đường khác ví dụ khi quay lui lại không đi xuống dưới nữa thì nó sẽ đi sang phải thì phải cộng thêm "R" chứ không phải D , vậy nên phải xóa đi chữ D sau khi nó hoàn thành một nhánh con đường .
        a[i + 1][j] = 1 ; // cái này cũng tương tự phải trả lại giá trị cho nó
    }
    // sang phải
    if (j + 1 <= n && a[i][j + 1] == 1){
        s += "R" ;
        a[i][j + 1] = 0 ;
        Try(i, j + 1) ;
        s.pop_back() ;
        a[i][j + 1] = 1 ;
    }
}
int main()
{
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ; j <= n ; j++ ){
            cin >> a[i][j] ;
        }
    }
    Try(1,1) ;
    if ( check == 0) cout << "-1" ;
    return 0 ;
}
/*
4
1 1 0 1
1 1 1 1
1 0 1 1
1 1 1 1
DDDRRR
DRRDDR
DRRDRD
DRRRDD
RDRDDR
RDRDRD
RDRRDD
*/