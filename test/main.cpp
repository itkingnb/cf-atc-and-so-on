import java.util.*;
public class Main{
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
//         System.out.print(s);
        int n=s.length();
        int[][] pre=new int[n+1][2];
        int[][] suf=new int[n+1][2];
        int c0=0,c1=0;
        for(int i=0;i<n;i++){
            pre[i+1][0]=c0;
            pre[i+1][1]=c1;
            if(s.charAt(i)=='0'){
                c0++;
                c1=0;
            }else if(s.charAt(i)=='1'){
                c1++;
                c0=0;
            }else{
                c0++;
                c1++;
            }
        }
        c0=0;c1=0;
        for(int i=n-1;i>=0;i--){
            suf[i+1][0]=c0;
            suf[i+1][1]=c1;
            if(s.charAt(i)=='0'){
                c0++;
                c1=0;
            }else if(s.charAt(i)=='1'){
                c1++;
                c0=0;
            }else{
                c0++;
                c1++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='0'){
                ans=Math.max(ans,pre[i+1][0]+suf[i+1][0]+1);
            }else if(s.charAt(i)=='1'){
                ans=Math.max(ans,pre[i+1][1]+suf[i+1][1]+1);
            }else{
                ans=Math.max(ans,pre[i+1][0]+suf[i+1][0]+1);
                ans=Math.max(ans,pre[i+1][1]+suf[i+1][1]+1);
            }
        }
        System.out.print(ans);
    }
}