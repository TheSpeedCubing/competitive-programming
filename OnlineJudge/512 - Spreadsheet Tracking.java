import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int ss = 1;
        boolean flag = true;

        while (true) {
            if (s.nextInt() == 0)
                return;
            if (s.nextInt() == 0)
                return;

            if (!flag)
                System.out.println();
            flag = false;

            List<String> cmdtype = new ArrayList<>();
            List<Integer[]> cmddata = new ArrayList<>();

            System.out.println("Spreadsheet #" + ss);
            ss++;

            int T = s.nextInt(), TN = T;
            while (T-- > 0) {
                String md = s.next();
                cmdtype.add(md);
                int T2;
                if (md.equals("EX")) {
                    T2 = 4;
                } else {
                    T2 = s.nextInt();
                }
                Integer[] i = new Integer[T2];
                for (int j = 0; j < T2; j++)
                    i[j] = s.nextInt();
                cmddata.add(i);
            }
            T = s.nextInt();
            while (T-- > 0) {
                int x = s.nextInt(), nx = x;
                int y = s.nextInt(), ny = y;
                boolean deleted = false;
                f:
                for (int j = 0; j < TN; j++) {
                    switch (cmdtype.get(j)) {
                        case "DC": {
                            int sub = 0;
                            for (int i : cmddata.get(j)) {
                                if (i < y) {
                                    sub++;
                                } else if (i == y) {
                                    deleted = true;
                                    break f;
                                }
                            }
                            y -= sub;
                        }
                        break;
                        case "DR": {
                            int sub = 0;
                            for (int i : cmddata.get(j)) {
                                if (i < x) {
                                    sub++;
                                } else if (i == x) {
                                    deleted = true;
                                    break f;
                                }
                            }
                            x -= sub;
                        }
                        break;
                        case "IC": {
                            int sub = 0;
                            for (int i : cmddata.get(j)) {
                                if (i <= y) {
                                    sub++;
                                }
                            }
                            y += sub;
                        }
                        break;
                        case "IR": {
                            int sub = 0;
                            for (int i : cmddata.get(j)) {
                                if (i <= x) {
                                    sub++;
                                }
                            }
                            x += sub;
                        }
                        break;
                        case "EX": {
                            Integer[] n = cmddata.get(j);
                            if (n[0] == x && n[1] == y) {
                                x = n[2];
                                y = n[3];
                            } else if (n[2] == x && n[3] == y) {
                                x = n[0];
                                y = n[1];
                            }
                        }
                        break;
                    }
                }
                if (deleted) {
                    System.out.println("Cell data in (" + nx + "," + ny + ") GONE");
                } else {
                    System.out.println("Cell data in (" + nx + "," + ny + ") moved to (" + x + "," + y + ")");
                }
            }
        }
    }
}
