package 정렬;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class 시리얼번호2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] arr = new String[N];

        for(int i = 0; i < N; i++){
            arr[i] = sc.next();
        }

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() < o2.length()) {
                    if(add(o1) == add(o2)){
                        return o1.compareTo(o2);
                    }else {
                        return Integer.compare(add(o1), add(o2));
                    }
                } else {
                    return 1;
                }
            }
        });

        for(String i : arr){
            System.out.println(i);
        }
    }
    static int add(String str){
        int sum = 0;
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if(ch >= '0' && ch <= '9'){
                sum += ch - '0';
            }
        }
        return sum;
    }

}
