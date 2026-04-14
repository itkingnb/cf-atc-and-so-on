import java.util.*;
public class App {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t --> 0){
            solve(sc);
        }
        
    }
    
    private static void solve(Scanner sc){
        int n = sc.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        if(a[0]==0&&a[n-1]==0){
            System.out.println("Bob");
        }else{
            System.out.println("Alice");
        }
        
 
    }
}