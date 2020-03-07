import java.util.*;

public class Main {
   
    
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int pink = sc.nextInt();
    	int green = sc.nextInt();
    	int red = sc.nextInt();
    	int orange = sc.nextInt();
    	int total = sc.nextInt();
    	int min = 1000000;
    	int total1 = 0;
    	int count = 0;
    	
    	for (int i =0;i<=total;i++) {
    		for (int j =0;j<=total;j++) {
    			for (int k =0;k<=total; k++) {
    				for (int l = 0;l<=total;l++) {
    					if ((i*pink+j*green+k*red+l*orange)==total) {
    						if (total1<min) {
    							total1 = i+j+k+l;
    							min = total1;
    						}
    						System.out.println("# of PINK is "+i+" # of GREEN is "+j+""
    								+ " # of RED is "+k+" # of ORANGE is "+l+"");
    						count++;
    					}
    				}
    			}
    		}
    	}
    	System.out.println("Total combos is "+count+".\r\n" + 
    			"Minimum number of tickets to print is "+min+".");
    	
	}
}