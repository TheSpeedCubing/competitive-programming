import java.io.*;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            String[] dt = bufferedReader.readLine().split(" ");
            int k = Integer.parseInt(dt[0]);
            int q = Integer.parseInt(dt[1]);
            int r = Integer.parseInt(dt[2]);
            byte[][] result = new byte[q][k];
            byte[] s = bufferedReader.readLine().getBytes();


            for (int i = 0; i < q; i++) {
                String[] arr = bufferedReader.readLine().split(" ");
                for (int j = 0; j < k; j++)
                    result[i][Integer.parseInt(arr[j]) - 1] = (i == 0 ? s : result[i - 1])[j];
            }
            for (int i = 0; i < r; i++)
                for (int j = 0; j < q; j++)
                    System.out.print((char) result[j][i]);
                System.out.println();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
