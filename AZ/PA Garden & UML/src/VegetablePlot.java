package com.gradescope.garden;

public class VegetablePlot extends AbstractPlot {
    public VegetablePlot(String name) {
        super(name);
    }

    @Override
    public void write(Screen screen) {
        for (int i = 0; i < Math.min(5, age); i++) {
            screen.writeBuffer(i, 2, getFirstLetter());
        }
    }

    @Override
    public PlotType getType() {
        return PlotType.VEGETABLE;
    }
}