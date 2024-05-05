#include<bits/stdc++.h>
using namespace std;
/*
Bài 23 _ Xâu con đối xứng dài nhất : Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự. Hãy tìm xâu con đối xứng dài nhất của S. 
nếu mà 2 thằng dầu cuối của một xâu bắt đầu từ i và kết thúc ở j bằng nhau và dãy con của nó là dãy đối xứng thì dãy đó sẽ là đối xứng
Khi xét đến một độ dài n nào đó nếu mà 2 thằng đầu của độ dài đó và cái thằng con có độ dài m được tính trước đó mà đối xứng và có độ dài max nào đó thì cái độ dài n đó được xác định là có đối xứng!
*/
int F[1001][1001];
int main(){
    string s ; cin >> s ;
    int n = s.size();
    s = "0" + s ;
    int max_len = 1 ;
    for ( int len = 1 ; len <= n ; i++ ){
        for (int i = 1 ; i + len - 1 <= n ; j++ ){
            int j = i + len - 1 ; // đánh dấu là thằng cuối dãy
            if ( len <= 2 ){ // có 2 trường hợp đó là len = 1 hoặc 2 thì điều kiện để là xâu đối xứng là chúng phải bằng nhau
                F[i][j] = (s[i] == s[j]);
            }
            else {
                F[i][j] = (s[i] == s[j]) && F[i + 1][j - 1];
            }
            if ( F[i][j]) max_len = len ;
        }
    }
    cout << max_len ;
    return 0;
}