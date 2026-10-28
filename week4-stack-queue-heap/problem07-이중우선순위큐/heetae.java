// 문제: 이중우선순위큐
/*
접근 방식: 우선순위 큐에 Node라는 객체를 만들어서 사용
  두개의 우선순위 큐를 만들되 Node에 삭제여부를 둬서 만약 삭제가 된 객체면 건너뛰도록 while문을 돌림
*/
// 시간복잡도: O(n log n)

import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        Queue<Node> min = new PriorityQueue<>((a,b)->Integer.compare(a.value, b.value));
        Queue<Node> max = new PriorityQueue<>((a,b)->Integer.compare(b.value, a.value));

        for(int i=0;i<operations.length;i++){
            String[] arr = operations[i].split(" ");

            if(arr[0].equals("I")){
                Node node = new Node(Integer.parseInt(arr[1]), false);
                min.offer(node);
                max.offer(node);
            }
            else{
                if(arr[1].equals("1")){
                    clean(max);
                    if(!max.isEmpty()){
                        Node node = max.poll();
                        node.isDelete = true;
                    }
                }
                else{
                    clean(min);
                    if(!min.isEmpty()){
                        Node node = min.poll();
                        node.isDelete = true;
                    }
                }
            }
        }

        clean(max);
        clean(min);

        if (min.isEmpty()) {
            return new int[]{0, 0};
        }
        return new int[]{max.peek().value,min.peek().value};
    }

    class Node{
        int value;
        boolean isDelete;

        public Node(int value,boolean isDelete){
            this.value = value;
            this.isDelete = isDelete;
        }
    }

    private void clean(Queue<Node> pq) {
        while (!pq.isEmpty() && pq.peek().isDelete) {
            pq.poll();
        }
    }

}
