#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define INF 9999

typedef struct Debtor
{
    char D_name[30];
    int amount;
    float total_amount;

}D;

typedef struct Agent
{
    char A_name[30];
    char User_ID[20];
    int password;
    float total_cash;
    struct Agent *next;
}A;

typedef struct Agent1
{
    char A_name[30];
    char User_ID[20];
    int password;
    float total_cash;
}A1;

void floyed(int n,int CO[15][15])
{
    int i,j,k;
   printf("The supplied input is\n");
     for(i = 0; i <n; i++){
        for(j = 0; j<n; j++){
            printf("%d\t", CO[i][j]);
        }
        printf("\n");
    }


    for(k = 0; k <n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if((CO[i][k] + CO[k][j]) < CO[i][j])
                    CO[i][j] = CO[i][k] + CO[k][j];
            }
        }
    }

    printf("All pair shortest paths:\n");
    for(i = 0; i <n; i++)
    {
        for(j = 0; j< n; j++)
        {
            printf("%d\t" , CO[i][j]) ;
        }
        printf("\n");}
   }

A* getnode()
{
    A *l;
    l=(A*)malloc(sizeof(A));
    l->User_ID[0]='\0';
    l->password=0;
    l->A_name[0]='\0';
    l->total_cash=0;
    l->next=NULL;
    return l;
}

void insert_at_the_end (A **H,char Tname[30],char Tuserid[30],int Tpassword)
{
    A *temp,*newnode,*p=*H;
    newnode=getnode();
    newnode->password=Tpassword;
    strcpy(newnode->A_name,Tname);
    strcpy(newnode->User_ID,Tuserid);
    if(*H==NULL)
    {
        *H=newnode;

    }
    else
    {
        temp=*H;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=newnode;
    }

}

void Hash_data(A **H[10],A1 Z[15])
{
    int k,i;
    for(k=0;k<15;k++)
    {
        i=Z[k].password%10;
        insert_at_the_end(H[i],Z[k].A_name,Z[k].User_ID,Z[k].password);
    }
}



bool Find_hash(A **H,char user[20],int pass)
{
    A *temp;
    int i;
    bool b;
    b=false;
    i=pass%10;
    temp=*(H+i);
    while(temp!=NULL)
    {
        if(temp->password==pass)
        {
            b=true;
            break;
        }
        temp=temp->next;

    }
    if(b)
    {
        if(strcmp(temp->User_ID,user)==0)
        {
            b=true;
        }
        else
        {
            b=false;
        }
    }
    return b;
}

