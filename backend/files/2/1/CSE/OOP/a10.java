/*Use a HashMap to access student names using roll number. Perform insert, delete and updateoperations using rollno.*/
import java.util.HashMap;

public class a10 {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();
        // Adding elements to the Map
        // using standard put() method
        map.put(101, "vishal");
        map.put(301, "sachin");
        map.put(201, "vaibhav");
        // Print size and content of the Map
        System.out.println("Size of map is " + map.size());
        // Printing elements in object of Map
        System.out.println(map);
        if (map.containsKey(301)) {
            // Mapping
            String name = map.get(301);
            // Printing value for the corresponding key
            System.out.println("value for key is " + name);
            map.remove(301);
            System.out.println(map);
        }
    }
}