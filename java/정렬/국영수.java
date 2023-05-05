package 정렬;

import java.util.Arrays;
import java.util.Scanner;

public class 국영수 {
    static class User{
        String name;
        Integer ko;
        Integer en;
        Integer mt;

        public User(String name, Integer ko, Integer en, Integer mt){
            this.name = name;
            this.ko = ko;
            this.en = en;
            this.mt = mt;
        }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        User[] users = new User[n];
        for(int i = 0; i < n; i++){
            String name = sc.next();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            users[i] = new User(name, a,b,c);
        }

        Arrays.sort(users, (u1, u2) -> {
            if(u1.ko == u2.ko){
                if(u1.en == u2.en && u1.mt == u2.mt){
                    return u1.name.compareTo(u2.name);
                }else if (u1.en == u2.en){
                    return u2.mt - u1.mt;
                }else {
                    return u1.en - u2.en;
                }
            } else {
                return u2.ko - u1.ko;
            }
        });

        for(int i = 0; i < n; i++){
            System.out.println(users[i].name);
        }
    }
}
