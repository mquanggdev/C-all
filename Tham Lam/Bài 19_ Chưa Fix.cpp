#include<bits/stdc++.h>
using namespace std;
/*
Bài 19 _ Di chuyển dấu ngoặc : Cho xâu S chỉ bao gồm các kí tự '(' hoặc ')' . S có độ dài là số chẵn có giá trị là N . Xâu S gồm N / 2 kí tự mở ngoặc và N / 2 kí tự đóng ngoặc. Ở mỗi thao tác các bạn được lựa chọn  gồm 1 kí tự bất kỳ của S để đưa về vị trí đầu tiên hoặc vị trí cuối cùng của dãy . Các bạn hãy xác định số thao tác tối thiểu để thực hiện một xâu ký tự hợp lệ 

tư tưởng bài này là đi tìm các cặp nào hợp lệ trước và lấy tổng số cặp trừ đi những cặp đó thì sẽ ra số thao tác.
*/
int main()
{
    string s ; cin >> s ;
    int n = s.size() / 2 ;
    int index;
    int index2;
    int index3;
    int cnt = 0;
    int cnt2 = 0;
    for ( int i = 0 ; i <= s.size() ; i++ ){
        if ( s[i] == '(' && s[i + 1] == ')'){
             index =  i;
             index2 = i + 1; 
            while (index >= 0 && s[index] != ')'){
                index--;
                cnt++ ;
            }
            while(index2 < s.size() &&  s[index2] != '('){
                index2++;
                cnt2++ ;
            }
            // if ( cnt > cnt2){
            //     index3 = i - cnt2;
            //     for (index3 ; index3 >= index ; index3--){
            //         if (s[s.size() - index3 - 1] == ')'){
            //             n-- ;
            //         }
            //     }
            // }
            n -=  min(cnt , cnt2) ;
            cnt = 0 ;
            cnt2 = 0 ;
        }
    }
    cout << n ;
    return 0 ;
}
/*
)))((((())(())(())
3
*/