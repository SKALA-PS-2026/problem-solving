// 문제: 문자열 압축
// 접근 방식: 1부터 길이/2까지 자를수있는 경우 다 시도해보기. 반복문에서 다음 인덱스 위치 지정하는것이 관건이었고, 앞에 붙는 숫자가 두자리 이상이 될수있다는걸 생각하지 못해서 틀렸었음...
// 시간복잡도: O(n³)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i=1; i<=s.size()/2; i++){
        int comp = s.size();
        for (int j=0; j<=s.size()-i*2; j+=i){
            string zip = s.substr(j,i);
            int cnt = 1, idx=j+i;
            while (idx+i<=s.size()){
                if (zip == s.substr(idx,i)){
                    cnt++; idx+=i;
                }
                else break;
            }
            if (cnt>1) {
                string cntstr = to_string(cnt);
                comp = comp - (cnt-1)*i + cntstr.size();
                j = idx-i;
            }
        }
        answer = min(answer,comp);
    }
    return answer;
}
