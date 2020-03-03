import java.util.*;

public class Main {
   
    
    public static void main(String[] args){
     Scanner sc = new Scanner(System.in);
     int initStreams = sc.nextInt();
     ArrayList<Double> streams = new ArrayList<Double>();
    
    for (int i =0;i<initStreams;i++){
         streams.add(sc.nextDouble());
     }
     boolean end = false;
     while (!end) {
    	 int action = sc.nextInt();
    	 if (action==99) {
    		 int splitStream = sc.nextInt()-1;
    		 double factor = sc.nextDouble();
    		 factor =factor* 0.01;
    		 streams.add(splitStream+1, (streams.get(splitStream)*(1-factor)));
    		 streams.set(splitStream,  (streams.get(splitStream) * factor)) ;
    		 
    	 }
    	 if (action==88) {
    		 int joinStream = sc.nextInt()-1;
    		 streams.set(joinStream, streams.get(joinStream)+streams.get(joinStream+1));
    		 streams.remove(joinStream+1);
    	 }
    	 if (action==77) {
    		 end = true;
    	 }
    
     }

     for (int i =0;i<streams.size();i++) {
    	 System.out.print(Math.round(streams.get(i)) +" ");
     }
    }
}