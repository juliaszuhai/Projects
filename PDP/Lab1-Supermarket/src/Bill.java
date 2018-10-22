import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Bill {
    private List<Transaction> transactions;
    private Integer totalPrice;

    public Bill() {
        this.transactions=new ArrayList<>();
        this.totalPrice = 0;

    }

    public Bill(List<Transaction> transactions) {
        this.transactions = transactions;
        this.totalPrice=0;
        for(Transaction t:transactions)
        {
           this.totalPrice+=t.getProduct().getPrice()*t.getQuantity();
        }
    }

    public void addProduct(Transaction t, Integer q)
    {
        this.transactions.add(t);
        this.totalPrice=+t.getProduct().getPrice()*q;

    }

    public List<Transaction> getTransactions() {
        return transactions;
    }

    public Integer getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(Integer totalPrice) {
        this.totalPrice = totalPrice;
    }

    @Override
    public String toString() {
        String str = "new bill:";
        for(int i = 0; i < transactions.size(); i++)
        {
            str += "\t" + transactions.get(i).toString();
        }
        return str;
    }
}

