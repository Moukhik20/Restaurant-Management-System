#include<stdio.h> //header files
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int s0=0,m0=0,d0=0;
int cs0=0,cm0,cd0=0;
struct starter { // creating the structure which will hold the start menu
	float price;
	char name[50];
	int ut;
	int key;
	int ckey;
	struct starter* next;
};
struct starter *heads,*tails=NULL;
void add_starter() { // function to add another starter to the menu
	float x;
	int a;
	if(s0<10) {
		struct starter *newStarter=(struct starter*)malloc(sizeof(struct starter));
		printf("Enter the name of the starter\n");
		scanf("%s",newStarter->name);
		printf("Enter the price of the starter\n");
		scanf("%f",&x);
		newStarter->price=x;
		printf("Enter the number of turns it takes to prepare\n");
		scanf("%d",&a);
		newStarter->ut=a;
		newStarter->next=NULL;
		newStarter->key=s0+1;
		newStarter->ckey=cs0+1;
		s0++;
		cs0++;
		if(heads==NULL) {
			heads=newStarter;
			tails=newStarter;
		} else {

			tails->next=newStarter;
			tails=newStarter;
		}



	} else {
		printf("The starter menu is full (At max 20 items)\n");
	}

}
void disp_starter() { // function to display the starter menu
    int i=1;
	printf("\n\nStarter Menu\n");
	struct starter *temp=heads;
	while(temp!=NULL) {
		printf("%-2d %-25s\t%-25.2f\n",temp->key,temp->name,temp->price);
		temp=temp->next;
		i++;
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
struct main_course {  //structure which will be the user defined data type to hold the details of main course menu
	float price;
	char name[50];
	int ut;
	int key;
	int ckey;
	struct main_course* next;
};
struct main_course *headm,*tailm=NULL;
void add_main() { // function which adds to the main course linked list
	float x;
	int a;
	if(m0<20) {
		struct main_course *newMain=(struct main_course*)malloc(sizeof(struct main_course));
		printf("Enter the name of the main course\n");
		scanf("%s",newMain->name);
		printf("Enter the price of the main course\n");
		scanf("%f",&x);
		newMain->price=x;
		printf("Enter the number of turns it takes to prepare\n");
		scanf("%d",&a);
		newMain->ut=a;
		newMain->next=NULL;
		newMain->key=m0+1;
		newMain->ckey=cm0+1;
		m0++;
		cm0++;
		if(headm==NULL) {
			headm=newMain;
			tailm=newMain;
		} else {

			tailm->next=newMain;
			tailm=newMain;
		}



	}
	else
    {
		printf("The main course menu is full (At max 20 items)\n");
	}

}


void disp_main() { // function to display the main course menu
    int i=1;
	printf("\n\nMain Course Menu\n(Prices to the right of the item)\n");
	struct main_course *temp=headm;
	while(temp!=NULL) {
		printf("%-2d %-25s%-25.2f\n",temp->key,temp->name,temp->price);
		temp=temp->next;
		i++;
	}

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct dessert { // structure which will hold details of dessrets
	float price;
	char name[50];
	int ut;
	int key;
	int ckey;
	struct dessert* next;
};
struct dessert *headd,*taild=NULL;
void add_dessert() { // function to add a dessert to the dessert menu
	float x;
	int a;
	if(d0<20) {
		struct dessert *newDessert=(struct dessert*)malloc(sizeof(struct dessert));
		printf("Enter the name of the dessert\n");
		scanf("%s",newDessert->name);
		printf("Enter the price of the dessert\n");
		scanf("%f",&x);
		newDessert->price=x;
		printf("Enter the number of turns it takes to prepare\n");
		scanf("%d",&a);
		newDessert->ut=a;
		newDessert->next=NULL;
		newDessert->key=d0+1;
		newDessert->ckey=cd0+1;
		d0++;
		cd0++;
		if(headd==NULL)
        {
			headd=newDessert;
			taild=newDessert;
		}
		else
		{

			taild->next=newDessert;
			taild=newDessert;
		}



	}
	else
    {
		printf("The dessert menu is full (At max 20 items)\n");
	}

}


void disp_dessert() { // function to display the dessert menu
	printf("\n\nDessert Menu\n(Prices to the right of the item)\n");
	struct dessert *temp=headd;
	while(temp!=NULL) {
		printf("%-2d %-25s%-25.2f\n",temp->key,temp->name,temp->price);
		temp=temp->next;
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void del_starter(int pos) // function to delete a starter from starter menu
{
    struct starter *temp=heads;
    struct starter *temp2=NULL,*del=NULL;
    int i=1;
    if(heads==NULL)
    {
        printf("Starter Menu is empty\n");
    }
    else
    {
    if(pos==1)
    {
        temp=heads;
        heads=heads->next;
        free(temp);
        s0--;

    }
    else
    {


        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;

        }
        temp2=temp->next->next;
        del=temp->next;
        temp->next=temp2;
        free(del);
        s0--;


    }
    }
    temp=heads;
    i=1;
    while(temp!=NULL)
    {
        temp->key=i;
        i++;
        temp=temp->next;
    }
}

void del_main(int pos) // function to delete an item from main course linked list
{
    struct main_course *temp=headm;
    struct main_course *temp2=NULL,*del=NULL;
    int i=1;
    if(headm==NULL)
    {
        printf("Main Course Menu is empty\n");
    }
    else
    {
    if(pos==1)
    {
        temp=headm;
        headm=headm->next;
        free(temp);
        m0--;

    }
    else
    {


        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;

        }
        temp2=temp->next->next;
        del=temp->next;
        temp->next=temp2;
        free(del);
        m0--;


    }
    }
    temp=headm;
    i=1;
    while(temp!=NULL)
    {
        temp->key=i;
        i++;
        temp=temp->next;
    }
}
void del_dessert(int pos) // function to delete an item from the dessert linked list
{
    struct dessert *temp=headd;
    struct dessert *temp2=NULL,*del=NULL;
    int i=1;
    if(headd==NULL)
    {
        printf("Dessert Menu is empty\n");
    }
    else
    {
    if(pos==1)
    {
        temp=headd;
        headd=headd->next;
        free(temp);
        d0--;

    }
    else
    {


        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;

        }
        temp2=temp->next->next;
        del=temp->next;
        temp->next=temp2;
        free(del);
        d0--;


    }
    }
    temp=headd;
    i=1;
    while(temp!=NULL)
    {
        temp->key=i;
        i++;
        temp=temp->next;
    }
}
//----------------------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////order stack area//////////////////


struct item_stack // item_stack is the structure that will hold the details of all the food items that are being prepared in the respective kitchens
{
    char name[100];
    int tid;
    int turns;
};
struct item_stack start[100]; // stack of struct item_stack type which will hold the details of all starters currently being prepared in the kitchen
int sttop=-1; // top variable
struct item_stack mcr[100];  // stack of struct item_stack type which will hold the details of all main course currently being prepared in the kitchen
int mctop=-1; // top variable
struct item_stack dess[100]; // stack of struct item_stack type which will hold the details of all desserts currently being prepared in the kitchen
int dtop=-1; // top variable
void starter_list_add(int cy,int table_id,int turn) // push function to add an item to the start stack
{
    struct starter *temp=heads;
    if(sttop==99)
    {
        printf("No more starters can be prepared at the moment\n");
    }
    else
    {
        sttop++;
        while(1)
        {
            if(temp->ckey==cy)
            {
                break;
            }
            else
            {
                temp=temp->next;
            }
        }

        strcpy(start[sttop].name,temp->name);
        start[sttop].tid=table_id;
        start[sttop].turns=turn;

    }
}
void starter_pop() // pop function of the stack which pops the items which have been prepared in the kitchen
{
    printf("\nStarters served this turn\n\n");
    int top=sttop;
    for(;top>=0;top--)
    {
        if(start[top].turns==0)
        {
            printf("%s has been served to table %d\n",start[top].name,(start[top].tid+1));
            sttop--;
        }
        else
        {
            break;
        }
    }
}

void quicksort_starter(struct item_stack start[100],int first,int last) // quicksort used to sort the items in the stack to make it easier to pop the items which have been prepared
{
   int i, j, pivot, t_turns ,t_tid;
   char temp_name[100];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(start[i].turns>=start[pivot].turns&&i<last)
            i++;
         while(start[j].turns<start[pivot].turns)
            j--;
         if(i<j){
            t_turns=start[i].turns;
            start[i].turns=start[j].turns;
            start[j].turns=t_turns;
            t_tid=start[i].tid;
            start[i].tid=start[j].tid;
            start[j].tid=t_tid;
            strcpy(temp_name,start[i].name);
            strcpy(start[i].name,start[j].name);
            strcpy(start[j].name,temp_name);
         }
      }

      t_turns=start[pivot].turns;
      start[pivot].turns=start[j].turns;
      start[j].turns=t_turns;
      t_tid=start[pivot].tid;
      start[pivot].tid=start[j].tid;
      start[j].tid=t_tid;
      strcpy(temp_name,start[pivot].name);
      strcpy(start[pivot].name,start[j].name);
      strcpy(start[j].name,temp_name);
      quicksort_starter(start,first,j-1);
      quicksort_starter(start,j+1,last);

   }
}
void view_starter() // function to view the starters being prepared in the kitchen in ascending order of turns left to prepare
{
    quicksort_starter(start,0,sttop);
    int i=0;
    printf("Starters being prepared\n\n");
    for(i=sttop;i>=0;i--)
    {
        printf("Item: %-25s     Table: %-25d     Turns Left: %-25d\n",start[i].name,(start[i].tid+1),start[i].turns);
    }
}


