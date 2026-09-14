// 문제: 같은 숫자는 싫어
// 접근 방식: 
// 시간복잡도: O(n)

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr[0]);
    
    for (int num : arr) {
        if (answer.back() != num) {
            answer.push_back(num);
        }
    }

    return answer;
}