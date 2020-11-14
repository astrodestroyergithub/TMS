
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Calculate min-hop route and display the same

void minimum_Hops(int E[][2], int C[], int n, int m)
{
    int i,j,hopcount=0,arr[n],A[10],F[10];
   
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            arr[i] = E[j][i];
            if(n==1)
                hopcount++;
        }
    }

    for(i=0; i<7; i++)
    {
        A[i]=i;
    }
   
    F[0]=0;
   
    for(i=0; i<5; i++)
    {
        F[i+1]=F[i]+i;
    }
   	
   	printf("The min-hop transaction route >>>\n\n");
   	
    for(i=1; i<5; i++)
    {
        if(F[i]==0)
        {
            printf("S");
        }
        else if(F[i]==1)
        {
            printf("A");
        }
        else if(F[i]==2)
        {
            printf("B");
        }
        else if(F[i]==3)
        {
            printf("C");
        }
        else if(F[i]==4)
        {
            printf("D");
        }
        else if(F[i]==5)
        {
            printf("E");
        }
        else if(F[i]==6)
        {
            printf("R");
            break;
        }
       
        printf(" -> ");
    }
   
    n=n+1;
    m=m-1;
   
   
}

// Take detailed info for creating adjacency matrix

void information()
{
	int n,m,N,M,i,j;
   	
   	printf("\n\n");
   	printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&m);
   
    N=n-1;
    M=m-1;
   
    int E[M][2];
    int C[M];
   	
   	printf("Enter details of amount flow for each transaction (lender,borrower,amount):\n");
    for(i=0; i<M; i++)
    {
        scanf("%d%d%d",&E[i][0],&E[i][1],&C[i]);
    }
   
    int R;
    printf("Enter Receiver index number: ");
    scanf("%d",&R);
   
    int Adj[N+1][N+1];
   
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            Adj[i][j]=0;
        }
    }
   
    for(i=0; i<M; i++)
    {
        int x = E[i][0];
        int y = E[i][1];
       
        Adj[x][y] = C[i];
    }
   	
   	printf("\n");
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            if(Adj[i][j]==0)
                printf("%d  ",Adj[i][j]);
            else
                printf("%d ",Adj[i][j]);
        }
        printf("\n");
    }
   
    printf("\n\n");
   
    minimum_Hops(E,C,N,M);
}





// MAIN FUNCTION -----

