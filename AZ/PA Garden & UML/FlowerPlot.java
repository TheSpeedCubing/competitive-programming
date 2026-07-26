package com.gradescope.garden;

public class FlowerPlot extends AbstractPlot {
    public FlowerPlot(String name) {
        super(name);
    }

    @Override
    public void write(Screen screen) {
        int maxDist = age - 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int dist = Math.abs(i - 2) + Math.abs(j - 2);
                screen.writeBuffer(i, j, (age > 0 && dist <= maxDist) ? getFirstLetter() : '.');
            }
        }
    }

    @Override
    public PlotType getType() {
        return PlotType.FLOWER;
    }
}