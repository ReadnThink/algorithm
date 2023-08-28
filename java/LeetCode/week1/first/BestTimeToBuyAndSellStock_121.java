package LeetCode;

public class BestTimeToBuyAndSellStock_121 {
    public int maxProfit(int[] prices) {
        int ret = 0;
        int min = (int) 1e9;

        for (int i = 0; i < prices.length; i++) {
            min = Math.min(min, prices[i]);
            ret = Math.max(ret, prices[i] - min);
        }
        return ret;
    }
    public static void main(String[] args) {
        BestTimeToBuyAndSellStock_121 b = new BestTimeToBuyAndSellStock_121();
        System.out.println(b.maxProfit(new int[]{7,1,5,3,6,4}));
        System.out.println(b.maxProfit(new int[]{7,6,4,3,1}));
    }
}
