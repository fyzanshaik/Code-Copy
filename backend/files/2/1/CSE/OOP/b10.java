/*Use Arrays class to perform the manipulation on array.*/
import java.util.Arrays;
public class b10 
{
	public static void main(String[] args)
	{
		int intArr[] = { 10, 20, 15, 22, 35 };
		Arrays.sort(intArr);
		int key = 22;
		System.out.println(key + " found at index = " + Arrays.binarySearch(intArr, key));
	}
}