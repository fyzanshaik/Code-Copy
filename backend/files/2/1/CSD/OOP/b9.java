import java.util.*;

public class b9 {
    public static void main(String args[]) {
        // Creating HashSet
        HashSet<String> set = new HashSet<String>();

        // Adding Elements to HashSet - ignores duplicates
        set.add("hyderabad");
        set.add("hyderabad");
        set.add("bangalore");
        set.add("chennai");
        set.add("kolkata");
        set.add("kolkata");
        set.add("pune");

        Iterator<String> i = set.iterator();
        while (i.hasNext()) {
            System.out.println(i.next());
        }

        // Removing specific element from HashSet
        set.remove("hyderabad");
        // Displaying set
        System.out.println("\n The list after remove ->" + set);

        // adding another set
        HashSet<String> set1 = new HashSet<String>();
        set1.add("Panjab");
        set1.add("Delhi");
        set.addAll(set1);
        System.out.println("\n Updated List is -> " + set);
        // removing new set from list
        set.removeAll(set1);
        System.out.println("\n Updated List is -> " + set);
        // Removing all the elements available in the set
        set.clear();
        System.out.println("\n After clear the set is -> " + set);

    }
}
