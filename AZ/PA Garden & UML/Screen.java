package com.gradescope.garden;

public class Screen {
    private final char[][] grid;
    private final int totalRows;
    private final int totalCols;
    private int offsetR;
    private int offsetC;

    public Screen(Garden garden) {
        this.totalRows = garden.getRows() * 5;
        this.totalCols = garden.getCols() * 5;
        grid = new char[totalRows][totalCols];
        for (int i = 0; i < garden.getRows(); i++) {
            for (int j = 0; j < garden.getCols(); j++) {
                this.offsetR = i;
                this.offsetC = j;
                drawPlot(garden.getPlot(i, j));
            }
        }
    }

    public void clear() {
        for (int r = 0; r < totalRows; r++) {
            for (int c = 0; c < totalCols; c++) {
                grid[r][c] = '.';
            }
        }
    }

    public void drawPlot(AbstractPlot plot) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                writeBuffer(i, j, '.');
            }
        }
        if (plot != null)
            plot.write(this);
    }

    public void writeBuffer(int r, int c, char ch) {
        grid[offsetR * 5 + r][offsetC * 5 + c] = ch;
    }

    public void display() {
        for (int r = 0; r < totalRows; r++) {
            for (int c = 0; c < totalCols; c++) {
                System.out.print(grid[r][c]);
            }
            System.out.println();
        }
    }
}
