public class Product {

    private Name name;
    private Integer price;

    public Product(Name name, Integer price) {
        this.name = name;
        this.price = price;
    }

    public Product(Integer price) {
        this.price = price;
    }

    public Integer getPrice() {
        return price;
    }

    public void setPrice(Integer price) {
        this.price = price;
    }

    public Name getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Product{" +
                "name=" + name +
                ", price=" + price +
                '}';
    }
}
