#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct story{
    char name[40];
    int h;
    int m;
    struct story* next;
}st;
 st*first;
void khoitao(st*first){
    first=NULL;
}
st*makenode(char*name,int*h,int*m){
  st*p=(st*)malloc(sizeof(st));
  if(p==NULL){
    printf("khong du bo nho de cap phat!");
    return NULL;
  }
  strcpy(p->name,name);
  p->h=h;
  p->m=m;
  p->next=NULL;
  return p;
}
// them node vao cuoi danh sach
st*dau=NULL;
st*addLast(char*name,int h,int m){
    st*q=makenode(name,h,m);
    if(first==NULL) return first=q;
    st*p=first;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    return first;
}
void load(char*filename){
    FILE*f;
    f=fopen(filename,"r");
    if(f==NULL) printf("Load data->file not found \n");
    while(!feof(f)){
        char name[40];
        int h,m;
        fscanf(f,"%s%d%d",name,&h,&m);
        addLast(name,h,m);
    }
    fclose(f);
}
void processLoad(){
    char name[256];
    scanf("%s",name);
    load(name);
}
void printList(){
    for(st*p=first;p!=NULL;p=p->next)
    printf("%-50s%-10d%-10d \n",p->name,p->h,p->m);
}
void findName(){
    char name[40];
    printf("nhap dia diem can tim:");
    scanf("%s",name);
    st*p=first;
    int x=0;
    while(p!=NULL){
        if(strcmp(p->name,name)==0){
         printf("%d:%d,",p->h,p->m);
         x=1;
}
p=p->next;
}
printf("\n");
if(x==0) printf("ban chua toi dia diem do\n");
}
void findTime(){
    int h,m;
    while(1){
        printf("nhap h:");
        scanf("%d",&h);
        printf("nhap phut:");
        scanf("%d",&m);
        if(h>=0&&h<=24&&m>=0&&m<=60) break;
        else printf("khong hop le vui long nhap lai:\n");
    }
    st*p=first;
    st*profile=NULL;
    while(!feof){
        if(p->h==h&&p->m==m){
            profile=p;
            break;
        }
        p=p->next;
    }
    if(profile==NULL) printf("khong tim thay lich su di chuyen\n");
    else printf("%s\n",profile->name);

}
int main(){
    first=NULL;
    printf("CHUONG TRINH TRUY VET COVID19 \n");
        printf("1.Nap file log lich su di chuyen\n");
        printf("2.In ra lich su di chuyen\n");
        printf("3.Tim kiem lich su theo dia diem\n");
        printf("4.Tim kiem lich su theo thoi gian\n");
        printf("5.Thoat\n");
    while (1)
    {
        int cmd;
        printf("Chon chuc nang:");
        scanf("%d",&cmd);
        if(cmd==5) break;
        else if(cmd==1) processLoad();
        else if(cmd==2) printList();
        else if(cmd==3) findName();
        else if(cmd==4) findTime();
        }
    return 0;
}
