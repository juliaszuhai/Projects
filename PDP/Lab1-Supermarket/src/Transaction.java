import java.util.List;
import java.util.Map;
import java.util.concurrent.Semaphore;

public class Transaction {
    private Map<Product, Integer>  listProducts;
    private Bill bill;
    private Product product;
    private Integer quantity;
    private Integer totalMoney;

    @Override
    public String toString() {
        return "Transaction of product: " + this.product.getName().toString() + " with quantity: " + this.quantity + " was succesfull\n";

    }

    public Transaction(Map<Product,Integer>listProducts, Product product, Integer quantity) {
        this.listProducts=listProducts;
        this.product = product;
        this.quantity = quantity;
        this.totalMoney=0;
        }

    public boolean sale()  {
        for (Map.Entry<Product,Integer> entry:listProducts.entrySet())
        {
            synchronized (entry) {
                if (entry.getKey().getName().equals(this.product.getName())) {
                    if (entry.getValue() - this.quantity > 0) {

                        entry.setValue(entry.getValue() - this.quantity);
                        this.totalMoney = this.quantity * this.product.getPrice();
                        //System.out.println("Remaining stock of " + this.product.getName().toString() + " is: " + entry.getValue());
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public Product getProduct() {
        return product;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setListProducts(Map<Product, Integer> listProducts) {
        this.listProducts = listProducts;
    }
}
