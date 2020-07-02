//tasks for everyone so everyone gets equal balance of workload and logic
//shreya logic for updating bill function. *check last few lines of main method to get an idea of how we are going to generate bill at the end*
//sharvari linked list sorting code & after everyone's codes are done, please combine everyone's code together to create one complete project
//divya complete all main method fill in the blanks

#include<iostream>
using namespace std;
class item
{
	friend class menu;
	int spiceLevel;
	int itemNo;
	int price;
	string name;
	item *next;

public:
	item(string n,int sl,int p,int i)
{
		name=n;
		spiceLevel=sl;
		itemNo=i;
		next=NULL;
		price=p;
}
};

class menu
{
public:

	double bill;
	item* head;
	menu()
	{
		head=NULL;
		bill =0.0;
	}
	void swape(item *node1,item *node2)
	{
		int sl,i_no,p;
		string nm;
		sl=node1->spiceLevel;
		node1->spiceLevel=node2->spiceLevel;
		node2->spiceLevel=sl;
		
		i_no=node1->itemNo;
		node1->itemNo=node2->itemNo;
		node2->itemNo=i_no;
		
		p=node1->price;
		node1->price=node2->price;
		node2->price=p;
		
		nm=node1->name;
		node1->name=node2->name;
		node2->name=nm;
		
	}
	void sort()
	{
		//sharvari
		//sort logic for least to most spicy food items(ascending order on spiceLevel)
		int swapped;
		item *ptr;
		item *rptr=NULL;
		do
		{
			swapped=0;
			ptr=head;
			while(ptr->next!=rptr)
			{
				if(ptr->spiceLevel > ptr->next->spiceLevel)
				{
					swape(ptr,ptr->next);
					swapped=1;
				}
				ptr=ptr->next;
			}
			rptr=ptr;
		}while(swapped);		
	}

	void add(string n,int sl,int p,int i)//will keep adding items to end of linked list
		{item *temp;
			temp=new item(n,sl,p,i);
			if(head==NULL)
			{
				head=temp;
			}
			else
			{item *ptr;ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				temp->next=NULL;
				ptr->next=temp;
			}
		}

	void updateBill(int itemNum,int quantity)
	{
		item *temp;
		temp = head;
		int flag =0;

	    	if(head==NULL)
	    	{
	    		bill = 0.0;
	    	}
	    	else
	    	{
	    		while(temp != NULL)
	      		{

	    			if(temp->itemNo == itemNum)
	    			{
	    				flag=1;
	    				break;
	    			}

	    			temp = temp->next;
	    		}

	    		if(flag == 1)
	    		{
	    		  bill = temp->price * quantity;
	    		}

	    }

	}

	void displayItems()
	{
				item *ptr;
				ptr=head;
				while(ptr!=NULL)
				{
					cout<<"Name: "<<ptr->name; cout<<endl;
					cout<<"Item no: "<<ptr->itemNo; cout<<endl;
					cout<<"Spicy level: "<<ptr->spiceLevel; cout<<endl;
					cout<<"Price: "<<ptr->price; cout<<endl;
					ptr=ptr->next;
					cout<<"---------------------"<<endl;
				}

	}

};


