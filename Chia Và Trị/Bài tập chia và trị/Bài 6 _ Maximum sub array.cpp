#include<bits./stdc++.h>
using namespace std;
/*
Bài 6 : Maximum sub array : cho dãy số nguyên a có n phần tử , nhiệm vụ của bạn là tính tổng của dãy con có tổng lớn nhất :
-> chưa áp dụng thuật toán chia và trị mà đang áp dụng phương pháp kadane với độ phức tạp O(n) ;
*/
int maxSubArray(int a[] , int n){
    int maxSoFar = a[0] ; // thằng này nó sẽ lưu trữ thằng tổng lớn nhất mà thu được từ mảng
    int maxEndinghere = a[0] ; // còn thằng này sẽ đi tìm tổng lớn nhất tính từ đầu đến vị trí hiện tại
    for ( int i = 0 ; i < n ; i ++){
        maxEndinghere = max (maxEndinghere + a[i], a[i]) ; // thằng này nó sẽ lọc ra - trong trường hợp dãy có số âm thì nó khi mà nó cộng với số tiếp theo mà là số âm chẳng hạn thì nó sẽ giữ lại số cũ và ngắt tổng ở đó , còn trong trường hợp số mới là số dương tức là khi cộng vào lớn hơn số cũ nó sẽ cập nhật tổng mới , --> nhưng bởi vì dãy con không giới hạn phần tử nên nó chỉ cần đi tìm số đầu tiên mà làm cho cái tổng nó trở lên dương , là bắt đầu đi cộng tổng từ đó.
        maxSoFar = max(maxSoFar,maxEndinghere) ; // lưu lại cái tổng lớn nhất bắt được.
    }
    return maxSoFar;
}
int main()
{
    int n ,a[1001] ;
    cin >> n  ;
    for ( int i = 0 ; i < n ; i ++){
        cin >> a[i] ;
    }
    cout << maxSubArray(a,n) ;
    return 0;
}
/*
5
-3 6 1 -3 6

10
*/