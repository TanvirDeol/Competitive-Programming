import java.util.*;

public class Main{
	public static void main(String[]args) {
	Scanner sc = new Scanner(System.in);
	int W = sc.nextInt();
	int[] waves = new int[W];
	int[] org = new int[W];
	for (int i =0;i<W;i++) {
		waves[i] = sc.nextInt();
	}
	Arrays.sort(waves);
	if (W%2==0) {
		int count =0;
		for (int i = (waves.length/2)-1;i>=0;i--) {
			org[count]= waves[i];
			count+=2;
		}
		count = 1;
		for (int i = waves.length/2;i<waves.length;i++) {
			org[count] = waves[i];
			count+=2;
		}
	}
	else {
		int count =0;
		for (int i = (waves.length/2);i>=0;i--) {
			org[count]= waves[i];
			count+=2;
		}
		count = 1;
		for (int i = (waves.length/2)+1;i<waves.length;i++) {
			org[count] = waves[i];
			count+=2;
		}
	}
	
	for(int i =0;i<org.length;i++) {
		System.out.print(org[i]+" ");
	}
	
	}
}