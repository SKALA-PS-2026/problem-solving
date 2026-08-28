// 문제: 팩토리얼
// 접근 방식: 제약조건상 재귀로만 해도 되긴하는데 메모리제이션도 넣었음
// 시간복잡도: O(1)

#include <string>
#include <vector>

using namespace std;

vector<int> fac(11);

int factorial(int a){
    if (fac[a]) return fac[a];
    fac[a] = a*factorial(a-1);
    return fac[a];
}

int solution(int n) {
    int answer = 0;
    fac[1]=1;
    answer = factorial(10);
    for (int i=10; i>=1; i--){
        if (fac[i]<=n) return i;
    }
}
