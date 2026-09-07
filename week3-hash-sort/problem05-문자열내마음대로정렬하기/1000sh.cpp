// 문제: 문자열 내 마음대로 정렬하기
// 접근 방식: 문자열 기준을 맵에 넣고 나머지를 뒤에 넣고 정렬되게 만든후 순서대로 뽑아서 정답에 집어 넣음.
// 시간복잡도: O(n L log n) n<=50 L<=100

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    map<char,set<string>> word;
    
    int size=strings.size();
    for(int i=0;i<size;i++)
    {
        word[strings[i][n]].insert(strings[i]);
    }
    
    for (auto& [key, values] : word)
    {   
        for (auto& value : values)
        {
            answer.push_back(value);
        }
    }   
    
    return answer;
}
