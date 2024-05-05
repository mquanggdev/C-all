#include<bits/stdc++.h>
using namespace std;
/* Bài 4 : Dãy con có tổng bằng K .Cho dãy a có n phần tử khác nhau và số tự nhiên k , hãy đưa ra tất cả dãy con của dãy số A  sao cho tổng các phần tử của dãy con đó đúng bằng k 
ý tưởng : đầu tiên ta sắp xếp bài này theo thứ tự từ bé đến lớn , tạo một vector để lưu các số tìm được , duyệt từng phần tử và push nó vào vector , và cộng biện tổng lên , nếu tổng bằng k thì in những số trong vector ra , gọi vòng for đầu tiên là for1 tức là vòng for được đệ quy lần 1  : ví dụ cho dãy sau 1 2 4 7 8 9 10 , k = 12
khi nó thêm 1 vào v , và tăng sum = 1 thì nó thấy không bằng k nhưng lại nhỏ hơn k thì nó thực thiện Try (i + 1) = Try(2) ; // v{1}; sum = 0 ;
---- lúc này có thêm vòng for mới là for2 
thêm 2 vào v và sum += 2 , so sánh thấy vẫn nhỏ hơn k lại thực hiện try(3) // v{1,2} sum = 3
---- lúc này lại thêm vòng for mới là for3 bắt đầu với i = 3 
=> thêm 4 vào v , sum += 4 thấy vẫn nhỏ hơn k => thực hiện Try(4) ; //v{1,2,4} sum = 7 ;
---- lúc này lại có thêm vòng for là for4 
=> thêm 7 vào trog v , và sum += 7 , lúc này thì sum = 14 , thấy khác k và lớn hơn k thì nó sẽ xóa thằng 7 đi và giảm sum đi 7 -> // v{1,2,4} sum = 7
** chú ý : lúc này thì trong Try(4) vẫn đang thực hiện vòng for4 , vòng for này mới chỉ chạy được chỉ số i = 4 , nên nó sẽ cộng i lên thành 5 .(chỗ này cần chú ý vì ta dễ bị nhầm là sẽ quay lui hẳn lại i = 1)
=> thêm a[5] = 8 vào trong  v , sum += 8 , thấy lớn hơn k ta sẽ lại pop 8 khỏi v và giảm s đi 8 -> // v{1 ,2 , 4} sum = 7
lúc này thì sẽ tiếp tục thực hiện vòng for4  đến khi i = 7 (nhưng ta nhận thấy , dãy là sắp xếp tăng dần nên từ 8 đi sẽ chỉ có số lớn hơn 8 nên sẽ không kiếm được phần tử nhỏ hơn k nên ta sẽ không viết tiếp) ;// v{1 ,2 , 4} sum = 7
->và khi i đã đạt đến 7 thì vòng for4 kết thúc , lúc này thì stack nó mới dẩy thằng for4 ra 
---- quay lại với for3 thì lúc này i của for3 mới tăng lên 4 ,
ta cộng thêm a[4] = 8  vào sum và thêm 8 vào v -> thấy sum > k nên sẽ xóa thằng 8 này khỏi v , và giảm s đi // v{1,2,4} s = 7 ;
như ở trên đã nói thì từ thằng 8 này trở về sau thì toàn thằng lớn hơn thôi nên ta sẽ không viết tiếp , nhưng máy nó vẫn chạy nha , nó vẫn sẽ tăng thằng i của for3 lên đến 6 và nó sẽ kết thúc thằng for3 , và khác ở chỗ khi mà kết thúc for3 thì nó sẽ xóa thằng a[3] = 4 đi khỏi v cà s = 7 - 4 = 3 // v {1.2} sum = 3 .
--- quay lại với for2 thì lúc này i của for2 mới tăng lên thành 3 
ta thêm a[3] vào v rồi cộng thêm 4 vào s , ta thấy nó quay lại bước for4 , máy sẽ hoạt động y vậy và đến khi quay lại vòng for[2] tăng i lên thành 4 và thêm a[4] = 7 vào và cộng s+= 7 , máy sẽ hoạt động như trên , dễ dàng nhận thấy cũng sẽ không ra kết quả , 
-- quay lại vòng for2 tăng i lên thành 5 và thêm a[5] = 8 , tiếp tục nhận thấy cũng sẽ không hợp lệ ,
-- tiếp tục vòng for tăng i lên thành 6 và ta có a[6] = 9 và thêm nó vào v và sum += 9  //v{1,2,9} sum = 12
-> lúc này đã tìm thấy 1 cặp và in ra sau đó xóa 9 ra khỏi v và s giảm đi 9, tiếp tục tăng i lên ,và khi i chạm tới 7 rồi , nó sẽ thoát vòng for2 kết thúc , nó sẽ xóa luôn cả 2 khỏi v và giảm s xuông

vầng lúc này thì ta mới quay lại được vòng for1 và tăng chỉ số i lên 2 . và cứ tiếp tục như thế đến một lúc nào đấy thì thằng for1 cũng sẽ kết thúc rồi mới bắt đầu một chuỗi for mới bắt đầu từ for2.


*/
int n , k , a[100] , x[1000] , ok = 0 , sum = 0 ;
vector<int> v ;
void init()
{
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
    }
    sort(a + 1 , a + n + 1) ;
}
void Try(int start) {
    for ( int j = start ; j <= n ; j++){
        v.push_back(a[j]) ;
        sum += a[j] ;
        if ( sum == k){
            ok = 1 ;
            cout << "{" ;
            for (int l = 0 ; l < v.size() ; l++ ){
                cout << v[l] ;
                if ( l == v.size() - 1) cout << "}" << endl;
                else cout << " " ;
            }
        }
        else if ( sum < k ){
            Try(j + 1) ;
        }
        sum -= a[j] ;
        v.pop_back() ;

    }
}

