import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
  	  int r = Integer.parseInt(sc.nextLine()), l = Integer.parseInt(sc.nextLine());
  	  String lights[] = new String[r];
  	  for(int i = 0; i < r; i++)  lights[i] = sc.nextLine().replaceAll(" ", "");
  	  Set<String> set = new HashSet<String>();
  	  
  	  
  	  for(int i = 0; i < r; i++) {
  		  String res = lights[i];
  		  for(int j = i + 1; j < r; j++) res = pushButton(res, lights[j]);
  		  set.add(res);
  	  }
  	System.out.println(set.size());
  	sc.close();

    }
	
    static String pushButton(String a, String b) {
  	  String res = "";
  	  for(int i = 0; i < a.length(); i++) {
  		  	if(a.charAt(i) == b.charAt(i)) res += 0;
  		  	else res += 1;
  	  }
  	  return res;
	}
}
