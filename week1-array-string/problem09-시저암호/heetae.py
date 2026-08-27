# 문제: 시저 암호
# 접근 방식: 공백은 그대로 두고, 각 영문의 코드에 n을 더한 후 대문자와 소문자 범위를 넘으면 알파벳 처음으로 돌린다.
# 시간복잡도: O(n) (n은 s의 길이)

def solution(s, n):
    answer = list(s)
    for i in range(0, len(answer)):
        if answer[i] == ' ':
            continue

        current = ord(answer[i]) + n

        if ord(answer[i]) >= 65 and ord(answer[i]) <= 90:
            if current > 90:
                current = current - 26
            answer[i] = chr(current)
        else:
            if current > 122:
                current = current - 26
            answer[i] = chr(current)

    return ''.join(answer)
