import java.util.Scanner;

public class Main {
   
    public static int count =0;
    public static int[][] fr;
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	
    	int N = Integer.parseInt(sc.nextLine());
    	boolean inputDone = false;
    	fr = new int[N][2];
    	for (int i =0;i<N;i++) {
    		fr[i][0] = sc.nextInt();
    		fr[i][1] = sc.nextInt();
    		
    	}
    	while (!inputDone) {
    		int src = sc.nextInt();
    		int req = sc.nextInt();
    		if (src == 0&& req==0) {
    			inputDone = true;
    		}else {
    			count = 0;
    			solve(src,req, src);
    		}
    	}
    	
    }
    public static void solve(int src, int req, int org) {
    	for (int i =0;i<fr.length;i++) {
    		if (fr[i][0]== src) {
    			if (fr[i][1]==req) {
    				System.out.println("Yes " + count);
    			}else if(fr[i][1]== org) {
    				//if (req!= org)
    					System.out.println("No");
    			}else {
    				count++;
    				solve(fr[i][1],req, org);
    			}
    		}
    	}
    }
}