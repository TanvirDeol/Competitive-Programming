import java.util.*; 

public class Main { 
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i =0;i<T;i++) {
			int N = sc.nextInt();
		
			Stack<Integer> nums = new Stack<Integer>();
			Stack<Integer> branch = new Stack<Integer>();
			for (int j =0;j<N;j++) {
				nums.push(sc.nextInt());
				
			}
			int count =1;
			while(count<=N) {
				if (!nums.isEmpty()&& nums.peek()==count) {
					count++;
					nums.pop();
				}else if(!branch.isEmpty()&& branch.peek()==count) {
					count++;
					branch.pop();
				}else if (!nums.isEmpty()) {
					branch.push(nums.pop());
				}else {
					System.out.println("N");
					break;
				}
			}
			if (count==N+1) {
				System.out.println("Y");
			}
		}
	}
}