// 문제: 괄호 회전하기
// 접근 방식: 
// 시간복잡도: O(N)

// Date: 29SEP2026
// Author: Jung Minkyu

import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] solution(int[] prices) {
        List<Stock> list = new ArrayList<>();
        list.add(new Stock(prices[0], 0));

        for (int i = 1; i < prices.length; i++) {
            int price = prices[i];

            for (Stock stock : list) {
                if (stock.isActive()) {
                    stock.addSecond();

                    if (price < stock.getPrice()) {
                        stock.setActive(false);
                    }
                }
            }

            list.add(new Stock(price, 0));
        }

        int[] answer = new int[list.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = list.get(i).getSecond();
        }

        return answer;
    }
}

class Stock {
    private int price;
    private int second;
    private boolean active;

    public Stock(int pr, int se) {
        this.price = pr;
        this.second = se;
        this.active = true;
    }

    public int getPrice() {
        return this.price;
    }

    public int getSecond() {
        return this.second;
    }

    public boolean isActive() {
        return this.active;
    }

    public void setActive(boolean act) {
        this.active = act;
    }

    public void addSecond() {
        ++this.second;
    }
}
