import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (true) {
            int a = s.nextInt();
            int b = s.nextInt();
            if (a == 0 && b == 0) {
                return;
            }
            int[] c = new int[15];
            int[] d = new int[15];

            int i = 0;
            while (a > 0) {
                c[i++] = a % 10;
                a /= 10;
            }
            i = 0;
            while (b > 0) {
                d[i++] = b % 10;
                b /= 10;
            }

            int cnt = 0;
            for (i = 0; i < 15; i++) {
                if (c[i] + d[i] > 9) {
                    c[i + 1]++;
                    cnt++;
                }
            }

            if (cnt == 0) {
                System.out.println("No carry operation.");
            } else
                System.out.println(cnt + " carry operation" + (cnt == 1 ? "." : "s."));
        }
    }
}
