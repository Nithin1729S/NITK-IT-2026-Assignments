class Example {
    private int num;

    public Example(int num) {
        this.num = num; // 'this' refers to the current instance of the class
    }

    public void display() {
        System.out.println("Value of num: " + this.num);
    }
}

public class This {
    public static void main(String[] args) {
        Example obj = new Example(10);
        obj.display();
    }
}
