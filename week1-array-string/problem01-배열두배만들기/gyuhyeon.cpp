// 문제: 배열 두 배 만들기
// 접근 방식: 
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int num : numbers) {
        answer.push_back(num*2);
    }
    
    return answer;
}