class Player {
    String name;
    Integer hP;

    public Player(String name, int hp) {
        this.name = name;
        this.hP = hp;
    }

    public String getName() {
        return name;
    }
}

public class GenericSearch {

    public static <T> int search(T[] arr, T key) {
        for (int i = 0; i < arr.length; i++) {
            if (key == null) {
                if (arr[i] == null || (arr[i] instanceof Player && ((Player) arr[i]).getName() == null)) {
                    return i;
                }
            } else if (key instanceof Player && arr[i] instanceof Player) {
                if (((Player) key).getName().equals(((Player) arr[i]).getName())) {
                    return i;
                }
            } else if (key.equals(arr[i])) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        // Integer Matrices
        Integer[] array = {1, 2, 3, 4, 5, 6, 7};
        Integer key = 5;

        // Double Matrices
        Double[] array1 = {1.1, 2.49, 3.0, 4.0, 5.8, 6.0, 7.0};
        Double key1 = 2.49;

        // String Matrices
        String[] array2 = {"Cow", "Man", "Bruh", "Kenma"};
        String key2 = "Johann";

        // User Defined Types
        Player[] array3 = new Player[5];
        array3[0] = new Player("Johann", 56);
        array3[1] = new Player("Tanji", 89);
        array3[2] = new Player("Mr.Bruh", 12);
        String key3 = "Johann";

        int index = search(array, key);
        if (index != -1)
            System.out.println("Key " + key + " is found at index " + index);
        else
            System.out.println("Key " + key + " is not found.");

        int index1 = search(array1, key1);
        if (index1 != -1)
            System.out.println("Key " + key1 + " is found at index " + index1);
        else
            System.out.println("Key " + key1 + " is not found.");

        int index2 = search(array2, key2);
        if (index2 != -1)
            System.out.println("Key " + key2 + " is found at index " + index2);
        else
            System.out.println("Key " + key2 + " is not found.");

        int index3 = search(array3, new Player(key3, 0));
        if (index3 != -1)
            System.out.println("Key " + key3 + " is found at index " + index3);
        else
            System.out.println("Key " + key3 + " is not found.");
    }
}
