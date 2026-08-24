// 문제: 같은 숫자는 싫어
// 접근 방식: 0번 인덱스만 넣어두고 그 뒤로는 앞이랑 똑같은 숫자면 넘어가고 다른 숫자면 넣기
// 시간복잡도: O(n)

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int i=1; i<arr.size(); i++){
        if (answer.back()==arr[i]){
            continue;
        }
        else{
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
