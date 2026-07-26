package com.gradescope.garden;

public class Point {
    private final int x;
    private final int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public static Point fromString(String string) {
        String[] s = string.replace("(", "").replace(")", "").split(",");
        return new Point(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
    }

    public static boolean isCoordinateWeak(String string) {
        return string.startsWith("(");
    }
}
