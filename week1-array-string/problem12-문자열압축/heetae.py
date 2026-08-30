# 문제: 문자열 압축
# 접근 방식: 1부터 문자열 길이의 절반까지 압축 단위를 변경하며, 연속한 동일 문자열의 개수를 세어 가장 짧은 압축 길이를 구한다.
# 하지만 파이썬 문자 자르기가 익숙하지 않아 틀림,,,
# 시간복잡도: O(n^2) (n은 문자열의 길이)

def solution(s):
    answer = len(s)

    for size in range(1, len(s) // 2 + 1):

        compressed = ""
        prev = s[:size]
        count = 1

        for i in range(size, len(s), size):
            chunk = s[i:i+size]

            if prev == chunk:
                count += 1

            else:
                if count == 1:
                    compressed += prev
                else:
                    compressed += str(count) + prev

                prev = chunk
                count = 1

        # 마지막 덩어리 처리
        if count == 1:
            compressed += prev
        else:
            compressed += str(count) + prev

        # 최소 길이 갱신
        answer = min(answer, len(compressed))

    return answer
