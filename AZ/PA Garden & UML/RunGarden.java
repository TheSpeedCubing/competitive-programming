package com.gradescope.garden;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class RunGarden {

    public static void main(String[] args) {
        InputHandler handler;
        try {
            handler = new InputHandler(new File(args[0]));
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
            return;
        }
        if(handler.readGarden() == null) {
            return;
        }
        handler.commandThread();
    }

    static class InputHandler {
        private final Scanner scanner;

        public InputHandler(File file) throws FileNotFoundException {
            this.scanner = new Scanner(file);
        }

        public Garden readGarden() {
            int r;
            int c;

            scanner.next();
            r = scanner.nextInt();
            scanner.next();
            c = scanner.nextInt();
            if (c * 5 > 80) {
                System.out.println("Too many plot columns.");
                return null;
            }
            scanner.nextLine();
            return new Garden(r, c);
        }

        public void commandThread() {
            CommandHandler handler = new CommandHandler();
            while (scanner.hasNextLine()) {
                String fullCommand = scanner.nextLine();
                handler.handle(fullCommand);
            }
        }
    }
}