// // import java.util.*;
// // import java.io.*;

// // public  class Main{
// //     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
// //     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
// //     static StringTokenizer st;
// //     static StringBuilder sb=new StringBuilder();
// //     static public void solve()throws IOException{
// //         int now=2025;
// //         int t=0;
// //         while(now>0){
// //             t++;
// //             now-=5;
// //             if(t%2==0){
// //                 now-=2;
// //             }else{
// //                 now-=15;
// //             }
// //             if(t%3==1){
// //                 now-=2;
// //             }else if(t%3==2){
// //                 now-=10;
// //             }else{
// //                 now-=7;
// //             }
// //         }
// //         sb.append(t);
// //     }
// //     public static void main(String[] args)throws IOException{
// //         int t=1;
// //         // t=Integer.parseInt(br.readLine());
// //         while(t-->0){
// //             solve();
// //         }
// //         bw.write(sb.toString());
// //         bw.flush();
// //     }
// // }

// // import java.util.*;
// // import java.io.*;

// // public  class Main{
// //     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
// //     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
// //     static StringTokenizer st;
// //     static StringBuilder sb=new StringBuilder();
// //     static public void solve()throws IOException{
// //         st=new StringTokenizer(br.readLine());
// //         int w=Integer.parseInt(st.nextToken());
// //         int h=Integer.parseInt(st.nextToken());
// //         int v=Integer.parseInt(st.nextToken());
// //         for(int i=0;i<h;i++){
// //             for(int j=0;j<w;j++){
// //                 sb.append('Q');
// //             }
// //             sb.append("\n");
// //         }
// //         for(int i=0;i<w;i++){
// //             for(int j=0;j<w+v;j++){
// //                 sb.append("Q");
// //             }
// //             sb.append('\n');
// //         }
// //     }
// //     public static void main(String[] args)throws IOException{
// //         int t=1;
// //         // t=Integer.parseInt(br.readLine());
// //         while(t-->0){
// //             solve();
// //         }
// //         bw.write(sb.toString());
// //         bw.flush();
// //     }
// // }
// // import java.util.*;
// // import java.io.*;

// // public  class Main{
// //     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
// //     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
// //     static StringTokenizer st;
// //     static StringBuilder sb=new StringBuilder();
// //     static public void solve()throws IOException{
// //         String s=br.readLine();
// //         int ans=0;
// //         for(int i=2;i<s.length();i++){
// //             int[] cnt=new int[3];
// //             for(int j=i;j>i-3;j--){
// //                 if(s.charAt(j)=='l'){
// //                     cnt[0]++;
// //                 }else if(s.charAt(j)=='q'){
// //                     cnt[1]++;
// //                 }else if(s.charAt(j)=='b'){
// //                     cnt[2]++;
// //                 }
// //             }
// //             if(cnt[0]==1&&cnt[1]==1&&cnt[2]==1){
// //                 i+=2;
// //                 ans++;
// //             }
// //         }
// //         sb.append(ans);
// //     }
// //     public static void main(String[] args)throws IOException{
// //         int t=1;
// //         // t=Integer.parseInt(br.readLine());
// //         while(t-->0){
// //             solve();
// //         }
// //         bw.write(sb.toString());
// //         bw.flush();
// //     }
// // }
// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         int n=Integer.parseInt(br.readLine());
//         st=new StringTokenizer(br.readLine());
//         int[] h=new int[n+1];
//         for(int i=1;i<=n;i++){
//             h[i]=Integer.parseInt(st.nextToken());
//         }
//         int[][] dp=new int[n+1][n+1];
//         for(int i=1;i<=n;i++){
//             dp[1][i]=1;
//         }
//         int mx=1;
//         for(int i=2;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 dp[i][j]=1;
//             }
//             for(int j=i-1;j>=1;j--){
//                 if(h[i]<h[j]){
//                     continue;
//                 }
//                 dp[i][i-j]=Math.max(dp[i][i-j],dp[j][i-j]+1);
//                 mx=Math.max(mx,dp[i][i-j]);
//             }
//         }
//         sb.append(mx);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }


// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         int now=2025;
//         int t=0;
//         while(now>0){
//             t++;
//             now-=5;
//             if(t%2==0){
//                 now-=2;
//             }else{
//                 now-=15;
//             }
//             if(t%3==1){
//                 now-=2;
//             }else if(t%3==2){
//                 now-=10;
//             }else{
//                 now-=7;
//             }
//         }
//         sb.append(t);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         st=new StringTokenizer(br.readLine());
//         int w=Integer.parseInt(st.nextToken());
//         int h=Integer.parseInt(st.nextToken());
//         int v=Integer.parseInt(st.nextToken());
//         for(int i=0;i<h;i++){
//             for(int j=0;j<w;j++){
//                 sb.append('Q');
//             }
//             sb.append("\n");
//         }
//         for(int i=0;i<w;i++){
//             for(int j=0;j<w+v;j++){
//                 sb.append("Q");
//             }
//             sb.append('\n');
//         }
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }
// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         String s=br.readLine();
//         int ans=0;
//         for(int i=2;i<s.length();i++){
//             int[] cnt=new int[3];
//             for(int j=i;j>i-3;j--){
//                 if(s.charAt(j)=='l'){
//                     cnt[0]++;
//                 }else if(s.charAt(j)=='q'){
//                     cnt[1]++;
//                 }else if(s.charAt(j)=='b'){
//                     cnt[2]++;
//                 }
//             }
//             if(cnt[0]==1&&cnt[1]==1&&cnt[2]==1){
//                 i+=2;
//                 ans++;
//             }
//         }
//         sb.append(ans);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }
// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         ArrayList<String> a=new ArrayList<>();
//         for(int i=0;i<50000;i++){
//             a.add(br.readLine());
//         }
//         a.sort((s,t)->s.length()-t.length());
//         sb.append(a.size());
        
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static int N=1048576;
//     static public void solve()throws IOException{
//         // sb.append(1<<30);
//         int L=Integer.parseInt(br.readLine());
//         long[] dp=new long[L+1];
//         for(int i=1;i<=L;i++){
//             for(int j=1;j*j<=i;j++){
//                 if(i%j==0&&j*j!=i){
//                     dp[i]+=2;
//                 }else if(i%j==0){
//                     dp[i]++;
//                 }
//             }
//         }
//         long[] pre=new long[L+1];
//         for(int i=1;i<=L;i++){
//             pre[i]=pre[i-1]+dp[i];
//         }
//         long ans=0;
//         for(int i=1;i<L;i++){
//             ans+=1L*dp[i]*pre[L-i];
//         }
//         sb.append(ans);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

import java.util.*;
import java.io.*;

public  class Main{
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb=new StringBuilder();
    static int N=1048576;
    static public void swap(int[] a,int i,int j){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    static public void add(int[] fen,int i,int n){
        while(i<=n){
            fen[i]++;
            i+=(i&-i);
        }
    }
    static public int query(int[] fen,int i){
        int ans=0;
        i--;
        while(i>0){
            ans+=fen[i];
            i-=(i&-i);
        }
        return ans;
    }
    static public void solve()throws IOException{
        int n=Integer.parseInt(br.readLine());
        int[] a=new int[n+1];
        int[] pos=new int[n+1];
        st=new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            a[i]=Integer.parseInt(st.nextToken());
            pos[a[i]]=i;
        }
        int[] fen=new int[n+1];
        // if(n<=10000){
        //     long ans=0;
        //     for(int i=1;i<=n;i++){
        //         while(pos[i]>i){
        //             swap(a,pos[i],pos[i]-1);
        //             ans++;
        //             pos[a[pos[i]]]++;
        //             pos[i]--;
        //         }
        //         while(pos[i]<i){
        //             swap(a,pos[i],pos[i]+1);
        //             ans++;
        //             pos[a[pos[i]]]--;
        //             pos[i]++;
        //         }
        //     }
        //     sb.append(ans);
        //     return ;
        // }
        long ans=0;
        for(int i=1;i<=n;i++){
            while(i!=pos[i]){
                swap(a,i,pos[i]);
                pos[a[pos[i]]]=pos[i];
                pos[i]=i;
                ans++;
            }
        }
        sb.append(ans);
    }
    public static void main(String[] args)throws IOException{
        int t=1;
        // t=Integer.parseInt(br.readLine());
        while(t-->0){
            solve();
        }
        bw.write(sb.toString());
        bw.flush();
        System.err.println();
    }
}
// // import java.util.*;
// // import java.io.*;

