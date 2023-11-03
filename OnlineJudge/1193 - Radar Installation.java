import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String str;
            int c = 0;
            while ((str = reader.readLine()) != null) {
                String[] s = str.split(" ");
                int n = Integer.parseInt(s[0]);
                int d = Integer.parseInt(s[1]);
                if (d == 0 && n == 0) {
                    return;
                }

                c++;
                int cnt = 1;

                List<Double[]> l = new ArrayList<>();
                boolean success = true;
                for (int i = 0; i < n; i++) {
                    str = reader.readLine();
                    s = str.split(" ");
                    int x = Integer.parseInt(s[0]);
                    int y = Integer.parseInt(s[1]);
                    if (y > d)
                        success = false;

                    double h = Math.sqrt(d * d - y * y);
                    l.add(new Double[]{x - h, x + h});
                }

                if (success) {
                    l.sort((a, b) -> {
                        if (a[0].doubleValue() != b[0].doubleValue()) {
                            return Double.compare(b[0], a[0]);
                        }
                        return Double.compare(a[1], b[1]);
                    });

                    double currentMax = l.get(0)[0];
                    for (int i = 1; i < n; i++) {
                        Double[] v = l.get(i);
                        if (currentMax <= v[1])
                            continue;
                        currentMax = v[0];
                        cnt++;
                    }
                } else
                    cnt = -1;
                System.out.println("Case " + c + ": " + cnt);
                reader.readLine();
            }
        } catch (
                Exception e) {
            e.printStackTrace();
        }
    }
}