void mc_list_add(int cy,int table_id,int turn)  // push function to add an item to the mcr stack
{
    struct main_course *temp=headm;
    if(mctop==99)
    {
        printf("No more main course dishes can be prepared at the moment\n");
    }
    else
    {
        mctop++;
        while(1)
        {
            if(temp->ckey==cy)
            {

                break;
            }
            else
            {
                temp=temp->next;
            }
        }
        strcpy(mcr[mctop].name,temp->name);
        mcr[mctop].tid=table_id;
        mcr[mctop].turns=turn;

    }
}
void main_pop() // pop function of the stack which pops the items which have been prepared in the kitchen
{
    printf("\nMain course served this turn\n\n");
    int top=mctop;
    for(;top>=0;top--)
    {
        if(mcr[top].turns==0)
        {
            printf("%s has been served to table %d\n",mcr[top].name,(mcr[top].tid+1));
            mctop--;
        }
        else
        {
            break;
        }
    }
}
void quicksort_mc(struct item_stack mcr[100],int first,int last) // quicksort used to sort the items in the stack to make it easier to pop the items which have been prepared
{
   int i, j, pivot, t_turns ,t_tid;
   char temp_name[100];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(mcr[i].turns>=mcr[pivot].turns&&i<last)
            i++;
         while(mcr[j].turns<mcr[pivot].turns)
            j--;
         if(i<j){
            t_turns=mcr[i].turns;
            mcr[i].turns=mcr[j].turns;
            mcr[j].turns=t_turns;
            t_tid=mcr[i].tid;
            mcr[i].tid=mcr[j].tid;
            mcr[j].tid=t_tid;
            strcpy(temp_name,mcr[i].name);
            strcpy(mcr[i].name,mcr[j].name);
            strcpy(mcr[j].name,temp_name);
         }
      }

      t_turns=mcr[pivot].turns;
      mcr[pivot].turns=mcr[j].turns;
      mcr[j].turns=t_turns;
      t_tid=mcr[pivot].tid;
      mcr[pivot].tid=mcr[j].tid;
      mcr[j].tid=t_tid;
      strcpy(temp_name,mcr[pivot].name);
      strcpy(mcr[pivot].name,mcr[j].name);
      strcpy(mcr[j].name,temp_name);
      quicksort_mc(mcr,first,j-1);
      quicksort_mc(mcr,j+1,last);

   }
}

