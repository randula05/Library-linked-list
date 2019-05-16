#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int books;
    int sorted;
    struct node *next;
    struct node *prev;
}node;
node *start;

void func(){
    // Insertion
    start=NULL;
    int n;
    scanf("%d",&n);
    int num;
    scanf("%d",&num);
    int i,j;
    for(i=0;i<n;i++){
        node *newnode=(node *)malloc(sizeof(node));
        newnode->books=num%10;
        newnode->sorted=0;
        newnode->next=start;
        if(newnode->next)
            newnode->next->prev=newnode;
        newnode->prev=NULL;
        start=newnode;
        num=num/10;
    }
    node *ptr=start;
    node *ptr2=start;
    node *b=start;
    // Querries
    int q;
    scanf("%d",&q);
    // getchar();

    char action;
    int num2;
    for(i=0;i<q;i++){
        action=getchar();
        scanf("%d",&num2);
        getchar();

        if(action=='0'){
            // Print output
            int rank=num2%10;
            num2=num2/10;
            int end=num2%10;
            num2=num2/10;
            int beg=num2%10;

            // Sorting
            ptr=start;
            j=1;
            while(ptr){
                // printf("%d %d %d\n",beg,end,j);
                if(j<=beg || j>end || beg==end){
                    if(j==beg)
                        b=ptr;
                    ptr->sorted=ptr->books;
                }
                else if(j>beg){
                    ptr2=ptr;
                    
                    while(ptr2){
                        if(!ptr2->prev)
                            break;
                        
                        if(ptr==ptr2){
                            if(ptr2->prev->sorted<=ptr2->books){
                                ptr2->sorted=ptr2->books;
                                break;
                            }else{
                                ptr2->sorted=ptr2->prev->sorted;
                                ptr2->prev->sorted=ptr2->books;
                            }
                        }else{
                            if(ptr2==b)
                                break;
                            
                            if(ptr2->prev->sorted<=ptr2->sorted){
                                ptr2->sorted=ptr2->sorted;
                                break;
                            }else{
                                int tempint=ptr2->sorted;
                                ptr2->sorted=ptr2->prev->sorted;
                                ptr2->prev->sorted=tempint;
                            }
                        }

                        ptr2=ptr2->prev;
                    }
                }
                ptr=ptr->next;
                j++;
            }
            
            j=1;
            ptr=start;
            while(ptr){
                if(j==rank){
                    printf("%d\n",ptr->sorted);
                    break;
                }
                ptr=ptr->next;
                j++;
            }

        }else if(action='1'){
            // Update
            int replace=num2%10;
            num2=num2/10;
            int find=num2%10;

            j=1;
            ptr=start;
            while(ptr){
                if(find==j){
                    ptr->books=replace;
                    break;
                }

                ptr=ptr->next;
                j++;
            }

        }
    }
}

void main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        func();
    }
}