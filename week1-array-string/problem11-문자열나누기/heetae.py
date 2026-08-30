# 문제: 문자열 나누기
# 접근 방식: 각 부분 문자열의 첫 문자와 같은 문자와 다른 문자의 개수를 세고, 두 개수가 같아질 때마다 분리한다.
# 시간복잡도: O(n) (n은 s의 길이)

def solution(s):
    answer = 0
    first = 0
    second = 0
    f_index = -1

    for i in range(0, len(s)):
        if f_index == -1:
            f_index = i
            first = 1
            continue
        else:
            if s[i] == s[f_index]:
                first += 1
            else:
                second += 1
        if first == second:
            answer += 1
            f_index = -1
            first = 0
            second = 0
    if f_index != -1:
        answer += 1
    return answer
