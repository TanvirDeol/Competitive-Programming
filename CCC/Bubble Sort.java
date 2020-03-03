import java.util.Arrays;
import java.util.Scanner;

public class Main {
   
   
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	int[] arr = new int[N];
    	
    	for (int i =0;i<N;i++) {
    		arr[i] = sc.nextInt();
    	}
    	toString(arr);
    	for (int i =0;i<arr.length-1;i++) {
    		for (int j = 0;j<arr.length-i-1;j++) {
    		int holder = 0;
    		if (arr[j]>arr[j+1]) {
    			holder = arr[j];
    			arr[j] = arr[j+1];
    			arr[j+1] = holder;
    			toString(arr);
    			}
    		}
    	}
    	
    }
    public static void toString(int[] arr) {
    	for (int i = 0;i<arr.length;i++) {
    		System.out.print(arr[i]+ " ");
    	}
    	System.out.println();
    }
}