void view_maincourse()  // function to view the main course items being prepared in the kitchen in ascending order of turns left to prepare
{
    quicksort_mc(mcr,0,mctop);
    int i=0;
    printf("Main Course being prepared\n\n");
    for(i=mctop;i>=0;i--)
    {
        printf("Item: %-25s     Table: %-25d     Turns Left: %-25d\n",mcr[i].name,(mcr[i].tid+1),mcr[i].turns);
    }
}
void dessert_list_add(int cy,int table_id,int turn) // push function to add an item to the dess stack
{
    struct dessert *temp=headd;
    if(dtop==99)
    {
        printf("No more desserts can be prepared at the moment\n");
    }
    else
    {
        dtop++;
        while(1)
        {
            if(temp->ckey==cy)
            {

                break;
            }
            else
            {
                temp=temp->next;
            }
        }
        strcpy(dess[dtop].name,temp->name);
        dess[dtop].tid=table_id;
        dess[dtop].turns=turn;
    }
}
void dessert_pop() // pop function of the stack which pops the items which have been prepared in the kitchen
{
    printf("\nDesserts served this turn\n\n");
    int top=dtop;
    for(;top>=0;top--)
    {
        if(dess[top].turns==0)
        {
            printf("%s has been served to table %d\n",dess[top].name,(dess[top].tid+1));
            dtop--;
        }
        else
        {
            break;
        }
    }
}
void quicksort_dessert(struct item_stack dess[100],int first,int last) // function to view the main course items being prepared in the kitchen in ascending order of turns left to prepare
{
   int i, j, pivot, t_turns ,t_tid;
   char temp_name[100];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(dess[i].turns>=dess[pivot].turns&&i<last)
            i++;
         while(dess[j].turns<dess[pivot].turns)
            j--;
         if(i<j){
            t_turns=dess[i].turns;
            dess[i].turns=dess[j].turns;
            dess[j].turns=t_turns;
            t_tid=dess[i].tid;
            dess[i].tid=dess[j].tid;
            dess[j].tid=t_tid;
            strcpy(temp_name,dess[i].name);
            strcpy(dess[i].name,dess[j].name);
            strcpy(dess[j].name,temp_name);
         }
      }

      t_turns=dess[pivot].turns;
      dess[pivot].turns=dess[j].turns;
      dess[j].turns=t_turns;
      t_tid=dess[pivot].tid;
      dess[pivot].tid=dess[j].tid;
      dess[j].tid=t_tid;
      strcpy(temp_name,dess[pivot].name);
      strcpy(dess[pivot].name,dess[j].name);
      strcpy(dess[j].name,temp_name);
      quicksort_dessert(dess,first,j-1);
      quicksort_dessert(dess,j+1,last);

   }
}

