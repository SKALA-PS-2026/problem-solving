# 문제: 문자열 다루기 기본
# 접근 방식: 문자열의 길이가 4 또는 6인지 확인하고, 모든 문자가 숫자 범위인지 검사한다.
# 시간복잡도: O(n) (n은 s의 길이)

def solution(s):
    if len(s) not in (4, 6):
        return False
    else:
        for i in range(0, len(s)):
            if s[i] < '0' or s[i] > '9':
                return False
    return True
