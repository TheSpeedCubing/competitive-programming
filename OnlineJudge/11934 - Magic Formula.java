import java.io.*;

class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String s;
            while ((s = reader.readLine()) != null) {
                String[] arr = s.split(" ");
                int a = Integer.parseInt(arr[0]);
                int b = Integer.parseInt(arr[1]);
                int c = Integer.parseInt(arr[2]);
                int d = Integer.parseInt(arr[3]);
                int L = Integer.parseInt(arr[4]);
                if (a != 0 || b != 0 || c != 0 || d != 0 || L != 0) {
                    int cnt = 0;
                    for (int i = 0; i <= L; i++) {
                        if (((a * i * i + b * i + c) %  d)  == 0) {
                            cnt++;
                        }
                    }
                    System.out.println(cnt);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
