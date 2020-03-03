import java.util.*;

public class Main{
	public static void main(String[]args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] ppl = new int[N];
	int sum = 0;
	for (int i =0;i<N;i++) {
		ppl[i] = sc.nextInt();
		sum+= ppl[i];
	}
	int div = sum/N;
	int count = 0;
	for (int i =0;i<N;i++) {
		if (ppl[i]!=div) {
			count++;
		}
	}
	System.out.println(count);
	}
}