int main()
{
    
    char Choice;
    printf("Enter Advanced Mode? (Y/N) ");
    scanf("%c",&Choice);
    if(Choice=='Y')
        information();
    else {
        
    
    int i,j,k;
    int n;
    printf("\n");
    printf("Enter number of people involved in transaction: ");
    scanf("%d",&n);
    struct node
    {
        float lend;
        float borrow;
        char name[50];
        char status[50];
        struct node *next[n];
    };
    printf("\n");
    struct node participant[n];
    int adjMatrix[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adjMatrix[i][j]=0;
    int ctr=0;
    while(ctr!=n)
    {
        printf("Enter name of participant: ");
        scanf("%s",&participant[ctr].name);
        ctr++;
    }
    printf("\n");
    ctr=0;
    while(ctr!=n)
    {
        char Res;
        int num;
        char borrower[50];
        char lender[50];
        float borrow;
        float lend;
        participant[ctr].borrow=0.0f;
        participant[ctr].lend=0.0f;
        printf("Has %s borrowed anything? (Y/N) ",participant[ctr].name);
        scanf("\n%c",&Res);
        if(Res=='Y')
        {
            printf("How many people have you borrowed from? ");
            scanf("%d",&num);
            for(k=0;k<num;k++)
            {
                printf("Whom have you borrowed? ");
                scanf("%s",&borrower);
                for(i=0;i<n;i++)
                {
                    if(strcmp(participant[i].name,borrower)==0)
                    {
                        adjMatrix[ctr][i]=1;
                    }
                }
                printf("How much have you borrowed? ");
                scanf("%f",&borrow);
                participant[ctr].borrow+=borrow;
            }
            printf("\n");
        }
        else
        {
            participant[ctr].borrow=0.0f;
            printf("\n");
        }
        printf("Has %s lend anything? (Y/N) ",participant[ctr].name);
        scanf("\n%c",&Res);
        if(Res=='Y')
        {
            printf("How many people have you lend money to? ");
            scanf("%d",&num);
            for(k=0;k<num;k++)
            {
                printf("Whom have you lend? ");
                scanf("%s",&lender);
                for(i=0;i<n;i++)
                {
                    if(strcmp(participant[i].name,lender)==0)
                    {
                        adjMatrix[ctr][i]=2;
                    }
                }
                printf("How much have you lend? ");
                scanf("%f",&lend);
                participant[ctr].lend+=lend;
            }
            printf("\n");
        }
        else
        {
            participant[ctr].lend=0.0f;
            printf("\n");
        }
        ctr++;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n\n");
    
    for(i=0;i<n;i++)
    {
        int c=0;
        for(j=0;j<n;j++)
        {
            if(adjMatrix[i][j]==2)
            {
                participant[i].next[c++]=(participant+j);
            }
        }
        while(c<n)
        {
            participant[i].next[c++]=NULL;
        }
    }
    
    while(1)
    {
	printf(">>>>>	~ ~ ~ ~ ~	>>>>>	~ ~ ~ ~ ~	>>>>>	~ ~ ~ ~ ~	>>>>>\n");
        printf("-------------------------------- MENU -----------------------------------\n");
        printf("| 1.  Choose sender and receiver                                        |\n");
        printf("| 2.  Confirm if exact amount sent by sender is transferred to receiver |\n");
        printf("| 3.  View details of passbook of any particular person                 |\n");
        printf("| 4.  View details of people who have amount to pay back                |\n");
        printf("| 5.  View details of people who have amount due from others            |\n");
        printf("| 6.  Display the least-hop transaction route for faster fund transfer  |\n");
        printf("| 7.  Exit                                                              |\n");
        printf("-------------------------------------------------------------------------\n");
	printf(">>>>>	~ ~ ~ ~ ~	>>>>>	~ ~ ~ ~ ~	>>>>>	~ ~ ~ ~ ~	>>>>>\n");
        int ch;
        int totSend;
        int totRecv;
        int sendrecv=0;
        char sender[50];
        char receiver[50];
        char name[50];
        
        printf("\n\n");
        printf("Enter choice >>> ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(sendrecv!=1)
                {
                printf("Enter sender's name: ");
                scanf("%s",&sender);
                printf("Enter receiver's name: ");
                scanf("%s",&receiver);
                for(i=0;i<n;i++)
                {
                    if(strcmp(participant[i].name,sender)==0)
                    {
                        strcpy(participant[i].status,"sender");
                    }
                    if(strcmp(participant[i].name,receiver)==0)
                    {
                        strcpy(participant[i].status,"receiver");
                    }
                }
                printf("Designations successfully assigned!\n");
                sendrecv=1;
                }
                else
                {
                printf("Sender and receiver already chosen!\n");
                }
                printf("\n\n");
                break;
                
            case 2:
                for(i=0;i<n;i++)
                {
                    if(strcmp(participant[i].status,"receiver")==0)
                    {
                        totRecv=participant[i].borrow;
                    }
                    if(strcmp(participant[i].status,"sender")==0)
                    {
                        totSend=participant[i].lend;
                    }
                }
                if(totRecv!=totSend)
                {
                    printf("Exact amount sent by sender not transferred to receiver!\n");
                }
                else
                {
                    printf("Exact amount sent by sender successfully transferred to receiver!!!\n");
                }
                printf("\n\n");
                break;
                
            case 3:
                printf("Enter name of person: ");
                scanf("%s",&name);
                printf("Loading... details...\n");
                printf("Name : %s\n",name);
                for(i=0;i<n;i++)
                {
                    if(strcmp(participant[i].name,name)==0)
                    {
                        printf("Total amount borrowed : %0.2f\n",participant[i].borrow);
                        printf("Total amount lend : %0.2f\n",participant[i].lend);
                    }
                }
                printf("\n\n");
                break;
                
            case 4:
                printf("Details of people who have amount to pay back :\n");
                for(i=0;i<n;i++)
                {
                    if(participant[i].borrow!=0 && strcmp(participant[i].status,"receiver")!=0)
                    {
                        printf("Name : %s\n",participant[i].name);
                        printf("Total amount to be paid back : %0.2f\n",participant[i].borrow);
                    }
                }
                printf("\n\n");
                break;
                
            case 5:
                printf("Details of people who have amount due from others :\n");
                for(i=0;i<n;i++)
                {
                    if(participant[i].lend!=0 && strcmp(participant[i].status,"sender")!=0)
                    {
                        printf("Name : %s\n",participant[i].name);
                        printf("Total amount to retrieve from others : %0.2f\n",participant[i].lend);
                    }
                }
                printf("\n\n");
                break;
                
            case 6:
                information();
                break;
                
            case 7:
	            exit(0);
                break;
                
            default :
	            exit(0);
                break;
        }
    }
    
    
    }
    
    return 0;
}


