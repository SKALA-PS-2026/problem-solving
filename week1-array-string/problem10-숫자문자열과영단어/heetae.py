# 문제: 숫자 문자열과 영단어
# 접근 방식: zero부터 nine까지의 영단어를 대응하는 숫자 문자로 차례대로 치환한 뒤 정수로 변환한다.
# 다른 풀이 방식엔 딕셔너리나 리스트에 저장해놓고 접근하는 방법도 있을듯
# 시간복잡도: O(n) (n은 s의 길이, 치환할 단어는 10개로 고정)

def solution(s):
    s = s.replace('zero','0')
    s = s.replace('one','1')
    s = s.replace('two','2')
    s = s.replace('three','3')
    s = s.replace('four','4')
    s = s.replace('five','5')
    s = s.replace('six','6')
    s = s.replace('seven','7')
    s = s.replace('eight','8')
    s = s.replace('nine','9')
    return int(s)
