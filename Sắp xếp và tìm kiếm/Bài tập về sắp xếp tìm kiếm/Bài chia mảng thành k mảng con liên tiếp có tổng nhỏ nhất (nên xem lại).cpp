#include<bits/stdc++.h>
using namespace std;
/*
Chia mảng thành k mảng con liên tiếp có tổng nhỏ nhất : Bạn được cung cấp một mảng chứa n số nguyên dương. Nhiệm vụ của bạn là chia mảng k mảng con liên tiếp sao cho tổng lớn nhất tronng một mảng con càng nhỏ càng tốt và ta đi tìm cái tổng đó 
*/
bool check(int a[] , int n , int k , int sum ){ // k là số mảng cho phép, sum là cái tổng  được chọn ra để mang so sánh khi chia cửa sổ
    int ans = 0 ; // lưu số cửa sổ có thể chia được 
    int tong = 0;
    for ( int i = 0 ; i < n ; i++ ){
        tong += a[i] ;
        if ( tong > sum ){ // nếu sau khi cộng phần tử tiếp theo mà thấy lớn hơn sum cho phép thì ta đóng cửa sổ đấy lại được rồi và reset giá trị của cử sổ bằng phần tử tiếp theo trong dãy : ví dụ 3 3 1 3 4 5 ... sum cho phép = 7 thì ta thấy cửa sổ đầu tiên 3 + 3 + 1 = 7 , sau khi cộng thêm 3 nó sẽ tăng leen thành 10 không đúng nữa thì ta khép cửa sổ lại tại 1 và res giá trị cửa sổ về vị trí có giá trị là 3
            ans++ ;
            tong = a[i] ;
        }
    }
    ++ans; // vì khi đóng cửa sổ thì giá trị tổng sẽ reset về ô tiếp theo , mà theo đúng nguyên tắc không có 1 giá trị nào trong dãy lớn hơn sum nên nếu đằng sau cái ô cửa sổ vừa đóng còn tồn tại phần tử thì tức coi đấy chính là 1 cửa sổ nữa và ta phải đếm cả nó : ví dụ 3 3 1 3 4 5 thì sẽ chia thành được 3 cửa sổ 331 , 34 , 5 , cửa sổ bằng 5 chính là cái còn sót 
    return ans <= k ; // tại sao không phải bằng k bởi vì nếu đã chia được số cửa sổ còn nhỏ hơn k mà vẫn có tổng phù hợp nhỏ hơn sum thì tức là ta sẽ chia được thành k cửa sổ bất cứ lúc nào.
}
int main()
{
    int n , k ; cin >> n >> k ; 
    int a[n] ;
    for ( int i = 0 ; i < n ; i++ ){
        cin >> a[i] ;
    }
    int left = *max_element(a,a+n); // đây là giá trị lớn nhất trong mảng trong trường hợp dãy chia thành n cửa sổ , cũng tức là tổng lớn nhất trong 1 cửa sổ là nhỏ nhất : ví dụ 1 2 3 5 8 9 thì left sẽ bằng 9 là bởi vì lúc nào cũng sẽ tồn tại cửa sổ l = 9 và không thể giảm cái giá trị cửa sổ nhỏ hơn được nữa vậy nên giá trị nhỏ nhất có thể giảm được đến chính là 9  
    int right = accumulate(a,a+n,0) ; // đây là giá trị sum nhỏ nhất trong trường hợp mà dãy chỉ chia thành 1 cửa sổ 
    // mục đích tìm hai chỉ số trên để ta có thể tìm ra cái mốc nằm giữa để mà so sánh  bởi vì 1 <= k <= n
    int ans = -1 ;
    while ( left <= right){
        int mid = (left + right) / 2 ;
        // check mid 
        if ( check(a,n,k,mid) ) { // nếu cái này đúng tức là đối với giá trị cửa sổ bằng mid thôi ta đã chia được k cửa sổ rồi và giá trị cửa sổ là nhỏ nhất có thể giảm . bởi vì mid càng nhỏ thì càng có nhiều cửa sổ và có thể mid nhỏ hơn thì vẫn có thể chia k cửa sổ nên ta sẽ giảm right đi để tìm mid mơi < mid cũ
            ans = mid ;
            right = mid - 1 ; // 
        }
        else { // ngược lại nếu cái giá trị trung gian đó làm ta chia được cửa sổ > k thì tức ta phải tăng giá trị của mid lên bằng cách tăng left lên , như vậy mid mới > mid cũ làm số cửa sổ được chia giảm đi
            left = mid  + 1 ;
        }
    }
    cout << ans << endl ;
    return 0;
}