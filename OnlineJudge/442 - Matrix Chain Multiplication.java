import java.io.*;
import java.util.*;

class Main {

    static List<Matrix> m = new ArrayList<>();

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(reader.readLine());
            for (int i = 0; i < n; i++) {
                String[] s = reader.readLine().split(" ");
                m.add(new Matrix(Integer.parseInt(s[1]), Integer.parseInt(s[2]), -1));
            }
            String s;
            c:
            while ((s = reader.readLine()) != null) {
                List<Matrix> to = new ArrayList<>();
                long result = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (Character.isUpperCase(s.charAt(i)))
                        to.add(m.get(s.charAt(i) - 'A'));
                    else if (s.charAt(i) == ')') {
                        Matrix m1 = to.get(to.size() - 2);
                        Matrix m2 = to.get(to.size() - 1);
                        to.remove(m1);
                        to.remove(m2);
                        if (m1.y != m2.x) {
                            System.out.println("error");
                            continue c;
                        } else {
                            int actualSize = m2.x * m2.y * m1.x;
                            Matrix newMatrix = new Matrix(m1.x, m2.y, actualSize);
                            to.add(newMatrix);
                            result += actualSize;
                        }
                    }
                }
                System.out.println(result);
            }
        } catch (Exception e) {

        }
    }

    static class Matrix {
        int x;
        int y;
        int size;

        public Matrix(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
        }
    }
}
