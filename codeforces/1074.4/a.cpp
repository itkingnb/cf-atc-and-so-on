#include<stdio.h>
void generatePerfectRoots(int n){
    int i,j,count;
    i=1;
    count=0;
    while(count<n){
        for(j=1;j<=i;j++){
            if (j*j==i) {printf("%d ",i);  count++; break;}            
        }
        i++;
    }    
}
int main(){
    int n;
    scanf("%d", &n);
    int i,j;
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &j);
        a[i]=j;     
    }
    for(i=0;i<n;i++){
        generatePerfectRoots(a[i]);
        printf("\n");
    }
    return 0;
}