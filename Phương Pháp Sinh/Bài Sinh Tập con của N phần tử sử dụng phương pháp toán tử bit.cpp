#include<bits/stdc++.h>
using namespace std;
/* ví dụ : Bài Liệt kê tập con khác rỗng của N theo thứ tự từ điển tăng dần
ý tưởng : Bài này cũng sẽ dựa theo bài toán sinh tập con bằng toán tử bit
*/
int n ;
void sinh(){
    vector< vector<int> > res ;
    for ( int i = 1 ; i < (1 << n) ; i++ ){
        vector<int> tmp ; 
        for ( int j = 0 ; j < n ; j++){  // j = n - 1 , j >= 0 , j-- thì sẽ in ra đúng
            if ((i & (1 << j)) != 0){
              tmp.push_back(j + 1);
            }
        }
      res.push_back(tmp)  ;
    } /* sau dòng này thì đáp án là: (đáp án này bị ngược do duyệt từ cuối nhưng vòng in từ đầu)
    thực tế thì xâu con của 4 chẳng hạn nó cũng chỉ là sự thay đổi vị trí của các bit 0 và 1 , chỗ nào có bit 1 thì nó sẽ mang giá trị của 1 trong 4 số là 1 2 3 4 : như kiểu là từ 4 số 1 2 3 4 lập ra tất cả các tổ hợp có thể tạo thành từ 4 số đó thì sẽ ra y như ở dưới , và mỗi tổ hợp nó tương ứng với số vị trí của bit 1 của các số từ 1 -> 2^n - 1 ;
    * lưu ý ở dưới là in ra kết quả j + 1 , lấy cái ở dưới - 1 sẽ ra đúng vị trí của các số 1
1 = 1 = 0001
2 = 2 = 0010
2 1 = 3 = 0011
3 = 4 = ....
3 1 = 5
3 2 = 6
3 2 1 = 7
4 = 8
4 1 = 9 
4 2 = 10
4 2 1 = 11
4 3 = 12
4 3 1 = 13
4 3 2 = 14
4 3 2 1 = 15
    */
     sort(res.begin(),res.end()) ;
     for ( auto it : res){
        for (auto x : it ) cout << x << " ";
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
1
1 2
1 2 3
1 2 3 4
1 2 4
1 3
1 3 4
1 4
2
2 3
2 3 4
2 4
3
3 4
4
*/