public class GenericSwap {

    public static <T> void swap(T[] arr) {
        T temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }

    public static void swap(Player a, Player b) {
        Player temp = new Player(a.name, a.hP);
        a.name = b.name;
        a.hP = b.hP;
        b.name = temp.name;
        b.hP = temp.hP;
    }

    static class Player {
        String name;
        Integer hP;

        public Player(String name, int hp) {
            this.name = name;
            this.hP = hp;
        }
    }

    public static void main(String[] args) {
        // Integer
        Integer intA = 2;
        Integer intB = 6;

        // Double
        Double doubleA = 3.14;
        Double doubleB = 9.86;

        // String
        String stringA = "Johann";
        String stringB = "Tenma";

        // User Defined Types
        Player playerA = new Player("Johann", 98);
        Player playerB = new Player("Tenma", 34);

        Integer[] arr = {intA, intB};
        Double[] arr1 = {doubleA, doubleB};
        String[] arr2 = {stringA, stringB};

        System.out.println("Before swap intA = " + arr[0] + " and intB = " + arr[1]);
        swap(arr);
        System.out.println("After swap intA = " + arr[0] + " and intB = " + arr[1]);

        System.out.println("Before swap doubleA = " + arr1[0] + " and doubleB = " + arr1[1]);
        swap(arr1);
        System.out.println("After swap doubleA = " + arr1[0] + " and doubleB = " + arr1[1]);

        System.out.println("Before swap stringA = " + arr2[0] + " and stringB = " + arr2[1]);
        swap(arr2);
        System.out.println("After swap stringA = " + arr2[0] + " and stringB = " + arr2[1]);

        System.out.println("Before swap playerA's name = " + playerA.name + " and hp = " + playerA.hP);
        System.out.println("Before swap playerB's name = " + playerB.name + " and hp = " + playerB.hP);
        swap(playerA, playerB);
        System.out.println("After swap playerA's name = " + playerA.name + " and hp = " + playerA.hP);
        System.out.println("After swap playerB's name = " + playerB.name + " and hp = " + playerB.hP);
    }
}
