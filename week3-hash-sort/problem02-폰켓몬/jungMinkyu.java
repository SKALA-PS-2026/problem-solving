/*
Author: Jung Minkyu
Date: 10SEP2026
풀이 과정 => 주석에 서술 완료.
*/

// 1928 ~ 1936 (풀이 시간 8분)
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int solution(int[] arr) {
        // 이번에는 문제를 푸는 과정에서 주석을 적으며 풀어보겠습니다
        /*
        N마리 폰켓몬 중 N/2 마리 가져가도 좋다 -> ponketmon = N / 2;
        폰켓몬은 종류에 따라 번호를 붙인다.
        같은 포켓몬 == 같은 번호
        4마리 폰켓몬에 대해. 3, 1, 2, 3 이라면 3이 2마리 1이 1마리 2가 1마리..
        4마리 폰켓몬 중 2가지 고르는 방법은 6가지 -> 4C2
        
        목표: 최대한 많은 종류의 폰켓몬을 포함해서 N / 2 선택하는 것 (ponketmon 만큼)
        N마리 폰켓몬 종류 번호 배열이 주어진다...
        가장 많은 종류 폰켓몬 선택하는 방법과, 그때 종류 번호의 개수를 return하라
        
        접근: 위에서 정의한 ponketmon == N / 2.
        N == arr.length;
        그러면 Set에 넣고, Set의 Size를 출력하기!
        이때 Set의 Size는 폰켓몬 종류의 개수
        따라서 Set.size() == 최대 가질 수 있는 모든 폰켓몬
        따라서 만약 Set.size()가 ponketmon보다 크면 정답은 ponketmon. 그게 아니라면 set.size가 될 것이다
        왜? -> 중복을 포함한다고 했을 때, Set의 size가 폰켓몬 보다 더 크면 모두 다른 ponketmon을 집을 수 있다는 것.
        동일 case에 대해, Set의 size가 폰켓몬 보다 더 작으면 Set의 사이즈만큼 ponketmon을 가지고 나머지는 중복해서 집을 수 있다는 것을 의미하기 때문이다.
        */
        
        // 구현
        Set<Integer> set = new HashSet<>();
        int N = arr.length;
        int ponketmon = N / 2;
        for (int monster : arr) set.add(monster);
        
        return (set.size() > ponketmon) ? ponketmon : set.size();
            
    }
}
/*
완전 옛날에 풀었던게 밑에 있는 풀이들
*/

// import java.util.HashSet;

// class Solution {
//     public int solution(int[] arr) {
//         int limit = arr.length / 2;
//         HashSet<Integer> set = new HashSet<>();
        
//         for (int el : arr) {
//             if (set.add(el)) {
//                 if (set.size() >= limit) return limit;
//             }
//         }
//         return set.size();
        
//     }
// }
// // 과거 시도 흔적
// // import java.util.HashSet;

// // class Solution {
// //     public int solution(int[] nums) {
// //         HashSet<Integer> repo = new HashSet<>();
// //         for (int i : nums)
// //             repo.add(i);
// //         // size => n
// //         // nCn/2
// //         // n! / (n/2)!
// //         int answer = 1;
// //         int cal = repo.size();
// //         int limit = cal / 2;
// //         int tmp = limit;
// //         System.out.println(cal + "C" + (cal / 2) + "를 원함");
// //         for (int i = 0; i <= limit; i++) {
// //             answer *= cal--;
// //         }
// //         for (int i = 0; i <= tmp; i++) {
// //             answer /= limit++;
// //         }
// //         return answer;
// //     }
// // }