package com.gradescope.garden;

public abstract class AbstractPlot {
    protected final String name;
    protected int age = 1;
    private final char firstLetter;

    public AbstractPlot(String name) {
        this.name = name;
        this.firstLetter = Character.toLowerCase(name.charAt(0));
    }

    public void grow() {
        age++;
    }

    public String getName() {
        return name;
    }

    public char getFirstLetter() {
        return firstLetter;
    }


    public abstract void write(Screen screen);

    public abstract PlotType getType();
}
