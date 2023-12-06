import java.util.Scanner;

class Nijika_or_Doritos {
    public static Tri a(String s) {
        String[] b = s.split(" ");
        int x1 = Integer.parseInt(b[0]);
        int y1 = Integer.parseInt(b[1]);
        int x2 = Integer.parseInt(b[2]);
        int y2 = Integer.parseInt(b[3]);
        int x3 = Integer.parseInt(b[4]);
        int y3 = Integer.parseInt(b[5]);
        int l1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int l2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        int l3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        return new Tri(l1, l2, l3);
    }

    public static boolean eq(int d1, int d2, int d3, int d4, int d5, int d6) {
        return d1 == d2 && d3 == d4 && d5 == d6;
    }

    static class Tri {
        int l1;
        int l2;
        int l3;

        public Tri(int l1, int l2, int l3) {
            this.l1 = l1;
            this.l2 = l2;
            this.l3 = l3;
        }

        public boolean e(Tri ano) {
            if (eq(ano.l1, l1, ano.l2, l2, ano.l3, l3))
                return true;
            if (eq(ano.l1, l1, ano.l2, l3, ano.l3, l2))
                return true;
            if (eq(ano.l1, l2, ano.l2, l3, ano.l3, l1))
                return true;
            if (eq(ano.l1, l2, ano.l2, l1, ano.l3, l3))
                return true;
            if (eq(ano.l1, l3, ano.l2, l1, ano.l3, l2))
                return true;
            if (eq(ano.l1, l3, ano.l2, l2, ano.l3, l1))
                return true;
            return false;
        }
    }

    public static void main(String[] a) {
        Scanner c = new Scanner(System.in);
        Tri tri1 = a(c.nextLine());
        Tri tri2 = a(c.nextLine());
        for (int i = 0; i < Integer.parseInt(c.nextLine()); i++) {
            Tri here = a(c.nextLine());
            if (here.e(tri1))
                System.out.println(here.e(tri1) ? "Nijika" : (here.e(tri2) ? "Doritos" : "None"));
        }
    }
}