int main() {
    int i,j,k,l;


    //insert agent details
    A1 Z[15] = {
    {"Rahul", "rahul1", 1234, 0},
    {"Priya", "priya2", 5678, 0},
    {"Anjali", "anjali_3", 9012, 0},
    {"Karan", "karan4", 3456, 0},
    {"Sneha", "sneha5", 7890, 0},
    {"Rajesh", "rajesh_6", 2345, 0},
    {"Amit", "amit7", 6789, 0},
    {"Manisha", "manisha8", 1534, 0},
    {"Pranav", "pranav_9", 5178, 0},
    {"Radhika", "radhika10", 9312, 0},
    {"Vivek", "vivek11", 3756, 0},
    {"Smita", "smita12", 7790, 0},
    {"Arjun", "arjun13", 2645, 0},
    {"Neha", "neha14", 6709, 0},
    {"Amitabh", "amitabh15", 1230, 0}};


    for(int i=0;i<15;i++)
    {
        printf("%s %s %d\n",Z[i].A_name,Z[i].User_ID,Z[i].password);
    }
    //create hash table
    A *H[10]={NULL};
    Hash_data(&H,Z);


    //insert debtor detials
    // Initialize C1 array
    D C1[15] = {
        {"Ravi", 10000, 0},
        {"Priya", 5000, 0},
        {"Amit", 7500, 0},
        {"Sneha", 15000, 0},
        {"Vikram", 20000, 0},
        {"Kavita", 3000, 0},
        {"Anjali", 12000, 0},
        {"Raj", 8000, 0},
        {"Neha", 25000, 0},
        {"Arun", 7000, 0},
        {"Aisha", 18000, 0},
        {"Sanjay", 9000, 0},
        {"Mayank", 6000, 0},
        {"Pooja", 11000, 0},
        {"Siddharth", 4000, 0},
    };

    // Initialize C2 array
    D C2[13] = {
        {"Gaurav", 12000, 0},
        {"Nisha", 8000, 0},
        {"Rahul", 15000, 0},
        {"Smita", 10000, 0},
        {"Aakash", 9000, 0},
        {"Anita", 4000, 0},
        {"Deepak", 6000, 0},
        {"Shikha", 20000, 0},
        {"Hitesh", 13000, 0},
        {"Nehal", 3000, 0},
        {"Mukesh", 18000, 0},
        {"Tanvi", 7000, 0},
        {"Divya", 5000, 0},
    };

    // Initialize C3 array
        D C3[10] = {
        {"Shashi", 14000, 0},
        {"Ritu", 11000, 0},
        {"Vineet", 8000, 0},
        {"Shivani", 6000, 0},
        {"Saurabh", 12000, 0},
        {"Komal", 9000, 0},
        {"Ajay", 100000,0},
        {"Mayank",50000,0},
        {"Virat",70000,0},
        {"Sheldon", 40000,0}};

        D C4[14]= {
                   {"Rohan",8000,0},
                   {"Rohini",5000,0},
                   {"Ramu",4000,0},
                   {"varun",9000,0},
                   {"kumar",5000,0},
                   {"Amith",9700,0},
                   {"Singham",6000,0},
                   {"Kavya",2000,0},
                   {"Omshree",6050,0},
                   {"Raone",9800,0},
                   {"Sidharnth",4800,0},
                   {"Raghani",6900,0},
                   {"Raghav",1000,0},
                   {"Raksha",1000,0}

                   };
    //insert adjacency matrices



        int CO1[15][15]={{0,1,0,10,4,0,0,0,0,2,0,0,0,0,0},
                    {1,0,7,9,0,0,0,0,0,0,3,1,0,0,0},
                    {0,7,0,3,0,0,0,5,0,0,0,0,4,4,0},
                    {10,9,3,0,0,0,0,0,0,0,0,0,0,0,0},
                    {4,0,0,0,0,3,0,0,0,0,0,0,0,0,1},
                    {0,0,0,0,3,0,5,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,5,0,0,3,0,0,0,0,0,0},
                    {0,0,5,0,0,0,0,0,0,0,0,6,0,0,0},
                    {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0},
                    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,1,0,0,0,0,0,6,0,0,0,0,0,0,0},
                    {0,0,4,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,4,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}};

        int CO2[13][13] = {{0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                     {3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 5, 0, 7, 0, 0, 0, 0, 0, 8, 0, 0, 0},
                     {0, 0, 7, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 4, 0, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 2, 0, 6, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 8, 0, 9, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 9, 0, 2, 0, 0, 0},
                     {0, 0, 8, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 3},
                     {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0}};

        int CO3[10][10] = {{0, 2, 0, 6, 0, 0, 0, 0, 0, 0},
                            {2, 0, 3, 8, 5, 0, 0, 0, 0, 0},
                            {0, 3, 0, 0, 7, 0, 0, 0, 0, 0},
                            {6, 8, 0, 0, 9, 4, 0, 0, 0, 0},
                            {0, 5, 7, 9, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 4, 0, 0, 5, 3, 0, 0},
                            {0, 0, 0, 0, 0, 5, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0, 3, 0, 0, 0, 6},
                            {0, 0, 0, 0, 0, 0, 2, 0, 0, 4},
                            {0, 0, 0, 0, 0, 0, 0, 6, 4, 0}};

        int CO4[14][14]={
                    {0,3,0,0,4,0,0,0,0,0,0,0,0,0},
                    {3,0,5,2,6,0,0,0,0,0,0,0,0,0},
                    {0,5,0,2,0,0,0,0,0,0,0,0,0,0},
                    {0,2,2,0,5,0,4,0,0,0,0,0,0,0},
                    {4,6,0,5,0,9,0,0,0,0,0,0,0,0},
                    {0,0,0,0,9,0,0,0,0,0,12,14,6,0},
                    {0,0,0,4,0,0,0,2,6,0,0,0,0,0},
                    {0,0,0,4,0,0,0,2,6,0,0,0,0,0},
                    {0,0,0,0,0,0,2,0,0,0,0,0,0,0},
                    {0,0,0,3,0,0,6,0,0,7,0,0,0,9},
                    {0,0,0,0,0,0,0,0,7,0,4,0,0,0},
                    {0,0,0,0,0,12,0,0,0,4,0,0,0,0},
                    {0,0,0,0,0,14,0,0,0,0,0,0,6,0},
                    {0,0,0,0,0,6,0,0,0,0,0,6,0,4},
                    {0,0,0,0,0,0,0,0,9,0,0,0,4,0}};


        int CO6[4][4]={
            {0,5,99,99},
            {99,0,3,99},
            {99,99,0,4},
            {1,8,99,0}

          };

    //login
    char user[20];
    int pass;
    bool a;
    while(true)
    {
        printf("Enter your UserID:\n");
        scanf("%s",user);
        printf("Enter password:\n");
        scanf("%d",&pass);
        a=Find_hash(&H,user,pass);
        if(a)
        {
            printf("\nLOGIN SUCCESSFUL!\n");
            //two pointer algorithm

                printf("\n WHICH COLONY WOULD YOU LIKE TO SELECT\n");
                int c,n;
                printf("1->Colony1\n2->Colony2\n3->Colony3\nColony4\n");
                 scanf("%d",&c);
                 switch(c)
                 {
                    case 1: n=15;
                         floyed(n,CO1);
                          break;

                    case 2: n=4;
                                             floyed(n,CO6);
                                             break;
                    case 3: n=10;
                                             floyed(n,CO3);
                                             break;
                    case 4: n=14;
                                             floyed(n,CO4);
                                             break;
                 }




            //dijkstras algorithm



            //avl trees

        }
        else{
            printf("\nINVALID LOGIN.\nTRY AGAIN!\n");
        }
    }

return 0;
}