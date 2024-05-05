#include<bits/stdc++.h>
using namespace std;
/*
bài 5 _ Sắp xếp tham lam 
ý tưởng : Tạo ra dãy đã được sắp xếp rồi và so sánh -> do chỉ lấy điểm chính giữa làm mốc quay nên các phần tử nó chỉ có được 2 vị trí -> nó phải nằm ở 1 trong 2 vị trí đã được sắp xếp(hoặc chưa được sắp xếp nhưng nếu sắp xếp nó sẽ ở đó) thì nó mới là chính xác!
*/
int main()
{
    int n ; cin >> n ; // phải là số lẻ
    vector<int> a ;
    vector<int> b ;
    int cnt = 0; 
    for ( int i = 0 ; i < n ; i++){
        int x ; cin >> x ;
        a.push_back(x) ;
        b.push_back(x) ;
    }
    sort(b.begin(),b.end()) ;
    for ( int i = 0 ; i < n ; i++ ){
        if ( a[i] == b[n - i - 1] || a[i] == b[i]){ 
            cnt += 1 ;
        }
    }
    if ( cnt == n){ cout << "YES" << endl;}
    else cout << "NO" << endl;
    return 0 ;
}
/*
7
1 6 3 4 5 2 7
YES

5
1 4 3 2 5
YES

5
1 3 8 7 3
NO
*/