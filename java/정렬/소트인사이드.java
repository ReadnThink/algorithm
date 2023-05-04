package 정렬;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class 점수집계 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] arr = new int[5];

        while(T-- > 0){
            for(int i = 0; i < 5; i++){
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);

            arr[0] = 0;
            arr[4] = 0;
//            System.out.printf(Arrays.toString(arr));

            int sum = 0;
            int mx = -1;
            int min = 11;
            for(int i = 1; i <= 3; i++){
                sum += arr[i];
                mx = Math.max(mx, arr[i]);
                min = Math.min(min, arr[i]);
            }

            if(Math.abs(mx - min) >= 4){
                System.out.println("KIN");
            }else{
                System.out.println(sum);
            }
        }
    }
}
