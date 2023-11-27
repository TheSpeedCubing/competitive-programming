import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(System.in);
            while (true) {
                long a = s.nextLong();
                long b = s.nextLong();
                System.out.print("[" + (a / b));
                boolean flag = true;
                while (true) {
                    long t = a % b;
                    a = b;
                    b = t;
                    if (t == 0)
                        break;
                    if (flag)
                        System.out.print(";" + a / b);
                    else
                        System.out.print("," + a / b);
                    flag = false;
                }
                System.out.println("]");
            }
        } catch (Exception e) {
        }
    }
}
