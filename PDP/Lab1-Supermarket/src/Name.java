import java.util.Random;

public enum Name {
    MILK,
    BUTTER,
    TOMATO,
    CHOCOLATE,
    CHEESE,
    PUMPKIN,
    MANGO,
    BREAD;


    private static final Name[] VALUES = values();
    private static final int SIZE = VALUES.length;
    private static final Random RANDOM = new Random();

    public static Name getRandomName()  {
        return VALUES[RANDOM.nextInt(SIZE)];
    }
}
