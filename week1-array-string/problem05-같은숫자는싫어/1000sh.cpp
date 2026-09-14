// 문제: 같은 숫자는 싫어
// 접근 방식: 배열을 집어넣고 최근것과 같으면 삭제
// 시간복잡도: O(n) n<=10^6

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    if(arr.size()==0) return {};
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]==answer.back())continue;
        answer.push_back(arr[i]);
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
