import java.util.*;



public class Main {
    public static int [] reward = {30,60,9}; 
    public static int [] cost= {35,100,10}; 
    public static int [] machinePlays;
    public static int quarters;
    
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    quarters = sc.nextInt();
    machinePlays= new int[]{sc.nextInt()+1,sc.nextInt()+1,sc.nextInt()+1};
    int turn = 0;
    long playCount=0;
    while (quarters>0){
        quarters--;
        playCount++;
        play(turn); 
        if (turn == 2) turn = 0;
        else turn++;
    }
    
        System.out.println("Martha plays "+playCount +" times before going broke.");
    
    
}
    public static void play(int i){
        if (machinePlays[i]==cost[i]){
            quarters += reward[i];
            machinePlays[i] = 1;
        }else{
            machinePlays[i]++;
        }
    }
}