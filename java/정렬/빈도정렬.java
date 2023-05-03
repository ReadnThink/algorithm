package 정렬;

import java.util.*;

public class 빈도정렬 {
    static int N, C;
    static int[] arr;

    static void solution(){
        HashMap<Integer, Integer> list = new HashMap<>();

        for(int i = 0; i < N; i++){
            if(list.containsKey(arr[i])){
                list.put(arr[i], list.getOrDefault(arr[i], 0) + 1);
            }else{
                list.put(arr[i], 1);
            }
        }

        ArrayList<Integer> v = new ArrayList<>(list.keySet());

        Collections.sort(v, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        //Iterator를 통해서 출력한다.
        Iterator<Integer> it = v.iterator();
        while (it.hasNext()) {
            Integer element = it.next();
            for(int i=0; i<list.get(element); i++){
                System.out.print(element+" ");
            }

        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        C = sc.nextInt();
        arr = new int[N+1];

        for(int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println("N = " + N);
        System.out.println("C = " + C);
        for(int i = 0; i < N; i++){
            System.out.println("arr = " + arr[i]);
        }

        solution();
    }
}
