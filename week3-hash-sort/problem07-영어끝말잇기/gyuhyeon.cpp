// 문제: 영어 끝말잇기
// 접근 방식: 이전 단어의 끝 글자와 현재 단어의 첫 글자를 비교하고 해시 집합으로 중복을 검사하여, 최초 탈락자의 번호와 차례를 구한다.
// 시간복잡도: 평균 O(M * L) (M: 단어 수, L: 단어의 최대 길이, 해시 연산 평균 기준)

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_set<string> word_set;
    
    int cnt = 0;
    
    word_set.insert(words[0]);
    
    for (int i=1; i<words.size(); i++) {
        if (words[i][0] != words[i-1][words[i-1].size()-1] ||
           word_set.find(words[i]) != word_set.end()) {
            cnt = i+1;
            break;
        }
        
        word_set.insert(words[i]);
    }
    
    if (cnt == 0) answer = {0,0};
    else {
        if (cnt%n==0) answer = {n, cnt/n};
        else {
            answer = {cnt%n, (cnt/n)+1};
        }
    }
    return answer;
}