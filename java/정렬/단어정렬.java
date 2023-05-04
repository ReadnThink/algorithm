package 정렬;

import java.util.*;

public class 단어정렬 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] arr = new String[n];

        for(int i = 0; i < n; i++){
            arr[i] = sc.nextLine();
        }

        Arrays.sort(arr, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                if(o1.length() == o2.length()){
                    return o2.compareTo(o1);
                }else{
                    return o2.length() - o1.length();
                }
            }
        });

        System.out.println(arr[0]);
        for(int i = 1; i < n; i++){
            if(!arr[i].equals(arr[i-1])){
                System.out.println(arr[i]);
            }
        }
    }
}
