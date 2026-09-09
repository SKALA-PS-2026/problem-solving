// 문제: 소수 찾기
// 접근 방식: 2부터 n까지의 숫자들에 대해 그 안에서 2에서 해당숫자의 제곱근까지 또 for문을 돌린다.
// 만약 나누어떨어진다면 소수가 아니므로 isPrime을 false로 설정하고 break한다.
// 시간복잡도: O(n√n)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> list;
    
    for(int i=2; i<=n; i++) {
        bool isPrime = true;
        
        for(int j=2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) answer++;
        
        
        // 소수라면? list에 push_back한다. 
        // list에 있는 숫자들 중 나누어떨어진다면 소수가 아님. continue
//         if(list.size() == 0) {
//             list.push_back(i);
//             answer++;
//         }
        
//         bool isPrime = true;
        
//         for(int k=0; k<list.size(); k++) {
//             if(i % list[k] == 0) {
//                 isPrime = false;
//                 break;
//             }
//         }
        // if(isPrime) {
        //     list.push_back(i);
        //     answer++;
        // }
    }
    
    
    return answer;
}