void view_dessert() // function to view the main course items being prepared in the kitchen in ascending order of turns left to prepare
{
    quicksort_dessert(dess,0,dtop);
    int i=0;
    printf("Desserts being prepared\n\n");
    for(i=dtop;i>=0;i--)
    {
        printf("Item: %-25s     Table: %-25d     Turns Left: %-25d",dess[i].name,(dess[i].tid+1,dess[i]).turns);
    }
}

void decrement() // function which decrements turns left by 1 after selecting the end turn option
{
    int i=0;
    for(i=0;i<=sttop;i++)
    {
        start[i].turns--;
    }
    for(i=0;i<=mctop;i++)
    {
        mcr[i].turns--;
    }
    for(i=0;i<=dtop;i++)
    {
        dess[i].turns--;
    }

}


//////////////////////////////////////////////////////
/////////////////////////////////////////////////////

struct customer // structure which stores the details of the customer
{
    char name[100];
    int phone;
    struct bill
    {
        char name_item[100];
        float price;
    };
    struct bill bill_cust[100]; // nested structures which contains the bill of the customer
    int avail;
};
struct customer table[20]; // array of struct customer type which shows the tables available at the restaurant
void initial() // intialize function
{
    int i=0;
    for(i=0;i<20;i++)
    {
        table[i].phone=0;
        table[i].avail=0;
        int j=0;
        for(j=0;j<100;j++)
        {
            table[i].bill_cust[j].price=-1;
        }
    }
}
void create_customer(int table_id) // function which creates customer
{
    printf("Enter the name of the customer\n");
    scanf("%s",table[table_id].name);
    printf("Enter the phone number of the customer\n");
    scanf("%d",&table[table_id].phone);
    table[table_id].avail=1;

}
void del_customer(int table_id) // function which resets the table availability
{
    table[table_id].avail=0;
}
int check_freetable() // function which checks the availabilty of tables and assigns a table to a customer if available (hashmap)
{
    int i=0,f=0;
    for(i=0;i<20;i++)
    {
        if(table[i].avail==0)
        {
            return i;
        }
    }
        if(f==0)
        {
            return 21;
        }
}
void display_customers() // function which displays the customers currently at the restaurant
{
    int i=0;
    printf("\nThe customers along with their table numbers are displayed\n\n");
    for(i=0;i<20;i++)
    {
        if(table[i].avail==1)
        {
            printf("%d.%s\n",(i+1),table[i].name);
        }
    }
}
////////////////////////////////////////
////////////////////////////////////////


