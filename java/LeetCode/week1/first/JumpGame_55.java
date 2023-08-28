package LeetCode.week1.first;

public class JumpGame_55 {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int pos = n - 1;
        for (int i = n-2; i >= 0; i--){
            if (pos <= i + nums[i]){
                pos = i;
            }
        }
        return pos == 0;
    }

    public static void main(String[] args) {
        JumpGame_55 j = new JumpGame_55();
        System.out.println(j.canJump(new int[]{2,3,1,1,4}) == true);
        System.out.println(j.canJump(new int[]{3,2,1,0,4}) == false);
    }
}
