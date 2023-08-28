package LeetCode;

public class BestTimeToBuyAndSellStock2_122 {
    public int maxProfit(int[] prices) {
        int ret = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i-1] < prices[i]) {
                ret += prices[i] - prices[i - 1];
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        BestTimeToBuyAndSellStock2_122 b = new BestTimeToBuyAndSellStock2_122();
        System.out.println(b.maxProfit(new int[]{7,1,5,3,6,4}));
        System.out.println(b.maxProfit(new int[]{7,6,4,3,1}));
    }
}
