package 정렬;

import java.util.*;

public class 단어정렬 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];

        sc.nextLine();
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextLine();
        }

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                if(s1.length() == s2.length()){
                    return s1.compareTo(s2);
                }else{
                    return s1.length() - s2.length();
                }
            }
        });

        String temp = "";
        for(String s : arr){
            if(!temp.equals(s)) System.out.println(s);
            temp = s;
        }
    }
}
