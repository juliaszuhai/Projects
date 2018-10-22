import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {
    public static Integer[][] matrix1;
    public static Integer[][] matrix2;
    public static int nr=10;
    private static int noThreads=1;
    public static int[][] matrixFinal=new int[nr][nr];

    public Main() {
        this.matrix1=new Integer[nr][nr];
        this.matrix2=new Integer[nr][nr];
        }

    public void initializeMatrices()
    {
        Random r=new Random();
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nr;j++)
            {
                this.matrix1[i][j]=r.nextInt(5);
                this.matrix2[i][j]=r.nextInt(5);
            } } }

    public Integer[][] getMatrix1() {
        return matrix1;
    }

    public Integer[][] getMatrix2() {
        return matrix2;
    }



    public static void main(String[] args)
    {

        Main m=new Main();
        m.initializeMatrices();
        List<MyThread> threads=new ArrayList<MyThread>();
        int nrRowsPerThread = nr/noThreads-1;
        long startTime = System.nanoTime();
        for(int i = 0 ; i < nr ; i+= 1 + nrRowsPerThread)
            {
                MyThread t = new MyThread(i,i+nrRowsPerThread);
                threads.add(t);
            }

        threads.forEach(Thread::start);
        for(int i = 0; i < threads.size(); i++) {
            try {
                threads.get(i).join();
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
        long endTime = System.nanoTime();

        long duration = (endTime - startTime);
        System.out.println(duration);
        System.out.println();
            for(int i=0;i<matrix1.length;i++)
            {
                for(int k=0;k<matrix1[i].length;k++)
                {
                    System.out.print(matrix1[i][k]+" ");
                }
                System.out.println();
            }

            System.out.println();
        for(int i=0;i<matrix2.length;i++)
        {
            for(int k=0;k<matrix2[i].length;k++)
            {
                System.out.print(matrix2[i][k]+" ");
            }
            System.out.println();
        }

        System.out.println();

        for(int i=0;i<matrixFinal.length;i++)
        {
            for(int k=0;k<matrixFinal[i].length;k++)
            {
                System.out.print(matrixFinal[i][k]+" ");
            }
            System.out.println();
        }

    }

}
