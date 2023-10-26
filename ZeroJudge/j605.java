import java.io.*;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
            int k = Integer.parseInt(r.readLine());
            int maxScore = -2;
            int maxTime = 0;
            int wrongCnt = 0;
            for (int i = 0; i < k; i++) {
                String[] a = r.readLine().split(" ");
                int t = Integer.parseInt(a[0]);
                int s = Integer.parseInt(a[1]);
                if (s > maxScore) {
                    maxScore = s;
                    maxTime = t;
                }
                if (s == -1)
                    wrongCnt++;
            }
            System.out.println(Math.max(maxScore - k - wrongCnt * 2, 0) + " " + maxTime);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
