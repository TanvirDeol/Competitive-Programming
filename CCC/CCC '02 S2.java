import java.util.*;

public class Main {
   
    
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	double num = sc.nextDouble();
    	double den = sc.nextDouble();
    	double sum =0;
    	double min =0;
    	double common = 0;
    	double max  =0 ;
    	double whole = 0;
    	String fraction = "";
    	
    	if (num == 0.0) {
    		fraction = "0";
    	}
    	if (num == den) {
    		fraction = "1";
    	}
    	if (num%den == 0.0) {
    		sum = num/den;
    		fraction  = (int)sum + "";
    	}else {
    		min = Math.min(num, den);
    		for (int i =0;i<min;i++) {
    			if (num%i ==0.0 && den%i==0.0) {
    				common = i;
    				if (common>max) {
    					max = common;
    				}
    			}
    		}
    		if (max ==1) {
    			if (num<den) {
    				fraction = (int)num + "/" + (int)den;
    			}else {
    				whole = Math.floor(num/den);
    				num = num -(den*whole);
    				fraction = (int)whole +" "+(int)num + "/" + (int)den;
    			}
    		}else if (max >1) {
    			num = num/max;
    			den = den/max;
    			if (num<den) {
    				fraction = (int)num + "/" + (int)den;
    			}else {
    				whole = Math.floor(num/den);
    				num = num -(den*whole);
    				fraction = (int)whole +" "+(int)num + "/" + (int)den;
    			}
    		}
    	}
    	
    	
    	
    	System.out.println(fraction);
	}
}