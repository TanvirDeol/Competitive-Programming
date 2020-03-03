import java.util.*;

public class Main {
   
    
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int N = Integer.parseInt(sc.nextLine());
    	
    	String[][] lines = new String[N][4];
     	for (int i =0;i<N;i++) {
     		for (int j=0;j<4;j++) {
     			lines[i][j] = sc.nextLine().toLowerCase();
     			
     			
     		}
     	}
     	
     	for (int i =0;i<N;i++) {
     		for (int j=0;j<4;j++) {
     		String a = "a" +lines[i][j].substring(lines[i][j].lastIndexOf('a')+1, lines[i][j].length());
     		String e = "e" +lines[i][j].substring(lines[i][j].lastIndexOf('e')+1, lines[i][j].length());
     		String eye ="i" + lines[i][j].substring(lines[i][j].lastIndexOf('i')+1, lines[i][j].length());
     		String o = "o" +lines[i][j].substring(lines[i][j].lastIndexOf('o')+1, lines[i][j].length());
     		String u = "u" +lines[i][j].substring(lines[i][j].lastIndexOf('u')+1, lines[i][j].length());
     		String space =  lines[i][j].substring(lines[i][j].lastIndexOf(" ")+1, lines[i][j].length());
     		int min = Math.min(space.length(), Math.min(u.length(), Math.min(o.length(), Math.min(eye.length(), Math.min(a.length(), e.length())))));
     		if (a.length()==min) {
     			lines[i][j] = a.toLowerCase();
     		}
     		if (e.length()==min) {
     			lines[i][j] = e.toLowerCase();
     		}
     		if (eye.length()==min) {
     			lines[i][j] = eye.toLowerCase();
     		}
     		if (o.length()==min) {
     			lines[i][j] = o.toLowerCase();
     		}
     		if (u.length()==min) {
     			lines[i][j] = u.toLowerCase();
     		}
     		if (space.length() == min) {
     			lines[i][j] = space.toLowerCase();
     		}
     		
     		}
     	}
    	
     	for (int i =0 ;i<N;i++) {
     		if (lines[i][0].equals(lines[i][1])&&lines[i][1].equals(lines[i][2])&&lines[i][2].equals(lines[i][3])) {
     			System.out.println("perfect");
     		}
     		else if (lines[i][0].equals(lines[i][1])&&lines[i][2].equals(lines[i][3])) {
     			System.out.println("even");
     		}
     		else if (lines[i][0].equals(lines[i][2])&&lines[i][1].equals(lines[i][3])) {
     			System.out.println("cross");
     		}
     		else if (lines[i][0].equals(lines[i][3])&&lines[i][1].equals(lines[i][2])) {
     			System.out.println("shell");
     		}
     		else {
     			System.out.println("free");
     		}
     	}
    	
    	

    	
	}
}