/*Cách 2 : nhận thấy đề bài bảo in tập con thì phải xác định đây cũng là một bài đếm tiến , nhưng đếm tiến cái gì , câu trả lời là vị trí , ví dụ cửa sổ 1 chọn thằng ở vị trí số 1 thì các thằng đằng sau chỉ được phép chọn các phần tử từ vị trí i = 2 trong dãy trở đi thì mới hợp lệ ,*/
// Giair thích : mảng a sẽ được dùng để lưu các giá trị trong dãy n , còn mảng x sẽ lưu vị trí của chúng sẽ xuất hiện trong cấu hình : Ví dụ dãy là 5 10 15 20 25 , s = 50 , thì cấu hình 1 là {5 , 20 ,25} thì x[1] = 1 là vị trí của 5 , x2 là vị trí của 20 nhưng tuowbg đương với a[4]
void ql(int i , int sum){
    for ( int j = x[i - 1] + 1 ; j <= n ; j++ ){ // j ở đây là vị trí trong  mảng a[]
        if ( sum + a[j] <= s){ // bước tối ưu nhánh cận
            x[i] = j ; // gán vị trí , như ví dụ trên thì có thể gán x[2] = 4 tức là phần tử thứ 2 trong cấu hình là phần tử thứ 4 trong mảng a[] ;
            if ( sum += a[j] == s){
                for ( int u = 1 ; u <= i ; u++){
                    cout << a[x[u]] << " ";
                }
            }
            else {
                ql(i + 1 ,sum + a[j]) ;
            }
        }
    }
}
int main()
{
    init() ;
    Try(1) ;
    if (!ok) cout << "-1" ;
    return 0;
}
/*
10 26
12 11 9 10 6 8 14 7 5 13

{5 6 7 8}
{5 7 14}
{5 8 13}
{5 9 12}
{5 10 11}
{6 7 13}
{6 8 12}
{6 9 11}
{7 8 11}
{7 9 10}
{12 14}
*/