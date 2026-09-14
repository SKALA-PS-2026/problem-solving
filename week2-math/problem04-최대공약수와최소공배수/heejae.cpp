// 문제: 최대공약수와 최소공배수
// 접근 방식: c++에는 최대공약수, 최소공배수 함수가 있어서 이용했다
// 시간복잡도: O(log(min(n, m)))

#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    
    int gcd = 0;
    int lcd = 0;
    
    gcd = std::gcd(n, m);
    lcd = n / gcd * m;
    
//     int big = max(n, m);
//     int small = min(n, m);
    
//     for(int i=small; i>=1; i--) {
//         if(big % i == 0 && small % i ==0) {
//             gcd = i;
//             break;
//         }
//     }
    
//     for(int i=big; i<=big * small; i++) {
//         if(i % big == 0 && i % small == 0) {
//             lcd = i;
//             break;
//         }
//     }
    
    answer[0] = gcd;
    answer[1] = lcd;
    
    return answer;
}
