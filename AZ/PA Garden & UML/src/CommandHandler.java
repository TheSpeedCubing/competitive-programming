package com.gradescope.garden;

import java.util.function.Predicate;

public class CommandHandler {

    public void handle(String commandString) {
        if (commandString.isEmpty()) {
            return;
        }
        String[] s = commandString.split(" ");
        if (s.length == 0) {
            return;
        }
        String command = s[0].toUpperCase();
        outputCommand(command, commandString);
        switch (command) {
            case "PLANT":
                commandPlant(s);
                break;
            case "PICK":
            case "HARVEST":
            case "CUT":
                commandRemove(command, s);
                break;
            case "GROW":
                commandGrow(s);
                break;
            case "PRINT":
                commandPrint();
                break;
        }
    }

    private void outputCommand(String command, String commandString) {
        if (!command.equals("PLANT")) {
            // fix input problem
            String suffix = commandString.substring(command.length());
            if (suffix.endsWith(" ")) {
                suffix = suffix.substring(0, suffix.length() - 1);
            }
            System.out.println("> " + command + suffix);
            if (!command.equals("PRINT")) {
                System.out.println();
            }
        }
    }

    private void commandPlant(String[] s) {
        Point p = Point.fromString(s[1]);
        String name = s[2].toLowerCase();
        Garden.getInstance().handlePlant(p, name);
    }

    private void commandPrint() {
        Garden.getInstance().printGarden();
        System.out.println();
    }

    private void commandRemove(String command, String[] s) {
        PlotType type = PlotType.fromCommand(command);

        if (s.length == 1) { // REMOVE
            Garden.getInstance().pick(new Predicate<AbstractPlot>() {
                @Override
                public boolean test(AbstractPlot plot) {
                    return plot.getType() == type;
                }
            });
            return;
        }
        if (!Point.isCoordinateWeak(s[1])) { // REMOVE (row,col)

            String name = s[1].toLowerCase();
            Garden.getInstance().pick(new Predicate<AbstractPlot>() {
                @Override
                public boolean test(AbstractPlot plot) {
                    return plot.getName().equals(name);
                }
            });
            return;
        }

        // REMOVE [type]
        Point coord = Point.fromString(s[1]);
        Garden.getInstance().pick(coord, type, command);
    }

    private void commandGrow(String[] s) {
        int round = Integer.parseInt(s[1]);
        if (s.length == 2) { // GROW
            Garden.getInstance().grow(round, new Predicate<AbstractPlot>() {
                @Override
                public boolean test(AbstractPlot plot) {
                    return true;
                }
            });
            return;
        }
        String s2 = s[2].toLowerCase();

        if (Point.isCoordinateWeak(s2)) { // GROW [num] (row,col)
            Garden.getInstance().grow(round, Point.fromString(s2));
            return;
        }

        // GROW [num] [type] or GROW [num] [name]
        PlotType type = PlotType.fromName(s2);

        Garden.getInstance().grow(round, new Predicate<AbstractPlot>() {
            @Override
            public boolean test(AbstractPlot plot) {
                return type != null ? plot.getType() == type : plot.getName().equals(s2);
            }
        });
    }
}
