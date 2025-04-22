class Mydetails {
    private int rollNo;
    private String name;
    private String department;

    public Mydetails(int rollNo, String name, String department) {
        this.rollNo = rollNo;
        this.name = name;
        this.department = department;
    }

    public void display() {
        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
    }
}

public class Main {
    public static void main(String[] args) {
        Mydetails m = new Mydetails(1010, "xxx", "xxdeptxx");
        m.display();
    }
}
