#include<stdio.h>

int type1(int s);
int type2(int s);
int type3(int s);
int type4(int s);


int main(){
    int size=0;
    int type=0;
    printf("size and type :");
    scanf("%d %d",&size,&type);
    if(type==1){
        type1(size);
    }
    else if(type==2){
        type2(size);
    }
    else if(type==3){
        type3(size);
    }
    else if(type==4){
        type4(size);
    }
    else{
        printf("type error");
    }
}

int type1(int s){
    for(int i=1;i<=s;i++){
        if(i<=(s+1)/2){
            for(int l=s-i;l<s;l++){
                printf("*");
            }
        }
        else{
            for(int l=i;l<=s;l++){
                printf("*");
            }
        }
        
        printf("\n");
    }
}


int type2(int s){
    for(int i=1;i<=s;i++){
        if(i<=(s+1)/2){
            for(int l=(s+1)/2;l>i;l--){
                printf(" ");
            }
            for(int l=s-i;l<s;l++){
                printf("*");
            }
        }
        else {
            for(int l=s-i+1;l<(s+1)/2;l++){
                printf(" ");
            }
            for(int l=i;l<=s;l++){
                printf("*");
            }
        }
        
        printf("\n");
    }
}


int type3(int s){
    int a=s;
    if(s%2==0){
        a--;
    }
    for(int i=1;i<=s;i++){
        if(i<=(s+1)/2){
            for(int l=1;l<i;l++){
                printf(" ");
            }
            for(int l=i*2-1;l<=a;l++){
                printf("*");
            }
        }
        else{
            for(int l=i;l<s;l++){
                printf(" ");
            }
            for(int l=a;l<=i*2-1;l++){
                printf("*");
            }
        }
        printf("\n");
    }
}

int type4(int s){
    for(int i=1;i<=s;i++){
        if(i<=(s+1)/2){
           for(int l=1;l<i;l++){
                printf(" ");
            }
            for(int l=i;l<=(s+1)/2;l++){
                printf("*");
            }
        }
        else{
            for(int l=0;l<(s-1)/2;l++){
                printf(" ");
            }
            for(int l=s-i;l<=(s-1)/2;l++){
                printf("*");
            }
        }
        
        printf("\n");
    }
}

