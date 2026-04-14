// import java.io.*;
// import java.util.*;

// public class Main {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringBuilder sb = new StringBuilder();
//     static StringTokenizer st;
//     static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//     public static void solve()throws IOException{    
//         int n=Integer.parseInt(br.readLine());
//         int[] a=new int[n];
//         int mx=0;
//         st = new StringTokenizer(br.readLine());
//         for(int i=0;i<n;i++){
//             a[i]=Integer.parseInt(st.nextToken());
//             mx=Math.max(mx,a[i]);
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(a[i]==mx){
//                 ans++;
//             }
//         }
//         sb.append(ans).append("\n");
//     }
//     public static void main(String[] args) throws IOException {
//         int t = Integer.parseInt(br.readLine());
//         // st = new StringTokenizer(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }
// import java.io.*;
// import java.util.*;

// public class Main {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringBuilder sb = new StringBuilder();
//     static StringTokenizer st;
//     static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//     public static void solve()throws IOException{    
//         int n=Integer.parseInt(br.readLine());
//         int[] a=new int[n];
//         st = new StringTokenizer(br.readLine());
//         for(int i=0;i<n;i++){
//             a[i]=Integer.parseInt(st.nextToken());
//         }
//         boolean ok=false;
//         for(int i=1;i<n;i++){
//             if(a[i]<a[i-1]){
//                 ok=true;
//             }
//         }
//         if(ok){
//             sb.append(1).append('\n');
//         }else{
//             sb.append(n).append('\n');
//         }
//     }
//     public static void main(String[] args) throws IOException {
//         int t = Integer.parseInt(br.readLine());
//         // st = new StringTokenizer(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.io.*;
// import java.util.*;

// public class Main {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringBuilder sb = new StringBuilder();
//     static StringTokenizer st;
//     static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//     public static void solve()throws IOException{    
//         int n=Integer.parseInt(br.readLine());
//         String s=br.readLine();
//         Deque<Character> stk=new ArrayDeque<>();
//         for(int i=0;i<n;i++){
//             if(stk.isEmpty()||stk.peek()!=s.charAt(i)){
//                 stk.push(s.charAt(i));
//             }else{
//                 stk.pop();
//             }
//         }
//         if(stk.isEmpty()){
//             sb.append("Yes").append("\n");
//         }else{
//             sb.append("No").append("\n");
//         }

//     }
//     public static void main(String[] args) throws IOException {
//         int t = Integer.parseInt(br.readLine());
//         // st = new StringTokenizer(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.io.*;
// import java.util.*;

// public class Main {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringBuilder sb = new StringBuilder();
//     static StringTokenizer st;
//     static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//     public static void solve()throws IOException{    
//         st=new StringTokenizer(br.readLine());
//         int n=Integer.parseInt(st.nextToken());
//         int x=Integer.parseInt(st.nextToken());
//         int y=Integer.parseInt(st.nextToken());
//         int[] a=new int[n];
//         st=new StringTokenizer(br.readLine());
//         ArrayList<Integer> t=new ArrayList<>();
//         for(int i=0;i<n;i++){
//             a[i]=Integer.parseInt(st.nextToken());
//         }
//         ArrayList<Integer> t2=new ArrayList<>();
//         int mn=n;
//         for(int i=0;i<n;i++){
//             if(i>=x&&i<y){
//                 t.add(a[i]);
//                 mn=Math.min(a[i],mn);
//             }else{
//                 t2.add(a[i]);
//             }
            
//         }
//         int idx=-1;
//         for(int i=0;i<n;i++){
//             if(t.get(i)==mn){
//                 idx=i;
//                 break;
//             }
//         }
//         boolean ok=false;
//         for(int i=0;i<t2.size();i++){
//             if(!ok&&t2.get(i)>mn){
//                 int cnt=0;
//                 while(cnt<y-x){
//                     cnt++;
//                     sb.append(t.get(idx)).append(" ");
//                     idx=(idx+1)%(y-x);
//                 }
//                 ok=true;
//             }
//             sb.append(t2.get(i)).append(" ");
//         }
//         if(!ok){
//             int cnt=0;
//             while(cnt<y-x){
//                 cnt++;
//                 sb.append(t.get(idx)).append(" ");
//                 idx=(idx+1)%(y-x);
//             }
//         }
//         sb.append('\n');
//     }
//     public static void main(String[] args) throws IOException {
//         int t = Integer.parseInt(br.readLine());
//         // st = new StringTokenizer(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.io.*;
// import java.util.*;

// public class Main {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringBuilder sb = new StringBuilder();
//     static StringTokenizer st;
//     static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//     static int N = 1000001;
//     static int[] primes = new int[N];
//     static int[] minp = new int[N];
//     static boolean[] isprime = new boolean[N];
//     static int cnt = 0;

//     public static void linearSieve(int n) {
//         for (int i = 2; i <= n; i++) {
//             if (!isprime[i]) {
//                 primes[cnt++] = i;
//                 minp[i] = i;
//             }
//             for (int j = 0; j < cnt && primes[j] * i <= n; j++) {
//                 int p = primes[j];
//                 isprime[p * i] = true;
//                 minp[p * i] = p;

//                 if (i % p == 0) break;
//             }
//         }
//     }
//     public static void solve()throws IOException{    
//         int n=Integer.parseInt(br.readLine());
//         int[] a=new int[n];
//         st=new StringTokenizer(br.readLine());
//         for(int i=0;i<n;i++){
//             a[i]=Integer.parseInt(st.nextToken());
//         }
//         boolean ok=false;
//         for(int i=1;i<n;i++){
//             if(a[i]<a[i-1]){
//                 ok=true;
//             }
//         }
//         if(!ok){
//             sb.append("Bob").append('\n');
//             return ;
//         }
//         int last=0;
//         for(int i=0;i<n;i++){
//             ArrayList<Integer>t=new ArrayList<>();
//             while(a[i]!=1){
//                 t.add(minp[a[i]]);
//                 a[i]/=minp[a[i]];
//             }
//             if(t.isEmpty()){
//                 t.add(a[i]);
//             }
//             if(!t.get(t.size()-1).equals(t.get(0))){//不可以写！=！！！！！！
//                 sb.append("Alice").append("\n");
//                 return ;
//             }
//             if(t.get(0)<last){
//                 sb.append("Alice").append("\n");
//                 return ;
//             }
//             last=t.get(0);
//         }
//         sb.append("Bob").append('\n');
//     }
//     public static void main(String[] args) throws IOException {
//         int t = Integer.parseInt(br.readLine());
//         linearSieve(1000000);
//         // st = new StringTokenizer(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.io.*;
// import java.util.*;

// public class Main {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringBuilder sb = new StringBuilder();
//     static StringTokenizer st;
//     static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//     static int N = 1000001;
//     static int[] primes = new int[N];
//     static int[] minp = new int[N];
//     static boolean[] isprime = new boolean[N];
//     static int cnt = 0;

//     public static void linearSieve(int n) {
//         for (int i = 2; i <= n; i++) {
//             if (!isprime[i]) {
//                 primes[cnt++] = i;
//                 minp[i] = i;
//             }
//             for (int j = 0; j < cnt && primes[j] * i <= n; j++) {
//                 int p = primes[j];
//                 isprime[p * i] = true;
//                 minp[p * i] = p;

//                 if (i % p == 0) break;
//             }
//         }
//     }
//     public static void solve()throws IOException{    
//         st=new StringTokenizer(br.readLine());
//         int n=Integer.parseInt(st.nextToken());
//         int m=Integer.parseInt(st.nextToken());
//         ArrayList<Long>[] t = new ArrayList[n+1];
//         for(int i=0;i<=n;i++){
//             t[i]=new ArrayList<>();
//         }
//         for(int i=0;i<n;i++){
//             st=new StringTokenizer(br.readLine());
//             long x=Long.parseLong(st.nextToken());
//             int y=Integer.parseInt(st.nextToken());
//             t[y].add(x);
//         }
//         long sum=0;
//         long[] dp=new long[n+1];
//         long[] pre=new long[n+1];
//         long mx=0;
//         PriorityQueue<Long> pq=new PriorityQueue<>();
//         for(int i=n;i>=0;i--){
//             for(int j=0;j<t[i].size();j++){
//                 pq.add(t[i].get(j));
//                 sum+=t[i].get(j);
//             }
//             long last=0;
//             while(pq.size()>i){
//                 last=pq.peek();
//                 sum-=pq.poll();
//             }
//             dp[i]=sum;
//             // suf[i]=Math.max(suf[i+1],dp[i]);
//             pre[i]=dp[i];
//             dp[i]+=last;
//             mx=Math.max(dp[i],mx);
//         }
//         for(int i=1;i<=n;i++){
//             pre[i]=Math.max(pre[i],pre[i-1]);
//         }
//         for(int i=0;i<m;i++){
//             st=new StringTokenizer(br.readLine());
//             long x=Long.parseLong(st.nextToken());
//             int y=Integer.parseInt(st.nextToken());
//             sb.append(Math.max(x+pre[y],mx)).append(" ");
//         }
//         sb.append('\n');
//     }
//     public static void main(String[] args) throws IOException {
//         int t = Integer.parseInt(br.readLine());
//         // st = new StringTokenizer(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N = 1000001;
    static int[] primes = new int[N];
    static int[] minp = new int[N];
    static boolean[] isprime = new boolean[N];
    static int cnt = 0;

    public static void linearSieve(int n) {
        for (int i = 2; i <= n; i++) {
            if (!isprime[i]) {
                primes[cnt++] = i;
                minp[i] = i;
            }
            for (int j = 0; j < cnt && primes[j] * i <= n; j++) {
                int p = primes[j];
                isprime[p * i] = true;
                minp[p * i] = p;

                if (i % p == 0) break;
            }
        }
    }
    public static void solve()throws IOException{    
        st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        ArrayList<Long>[] t = new ArrayList[n+1];
        for(int i=0;i<=n;i++){
            t[i]=new ArrayList<>();
        }
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            long x=Long.parseLong(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            t[y].add(x);
        }
        long sum=0;
        long[] dp=new long[n+1];
        long[] pre=new long[n+1];
        long mx=0;
        PriorityQueue<Long> pq=new PriorityQueue<>();
        for(int i=n;i>=0;i--){
            for(int j=0;j<t[i].size();j++){
                pq.add(t[i].get(j));
                sum+=t[i].get(j);
            }
            long last=0;
            while(pq.size()>i){
                last=pq.peek();
                sum-=pq.poll();
            }
            dp[i]=sum;
            // suf[i]=Math.max(suf[i+1],dp[i]);
            pre[i]=dp[i];
            dp[i]+=last;
            mx=Math.max(dp[i],mx);
        }
        for(int i=1;i<=n;i++){
            pre[i]=Math.max(pre[i],pre[i-1]);
        }
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine());
            long x=Long.parseLong(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            sb.append(Math.max(x+pre[y],mx)).append(" ");
        }
        sb.append('\n');
    }
    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        // st = new StringTokenizer(br.readLine());
        while(t-->0){
            solve();
        }
        bw.write(sb.toString());
        bw.flush();
    }
}