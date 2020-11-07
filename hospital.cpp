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


int main()
{
	int ch, user;
	hospital obj;
	cout << "------------------------------------------------------------------------------------\n"
			 << "1.Doctor\n2.Patient\n3.Admin\n"
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
	default:
		exit(0);
	}
}
