package com.gradescope.garden;

import java.util.Arrays;
import java.util.List;

public enum PlotType {
    FLOWER(
            "flower",
            "PICK",
            Arrays.asList("iris", "lily", "rose", "daisy", "tulip", "sunflower")
    ),
    VEGETABLE(
            "vegetable",
            "HARVEST",
            Arrays.asList("garlic", "zucchini", "tomato", "yam", "lettuce")
    ),
    TREE(
            "tree",
            "CUT",
            Arrays.asList("oak", "willow", "banana", "coconut", "pine")
    );

    private final String name;
    private final String pickCommand;
    private final List<String> plantNames;

    PlotType(String name, String pickCommand, List<String> plantNames) {
        this.name = name;
        this.pickCommand = pickCommand;
        this.plantNames = plantNames;
    }

    public static PlotType fromName(String name) {
        for (PlotType type : values()) {
            if (type.name.equalsIgnoreCase(name)) return type;
        }
        return null;
    }

    public static PlotType fromCommand(String command) {
        for (PlotType type : values()) {
            if (type.pickCommand.equalsIgnoreCase(command)) return type;
        }
        return null;
    }

    public static PlotType fromPlantName(String name) {
        for (PlotType type : values()) {
            if (type.plantNames.contains(name)) return type;
        }
        return null;
    }
}