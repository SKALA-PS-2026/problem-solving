// 문제: 자연수 뒤집어 배열로 만들기
// 접근 방식: 1의 자리 배열에 넣고 10으로 나누고 반복
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while (n>9){
        answer.push_back(n%10);
        n/=10;
    }
    answer.push_back(n);
    return answer;
}
