#include<bits/stdc++.h>
using namespace std;
/* Bài 1 : cho số n , k , s : n là giá trị max mà mỗi phần tử nhận được , k là số phần tử cho phép , s là tổng của các phần tử , nhiệm vụ của bạn là tìm ra tất cả tập hợp có thể tạo thành từ k phần tử có tổng bằng s với các số trong khoagr từ 1 -> n , và mỗi hoán vị là duy nhất ví dụ {6,7,8} = {7, 8 , 6} đều được tính một lần
*/
int n , k , s , x[50];
int cnt = 0 ;
int a[1001] ;
//cách 1 : chưa hiểu rõ lắm
void solve(int i , int sz , int sum){
    if ( i == n + 1){
        if (sum == s && sz == k){
            cnt++ ;
        }
        return;
    }
    if ( sz + 1 <= k){
        solve(i + 1 ,sz + 1 , sum + a[i]);
    }
    solve(i + 1 , sz , sum) ;
}
// cách 2 : thực tế cách này thì dễ hiểu hơn , đầu tiên dựa vào đề bài ta có thể xác định được để có thể không có cấu hình nào trùng lặp nhau thì bắt buộc các cấu hình phải là một dãy tăng => vòng for j = x[i - 1] + 1 , nghe khá giống với phương pháp sinh tổ hợp , nhưng vì không phải lúc nào ta cũng nhận được đề bài như vậy và để hoàn thành cửa sổ thì ta có 2 điều kiện , số phần tử phải bằng k và tổng cửa sổ đó phải bằng s 
void ql(int i , int sum){
    for ( int j = x[i - 1] + 1 ; j <= n ; j++ ){
        // nếu muốn nhanh hơn ta dùng đến nhánh cận if ( sum + j <= s) thì sẽ thực hiện các dòng phía dưới : tức là nếu mà cái sum trước đó và cộng với giá trị hiện tại mà lớn hơn s thì ta sẽ không đi xét , bởi nếu xét thêm cũng chỉ ra kết quả lớn hơn , nên ta sẽ dừng ngay tại bứoc này => thời gian sẽ nhanh hơn so với sử dụng nguyên như dưới
        x[i] = j ;
        if ( i == k){
            if ( sum + x[i] == s){ // tức là khi i = k thì cái sum lúc này là sum lúc mà x[2] + x[i] , thì nó sẽ kiểm tra nếu sum lúc i = 2 mà + với sum lúc i = 3 mà hợp lệ thì nó sẽ tăng cnt , 
                cnt ++ ;
            }
        }
        else {
            ql(i + 1, sum + x[i]) ; // còn không nó sẽ gọi đệ quy tiếp đến i + 1 , giả dụ i đang bằng 1 và khi chạy đến chỗ này thì nó sẽ gọi đến i = 2  , nhưng sum lúc này = 0 còn như kiểu là khi trước khi bước vào i = 1  , sum chưa có gì , và khi ta bước vào 2 thì nó nhận được mes rằng , à ta đã có sum mới = 0 + x[1] ,vì vậy mới có công thức kia
        }
    }
}
int main()
{
    cin >> n >> k >> s;

    for ( int i = 1 ; i <= n ; i++) {
        a[i] = i ;
    }
    solve(1,0,0) ;
    ql(1,0);
    cout << cnt ;
    return 0 ;
}