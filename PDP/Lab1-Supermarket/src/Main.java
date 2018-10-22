import com.sun.javafx.scene.control.skin.IntegerFieldSkin;

import java.util.*;
import java.util.concurrent.Semaphore;

class MyThread extends Thread {
    //private Thread t;
    private String threadName;
    private List<Bill> bills;
    private Map<Product, Integer> listProducts;


    public MyThread(String nameThread, Map<Product, Integer> listProducts, List<Bill> bills) {
        this.threadName = nameThread;
        this.bills = bills;
        this.listProducts = listProducts;

    }

    public List<Bill> getBills() {
        return bills;
    }

    public void run() {
        Random r = new Random();
        //Integer noT = r.nextInt(20);
        for (int j = 0; j < 4; j++) {
            List<Transaction> transaction = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                Name name = Name.getRandomName();
                Product p=null;
                for(Map.Entry<Product,Integer> entry:this.listProducts.entrySet())
                {
                    if(entry.getKey().getName().equals(name))
                    {
                        p=new Product(name,entry.getKey().getPrice());
                    }
                }
                if (p != null) {
                    Transaction t = new Transaction(listProducts, p, r.nextInt(20));
                    boolean added = t.sale();
                    if (added) {
                        transaction.add(t);
                    }

                }
                Bill newBill = new Bill(transaction);
                synchronized (Shop.income) {
                    Shop.income += newBill.getTotalPrice();
                }
                System.out.println("thread " + threadName + " done:");
                System.out.println(newBill);
                bills.add(newBill);
                }

        }
    }
}
public class Main {
    public static void main(String args[]) {
        /*int nrThreads = 3;

        Shop shop = new Shop();
        shop.generateStock();
        List<MyThread> threads = new ArrayList<>();
        for(int i = 0; i < nrThreads; i++)
        {
            MyThread t = new MyThread(String.valueOf(i), shop.getListProducts(), shop.getBills(), shop.getIncome());
            threads.add(t);
        }
        threads.forEach(Thread::start);
        //System.out.println(stock);
        for(int i = 1; i < threads.size(); i++)
        {
            try {
            threads.get(i).join();
        } catch (InterruptedException e) {
            System.out.println("Interrupted");
        }}*/


        long startTime = System.nanoTime();

        Shop shop= new Shop();
        Map<Product,Integer> stock=new HashMap<Product,Integer>();
        stock.put(new Product( Name.BREAD,3),15);
        stock.put(new Product( Name.CHOCOLATE,4),20);
        stock.put(new Product( Name.MILK,5),20);
        stock.put(new Product( Name.BUTTER,5),20);
        stock.put(new Product( Name.CHEESE,5),20);
        stock.put(new Product( Name.MANGO,5),20);
        stock.put(new Product( Name.PUMPKIN,5),20);
        stock.put(new Product( Name.TOMATO,5),20);
        shop.setListProducts(stock);
        int nrThreads = 8;
        List<MyThread> threads = new ArrayList<>();
        for(int i = 0; i < nrThreads; i++)
        {
            MyThread t = new MyThread(String.valueOf(i), stock, shop.getBills());
            threads.add(t);
        }
        threads.forEach(Thread::start);
        //System.out.println(stock);
        for(int i = 1; i < threads.size(); i++)
        {
            try {
                threads.get(i).join();
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }}

        long endTime = System.nanoTime();

        long duration = (endTime - startTime);
        System.out.println(duration);
        try {
            Thread.sleep(7000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        shop.checkBills(threads.get(0).getBills(),Shop.income);


    }
}

