 #include<stdio.h>
int power ( int x , int y ) {
    if ( y==0 ) {
        return 1;
    }
    return x*(power(x,y-1));
}
void main() {
    int x,y,res;
    printf("Enter Base & Exponent : ");
    scanf("%d %d",&x,&y);
    res = power(x,y);
    printf("%d ",res);
}