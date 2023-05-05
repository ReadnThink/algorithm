package 정렬;

import java.util.Arrays;
import java.util.Scanner;

public class 나이순정렬 {
    static class User{
        Integer age;
        String name;
        Integer order;

        User(Integer age, String name, Integer order) {
            this.age = age;
            this.name = name;
            this.order = order;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        User[] users = new User[n];
        for(int i = 0; i < n; i++){
            int a = sc.nextInt();
            String name = sc.nextLine();
            users[i] = new User(a, name, i);
        }

        Arrays.sort(users, (o1, o2) -> {
            if (o1.age == o2.age) {
                return o1.order - o2.order;
            } else {
                return o1.age - o2.age;
            }
        });

        for(int i = 0; i < n; i++){
            System.out.println(users[i].age + users[i].name);
        }
    }
}
