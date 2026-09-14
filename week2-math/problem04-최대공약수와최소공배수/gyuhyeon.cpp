// 문제: 최대공약수와 최소공배수
// 접근 방식: 최대공약수를 구하고 두 수의 곱을 최대공약수로 나눠 최소공배수를 구한다.
// 시간복잡도: O(log(min(n, m)))
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

vector<int> solution(int n, int m) {
    
    int a = max(n,m);
    int b = min(n,m);
    
    int k = gcd(a,b);
    
    vector<int> answer = {k, a*b/k};
    
    return answer;
}