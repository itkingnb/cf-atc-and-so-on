import java.io.*;
import java.util.*;

public class a {

    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void solve() throws IOException {
        st = new StringTokenizer(bf.readLine());
        long n = Long.parseLong(st.nextToken());
        long c = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        Long[] a = new Long[(int)n];
        st = new StringTokenizer(bf.readLine());
        PriorityQueue<Long> pq=new PriorityQueue<>();
        for(int i=0;i<n;i++){
            a[i]=Long.parseLong(st.nextToken());
            pq.add(a[i]);
        }
        while(pq.size()>0){
            Long x=pq.poll();
            Long mx=Math.max(0,Math.min(k,c-x));
            k-=mx;
            x+=mx;
            // System.err.println(x);
            if(x<=c){
                c+=x;
            }else{
                break;
            }
        }
        bw.write(String.valueOf(c));
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