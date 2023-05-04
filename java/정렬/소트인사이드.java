package 정렬;

import java.util.*;


public class 소트인사이드 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] counting = new int[10];

        while(n > 0){
            counting[n % 10]++;
            n /= 10;
        }

        for(int i = 9; i >= 0; i--){
            while(counting[i] > 0){
                System.out.print(i);
                counting[i]--;
            }
        }
    }
}
