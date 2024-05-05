#include<bits./stdc++.h>
using namespace std;
/*
Quy hoạch động : dạng thuật toán này có độ phức tạp rất tốt , thường dùng trong những bài tập dạng tối ưu bài toán , đếm cấu hình ... ;
Nó hoạt động dựa trên nguyên tắc chia nhỏ bài toán lớn thành các bài toán con nhỏ hơn, lưu trữ kết quả của các bài toán con này (còn gọi là “memoization”), và sau đó sử dụng các kết quả đó để tìm lời giải cho bài toán lớn.
*/
/*
Bài 7 _ squirrel 1: Có N nhóm ngũ cốc được đánh số từ 1 -> N . một con sóc đi từ ô thứ 1 và nó phải đến ô thứ N , chi phí mỗi lần di chuyển là abs[A[y]-A[x]] từ x -> y ; môi lần di chuyển con sóc có thể bước 1 ô hoặc 2 ô -> nhiệm vụ của bạn là tính chi phí tối thiểu để giúp con sóc đi tới N (nếu được in ra đường đi!);

// đây là một bài toán điển hình : ý tưởng là TA SẼ tạo ra một mảng F[i] lưu lại các kỷ lục về chi phí con sóc từ đầu đến vị trí i :
ví dụ : đường đi : 3 7 2 4 8 -> chi phí tại f[0] = 0 , chi phí f[1]= |3 - 7| = 4 -> xác nhận kỉ lục
f[2] -> tại đây con sóc nó đã có 2 lựa chọn : 1 là đi theo 3 7 2 thì chi phí của nó sẽ bằng kỉ lục đằng trước tức đường đi tôn ít chi phí nhất khi mà đi đến 7 là 4 cộng với chi phí hiện tại để đi đến 2 nữa là |2 - 7| = 5 => tổng chi phí khi đi con đường 3 5 7 là 5 + 4 = 9 :
cách thứ 2 là nó đi theo con đường 3 -> 2, thì chi phí kỉ lục để đi đến 3 là 0 , + thêm với chi phí hiện tại là |3 - 2| = 1
rõ ràng là chi phí đi từ 3 -> 2 thì sẽ rẻ hơn vậy nên xác nhận f[2] = 1 -> kỉ lục chi phí nhỏ nhất đi đến 2 là 1
cứ như vậy thì khi mà i -> n thì f[n] chính là chi phí nhỏ nhất mà ta cần tìm
*/
int n ;
int a[1001] ;
int f[1001] ;
vector<int> vp;
void  solve() {
    for ( int i = 2 ; i <= n ; i++){
        f[i] = min ((f[i - 1] + abs(a[i] - a[i - 1])) , f[i - 2] + abs(a[i - 2] - a[i])) ;

    }
}
int main()
{
    cin >> n ;
    for ( int i = 1; i <= n ; i++ ){
        cin >> a[i];
    }
    f[1] = 0 ;
    solve() ;
    cout << f[n] ;
    return 0;
}
/*
9
3 7 2 4 8 1 1 5 5
10


6
1 4 12 7 5 9
8
*/