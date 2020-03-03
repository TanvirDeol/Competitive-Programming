import java.util.*;

public class Main{
	public static void main(String[]args) {
	Scanner sc = new Scanner(System.in);
	int []one = new int[5];
	int []two = new int[5];
	for (int i =0;i<5;i++) {
		one[i] = sc.nextInt();
	}
	for (int i =0;i<5;i++) {
		two[i] = sc.nextInt();
	}
	Arrays.sort(one);
	Arrays.sort(two);
	int sum1 = 0; int sum2=0;
	for (int i =1;i<5;i++) {
		sum1+= one[i];
	}
	for (int i =1;i<5;i++) {
		sum2+= two[i];
	}
	int max = Math.max(sum1, sum2);
	System.out.println(max);
	}
}