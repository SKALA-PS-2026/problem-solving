// 문제: 배열 두 배 만들기
// 접근 방식: 배열 for로 돌려서 2배해서 바로 대입.
// 시간복잡도: O(n)  O(1000)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    for(int i=0;i<numbers.size();i++)
    {
        answer[i] = numbers[i]*2;
    }
    return answer;
}
