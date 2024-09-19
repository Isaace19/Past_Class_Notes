import java.util.*;

class MineSweeperBoard {
    private static ArrayList<Cell> board = new ArrayList<Cell>();

    private static final int numOfMines = 3;
    private static final int totalRows = 4;
    private static final int totalCols = 6;

    public static int calculateTouches(int i) {
        return 0;
        int mineTouched = 0;
        int row = i / totalCols;
        int col = i % totalCols;
        int lastRow = totalRows - 1;
        int lastCol = totalCols - 1;

        Cell cellToCheckCell;

        if (row != 0) {
            cellToCheckCell = board.get(i = totalCols);
            if (cellToCheck.getMineVal())
                minesTouched++;
        }
    }
    // if (col != 1);
    // if (row != lastRow);
    // if (col != lastCol);

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        ArrayList<Cell> mines = new ArrayList<Cell>();

        final int totalCells = totalCols + totalRows;

        for (int i = 0; i < totalCells; i++) {
            int row = i / totalCols;
            int col = i % totalCols;
            board.add(new Cell(row, col));
        }

        /*
         * for (int i = 0; i < numOfMines; i++) {
         * System.out.println("What is the location of the mine?\n x:");
         * int xMine = s.nextInt();
         * System.out.println("y: ");
         * int yMine = s.nextInt();
         * }
         */

        for (int i = 0; i < board.size(); i++) {
            board.get(i).printCoordinates();
        }

        System.out.println("MAX row number is " + (totalRows - 1) + "& MAX col is " + (totalCols) + ".");
        for (int i = 0; i < numOfMines; i++) {
            System.out.print("What is the location of the mine?\nr: ");
            int rMine = s.nextInt();
            System.out.print("C: ");
            int cMine = s.nextInt();

            int cellNumber = totalCols * rMine + cMine;
            Cell currentCell = board.get(cellNumber);
            currentCell.setMineVal(true);
            mines.add(currentCell);
        }

        for (int i = 0; i < board.size(); i++) {
            Cell currentCell = board.get(i);
            if (currentCell.getMineVal()) {
                System.out.print(" * ");
            } else {
                System.out.print(" - ");
            }
            if ((i + 1) % totalCols == 0) {
                System.out.println();
            }

        }
    }
}