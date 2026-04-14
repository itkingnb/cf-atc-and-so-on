#include<bits/stdc++.h>
using namespace std;
int t,r,g,b,rb,gb,rg;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&r,&g,&b);
		while(((r > 0) + (g > 0) + (b > 0)) >> 1){
			if(r <= g && r <= b)
				gb ++,g --,b --;
			else if(g <= r && g <= b)
				rb ++,r --,b --;
			else if(b <= r && b <= g)
				rg ++,r --,g --;
		}
		if(g > 0){
		    putchar('G');
		    while(rg > 0)
		   		putchar('R'),putchar('G'),rg --;
		   	bool flg = false;
		   	while(gb > 0)
		   		putchar('B'),putchar('G'),gb --,flg = true;
		    	if(flg){
		   		while(rb > 0)
		    			putchar('B'),putchar('R'),rb --;
		    	}
		    	else{
		    		while(rb > 0)
	    				putchar('R'),putchar('B'),rb --;
		    	}
		}
		else if(r > 0){
			putchar('R');
			while(rg > 0)
				putchar('G'),putchar('R'),rg --;
			bool flg = false;
			while(rb > 0)
				putchar('B'),putchar('R'),rb --,flg = true;
			if(flg){
				while(gb > 0)
					putchar('B'),putchar('G'),gb --;
			}
			else{
				while(gb > 0)
					putchar('G'),putchar('B'),gb --;
			}
		}
		else{
			if(b > 0)
				putchar('B');
			while(gb > 0)
				putchar('G'),putchar('B'),gb --;
			bool flg = false;
			while(rb > 0)
				putchar('R'),putchar('B'),rb --,flg = true;
			if(flg){
				while(rg > 0)
					putchar('R'),putchar('G'),rg --;
			}
			else{
				while(rg > 0)
					putchar('G'),putchar('R'),rg --;
			}
		}
		puts("");
	}
} 
