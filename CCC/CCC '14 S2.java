import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		boolean bad = false;
		int match =0;
		int n = sc.nextInt();
		String[] part1 = new String[n];
		String[] part2 = new String[n];
		String[] pairs = new String[n];
		String[] pairs2 = new String[n];
		
		for (int i=0;i<n;i++) {
			part1[i] = sc.next();
			
		}
		for (int i=0;i<n;i++) {
			part2[i] = sc.next();
			
		}
		for (int i=0;i<n;i++) {
			pairs[i] = part1[i]+part2[i];
			
			if (part1[i].equals(part2[i])){
				bad = true;
				
			}
		}
		for (int i=0;i<n;i++) {
			pairs2[i] = part2[i]+part1[i];
			
			
		}
		
		for (int i=0;i<pairs.length;i++) {
			for (int j=0;j<pairs.length;j++) {
				if (!pairs[i].equals(pairs2[j])) {
					continue;
				}else {
					match++;
				}
					
			}
			
		}
		if (match<n) {
			bad = true;
			
		}
		if (bad) {
			System.out.print("bad");
		}else {
			System.out.print("good");
		}
		
		
		
		
	}

	}