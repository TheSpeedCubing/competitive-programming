import java.io.*;
import java.util.Stack;

public class Main {
    static long max, min;

    public static void f(String s) {
        max = Integer.MIN_VALUE;
        min = Integer.MAX_VALUE;
        long multiply = 1;
        long add = 0;
        long n = 0;
        for (char c : (s + ",").toCharArray()) {
            if (c == ',' || c == '*' || c == '+') {
                add += n;
                n = 0;
            }
            if (c == ',' || c == '*') {
                multiply *= add;
                add = 0;
            }
            if (c == ',') {
                max = Math.max(multiply, max);
                min = Math.min(multiply, min);
                multiply = 1;
            }
            if ('0' <= c && c <= '9')
                n = n * 10 + c - 48;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String q;
        while ((q = reader.readLine()) != null) {
            Stack<String> stack = new Stack<>();
            StringBuilder s = new StringBuilder();
            for (char c : q.toCharArray()) {
                if (c == '(') {
                    stack.push(s.toString());
                    s = new StringBuilder();
                } else if (c == ')') {
                    f(s.toString());
                    s = new StringBuilder(stack.pop() + (max - min));
                } else if (c != 'f')
                    s.append(c);
            }
            f(s.toString());
            System.out.println(max);
        }
    }
}
