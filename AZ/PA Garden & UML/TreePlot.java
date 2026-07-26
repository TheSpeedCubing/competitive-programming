package com.gradescope.garden;

public class TreePlot extends AbstractPlot {
    public TreePlot(String name) {
        super(name);
    }

    @Override
    public void write(Screen screen) {
        for (int i = 0; i < Math.min(5, age); i++) {
            screen.writeBuffer(4 - i, 2, getFirstLetter());
        }
    }

    @Override
    public PlotType getType() {
        return PlotType.TREE;
    }
}