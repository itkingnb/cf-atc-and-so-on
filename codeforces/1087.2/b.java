import java.io.*;
import java.util.*;

public class b {

    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void solve() throws IOException {
        int n = Integer.parseInt(bf.readLine());
        int[] a=new int[n];
        st=new StringTokenizer(bf.readLine());
        for(int i=0;i<n;i++){
            a[i]=Integer.parseInt(st.nextToken());
        }
        for(int i=0;i<n;i++){
            int c0=0,c1=0;
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]){
                    c0++;
                }else if(a[i]<a[j]){
                    c1++;
                }
            }
            bw.write(String.valueOf(Math.max(c0,c1))+" ");
        }
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(bf.readLine());
        while (t-- > 0) {
            solve();
            bw.write('\n');
        }
        bw.flush();
    }
}