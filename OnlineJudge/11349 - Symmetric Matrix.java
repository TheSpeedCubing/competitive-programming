import java.io.*;

class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            int T = Integer.parseInt(reader.readLine());
            for (int t = 1; t <= T; t++) {
                int n = Integer.parseInt(reader.readLine().substring(4));
                long[] dt = new long[n * n];
                boolean flag = true;
                for (int i = 0; i < n; i++) {
                    String[] arr = reader.readLine().split(" ");
                    for (int j = 0; j < n; j++) {
                        long l = Long.parseLong(arr[j]);
                        if (l < 0) {
                            flag = false;
                            break;
                        }
                        dt[i * n + j] = l;
                    }
                }
                if (flag)
                    for (int i = 0; i < (n * n) / 2 + 1; i++) {
                        if (dt[i] != dt[n * n - 1 - i]) {
                            flag = false;
                            break;
                        }
                    }
                System.out.println("Test #" + t + ": " + (flag ? "Symmetric." : "Non-symmetric."));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
