// 문제: H-Index
// 접근 방식: 정렬후 해당 최대크기 - 인덱스보다 큰지 비교
// 시간복잡도: O(nlongn)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    int size=citations.size();
    for(int i=0;i<size;i++)
    {
        cout<<citations[i]<<".  "<<size-i<<endl;
        if(citations[i]>=size-i) return size-i;
    }
    return answer;
}