int main()
 {
	int ch,cho,ch1,ch2,ch3,ch4,q;
	char t,chh;
	//4 menu lists for soups,starters,main course,desserts
	menu m1; //soups
	menu m2; //starters
	menu m3; //main course
	menu m4; //desserts

	m1.add("cream of tomato soup",0,100,1);
	m1.add("Manchow soup",2,120,2);
	m1.add("Hot and Sour soup",3,120,3);
	m1.add("cream of mushroom soup",1,130,4);

	m2.add("Mushroom Pakora",0,150,1);
	m2.add("Fish Pakora ",2,190,2);
	m2.add("Lamb Tikka",1,190,3);
	m2.add("Seekh Kebab",4,180,4);
	m2.add("Garlic Pepper Chicken ",3,200,5);

	m3.add("Paneer Kesari",0,430,1);
	m3.add("Grilled Salmon",2,450,2);
	m3.add("Red Spinach Prown",1,450,3);
	m3.add("Chicken Tikka Massala ",4,470,4);
	m3.add("Tandoori Chicken Massala",3,480,5);

	m4.add("Fruit Salad ",0,120,1);
	m4.add("Apple Pie with Cream",0,150,2);
	m4.add("Black Forest Cake ",0,130,3);
	m4.add("Carrot Halva ",0,120,4);

	//Similarly add atleast 4-5 items for other 3 menu lists---divya
	//remember spice is not an issue for desserts so put 0 for all dessert's spice levels

	do
	{
		cout<<"\n 1.Soups\n 2.Starters\n 3.Main Course\n 4.Desserts\n"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			do{
			cout<<"Enter y if spice levels are an issue to show menu according to spice levels	:"<<endl;
			cin>>t;
			if(t=='y' || t=='Y'){ m1.sort();}
			m1.displayItems();
			cout<<"Enter the item number to order for it:"<<endl;
			cin>>ch1;

			switch(ch1)
			{
			case 1:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m1.updateBill(1,q);
				break;
			case 2:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m1.updateBill(2,q);
				break;
			case 3:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m1.updateBill(3,q);
				break;
			case 4:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m1.updateBill(4,q);
				break;
			default:cout<<"\nPlease enter valid choice..";
			}
			cout<<"More soup? Enter y or n"<<endl;
			cin>>chh;
			}while(chh=='y' || chh=='Y');
			break;

		case 2:
			do{
				cout<<"Enter y if spice levels are an issue to show menu according to spice levels	:"<<endl;
				cin>>t;
				if(t=='y' || t=='Y'){ m2.sort();}
				m2.displayItems();
				cout<<"Enter the item number to order for it:"<<endl;
				cin>>ch2;
			switch(ch2)
			{
			case 1:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m2.updateBill(1,q);
				break;
			case 2:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m2.updateBill(2,q);
				break;
			case 3:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m2.updateBill(3,q);
				break;
			case 4:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m2.updateBill(4,q);
				break;
			case 5:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m2.updateBill(5,q);
				break;
			default:cout<<"\nPlease enter valid choice..";
			}

			cout<<"More starters? Enter y or n"<<endl;
						cin>>chh;
						}while(chh=='y' || chh=='Y');

			break;

		case 3:
			do{
				cout<<"Enter y if spice levels are an issue to show menu according to spice levels	:"<<endl;
				cin>>t;
				if(t=='y' || t=='Y'){ m3.sort();}
				m3.displayItems();
				cout<<"Enter the item number to order for it:"<<endl;
				cin>>ch3;
			switch(ch3)
			{
			case 1:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m3.updateBill(1,q);
				break;
			case 2:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m3.updateBill(2,q);
				break;
			case 3:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m3.updateBill(3,q);
				break;
			case 4:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m3.updateBill(4,q);
				break;
			case 5:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m2.updateBill(5,q);
				break;
			default:cout<<"\nPlease enter valid choice..";
			}
			cout<<"More main course items? Enter y or n"<<endl;
						cin>>chh;
						}while(chh=='y' || chh=='Y');

			break;

		case 4:
			do{
				m4.displayItems();
				cout<<"Enter the item number to order for it:"<<endl;
				cin>>ch4;
			switch(ch4)
			{
			case 1:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m4.updateBill(1,q);
				break;
			case 2:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m4.updateBill(2,q);
				break;
			case 3:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m4.updateBill(3,q);
				break;
			case 4:
				cout<<"Enter Quantity"<<endl;
				cin>>q;
				m4.updateBill(4,q);
				break;
			default:cout<<"\nPlease enter valid choice..";
			}
			cout<<"More desserts? enter y or n"<<endl;
						cin>>chh;
						}while(chh=='y' || chh=='Y');

			break;
		default:cout<<"\nPlease enter valid choice..";
		}
		cout<<"Enter 1 for more restaurant ordering or 0 to exit:"<<endl;
		cin>>cho;
	}while(cho==1);


	cout<<"\n\t\tBill";
	cout<<"\nSoup \t\t\t\t"<<m1.bill;
	cout<<"\nStarters \t\t\t"<<m2.bill;
	cout<<"\nMain Course \t\t\t"<<m3.bill;
	cout<<"\nDesserts \t\t\t"<<m4.bill;
	cout<<"\nTotal bill\t\t\t"<<(m1.bill+m2.bill+m3.bill+m4.bill);


	cout<<endl;

}

