import java.util.*;

public class Shop {
    private List<Bill> bills;
    private Map<Product,Integer> listProducts;
    public static Integer income=0;

    public Shop() {
        this.bills = new ArrayList<Bill>();
        this.listProducts = new HashMap<Product,Integer>();

    }

    public List<Bill> getBills() {
        return bills;
    }

    public Map<Product, Integer> getListProducts() {
        return listProducts;
    }

    public Integer getIncome() {
        return income;
    }

    public void setListProducts(Map<Product, Integer> listProducts) {
        this.listProducts = listProducts;
    }

    public void generateStock()
    {
        listProducts=new HashMap<>();
        Random r=new Random();
        for(int i=0;i<=100;i++)
        {
            int ok=0;
            Name name=Name.getRandomName();
            Product p=new Product(name,5);
            for(Map.Entry<Product,Integer> entry:listProducts.entrySet())
            {
                if(entry.getKey().getName().equals(p.getName()))
                {
                    entry.setValue(entry.getValue()+r.nextInt(20));
                    ok=1;
                    break;
                }
            }
            if(ok==0)
            {
                listProducts.put(p,r.nextInt(20));
            }
        }
    }




    public void checkBills(List<Bill> billuri, Integer income )
    {
        int billSum=0;
        for(Bill bill:billuri)
        {
            billSum+=bill.getTotalPrice();
        }
        System.out.println("Bill sum "+billSum);
        System.out.println("income: " + income);
        if(income==billSum)
        {
            System.out.println("Yaas");
        }
        else
        {
            System.out.println("It's a NO NO");
        }
    }
}
