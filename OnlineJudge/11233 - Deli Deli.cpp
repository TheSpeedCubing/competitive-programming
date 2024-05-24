import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        int N = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < L; i++) {
            String s1 = sc.next();
            String s2 = sc.next();
            map.put(s1, s2);
        }
        for (int i = 0; i < N; i++) {
            String s = sc.next();
            if (map.containsKey(s)) {
                System.out.println(map.get(s));
                continue;
            }
            if (s.endsWith("y")) {
                char last = s.charAt(s.length() - 2);
                if (last != 'a' && last != 'e' && last != 'i' && last != 'o' && last != 'u') {
                    System.out.println(s.substring(0, s.length() - 1) + "ies");
                    continue;
                }
            }

            if (s.endsWith("o") || s.endsWith("s") || s.endsWith("ch") || s.endsWith("sh") || s.endsWith("x")) {
                System.out.println(s + "es");
                continue;
            }

            System.out.println(s + "s");
        }
    }
}