// // public  class Main{
// //     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
// //     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
// //     static StringTokenizer st;
// //     static StringBuilder sb=new StringBuilder();
// //     static public void solve()throws IOException{
// //         int now=2025;
// //         int t=0;
// //         while(now>0){
// //             t++;
// //             now-=5;
// //             if(t%2==0){
// //                 now-=2;
// //             }else{
// //                 now-=15;
// //             }
// //             if(t%3==1){
// //                 now-=2;
// //             }else if(t%3==2){
// //                 now-=10;
// //             }else{
// //                 now-=7;
// //             }
// //         }
// //         sb.append(t);
// //     }
// //     public static void main(String[] args)throws IOException{
// //         int t=1;
// //         // t=Integer.parseInt(br.readLine());
// //         while(t-->0){
// //             solve();
// //         }
// //         bw.write(sb.toString());
// //         bw.flush();
// //     }
// // }

// // import java.util.*;
// // import java.io.*;

// // public  class Main{
// //     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
// //     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
// //     static StringTokenizer st;
// //     static StringBuilder sb=new StringBuilder();
// //     static public void solve()throws IOException{
// //         st=new StringTokenizer(br.readLine());
// //         int w=Integer.parseInt(st.nextToken());
// //         int h=Integer.parseInt(st.nextToken());
// //         int v=Integer.parseInt(st.nextToken());
// //         for(int i=0;i<h;i++){
// //             for(int j=0;j<w;j++){
// //                 sb.append('Q');
// //             }
// //             sb.append("\n");
// //         }
// //         for(int i=0;i<w;i++){
// //             for(int j=0;j<w+v;j++){
// //                 sb.append("Q");
// //             }
// //             sb.append('\n');
// //         }
// //     }
// //     public static void main(String[] args)throws IOException{
// //         int t=1;
// //         // t=Integer.parseInt(br.readLine());
// //         while(t-->0){
// //             solve();
// //         }
// //         bw.write(sb.toString());
// //         bw.flush();
// //     }
// // }
// // import java.util.*;
// // import java.io.*;

// // public  class Main{
// //     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
// //     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
// //     static StringTokenizer st;
// //     static StringBuilder sb=new StringBuilder();
// //     static public void solve()throws IOException{
// //         String s=br.readLine();
// //         int ans=0;
// //         for(int i=2;i<s.length();i++){
// //             int[] cnt=new int[3];
// //             for(int j=i;j>i-3;j--){
// //                 if(s.charAt(j)=='l'){
// //                     cnt[0]++;
// //                 }else if(s.charAt(j)=='q'){
// //                     cnt[1]++;
// //                 }else if(s.charAt(j)=='b'){
// //                     cnt[2]++;
// //                 }
// //             }
// //             if(cnt[0]==1&&cnt[1]==1&&cnt[2]==1){
// //                 i+=2;
// //                 ans++;
// //             }
// //         }
// //         sb.append(ans);
// //     }
// //     public static void main(String[] args)throws IOException{
// //         int t=1;
// //         // t=Integer.parseInt(br.readLine());
// //         while(t-->0){
// //             solve();
// //         }
// //         bw.write(sb.toString());
// //         bw.flush();
// //     }
// // }
// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         int n=Integer.parseInt(br.readLine());
//         st=new StringTokenizer(br.readLine());
//         int[] h=new int[n+1];
//         for(int i=1;i<=n;i++){
//             h[i]=Integer.parseInt(st.nextToken());
//         }
//         int[][] dp=new int[n+1][n+1];
//         for(int i=1;i<=n;i++){
//             dp[1][i]=1;
//         }
//         int mx=1;
//         for(int i=2;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 dp[i][j]=1;
//             }
//             for(int j=i-1;j>=1;j--){
//                 if(h[i]<h[j]){
//                     continue;
//                 }
//                 dp[i][i-j]=Math.max(dp[i][i-j],dp[j][i-j]+1);
//                 mx=Math.max(mx,dp[i][i-j]);
//             }
//         }
//         sb.append(mx);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }


// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         int now=2025;
//         int t=0;
//         while(now>0){
//             t++;
//             now-=5;
//             if(t%2==0){
//                 now-=2;
//             }else{
//                 now-=15;
//             }
//             if(t%3==1){
//                 now-=2;
//             }else if(t%3==2){
//                 now-=10;
//             }else{
//                 now-=7;
//             }
//         }
//         sb.append(t);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         st=new StringTokenizer(br.readLine());
//         int w=Integer.parseInt(st.nextToken());
//         int h=Integer.parseInt(st.nextToken());
//         int v=Integer.parseInt(st.nextToken());
//         for(int i=0;i<h;i++){
//             for(int j=0;j<w;j++){
//                 sb.append('Q');
//             }
//             sb.append("\n");
//         }
//         for(int i=0;i<w;i++){
//             for(int j=0;j<w+v;j++){
//                 sb.append("Q");
//             }
//             sb.append('\n');
//         }
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }
// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         String s=br.readLine();
//         int ans=0;
//         for(int i=2;i<s.length();i++){
//             int[] cnt=new int[3];
//             for(int j=i;j>i-3;j--){
//                 if(s.charAt(j)=='l'){
//                     cnt[0]++;
//                 }else if(s.charAt(j)=='q'){
//                     cnt[1]++;
//                 }else if(s.charAt(j)=='b'){
//                     cnt[2]++;
//                 }
//             }
//             if(cnt[0]==1&&cnt[1]==1&&cnt[2]==1){
//                 i+=2;
//                 ans++;
//             }
//         }
//         sb.append(ans);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }


// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static int N=1048576;
//     static public void solve()throws IOException{
//         // sb.append(1<<30);
//         int L=Integer.parseInt(br.readLine());
//         long[] dp=new long[L+1];
//         for(int i=1;i<=L;i++){
//             for(int j=1;j*j<=i;j++){
//                 if(i%j==0&&j*j!=i){
//                     dp[i]+=2;
//                 }else if(i%j==0){
//                     dp[i]++;
//                 }
//             }
//         }
//         long[] pre=new long[L+1];
//         for(int i=1;i<=L;i++){
//             pre[i]=pre[i-1]+dp[i];
//         }
//         long ans=0;
//         for(int i=1;i<L;i++){
//             ans+=1L*dp[i]*pre[L-i];
//         }
//         sb.append(ans);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }

// import java.util.*;
// import java.io.*;
// import java.math.BigInteger;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static int N=1048576;
//     static public void swap(int[] a,int i,int j){
//         int tmp=a[i];
//         a[i]=a[j];
//         a[j]=tmp;
//     }
//     static public void add(int[] fen,int i,int n){
//         while(i<=n){
//             fen[i]++;
//             i+=(i&-i);
//         }
//     }
//     static public int query(int[] fen,int i){
//         int ans=0;
//         i--;
//         while(i>0){
//             ans+=fen[i];
//             i-=(i&-i);
//         }
//         return ans;
//     }
//     static public void solve()throws IOException{
//         int n=Integer.parseInt(br.readLine());
//         int[] a=new int[n+1];
//         st=new StringTokenizer(br.readLine());
//         for(int i=1;i<=n;i++){
//             a[i]=Integer.parseInt(st.nextToken());
//         }
//         // if(n<=10000){
//         //     long ans=0;
//         //     for(int i=1;i<=n;i++){
//         //         for(int j=i+1;j<=n;j++){
//         //             ans+=1L*(a[i]^a[j])*(j-i);
//         //         }
//         //     }
//         //     sb.append(ans);
//         //     return ;
//         // }
//         BigInteger ans=BigInteger.ZERO;
//         for(int l=1,r=n;l<r;l++,r--){
//             swap(a,l,r);
//         }
//         long[][] pre=new long[2][21];
//         long[][] sum=new long[2][21];
//          for(int i=0;i<21;i++){
//             pre[((a[1]>>i)&1)][i]+=(1<<i);
//             sum[((a[1]>>i)&1)][i]+=(1<<i);
//         }
//         for(int i=2;i<=n;i++){
//             for(int j=0;j<21;j++){
//                 ans = ans.add(BigInteger.valueOf(pre[1-((a[i]>>j)&1)][j]));
//                 sum[((a[i]>>j)&1)][j]+=(1<<j);
//                 pre[0][j]+=sum[0][j];
//                 pre[1][j]+=sum[1][j];
//             }
//         }
//         sb.append(ans);
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }


// import java.util.*;
// import java.io.*;

// public  class Main{
//     static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//     static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
//     static StringTokenizer st;
//     static StringBuilder sb=new StringBuilder();
//     static public void solve()throws IOException{
//         sb.append("aprdq");
//     }
//     public static void main(String[] args)throws IOException{
//         int t=1;
//         // t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             solve();
//         }
//         bw.write(sb.toString());
//         bw.flush();
//     }
// }