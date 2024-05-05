#include<bits/stdc++.h>
using namespace std;
/*
Bài 15 : Đổi chỗ chữ số : Cho số tự nhiên K và xâu ký tự chữ số S . Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S.ví dụ K = 3 : S = 1234567 -> 7654321 
*/
int k ;
string s ;
string res ;
void ql(int i , int cnt , string s){
    cout << i << " " << s << endl;
    if ( i == s.size() || cnt == k){
        res = max(res,s) ;
        return;
    }

    char max_value = s[i] ; // thằng này có nhiệm vụ đi tìm thằng lớn nhất trong dãy
    vector<int> max_pos ; ; // thằng này thì có nhiệm vụ lưu lại vị trí của những thằng lớn nhất trong dãy bởi vì đôi khi trong một dãy thì sẽ có nhiều thằng lớn bằng nhau

    for ( int j = i + 1 ; j < s.size() ; j++ ){
        if ( s[j] > max_value){
            max_value = s[j];
            max_pos.clear();
        }
        if ( s[j] == max_value){
            max_pos.push_back(j);
        }
    }

    if ( max_value > s[i]){ // nếu thằng hiện tại nhỏ hơn thằng max_value thì ta swap 2 thằng đó với nhau : lưu ý swap theo vị trí trong vector bởi vì do nhiều thằng cùng vị trí nên gặp thằng nào mà max đầu tiên thì đổi chỗ cho thằng đấy.
        for(auto x : max_pos){
            string tmp = s ;
            swap(tmp[i] , tmp[x]);
            ql(i + 1 , cnt + 1 , tmp) ; // tiếp tục đến vị trí tiếp theo , tăng cnt lên để đánh dấu đã hoán vị 1 lần
        }

    }
    else {
        ql(i + 1, cnt ,s); // bởi vì nếu thằng đầu đã là max thì ta phải xét đến vị trí thứ 2.
    }
}
int main()
{
    cin >> k >> s ;
    ql(0, 0 , s) ;
    cout << res << endl ;   
    return 0 ;
    
}
/*
2
2155
0 2155
1 5125
2 5521
1 5152
2 5512
5521
*/