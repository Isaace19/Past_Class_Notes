class Cell {
    private int r;
    private int c;
    private boolean isAMine;

    public Cell(int rowNum, int colNum) {
        r = rowNum;
        c = colNum;
    }

    public void printCoordinates() {
        System.out.println("R: " + r + " C: " + c);
    }

    public void printCoordinatesAndMine() {
        System.out.println("R: " + r + " C: " + c);
        if (isAMine)
            System.out.println(" is a MINE!!!!");
        else
            System.out.println("is not a mine");
    }

    public void setMineVal(boolean mineVal) {
        isAMine = mineVal;
    }

    public boolean getMineVal() {
        return isAMine;
    }
}