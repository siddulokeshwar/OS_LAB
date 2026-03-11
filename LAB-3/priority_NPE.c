#include<stdio.h>
#include<stdlib.h>

typedef struct p{
    int id,at,bt,pt,ct,tat,wt,done;
    struct p* next;
}p;

p* create(int id,int pt,int at,int bt){
    p* n = (p*)malloc(sizeof(p));
    if(!n){
        printf("\nFailed process creation!!!");
        return NULL;
    }
    n->id=id;
    n->pt=pt;
    n->at=at;
    n->bt=bt;
    n->done=0;
    n->next=NULL;
    return n;
}

p* insert(p* root,int id,int pt,int at,int bt){
    p* n=create(id,pt,at,bt);
    if(!root)
        return n;
    p* temp=root;
    while(temp->next)
        temp=temp->next;
    temp->next=n;
    return root;
}

p* computeCSum(p* root,int n){
    int time=0,completed=0;
    while(completed<n){
        p* temp=root;
        p* best=NULL;
        while(temp){
            if(!temp->done && temp->at<=time){
                if(!best || temp->pt < best->pt)
                    best=temp;
            }
            temp=temp->next;
        }
        if(!best){
            time++;
            continue;
        }
        best->ct=time+best->bt;
        time=best->ct;
        best->tat=best->ct-best->at;
        best->wt=best->tat-best->bt;
        best->done=1;
        completed++;
    }
    return root;
}

void display(p* root){
    printf("\nPID\tAT\tBT\tPT\tCT\tTAT\tWT\n");
    p* temp=root;
    while(temp){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        temp->id,temp->at,temp->bt,temp->pt,
        temp->ct,temp->tat,temp->wt);
        temp=temp->next;
    }
}

int main(){
    int n;
    printf("Enter no of process: ");
    scanf("%d",&n);
    p* root=NULL;
    printf("Enter priority arrival time burst time:\n");
    for(int i=0;i<n;i++){
        int pt,at,bt;
        scanf("%d %d %d",&pt,&at,&bt);
        root=insert(root,i+1,pt,at,bt);
    }
    root=computeCSum(root,n);
    display(root);
    return 0;
}
