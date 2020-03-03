import java.util.*;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int b = sc.nextInt();
		int[][] boxes = new int[b][3];
		for (int i =0;i<b;i++) {
		//	String s = sc.nextLine();
			
			for (int j =0;j<3;j++) {
				if (j==0) 
				boxes[i][j]= sc.nextInt();
				else if (j==1) {
					boxes[i][j]= sc.nextInt();
				}
				else if (j==2)
					boxes[i][j]= sc.nextInt();
			}
			
		}
		int it = sc.nextInt();
		int[][] items = new int[it][3];
		for (int i =0;i<it;i++) {
		//	String s = sc.nextLine();
			
			for (int j =0;j<3;j++) {
				if (j==0)
					items[i][j]= sc.nextInt();
					else if (j==1) {
						
						items[i][j]=sc.nextInt();
					}
					else if (j==2)
						items[i][j]= sc.nextInt();
			}
			
			Arrays.sort(items[i]);
		}
		for (int i =0;i<items.length;i++) {
			int vol = checkFit(items[i],boxes);
			if (vol == 0) {
				System.out.println("Item does not fit.");
			}else {
				System.out.println(vol);
			}
		}
		
	}
	public static int checkFit(int[] item, int[][]boxes) {
		int minVol = Integer.MAX_VALUE;
		int curVol =0;
		
		for (int i =0;i<boxes.length;i++) {
			Arrays.sort(boxes[i]);
			for (int j = 0;j<3;j++) {
				
				if (item[j]==boxes[i][j]||item[j]<boxes[i][j]) {
					if (j==2)
						curVol = boxes[i][0]*boxes[i][1]*boxes[i][2];
					continue;
				}else {
					curVol = Integer.MAX_VALUE;
					break;
				}
				
			}
			if (curVol <minVol) {
				minVol = curVol;
			}
			
		}
		
		if (minVol == Integer.MAX_VALUE) {
			minVol = 0;
		}
		return minVol;
	}
}