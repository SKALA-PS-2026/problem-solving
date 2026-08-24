// 문제 이름: 배열만들기2
// 시간복잡도: O(2n)
// 풀이 방법: 5에서 출발해서 0붙인거 추가, 5붙인거 추가를 반복함! (ex 5에서 0붙여서 50추가하고 5붙여서 55추가. 그다음에는 50에다가 0붙여서 500추가, 55에다 0붙여서 550 추가)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int ten (int a){
    int cnt=0;
    while (a/10>0){
        a/=10;
        cnt++;
    }
    return cnt;
}

vector<int> solution(int l, int r) {
    vector<int> tmp;
    tmp.push_back(5);
    int idx=0;
    int start=ten(l);
    int end=ten(r);
    while(pow(2,end)>idx){
        tmp.push_back(tmp[idx]*10);
        tmp.push_back(tmp[idx]*10+5);
        idx++;
    }
    vector<int> answer;
    for (int i=pow(2,start)-1; i<pow(2,end+1); i++){
        if (tmp[i]>=l&&tmp[i]<=r) answer.push_back(tmp[i]);
    }
    if (answer.empty()) answer.push_back(-1);
    return answer;
}