void select_starter(int key) // function for a customer to select an item from starter menu
{
    struct starter *temp=heads;
    int ch,re,i,cust=key;
    do
    {
        printf("Please place your order from the above starter menu\n");
        scanf("%d",&ch);
        for(i=1;i<ch;i++)
        {
            temp=temp->next;
        }
        starter_list_add(temp->ckey,cust,temp->ut);
        int x=0;
        while(table[cust].bill_cust[x].price!=-1) //to add items to bill
        {
            x++;
        }
        table[cust].bill_cust[x].price=temp->price;
        strcpy(table[cust].bill_cust[x].name_item,temp->name);
        printf("Do you want to place another starter order?  (Please enter 1 for yes and 0 for no)\n");
        scanf("%d",&re);
        temp=heads;

    }while(re==1);

}
void select_main(int key) // function for a customer to select an item from main course menu
{
    struct main_course *temp=headm;
    int ch,re,i,cust=key;
    do
    {
        printf("Please place your order from the above main course menu\n");
        scanf("%d",&ch);
        for(i=1;i<ch;i++)
        {
            temp=temp->next;
        }
        mc_list_add(temp->ckey,cust,temp->ut);
                int x=0;
        while(table[cust].bill_cust[x].price!=-1) //to add items to bill
        {
            x++;
        }
        table[cust].bill_cust[x].price=temp->price;
        strcpy(table[cust].bill_cust[x].name_item,temp->name);
        printf("Do you want to place another main course order?  (Please enter 1 for yes and 0 for no)\n");
        scanf("%d",&re);
        temp=headm;

    }while(re==1);

}
void select_dessert(int key) // function for a customer to select an item from dessert menu
{
    struct dessert *temp=headd;
    int ch,re,i,cust=key;
    do
    {
        printf("Please place your order from the above dessert menu\n");
        scanf("%d",&ch);
        for(i=1;i<ch;i++)
        {
            temp=temp->next;
        }
        dessert_list_add(temp->ckey,cust,temp->ut);
                int x=0;
        while(table[cust].bill_cust[x].price!=-1) //to add items to bill
        {
            x++;
        }
        table[cust].bill_cust[x].price=temp->price;
        strcpy(table[cust].bill_cust[x].name_item,temp->name);
        printf("Do you want to place another dessert order?   (Please enter 1 for yes and 0 for no)\n");
        scanf("%d",&re);
        temp=headd;

    }while(re==1);

}
void place_order(int table_id) // overview menu for a customer to place an order
{
    int ch,key=table_id;
    do
    {
        printf("\nSelect which menu you want to order from\n1. Starter Menu\n2. Main Course Menu\n3. Dessert Menu\n4. Exit\nPlease enter the required number\n\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                disp_starter();
                select_starter(key);
                break;
            case 2:
                disp_main();
                select_main(key);
                break;
            case 3:
                disp_dessert();
                select_dessert(key);
                break;
            case 4:
                break;
            default:
                printf("Please enter a valid choice\n");

        }

    }while(ch!=4);
}
///////////////////////////////////////////////////////////////////////////////////
void generate_bill(int table_id) // function which generates a bill for a customer depending on key value (table_id)
{
    float sum=0,gst=0,total=0;
    int i=0;
    printf("\nName: %s\nPhone No: %d\n\n",table[table_id].name,table[table_id].phone);
    printf("%-25s   %-25s\n\n","Item","Price");
    for(i=0;i<=100;i++)
    {
        if(table[table_id].bill_cust[i].price<0)
        {
            break;
        }
        else
        {
            sum+=table[table_id].bill_cust[i].price;
        }



    }
    gst=0.18*sum;
    total=sum+gst;

    for(i=0;i<=100;i++)
    {
        if(table[table_id].bill_cust[i].price!=-1)
        {
            printf("%-25s   %-25.2f\n",table[table_id].bill_cust[i].name_item,table[table_id].bill_cust[i].price);

        }
        else
        {
            break;
        }

    }

    printf("\nTotal:  %.2f\nGST(18%):%.2f\nGrand Total: %.2f\n",sum,gst,total);
    printf("Thank You for visiting\nHope you have a great day\n\n");
}
/////renew a bill at particular table
void renew_bill(int table_id) // function to renew the particular table for another customer
{
    int i=0;
    for(i=0;i<100;i++)
    {
        table[table_id].bill_cust[i].price=-1;
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////

void customer_menu() // overview menu for customer options
{
    printf("\nWelcome to the customer menu\n");
    int ch;

    do{
        printf("\n1.Add a customer\n2.Let a customer leave the restaurant\n3.Place Order\n4.End turn\n5.Go to previous menu\n\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
                display_customers();
                int i=0;
                int table_id=check_freetable();
                if(table_id==21)
                {
                    printf("There are no free tables\n");
                }
                else
                {
                    create_customer(table_id);
                }
                break;
        case 2:
                display_customers();
                int j=0,f=0;
                do
                {


                printf("Select the customer who wants to leave\n");
                scanf("%d",&j);
                if(table[j-1].avail==1)
                {
                    generate_bill(j-1);
                    renew_bill(j-1);
                    del_customer(j-1);
                    f=1;
                }
                else
                {
                   printf("Table is empty\n");
                }
                }while(f!=1);
                break;
        case 3:
                display_customers();
                int k=0,g=0;
                do
                {
                printf("Select the customer who wants to place an order\n");
                scanf("%d",&k);


                if(table[k-1].avail==1)
                {
                    place_order(k-1);
                    g=1;
                }
                else
                {
                   printf("Table is empty\n");
                }
                }while(g!=1);
                break;
        case 4:
                printf("\nTurn Ending\n");
                quicksort_starter(start,0,sttop);
                quicksort_mc(mcr,0,mctop);
                quicksort_dessert(dess,0,dtop);
                starter_pop();
                main_pop();
                dessert_pop();
                decrement();
                break;
        case 5:
                break;
        default:
                printf("Enter a valid choice\n");


        }
    }while(ch!=5);



}
/////////////////////////////////////////////////////////////////////
void view_kitchen() //menu for kitchen orders viewing
{
    int ch;
    do
    {
        printf("\n1.Starter Kitchen Preparations\n2.Main Course Kitchen Preparations\n3.Dessert Kitchen Preparations\n4.End turn\n5.Go to previous menu\n\n\n");
        printf("Choose the option\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            view_starter();
            break;
        case 2:
            view_maincourse();
            break;
        case 3:
            view_dessert();
            break;
        case 4:
            printf("\nTurn Ending\n");
            quicksort_starter(start,0,sttop);
            quicksort_mc(mcr,0,mctop);
            quicksort_dessert(dess,0,dtop);
            starter_pop();
            main_pop();
            dessert_pop();
            decrement();
            break;
        case 5:
            break;
        default:
            printf("Please enter a valid choice\n");

        }

    }while(ch!=5);
}
void manager_menu() // manager overview and options
{
    int ch,ch2,ch3,ch4,a,b,c;
    do
    {
        printf("\n1.Modify Menu\n2.View Menu\n3.View Customers\n4.Kitchen Queues\n5.End turn\n6.Return to previous menu\n\n\n");
        printf("Please enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            do
            {
                printf("\n1.Add to Menu\n2.Delete from Menu\n3.Go to previous menu\n\n\n");
                printf("Please enter your choice\n");
                scanf("%d",&ch2);
                switch(ch2)
                {
                case 1:
                    do
                    {
                        printf("\n1.Add to starter menu\n2.Add to main course menu\n3.Add to dessert menu\n4.Go to previous menu\n\n\n");
                        printf("Please enter your choice\n");
                        scanf("%d",&ch3);
                        switch(ch3)
                        {
                        case 1:
                            add_starter();
                            break;
                        case 2:
                            add_main();
                            break;
                        case 3:
                            add_dessert();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Please enter a valid choice\n");
                        }

                    }while(ch3!=4);
                    break;
                case 2:
                    do
                    {
                        printf("\n1.Delete from starter menu\n2.Delete from main course menu\n3.Delete from dessert menu\n4.Go to previus menu\n\n\n");
                        printf("Please enter your choice\n");
                        scanf("%d",&ch4);
                        switch(ch4)
                        {
                        case 1:
                            disp_starter();
                            printf("Enter the index of starter to delete\n");
                            scanf("%d",&a);
                            del_starter(a);
                            break;
                        case 2:
                            printf("Enter the index of main course to delete\n");
                            scanf("%d",&b);
                            del_main(b);
                            break;
                        case 3:
                            printf("Enter the index of dessert to delete\n");
                            scanf("%d",&c);
                            del_dessert(c);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Please enter a valid choice\n");
                        }

                    }while(ch4!=4);
                    break;
                case 3:
                    break;
                default:
                    printf("Please enter a valid choice\n");


                }

            }while(ch2!=3);
            break;
        case 2:
            disp_starter();
            disp_main();
            disp_dessert();
            break;
        case 3:
            display_customers();
            break;
        case 4:
            view_kitchen();
            break;
        case 5:
            printf("\nTurn Ending\n");
            quicksort_starter(start,0,sttop);
            starter_pop();
            main_pop();
            dessert_pop();
            decrement();
            break;
        case 6:
            break;
        default:
            printf("Please enter a valid choice\n");

        }
    }while(ch!=6);
}

/////////////////////////////////////////////////////////////////////
void menu() // main menu of the program
{
    printf("Hello\nWelcome to ABC restaurant\n");
    initial();
    int ch,ch2,ch3,ch4,a,b,c;
    do{
        printf("\n1.Create or modify menu\n2.Customers\n3.Restaurant Management\n4.End Turn\n5.Exit\n\n\n");
        printf("Please choose the section you want to go to\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            do
            {
                printf("\n1.Add to Menu\n2.Delete from Menu\n3.Go to previous menu\n\n\n");
                printf("Please enter your choice\n");
                scanf("%d",&ch2);
                switch(ch2)
                {
                case 1:
                    do
                    {
                        printf("\n1.Add to starter menu\n2.Add to main course menu\n3.Add to dessert menu\n4.Go to previous menu\n\n\n");
                        printf("Please enter your choice\n");
                        scanf("%d",&ch3);
                        switch(ch3)
                        {
                        case 1:
                            add_starter();
                            break;
                        case 2:
                            add_main();
                            break;
                        case 3:
                            add_dessert();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Please enter a valid choice\n");
                        }

                    }while(ch3!=4);
                    break;
                case 2:
                    do
                    {
                        printf("\n1.Delete from starter menu\n2.Delete from main course menu\n3.Delete from dessert menu\n4.Go to previus menu\n\n\n");
                        printf("Please enter your choice\n");
                        scanf("%d",&ch4);
                        switch(ch4)
                        {
                        case 1:
                            disp_starter();
                            printf("Enter the index of starter to delete\n");
                            scanf("%d",&a);
                            del_starter(a);
                            break;
                        case 2:
                            printf("Enter the index of main course to delete\n");
                            scanf("%d",&b);
                            del_main(b);
                            break;
                        case 3:
                            printf("Enter the index of dessert to delete\n");
                            scanf("%d",&c);
                            del_dessert(c);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Please enter a valid choice\n");
                        }

                    }while(ch4!=4);
                    break;
                case 3:
                    break;
                default:
                    printf("Please enter a valid choice\n");


                }

            }while(ch2!=3);
            break;


        case 2:
            customer_menu();
            break;
        case 3:
            manager_menu();
            break;
        case 4:
            printf("\nTurn Ending\n");
            quicksort_starter(start,0,sttop);
            starter_pop();
            main_pop();
            dessert_pop();
            decrement();
            break;
        case 5:
            break;
        default:
            printf("Please enter a valid choice\n\n");
        }
    }while(ch!=5);


}

void main() // main function
{
    menu();
}
//end


