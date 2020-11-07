#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <process.h>
#include <stdlib.h>

using namespace std;

char fname[100] = "hospital_record.txt";

struct record
{
	char id[5], name[15], age[5], sex[5], contact[15], time[10], discription[100];
};

class hospital
{
public:
	void pack(record r);
	record unpack(char a[]);
	void writedata();
	int owner_authen();
	void display();
	void search();
	void modify();
};

int hospital::owner_authen()
{
	char o_username[20], o_password[20];
	char o_user[20] = "admin", o_pass[20] = "admin";
	cout << endl
			 << endl;
	cout.width(25);
	cout << "Enter Doctors User id and Password\n"
			 << "------------------------------------------------------------------------------------\n";
	cout << endl
			 << "username: ";
	cin >> o_username;
	cout << "password: ";
	cin >> o_password;
	cout << "------------------------------------------------------------------------------------\n";
	if (strcmp(o_username, o_user) == 0 && strcmp(o_password, o_pass) == 0)
		return 1;
	else
		return 0;
}

void hospital::pack(record r)
{
	fstream fp;
	fp.open(fname, ios::out | ios::app);
	if (!fp)
	{
		cout << "\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff, r.id);
	strcat(buff, "|");
	strcat(buff, r.name);
	strcat(buff, "|");
	strcat(buff, r.age);
	strcat(buff, "|");
	strcat(buff, r.sex);
	strcat(buff, "|");
	strcat(buff, r.contact);
	strcat(buff, "|");
	strcat(buff, r.time);
	strcat(buff, "|");
	strcat(buff, r.discription);
	strcat(buff, "|*");
	fp << buff << endl;
	fp.close();
}
record hospital::unpack(char buff[])
{
	record r;
	int i = 0, j = 0;
	while (buff[j] != '|')
		r.id[i++] = buff[j++];
	r.id[i] = '\0';
	i = 0;
	j++;
	while (buff[j] != '|')
		r.name[i++] = buff[j++];
	r.name[i] = '\0';
	i = 0;
	j++;
	while (buff[j] != '|')
		r.age[i++] = buff[j++];
	r.age[i] = '\0';
	i = 0;
	j++;
	while (buff[j] != '|')
		r.sex[i++] = buff[j++];
	r.sex[i] = '\0';
	i = 0;
	j++;
	while (buff[j] != '|')
		r.contact[i++] = buff[j++];
	r.contact[i] = '\0';
	i = 0;
	j++;
	while (buff[j] != '|')
		r.time[i++] = buff[j++];
	r.time[i] = '\0';
	i = 0;
	j++;
	while (buff[j] != '|')
		r.discription[i++] = buff[j++];
	r.discription[i] = '\0';
	return (r);
}
void hospital::writedata()
{
	record r;
	cout << "\nEnter ID:";
	cin >> r.id;
	cout << "\nEnter Name:";
	cin >> r.name;
	cout << "\nEnter age:";
	cin >> r.age;
	cout << "\nEnter Sex (M/F):";
	cin >> r.sex;
	cout << "\nEnter Contact Number:";
	cin >> r.contact;
	cout << "\nEnter Time Slot:";
	cin >> r.time;
	cout << "\nEnter Discription:";
	cin >> r.discription;
	pack(r);
}
void hospital::display()
{
	fstream fp;
	char buff[500];
	record r;
	fp.open(fname, ios::in);
	if (!fp)
	{
		cout << "\ncan not open file";
		exit(0);
	}
	cout << "#\tID\tName\tAge\tSex\tContact Number\tTime Slot\tDiscription\n";
	int c = 1;
	while (1)
	{
		fp.getline(buff, 500, '*');
		if (fp.eof())
			break;
		r = unpack(buff);
		cout << c << "\t" << r.id << "\t" << r.name << "\t" << r.age << "\t" << r.sex << "\t" << r.contact << "\t" << r.time << "\t" << r.discription << endl;
		c++;
	}
	fp.close();
	return;
}
void hospital::modify()
{
	fstream fp;
	char id[15], buff[45];
	int i, j;
	record s[100];
	fp.open(fname, ios::in);
	if (!fp)
	{
		cout << "\ncan not open file";
		exit(0);
	}
	cout << "\nenter the ID to be modified:";
	cin >> id;
	i = 0;
	while (1)
	{
		fp.getline(buff, 45, '*');
		if (fp.eof())
			break;
		s[i] = unpack(buff);
		i++;
	}
	for (j = 0; j < i; j++)
	{
		if (strcmp(s[j].id, id) == 0)
		{
			cout << "\nvalues of the record are:\n";
			cout << "\nID:" << s[j].id;
			cout << "\nName:" << s[j].name;
			cout << "\nAge:" << s[j].age;
			cout << "\nSex (M/F):" << s[j].sex;
			cout << "\nContact:" << s[j].contact;
			cout << "\nTime Slot:" << s[j].time;
			cout << "\nDiscription:" << s[j].discription;
			cout << "\nenter the new values:\n";
			cout << "\nID:";
			cin >> s[j].id;
			cout << "\nName:";
			cin >> s[j].name;
			cout << "\nAge:";
			cin >> s[j].age;
			cout << "\nSex (M/F):";
			cin >> s[j].sex;
			cout << "\nContact:";
			cin >> s[j].contact;
			cout << "\nTime Slot:";
			cin >> s[j].time;
			cout << "\nDiscription:";
			cin >> s[j].discription;
			break;
		}
	}
	if (j == i)
	{
		cout << "\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname, ios::out | ios::trunc);
	if (!fd)
	{
		cout << "\ncan not open file";
		exit(0);
	}
	for (j = 0; j < i; j++)
		pack(s[j]);
	fd.close();
}
void hospital::search()
{
	fstream fp;
	char id[15],buff[45];
	int i,j;
	record s;
	fp.open(fname,ios::in);
	if(!fp)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the ID to be searched:";
	cin>>id;
	i=0;
	fp.getline(buff,45);
	s=unpack(buff);
	while(1)
	{

		if(fp.eof())
			break;
		if(strcmp(s.id,id)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nID:"<<s.id;
			cout<<"\nName:"<<s.name;
			cout<<"\nAge:"<<s.age;
			cout<<"\nSex (M/F):"<<s.sex;
			cout<<"\nContact:"<<s.contact;
			cout<<"\nDescription:"<<s.discription;
		}
		fp.getline(buff,45);
		s=unpack(buff);
	}
	return;
}

int passwords()
{

	char p1,p2,p3;

	cout<<"\n\n\n\n\n\n\t\t\tENTER THE PASSWORD: ";

	cin>>p1;
	cout<<"*";
	cin>>p2;
	cout<<"*";
	cin>>p3;
	cout<<"*";

	if ((p1=='a'||p1=='A')&&(p2=='d'||p2=='D')&&(p3=='m'||p3=='M'))

		return 1;

	else
		return 0;
}

class admin
{
	char Iname[50][50];

public:
	int totalitems;
	float price[3];
	void input();
	void output();
	void administration();
};
class total:public admin
{
public:
	void outputs();
};

void admin::input()
{
	system("CLS");
	cout<<"\nEnter number of services used= ";
	cin>>totalitems;

	for(int i=0; i<totalitems; i++)
	{
		cout<<"\nEnter name of service used/problems "<<i+1<<": ";
		cin>>Iname[i];
		cout<<"Enter price of item "<<i+1<<": ";
		cin>>price[i];
	}
}

void admin::output()
{
	int a;

	ifstream infile("COUNT.TXT");
	infile>>a;

	ofstream outfile("COUNT.TXT");
	a+=1;
	outfile<<a;
	outfile.close();

	{ofstream outfile("HIS.TXT", ios::app);
	outfile<<endl<<"Bill No.: "<<a<<endl;
	outfile<<"------------------------------------------------------------------------"<<endl;
cout<<"\n";
	cout<<"Name of Item\t   Price  Total Price\n";
	for(int i=0;i<totalitems;i++)
	{
		outfile<<"Name: "<<Iname[i]<<" Price: "<<price[i]<<endl;
		cout<<Iname[i]<<"\t\t"<<"\t   "<<price[i]<<"\t"<<'\n';
	}

	outfile<<"------------------------------------------------------------------------"<<endl;
	outfile.close();
	}
}



void total::outputs()
{
	input();
	output();

	float cash=0,sum=0,qty=0,sumt=0;

	for(int i=0;i<totalitems;i++)
	{
	       sumt+=price[i];
	}
	cout<<"\nTotal:";
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\n\t\t Sum= "<<sumt;
	cout<<"\n------------------------------------------------------------------------------";

pay:

	cout<<"\n\n\t\t\t****PAYMENT SUMMARY****\n";
	cout<<"\n\t\t\tTotal cash given: ";
	cin>>cash;

	if(cash>=sumt)
		cout<<"\n\t\t\tTotal cash repaid: "<<cash-sumt<<'\n';

	else
	{	cout<<"\n\t\t\tCash given is less than total amount!!!";

	goto pay;
	}
}

void administration(){
	total obj;
	char opt, ch;
	int a=1;
	ifstream fin;

	a==passwords();
	if(!a)
	{
		for(int i=0;i<2;i++)
		{
			cout<<"\nWrong password try once more\n";
			if(passwords())
			{
				goto last;
			}
			else
			{
				cout<<"\n\n\t\t\t all attempts failed.....";
				cout<<"\n\n\n\t\t\t see you.................. ";
				exit(0);
			}

		}
		cout<<"\t\t\t sorry all attempts failed............. \n \t\t\tinactive";
			 }
	else{
last:;


	 do{
start:
	system("PAUSE");
	system("CLS");
	cout<<"\n\n\t\t\t------------------------------";
	cout<<"\n\t\t\tAdministration";
	cout<<"\n\t\t\t------------------------------";
	 cout<<"\n\n\t\t\tWhat you want to do?";
	 cout<<"\n\t\t\t1.\tTo enter new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n";
	 cout<<"\n\nEnter your option: ";
	 cin>>opt;
	 switch(opt)
	 {
	 case'1':
		 obj.outputs();
		 goto start;
	 case'2':

		 fin.open("HIS.TXT", ios::in);
		 while(fin.get(ch))
		 {
			 cout<<ch;
		 }
		 fin.close();

		 goto start;
	 case'3':
		 exit(0);
	 default:
		 cout<<"\a";
	 }

	 }while(opt!=3);
	}
}

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


void pharmacy(){
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
}





int main()
{
	int ch, user;
	hospital obj;
	cout << "------------------------------------------------------------------------------------\n"
			 << "1.Doctor\n2.Patient\n3.Admin\n4.Pharmacy\n"
			 << "------------------------------------------------------------------------------------\n";
	cout << "Select User: ";
	cin >> user;
	switch (user)
	{
	case 1:
		int check;
		check = obj.owner_authen();
		if (check == 1)
		{
			cout << "Welcome Doctor\n"
					 << "------------------------------------------------------------------------------------\n";
			cout << "1.write data\n2.display\n3.search\n4.modify\n5.exit:";
			while (1)
			{
				cout << "\nenter your choice:";
				cin >> ch;
				switch (ch)
				{
				case 1:
					obj.writedata();
					break;
				case 2:
					obj.display();
					break;
				case 3:
					obj.search();
					break;
				case 4:
					obj.modify();
					break;
				default:
					exit(0);
				}
			}
			break;
		}
		else
			cout << endl
					 << "Invalid Username or Password!! Please try again...";
		break;

	case 2:
		cout << "Patient Record\n"
				 << "------------------------------------------------------------------------------------\n";
		while (1)
		{
			obj.search();
		}
		break;
	case 3:
		administration();
		break;
	case 4:
		pharmacy();
		break;	
	default:
		exit(0);
	}
}
