"""
Week3 문제 폴더 자동 생성 스크립트

사용법:
1. 레포를 로컬에 clone 받는다
   git clone https://github.com/본인계정/SKALA-PS-2026.git
2. clone 받은 폴더 안으로 이동
   cd SKALA-PS-2026
3. 이 스크립트를 그 폴더 안에 저장 (예: setup_week3.py)
4. 실행
   python setup_week3.py
5. 생성된 것 확인 후 push
   git add .
   git commit -m "Week3 문제 폴더 생성"
   git push
"""

import os

problems = [
    ("01", "완주하지못한선수", "완주하지 못한 선수", "Lv.1", "https://school.programmers.co.kr/learn/courses/30/lessons/42576"),
    ("02", "폰켓몬", "폰켓몬", "Lv.1", "https://school.programmers.co.kr/learn/courses/30/lessons/1845"),
    ("03", "신고결과받기", "신고 결과 받기", "Lv.1", "https://school.programmers.co.kr/learn/courses/30/lessons/92334"),
    ("04", "문자열내림차순으로배치하기", "문자열 내림차순으로 배치하기", "Lv.1", "https://school.programmers.co.kr/learn/courses/30/lessons/12917"),
    ("05", "문자열내마음대로정렬하기", "문자열 내 마음대로 정렬하기", "Lv.1", "https://school.programmers.co.kr/learn/courses/30/lessons/12915"),
    ("06", "실패율", "실패율", "Lv.1", "https://school.programmers.co.kr/learn/courses/30/lessons/42889"),
    ("07", "영어끝말잇기", "영어 끝말잇기", "Lv.2", "https://school.programmers.co.kr/learn/courses/30/lessons/12981"),
    ("08", "H-Index", "H-Index", "Lv.2", "https://school.programmers.co.kr/learn/courses/30/lessons/42747"),
    ("09", "가장큰수", "가장 큰 수", "Lv.2", "https://school.programmers.co.kr/learn/courses/30/lessons/42746"),
    ("10", "베스트앨범", "베스트앨범", "Lv.3", "https://school.programmers.co.kr/learn/courses/30/lessons/42579"),
]

base_dir = "week3-hash-sort"

for num, folder_name, title, level, url in problems:
    folder_path = os.path.join(base_dir, f"problem{num}-{folder_name}")
    os.makedirs(folder_path, exist_ok=True)

    readme_content = f"""# {title}

- 난이도: {level}
- 링크: {url}

## 풀이 올리는 방법
이 폴더 안에 본인 이름으로 파일을 올려주세요. (예: hong.py, kim.java, park.cpp)

코드 상단에 아래 형식으로 주석을 남겨주세요.

**Python**
```python
# 문제: {title}
# 접근 방식: 
# 시간복잡도: 
```

**Java / C++**
```
// 문제: {title}
// 접근 방식: 
// 시간복잡도: 
```
"""
    with open(os.path.join(folder_path, "README.md"), "w", encoding="utf-8") as f:
        f.write(readme_content)

    print(f"생성됨: {folder_path}")

print("\n완료! 이제 아래 명령어로 GitHub에 올리세요:")
print("  git add .")
print('  git commit -m "Week3 문제 폴더 생성"')
print("  git push")