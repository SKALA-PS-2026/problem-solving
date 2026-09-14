// 문제: k진수에서 소수 개수 구하기
// 접근 방식: n을 k진수로 변환하고 0을 기준으로 분리한 각 수가 소수인지 판별한다.
// 시간복잡도: O(log_k(n) * sqrt(n))
#include <string>
using namespace std;

string change(int n, int k) {
    string ret = "";

    while (n > 0) {
        ret = to_string(n % k) + ret;
        n /= k;
    }

    return ret;
}

bool is_prime(long long n) {
    if (n <= 1) return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string s = change(n, k);
    string num = "";

    for (char c : s) {
        if (c == '0') {
            if (!num.empty()) {
                if (is_prime(stoll(num)))
                    answer++;

                num = "";
            }
        } 
        
        else num += c;
    }

    if (!num.empty() && is_prime(stoll(num)))
        answer++;

    return answer;
}