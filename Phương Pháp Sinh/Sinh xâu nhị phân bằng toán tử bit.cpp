#include<bits/stdc++.h>
using namespace std;
/* Phướng pháp sinh tập con bằng toán tử bits  - kết quả thì giống phương pháp sinh nhị phân nhưng cách làm thì hoạt động dựa trên toán tử bit 0 và 1 ;
*/
int n ;
void sinh(){
    for ( int i = 0 ; i < (1 << n) ; i++ ){ // tức là  < 2*n 
        // phan tich xem tung bit mot cua so i xem la 0 hay la 1 ;
        for ( int j = 0 ; j <= n ; j++){ //int j = n - 1 ; j >= 0 ; j-- thì sẽ in đúng hơn (bởi vì theo thuật toán ta duyệt từ cuối lại nên nó sẽ in ngược)

            // đây là toán tử AND nếu 1 AND 2^j(được biểu diễn bởi toán tử bit) tức ví dụ như sau n = 4: i = 2 tức là cấu hình hiện tại là 00010 thì nó sẽ xét cấu hình tiếp theo bằng cách AND từng vị trí của số trên với 2^j với j chạy từ 1 cho đến 4 để mà xác định số ở vị trí j = 1 là j , j = 2 là gì ? chẳng hạn như ví dụ trên ta có j = 0 thì 00010 * 00000 = 00000 tức bằng 0 thì nó sẽ hiểu là bit thứ 0 của số 2 bằng 0 -> đúng , j=1 ->  00010 * 00010 = 00010 tức bằng 2 != 0 => vị trí số 1 của số thập phân 2 = 1 là đúng , j = 2 -> 00010 * 00100 = 00000 = 0 -> vị trí số 2 của số thập phân 2 = 0 là đúng , j = 3 -> 00010 * 01000 = 00000 = 0 -> vị trí thứ 3 của số thập phân 2 là đúng  ,vậy => số 2 được in -> 00010
            //vốn dĩ máy tính nó không tự in ra 00010 cho số 2 được nhưng nó sẽ tự hiẻu 2 thành 00010 và việc của ta là lấy cái nó hiểu để làm công việc in ra => như thế mới là sinh xâu   
            if ((i & (1 << j)) != 0){
                cout << 1 ;
            }
            else cout << 0;
        }
        cout << endl;
    }
}
int main()
{
    cin >> n ;
    sinh() ;
    return 0;
}
/*
4

00000
10000
01000
11000
00100
10100
01100
11100
00010
10010
01010
11010
00110
10110
01110
11110
*/