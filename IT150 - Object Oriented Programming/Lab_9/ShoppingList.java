public class ShoppingList {
    public static void main(String[] args) {
        printShoppingListNewLine();
        System.out.println();
        printShoppingListCommaSeparated();
    }

    public static void printShoppingListNewLine() {
        System.out.println("Shopping List:");
        System.out.println("1. Milk");
        System.out.println("2. Bread");
        System.out.println("3. Eggs");
        System.out.println("4. Cheese");
        System.out.println("5. Apples");
    }

    public static void printShoppingListCommaSeparated() {
        System.out.println("Shopping List:");
        System.out.println("1. Milk, 2. Bread, 3. Eggs, 4. Cheese, 5. Apples");
    }
}
