// https://school.programmers.co.kr/learn/courses/30/lessons/60058
// 문제 이름: 괄호 변환
// 아이디어: 재귀문제. 올바른 괄호 문자열인거는 카운트 변수를 하나 잡고 '('일때 +1, ')'일때 -1 하게해서 계산. -1이 되는 순간이 있으면 (이게 없는데 )얘가 나온거니까 올바르지않다는것임

#include <string>
#include <vector>

using namespace std;

string rec (string A) {
    if (A=="") return "";
    int cnt=0;
    bool flag=0;
    string u,v;
    for (int i=0; i<A.size(); i++){
        if (A[i]=='(') cnt++;
        else cnt--;
        if (cnt<0) flag=1;
        if (cnt==0) {
            u = A.substr(0,i+1);
            v = A.substr(i+1);
            break;
        }
    }
    string ret = "";
    if (flag) {
        ret += '('+rec(v)+')';
        for (int i=1; i<u.size()-1; i++){
            ret += u[i]=='('? ')':'(';
        }
    }
    else ret = u+rec(v);
    return ret;
}

string solution(string p) {
    string answer = rec(p);
  
    return answer;
}
