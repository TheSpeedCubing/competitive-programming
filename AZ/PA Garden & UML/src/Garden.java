package com.gradescope.garden;

import java.util.function.Predicate;

public class Garden {

    private static Garden garden;

    public static Garden getInstance() {
        return garden;
    }

    private final int rows;
    private final int cols;
    private final AbstractPlot[][] plots;

    public Garden(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.plots = new AbstractPlot[rows][cols];
        garden = this;
    }

    // PICK
    public void pick(Point p, PlotType type, String command) {
        if (!isValid(p)) { // out of garden
            System.out.println("Can't " + command.toLowerCase() + " there.\n");
            return;
        }
        if (getPlot(p) == null) { // empty
            System.out.println("Can't " + command.toLowerCase() + " there.\n");
            return;
        }
        if (getPlot(p).getType() != type) { // not c
            System.out.println("Can't " + command.toLowerCase() + " there.\n");
            return;
        }
        setPlot(p, null);
    }

    public void pick(Predicate<AbstractPlot> filter) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (plots[i][j] != null && filter.test(plots[i][j])) {
                    plots[i][j] = null;
                }
            }
        }
    }

    // GROW
    public void grow(int rounds, Point p) {
        if (!isValid(p)) {
            System.out.println("Can't grow there.\n");
            return;
        }
        if (getPlot(p) == null) {
            System.out.println("Can't grow there.\n");
            return;
        }
        while (rounds-- != 0) {
            getPlot(p).grow();
        }
    }

    public void grow(int rounds, Predicate<AbstractPlot> filter) {
        while (rounds-- > 0) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    AbstractPlot plot = getPlot(i, j);
                    if (plot != null && filter.test(plot)) {
                        plot.grow();
                    }
                }
            }
        }
    }

    // PLANT
    public void handlePlant(Point p, String name) {
        if (!isValid(p)) {
            return;
        }
        if (getPlot(p) != null) {
            return;
        }
        PlotType type = PlotType.fromPlantName(name);
        if (type == PlotType.FLOWER) {
            setPlot(p, new FlowerPlot(name));
        } else if (type == PlotType.TREE) {
            setPlot(p, new TreePlot(name));
        } else if (type == PlotType.VEGETABLE) {
            setPlot(p, new VegetablePlot(name));
        }
    }

    public boolean isValid(Point p) {
        return isValid(p.getX(), p.getY());
    }

    public boolean isValid(int x, int y) { // is it empty or is it out of range?
        return (x >= 0 && x < rows) && (y >= 0 && y < cols);
    }

    public AbstractPlot getPlot(Point p) {
        return getPlot(p.getX(), p.getY());
    }

    public AbstractPlot getPlot(int x, int y) {
        return plots[x][y];
    }

    public void setPlot(Point p, AbstractPlot plot) {
        setPlot(p.getX(), p.getY(), plot);
    }

    public void setPlot(int x, int y, AbstractPlot plot) {
        this.plots[x][y] = plot;
    }

    public void printGarden() {
        Screen screen = new Screen(this);
        screen.display();
    }

    public int getRows() {
        return rows;
    }

    public int getCols() {
        return cols;
    }
}
