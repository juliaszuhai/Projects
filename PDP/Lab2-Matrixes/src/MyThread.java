public class MyThread extends Thread {


    private int start;
    private int end;

    public MyThread( int start, int end) {
        this.start = start;
        this.end = end;
    }

    public void run() {
        for (int i = start; i <= end; i++)
            for (int j = 0; j < Main.nr; j++)
                for(int k=0 ; k < Main.nr; k++)
                Main.matrixFinal[i][j] += Main.matrix1[i][k] * Main.matrix2[k][j];
    }

    /*public void run() {
        for (int i = start; i <= end; i++)
            for (int j = 0; j < Main.nr; j++)
                Main.matrixFinal[i][j] = Main.matrix1[i][j] + Main.matrix2[i][j];
    }*/


}
