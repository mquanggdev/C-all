#include<bits/stdc++.h>
using namespace std;
/*
Bài toán cái túi : Một tên trộm có một cái túi có thể mang các đồ vật với trọng lựa tối đa là V. Hiện tại tên trộm muon lựa chọn các đồ vật trong N đồ vật để ăn trộm , mỗi đồ vật có trọng lựa w[i] và giá trị là v[i] . hãy xác định tổng giá trị lớn nhất của các đồ vật mà tên trộm này lựa chọn sao cho  trọng luơng của chúng không vượt quá V
*/
/*
Ý tưởng như sau : khởi tạo một F[i][j] : nó sẽ lưu value của cái túi khi mà đựng đồ vật i và nó có max trọng lượng = j

giải dụ với đề bài : n = 4 , v = 9 , 
                     w: 3   1    5    6
                     v: 20  10  30   15

i sẽ chạy từ 1 -> 4 biểu thị sẽ chọn đồ vật thứ 1 -> 4 ;
j sẽ chạy từ 1 -> 9 biểu thị cái túi sẽ có trọng lượng max từ 1 -> 9 ;

Đầu tiên  : F[1][1] -> nó sẽ chọn cái đồ vật số 1 và cái túi chỉ có trọng lượng là 1kg < trọng lượng vật 1 = 3 -> coi như không bỏ gì vào
...
-> tiếp đến F[1][3] -> lúc này cái túi đã có trọng lượng là 3kg => đã bỏ được cái vật 1 vào -> cập nhật value lên 20 -> hiển nhiên tất cả cái túi sau đó có trọng lượng lớn hơn 3kg đều sẽ đặt được vật 1 nên đều có value = 20 ;

Đến chọn vật 2 : F[2][1] -> với cái túi có trọng lượng 1kg -> nó sẽ bỏ được vật 2 vào -> cập nhật value lên 10 , tương tự với F[2][2]
-> tuy nhiên ở F[2][3] -> với cái túi có trọng lương 3kg -> nó cũng sẽ bỏ được vật 2 vào -> nhưng phải xem nó bỏ thêm được vật 2 và 1 chung hay không hoặc là chọn bỏ 1 trong 2 đồ vật có giá trị lớn hơn . -> lúc này ta thấy vốn dĩ cái túi có trọng lượng 3kg nó đã bỏ được vật 1 vào rồi và nó có F[1][3] = 20 đang giữ kỉ lục
=> F[1][3] = F[2][3] : và nếu muốn bỏ được vật 2 thì nó phải thừa ra 1kg cho vật 2 vậy thì nó quay ngược lại với cái túi 2kg thì nó thấy kỷ lục của cái túi 2kg chỉ là 10 thôi => nó không cập nhât -> nó vẫn bằng 20
-> nhưng sang cái túi có trọng lượng 4kg : 
F[2][4] = F[1][4] -> đang giữ kỉ lục là đựng vật 1 với giá trị 20 
xét đến vật 2 xem nó có bỏ được vật 2 hoặc thêm vật 2 vào hay không :
-> để bỏ được vật 2 thì nó phải dư ra 1kg => nó phải lần ngược lại cái túi 3kg ! thì thấy à với cái túi 3kg đang giữ kỉ lục là 20 và hiện tại nếu nó bỏ thêm vật 2 nó sẽ có giá trị là 30 -> nó cập nhật 


-> đến với trường hợp xa hơn : khi ta xét vật 3 : và cái túi đang ở mức 6kg :
F[3][6] hiện tại đang có kỷ lục = với cái túi F[2][6] tức là bằng kỉ lục tại thời điểm xét vật 2 là 30

Khi nó xét vật 3 có trọng lượng 5kg thì thấy à nó có thể chứa được thằng 5kg này và nó dư ra 1kg thì nó quay lại cái túi 1kg so sánh xem cái túi 1kg này đã bỏ được gì chưa -> nếu cái túi 1kg này đã bỏ vật gì vào rồi thì tức là cái túi 6kg này sẽ bỏ được cả cái vật mà cái túi 1kg đựng được trước đó và cả cái vật 3 có khối lượng này vào chung

nó so sánh : thấy được cái túi 1kg đang đựng được vật 2 tức F[2][1] = 10 => nếu nó đựng thêm vật 3 giá trị 30 và nó đựng được => giá trị của nó tăng lên 40 lớn hơn hẳn cái kỷ lục F[2][6] = 30

vì vậy ta mới có công thức F[i][j] = max[F[i-1][j], F[i][j - V[i]] + W[i]. 
*/
int w[1001] ;
int v[1001] ;
int F[1001][1001] ; // đại diện đặt đồ vật i vào túi có trọng lượng j thì mang lại value = ?
int main()
{
    int n , V ;
    cin >> n >> V ;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> w[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> v[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ ){ // duyệt qua từng đồ vât
        for ( int j = 1 ; j <= V ; j++ ){ // chia nhỏ trọng lượng của cái túi
            F[i][j] = F[i - 1][j] ; // hiển nhiên nếu cái túi có chịu lực j đã đặt được vật i thì các túi có trọng lượng > j cũng sẽ đặt được đồ vật i.
            if ( j >= w[i]){ // nếu mà cái túi chịu lực j > khối lượng của đồ vật đó tức là bỏ được đồ này vào trong -> so sánh : Nếu mà với cùng chịu lực j thì đặt đồ vật i - 1 hay i hoặc cả hai thì sẽ mang lại value to hơn
                F[i][j] = max ( F[i - 1][j] , F[i - 1][j - w[i]]  + v[i] ) ;
            }
        }
    }
    cout << F[n][V] << endl;
    return 0 ;
}
/*
6 22
39 44 4 59 91 70
47 26 92 33 6 69

92
*/