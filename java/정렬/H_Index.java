package 정렬;

import java.util.Arrays;

public class H_Index {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        System.out.println(Arrays.toString(citations));
        int cnt = 0;
        int n = citations.length;
        for(int i = 0; i < n; i++){
            System.out.println("i = " + i + " cnt = " + cnt);
            while(true){
                if(cnt >= n - i){
                    return cnt;
                }
                if(cnt == citations[i]) break;

                cnt++;
            }
        }
        return answer;
    }
}
