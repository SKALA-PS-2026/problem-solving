# 문제: 이상한 문자 만들기
# 접근 방식: 문자열을 한 번 순회하며 각 단어의 인덱스가 짝수면 대문자, 홀수면 소문자로 변환한다.
# 시간복잡도: O(n) (n은 s의 길이)

def solution(s):
    index = 0
    chars = list(s)
    for i in range(0,len(s)) :
        if chars[i]==' ':
            index = 0
        elif index%2==0 :
            chars[i] = chars[i].upper()
            index+=1
        else :
            chars[i] = chars[i].lower()
            index+=1
    return ''.join(chars)
