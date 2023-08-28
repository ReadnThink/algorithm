package LeetCode.week1.sec;

public class ValidPalindrome_125 {
    public boolean isPalindrome(String s) {
        final String lowerS = s.toLowerCase();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < lowerS.length(); i++) {
            if (lowerS.charAt(i) >= 'A' && lowerS.charAt(i) <= 'Z' || lowerS.charAt(i) >= 'a' && lowerS.charAt(i) <= 'z') {
                sb.append(lowerS.charAt(i));
            }
            if (lowerS.charAt(i) >= '0' && lowerS.charAt(i) <= '9') {
                sb.append(lowerS.charAt(i));
            }
        }

        String result = sb.toString();
        String reverse = sb.reverse().toString();
        return reverse.equals(result);
    }

    public static void main(String[] args) {
        ValidPalindrome_125 v = new ValidPalindrome_125();
        System.out.println(v.isPalindrome("A man, a plan, a canal: Panama"));
        System.out.println(v.isPalindrome("race a car"));
        System.out.println(v.isPalindrome("0P"));

    }
}
