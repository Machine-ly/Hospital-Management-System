#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;


class Meds
{
public:

    void TakeOrder();
    void DeleteOrder();
    void modify();
	void OrderList();
	void Summary();
	void exit();
};


struct node
{
	int RecieptNo;
	string Costumer_Name;
	string date;
	int quantity[20];
	int x, menu2[20];
    int amount[20];
    string MedicineName[20]={"Humira", "Keytruda", "Revlimid", "Opdivo", "Eylea" ,"Eliquis", "Enbrel", "Avastin", "Stelara", "Rituxan", "Xarelto",
                             "Herceptin" ,"Prevnar", "Imbruvica", "Remicade", "Ibrance", "Biktarvy", "Tecfidera", "Trulicity", "Genvoya"};
	int Medicine[20] = {25,30,13,47,85,65,78,94,75,12,27,90,33,47,75,65,78,94,75,99};
	int total;

	node *prev;  // self referencial nodes
	node *next;
	node *link;

}*q, *temp;


node *start = NULL;
node *head = NULL;
node *last = NULL;

int main()
{

	system("COLOR 0");
	Meds medicine;   // object of meds class
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.TakeOrder();
				break;
			}


		case 2:
			{
				medicine.DeleteOrder();
				system("PAUSE");
				break;
			}

		case 3:
			{
				medicine.modify();
				system("PAUSE");
				break;
			}

		case 4:
			{
				medicine.OrderList();
				system("PAUSE");
				break;
			}
		case 5:
			{
				medicine.Summary();
				system("PAUSE");
				break;
			}
        case 6:
			{
				medicine.exit();
				goto a;
				break;
			}


		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
	}
	while(menu!=6);    // DOUBT
	a:
	cout<<"thank you"<<endl;
	system ("PAUSE");
	return 0;
}


void Meds::TakeOrder()
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"**************************************************************************\n";
				cout<<"DRUGS ID"<<"\t\tDRUGS NAME"<<"\t\tDRUGS PRICE(Rs.)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<" 1"<<"\t"<<"\t\tHumira    "<<"\t\tRs.25"<<endl;
                cout<<" 2"<<"\t"<<"\t\tKeytruda  "<<"\t\tRs.30"<<endl;
                cout<<" 3"<<"\t"<<"\t\tRevlimid  "<<"\t\tRs.13"<<endl;
                cout<<" 4"<<"\t"<<"\t\tOpdivo    "<<"\t\tRs.47"<<endl;   //25,30,13,47,85,65,78,94,75,12,27,90,33,47,75,65,78,94,75,99
                cout<<" 5"<<"\t"<<"\t\tEylea     "<<"\t\tRs.85"<<endl;
                cout<<" 6"<<"\t"<<"\t\tEliquis   "<<"\t\tRs.65"<<endl;
                cout<<" 7"<<"\t"<<"\t\tEnbrel    "<<"\t\tRs.78"<<endl;
                cout<<" 8"<<"\t"<<"\t\tAvastin   "<<"\t\tRs.94"<<endl;
                cout<<" 9"<<"\t"<<"\t\tStelara   "<<"\t\tRs.75"<<endl;
                cout<<"10"<<"\t"<<"\t\tRituxan   "<<"\t\tRs.12"<<endl;
                cout<<"11"<<"\t"<<"\t\tXarelto   "<<"\t\tRs.27"<<endl;
                cout<<"12"<<"\t"<<"\t\tHerceptin "<<"\t\tRs.90"<<endl;
                cout<<"13"<<"\t"<<"\t\tPrevnar 13"<<"\t\tRs.33"<<endl;
                cout<<"14"<<"\t"<<"\t\tImbruvica "<<"\t\tRs.47"<<endl;
                cout<<"15"<<"\t"<<"\t\tRemicade  "<<"\t\tRs.75"<<endl;
                cout<<"16"<<"\t"<<"\t\tIbrance   "<<"\t\tRs.65"<<endl;
                cout<<"17"<<"\t"<<"\t\tBiktarvy  "<<"\t\tRs.78"<<endl;
                cout<<"18"<<"\t"<<"\t\tTecfidera "<<"\t\tRs.94"<<endl;
                cout<<"19"<<"\t"<<"\t\tTrulicity "<<"\t\tRs.75"<<endl;
                cout<<"20"<<"\t"<<"\t\tGenvoya   "<<"\t\tRs.99"<<endl;
                cout<<" "<<endl;

	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->RecieptNo;
	cout<< "Enter Customer Name: ";
	cin>> temp->Costumer_Name;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 20 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >20)
	{
		cout << "The Medicine you order is exceeding the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->MedicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "Amount for this Medicine: " << temp->amount[i]<<" Rs."<<endl;
        system("PAUSE");

	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start!=NULL)
	{
		temp->next=start;
	}
	start=temp;
	system("cls");
}
}


void Meds::OrderList()
{
	int i, num, num2;
	bool found;
	system("cls");
	node *temp;

	temp=start;
	found = false;

	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n";
	cout<<"==========================================================================="<<endl;


	if(temp == NULL)
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->RecieptNo==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)
        {
		cout <<"Reciept Number : "<<temp->RecieptNo;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->Costumer_Name<<endl;

		cout<<"Order Date : "<<temp->date<<endl;

		cout<<"_____________________________________________________________________________"<<endl;

		cout << "===============================================================================" << endl;
		cout << "|  Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout<<temp->MedicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" Rs."<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}

		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}


void Meds::DeleteOrder()
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start->RecieptNo == num)
		{
			q = start;
			start = start->next;
			count--;
			if(start == NULL)
			last = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start;
			q = start->next;

		while((!found) && (q != NULL))
		{
  			if(q->RecieptNo != num)
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q)
				last = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		}
}



void Meds::modify()
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->RecieptNo==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->RecieptNo;
	cout<< "Change Customer Name: ";
	cin>> temp->Costumer_Name;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 20 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >20)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->MedicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" RM"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");

	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else
 {
 	if(temp != NULL && temp->RecieptNo != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}



void Meds::Summary()
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start;


	if(temp == NULL)
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n";
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{

				cout <<"Reciept Number : "<<temp->RecieptNo;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->Costumer_Name<<endl;

				cout<<"Order Date : "<<temp->date<<endl;

				cout<<"____________________________________________________________________________"<<endl;

				cout << "==========================================================================" << endl;
				cout << "|  Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout<<temp->MedicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" RM"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}

			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;

			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";

			temp=temp->next;
		}
	}
}
void Meds::exit()
{
	cout<<"\nYou choose to exit.\n"<<endl;
}
