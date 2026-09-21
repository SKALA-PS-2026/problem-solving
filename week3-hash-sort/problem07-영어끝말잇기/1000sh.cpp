// 문제: 영어 끝말잇기
/*
접근 방식: set에 넣고 개수 측정후 안오르면 중복으로 판정
  끝자리 글자와 첫글자만 비교해서 다르면 오류
*/
// 시간복잡도: O(n) n<=100

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> keyword;
    int size=words.size();
    int i=0;
    char end=words[0][0];
    for(i=0;i<size;i++)
    {
        if(end!=words[i][0])break;
        keyword.insert(words[i]);
        if(i>=keyword.size()) break;
        end=words[i][words[i].size()-1];
    cout << words[i]<<"  "<<end<< endl;
        
    }
    if(i==size)return {0,0};
    i++;
    answer.push_back((i-1)%n+1);
    answer.push_back(ceil(i/(float)n));
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return answer;
}
