// 문제: 배열 두 배 만들기
// 접근 방식: 
// 시간복잡도: 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i = 0;i < numbers.size(); i++) {
        answer.push_back(numbers[i] * 2);
    }
    return answer;
}
