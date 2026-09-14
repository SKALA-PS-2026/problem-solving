# 문제: 배열 만들기 2
# 접근 방식: l부터 r까지 모든 수를 문자열로 바꾼 각 자릿수가 0 또는 5인지 확인한다.
# 시간복잡도: O((r - l + 1) log r) (각 수의 자릿수까지 검사)

def solution(l, r):
    answer = []

    for i in range(l, r + 1):
        valid = True

        for c in str(i):
            if c != '0' and c != '5':
                valid = False
                break

        if valid:
            answer.append(i)

    if not answer:
        return [-1]

    return answer
