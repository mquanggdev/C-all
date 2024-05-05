#include<bits/stdc++.h>
using namespace std;
/* Sinh Phân hoạch  
*/
int n , a[101] , ok , cnt;
void init(){
    cnt = 1 ; // số lượng số hạng hiện tại
    a[1] = n ;
}
void SinhPhanHoach(){
    int i = cnt ;
    while (i >= 0 && a[i] == 1 ){
        --i ;
    }
    if ( i == 0 ){
        ok = 0;
    }
    else {
        a[i]--;
        int d = cnt - 1 + 1 ; // đếm số lần số 1 bị bỏ qua hay số đơn vị đã bị giảm đi cho đến hiện tại ( + 1) là do vừa bị trừ đi đấy
        cnt = i ; // vị trí hiện tại của i là độ dài sau khi bỏ qua d đơn vị hay bỏ qua d số 1 ; ví dụ cấu hình hiện tại là 4 3 1 1 -> sau dòng này thì cnt = 2 tương đương 4 2 do ta bỏ qua 2 số 1 đầu tiên và trừ đi một đơn vị của số 3 nên d = 3 ;
        // sau dòng trên thì ta cần đi tìm cách biểu diễn cho số đơn vị còn thiếu và cách biểu diễn như sau : ví dụ cấu hình hiện tại là 4 3 1 1 thì sau đó phải là 4 2 2 1 , bởi vì mục đích cuối cùng  của ta là biểu diễn ra n số 1 có tổng là n , nên không thể cứ mỗi lần trừ ta viết thêm số 1 đằng sau , như thế sẽ bị mất các cấu hình
        int q = d / a[i] ;  // ở vị trí a[i] sẽ là cái số sẽ được lấy để biểu diện cho đoạn còn lại , nếu bị thiếu sẽ lấy thêm phần dư phía dưới để biểu diễn , như ví dụ trên 3 % 2 = 1 tức là có 1 số 2 được biểu diễn và dư là 1 nên số 1 sẽ được biểu diễn tiếp theo
        int r = d % a[i] ; 

         if(q){ // 
            for ( int j = 1 ; j <= q ; j ++){ // có q số a[i] cần biểu diễn ;
                ++cnt; // i đang bằng i tức trong dãy chẳng hạn có 4 2 thì cần cộng thêm cnt dể chỉ số tăng lên 3 rồi gán a[3] = với a[i] hiện tại tức là a[2] ;
                a[cnt] = a[i];
            }
        }
        if (r) { // sau khi biểu diễn a[i] theo q xong mà còn dư thì a[i] tiếp theo sẽ được biểu diễn theo r .
            ++cnt;
            a[cnt] = r ;
        }
    }
}
int main(){
    cin >> n ;
    init() ;
    ok = 1 ;
    while (ok){
        for ( int i = 1 ; i <= cnt ; i++ ){
            cout << a[i] << " ";
        }
        cout << endl;
        SinhPhanHoach();
    }
}