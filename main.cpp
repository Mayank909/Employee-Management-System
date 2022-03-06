#include <iostream>
#include<windows.h>
#include<stdlib.h>
#include<mysql.h>
#include<sstream>
#include<conio.h>
#include<stdio.h>
COORD c;
void gotoxy(int x,int y)
{
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


using namespace std;
int main();

class employee
{
        MYSQL* con;
        MYSQL_ROW row;
        MYSQL_RES* res;
    public:
         employee()
    {
        con=mysql_init(0);
        con=mysql_real_connect(con,"localhost","user","user","employee_data",0,NULL,0);
        if(con)
            cout<<"connect";
        else
            cout<<"not connect";



    }
    void salupd();
    void wadmin();
    void insert();
    void select();
    void dept();
    void see();
    void check();
    void  userlogin();
    void registe();
    void admin();
    void works();
    void tim();
    void empdep();
    void pinsert();
    void edelete();
    void ddelete();
    void dinsert();
    void updmgr();
    void pselect();
    void pdelete();
    void pupdate();
    void word();
};
void employee:: wadmin()
{
    int n,n1;
    cout<<endl<<endl;
     gotoxy(38,4);cout<<"WELCOME ADMIN";
    cout<<endl<<endl;
    label:
    cout<<"Admin want to  \n\n1.Employee record \n\n2.Department details \n\n3.Project details\n\n4.To LogOut\n";
    cout<<"\n\nEnter your choice";
    cin>>n;
    system("CLS");
    switch(n)
    {
case 1 :
    cout<<endl<<endl;
    emp:
    system("CLS");
    cout<<endl<<endl;
    cout<<"Employee Details \n\n1.See employee information\n\n2.Insert new employees\n\n3.Update employee salary\n\n4.Delete employee record\n\n5.To go back";
    cout<<"\n\nEnter your choice";
    cin>>n1;
    system("CLS");
    if(n1==1)
    {
        see();
        system("pause");
        goto emp;
    }
    else if(n1==2)
    {
       insert();
       system("pause");
        goto emp;
    }
    else if(n1==3)
    {
        salupd();
        system("pause");
        goto emp;
    }
    else if(n1==4)
    {
        edelete();
        system("pause");
        goto emp;
    }
    else if(n1==5)
    {
        system("CLS");
        goto label;
    }
    break;
case 2 :
    hss:
    system("CLS");
    cout<<endl<<endl;
    cout<<"Department Details\n\n1.See Department list\n\n2.Insert new department\n\n3.Delete department details\n\n4.Update Manager details\n\n5.To Go Back\n\n";
    cout<<"Enter your choice";
    cin>>n1;
    system("CLS");
    if(n1==1)
    {
        dept();
        system("pause");
        goto hss;
    }
    else if(n1==2)
    {
       dinsert();
       system("pause");
        goto hss;
    }
    else if(n1==3)
    {
        ddelete();
        system("pause");
        goto hss;
    }
    else if(n1==4)
    {
        updmgr();
        system("pause");
        goto hss;
    }
    else if(n1==5)
    {
        system("CLS");
        goto label;
    }
    break;
case 3 :
    pro:
    system("CLS");
    cout<<"Project Details\n\n1.See Project list\n\n2.Insert new Project\n\n3.Project cancelled\n\n4.To assign employee to project\n\n5.Update Project details\n\n6.To see employee on project\n\n7.To GO Back";
    cout<<"\n\nEnter your choice";
    cin>>n1;
    system("CLS");
    if(n1==1)
    {
        pselect();
        system("pause");
        goto pro;
    }
    else if(n1==2)
    {
       pinsert();
       system("pause");
       goto pro;
    }
    else if(n1==3)
    {
        pdelete();
        system("pause");
        goto pro;
    }
    else if(n1==4)
    {
        works();
        system("pause");
        goto pro;
    }
    else if(n1==5)
    {
        pupdate();
        system("pause");
        goto pro;
    }
    else if(n1==6)
    {
        word();
        system("pause");
        goto pro;
    }
    else if(n1==7)
    {
        system("CLS");
        goto label;
    }
    break;
case 4:
    main();
    break;
    }
}
void employee::insert()
{
    int qstate;
    cout<<"enter employee details"<<endl;
    string name,l_name,eid,add,city,dep,sal;
    cout<<"\n\nenter the name";
    cin>>name;
    cout<<"\nenter the lname\t";
    cin>>l_name;
    cout<<"\nenter employee id\t";
    cin>>eid;
    cout<<"\nenter employee Address\t";
    cin>>add;
    cout<<"\nenter employee city\t";
    cin>>city;
    cout<<"\nenter employee Department No.\t";
    cin>>dep;
    cout<<"\nenter employee Salary\t";
    cin>>sal;

    stringstream ss;
    ss<< "INSERT INTO emp(name, l_name,eid,address,city,salary,dep_no) VALUES('" << name << "', '"<< l_name << "','"<<eid<<"', '"<< add << "', '"<< city << "', '"<< sal << "', '"<< dep << "')";
    string query=ss.str();
    const char* q=query.c_str();
     qstate=mysql_query(con,q);
     if(qstate==0)
         cout<<"row inserted";
    else
        {
            cout<<"EMP ID should be unique\n"<<endl;
            cout<<"record not inserted ";
        }
}
void employee::pinsert()
{
    int qstate;
    string name,l_name,eid;
    cout<<"enter the dep_no";
    cin>>name;
    cout<<"enter the project name";
    cin>>l_name;
    cout<<"enter project pid";
    cin>>eid;
    stringstream ss;
    ss<< "INSERT INTO project(dep_no,pname,pid) VALUES('" << name << "', '"<< l_name << "','"<<eid<<"')";
    string query=ss.str();
    const char* q=query.c_str();
     qstate=mysql_query(con,q);
     if(qstate==0)
         cout<<"row inserted";
    else
    {
        cout<<"PID should be unique"<<endl;
        cout<<"record not inserted ";
    }

}

void employee::works()
{
      string rol,pno;
      cout<<"Assign project to employee from project details\n";
      cout<<"Enter employee ID. :- ";
      cin>>rol;
      cout<<"Enter Project NO. :- ";
      cin>>pno;
       int qstate=0;
  stringstream ss;
  ss<< "INSERT INTO works(eid,pid) VALUES('"<< rol << "','"<<pno<<"')";
   string query= ss.str();
   const char* q=query.c_str();
   qstate = mysql_query(con,q);

   if(qstate==0)
        cout<<" Record Inserted.."<<endl;
   else
    cout<<" Record not Inserted.."<<endl;

}
void employee::registe()
{
    string u,emp,pas,rpas;
    gotoxy(40,3); cout<<"####################################";
    gotoxy(40,4); cout<<"##  WELCOME TO REGISTRATION DESK  ##";
    gotoxy(40,5); cout<<"####################################"<<endl;
        cout<<endl<<endl;
        cout<<"Enter User Name :- ";
        cin>>u;
        cout<<"\nEnter your employee id :-";
        cin>>emp;
        cout<<"\nEnter Password :-";
        cin>>pas;
        cout<<"\nRe-type Password :-";
        cin>>rpas;
        cout<<endl<<endl;
    while(1)
    {
        if(pas==rpas)
        {
            cout<<"confirm password"<<endl;
            break;
        }
        else
        {
        cout<<"Please Re-enter your password.\n";
        cout<<"Enter Password :-";
        cin>>pas;
        cout<<"\nRe-type Password :-";
        cin>>rpas;
        }
    }
        int qstate;
  stringstream ss;
  ss<< "INSERT INTO login(username,password,eid) VALUES('"<< u << "','"<< pas <<"','"<< emp <<"')";
   string query= ss.str();
   const char* q=query.c_str();
   qstate = mysql_query(con,q);

   if(qstate==0)
        cout<<"Your account is successfully created."<<endl;
   else
       {
        cout<<"Your account is not created."<<endl;
        cout<<"Please check through admin where emp_id exist or not"<<endl;
        cout<<"username & password should be unique";
       }

}
void employee::userlogin()
{

     string U,Pas,rPas,emp;
     int f=1;
        gotoxy(35,3); cout<<"****************";
        gotoxy(35,4); cout<<"**WELCOME USER**";
        gotoxy(35,5); cout<<"****************"<<endl;
        cout<<endl<<endl;
        cout<<"Enter user name:- ";
        cin>>U;
        cout<<"\n\nEnter your employee id:-";
        cin>>emp;
        cout<<"\n\nEnter your password :- ";
        cin>>Pas;
        cout<<endl<<endl;
   stringstream ss,ss1;
   ss<<"select username,password,eid from login where eid='"<<emp<<"'";
        string query = ss.str();
        const char* q = query.c_str();
        int qstate;
        qstate = mysql_query(con,q);
    if(!qstate)
   {
   res=mysql_store_result(con);
    while(row=mysql_fetch_row(res))
    {
      if(U==row[0]&&Pas==row[1]&&emp==row[2])
      {
       f=0;
       cout<<"you are logged in \n";
       system("pause");
       system("CLS");
       ss1<<"select * from emp where eid=(select eid from login where username='"<<U<<"' AND password='"<<Pas<<"')";
        string query = ss1.str();
        const char* q1 = query.c_str();
        qstate = mysql_query(con,q1);
        int i=5;
    if(!qstate)
    {
     res = mysql_store_result(con);

      gotoxy(5,1);   cout<<"+--------------+--------------+----------+--------------+---------+---------+----------+";
      gotoxy(5,2);   cout<<"+   F_name     |    L_name    |  EMP_ID  |    Address   |  City   | Salary  |   Dept_no ";
      gotoxy(5,3);   cout<<"+--------------+--------------+----------+--------------+---------+---------+----------+";
            while(row = mysql_fetch_row(res))
            {
           gotoxy(5,i); cout<<"+"; gotoxy(8,i);  cout << row[0]; gotoxy(20,i);cout<<"|";gotoxy(25,i);cout<<row[1];gotoxy(35,i);cout<<"|";gotoxy(40,i);cout<< row[2]; gotoxy(46,i); cout<<"|"; gotoxy(50,i); cout<<row[3]; gotoxy(61,i); cout<<"|"; gotoxy(63,i); cout<<row[4]; gotoxy(71,i); cout<<"|"; gotoxy(74,i); cout<<row[5]; gotoxy(81,i); cout<<"|"; gotoxy(85,i); cout<<row[6]; gotoxy(92,i); cout<<"+"<<endl<<endl;
   i=i+1;

            }
      break;
      }
   }

    else
       {
        cout<<"You are not logged please re-type "<<endl;
                userlogin();

         break;
       }}
}

    int n,flag=0;
    if(flag==1)
    {
        system("CLS");
    }
    if(f==0)
    {us:
    cout<<"1.To Update Personal Info. \n2.To See Department \n3.To See Project Details \n4.To LogOut";
    cout<<endl<<"\nEnter your choice\n";
    cin>>n;
    system("CLS");
    cout<<endl;

 switch(n)
 {
 case 1:
      {
          flag=1;
          int n;
          m:
     cout<<"\nEnter your choice\n";
     cout<<"1. TO update name \n2. To update surname \n3. To update address \n4. To update city \n5. To update dep_no. \n6. To Go Back";
     cin>>n;
   if(n==1)
    {
      system("CLS");
      string name,empid;
      gotoxy(40,5); cout<<"Update Name"<<endl;
      cout<<"enter name you want to change";
      cin>>name;
      cout<<"enter the emp_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE emp set name = '" << name << "' WHERE eid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
       system("pause"); system("CLS");
        goto m;
    }
   else if(n==2)
   {
      system("CLS");
      string lname,empid;
      gotoxy(40,5); cout<<"Update last name"<<endl;
      cout<<"enter lname you want to change";
      cin>>lname;
      cout<<"enter the emp_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE emp set l_name = '" << lname << "' WHERE eid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
        system("pause");system("CLS");
        goto m;
   }
  else if(n==3)
    {
     system("CLS");
      string name,empid;
      gotoxy(40,5); cout<<"Update Address"<<endl;
      cout<<"enter address you want to change";
      cin>>name;
      cout<<"enter the emp_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE emp set address = '" << name << "' WHERE eid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
        system("pause");system("CLS");
        goto m;
    }
 else if(n==4)
    {
        system("CLS");
      string name,empid;
      gotoxy(40,5); cout<<"Update City"<<endl;
      cout<<"enter city you want to change";
      cin>>name;
      cout<<"enter the emp_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE emp set city = '" << name << "' WHERE eid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1==0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
        system("pause");system("CLS");
        goto m;
    }
 else if(n==5)
    {
      string name,empid;
      system("CLS");
      gotoxy(40,5); cout<<"Update Department"<<endl;
      cout<<"enter department no. you want to change";
      cin>>name;
      cout<<"enter the emp_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE emp set dep_no = '" << name << "' WHERE eid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
        system("pause");
        system("CLS");
        goto m;
    }
    else if(n==6)
    {
        system("CLS");
        goto us;
    }
      }
        break;
 case 2:
        {
            flag=1;
        stringstream ss;
        ss<<"select * from department where dep_id=(select dep_no from emp where eid='"<<emp<<"')";
        string query = ss.str();
        const char* q = query.c_str();
        int qstate;
        int i=5;
        qstate = mysql_query(con,q);
        if(!qstate)
        {
        gotoxy(5,1);    cout<<"+----------------+--------------------+------------------+";
         gotoxy(5,2);   cout<<"+  Dep_name      |       Dept_no      |     Manager_ID    ";
         gotoxy(5,3);   cout<<"+----------------+--------------------+------------------+";
            res = mysql_store_result(con);
            while(row = mysql_fetch_row(res))
            {
           gotoxy(5,i); cout<<"+";  gotoxy(8,i);  cout << row[0]; gotoxy(22,i);cout<<"|";gotoxy(31,i);cout<<row[1];gotoxy(43,i);cout<<"|";gotoxy(52,i);cout<< row[2];gotoxy(62,i); cout<<"+"<<endl<<endl;
         i=i+1;
            }

        }

    system("pause");
    goto us;
        }
    break;

 case 3:
        {
            flag=1;
            stringstream ss;
          ss<<"SELECT * FROM project where pid=(select pid from works where eid='"<<emp<<"')";
            string query = ss.str();
        const char* q = query.c_str();
        int qstate,i=5;
        qstate = mysql_query(con, q);
        if(!qstate)
        {
                gotoxy(5,1);   cout<<"+----------------+----------------------+------------------+";
                gotoxy(5,2);   cout<<"+   Dept_no      |    Project_name      |     PROJECT_ID    ";
                gotoxy(5,3);   cout<<"+----------------+----------------------+------------------+";

            res = mysql_store_result(con);
            while(row = mysql_fetch_row(res))
            {

             gotoxy(5,i); cout<<"+";   gotoxy(11,i);  cout << row[0]; gotoxy(22,i);cout<<"|";gotoxy(30,i);cout<<row[1];gotoxy(45,i);cout<<"|";gotoxy(53,i);cout<< row[2]; gotoxy(64,i);cout<<"+"<<endl;
           i=i+1;
            }

        }
        system("pause");
        goto us;
        }
        break;
 }
    }
    else
    {
            cout<<"Not login";
            system("pause");
            system("CLS");
    }
}
void employee::admin()
{

        string U,Pas,rPas;
            int flag=0,flag1=0;
        cout<<endl<<endl;
        cout<<"Enter user name:- ";
        cin>>U;
        cout<<"\n\nEnter your password :- ";
        cin>>Pas;
        cout<<endl;
   stringstream ss,ss1;
   ss<<"select username,password from login";
        string query = ss.str();
        const char* q = query.c_str();
        int qstate =0;
        qstate = mysql_query(con, q);
    if(!qstate)
   {

   res=mysql_store_result(con);
    while(row=mysql_fetch_row(res))
    {
      if(row[0]==U&&row[1]==Pas)
      {
          flag=1;
       cout<<"\nyou are logged in \n";
        system("CLS");
        cout<<endl<<endl;
        wadmin();
        break;

      }
        }
    if(flag==0)
    {
        cout<<" !You are Not log in. ";
        system("CLS");
    }
   }
}
void employee::see()
{

     stringstream ss;
     int i=5;
     ss<<"SELECT * from emp";
         string query= ss.str();
        const char*q = query.c_str();
        int qstate=mysql_query(con,q);
        if(!qstate)
        {
            res = mysql_store_result(con);

      gotoxy(5,1);   cout<<"+--------------+--------------+----------+--------------+---------+---------+----------+";
      gotoxy(5,2);   cout<<"+   F_name     |    L_name    |  EMP_ID  |    Address   |  City   | Salary  |   Dept_no ";
      gotoxy(5,3);   cout<<"+--------------+--------------+----------+--------------+---------+---------+----------+";
            while(row = mysql_fetch_row(res))
            {
           gotoxy(5,i); cout<<"+"; gotoxy(8,i);  cout << row[0]; gotoxy(20,i);cout<<"|";gotoxy(25,i);cout<<row[1];gotoxy(35,i);cout<<"|";gotoxy(40,i);cout<< row[2]; gotoxy(46,i); cout<<"|"; gotoxy(50,i); cout<<row[3]; gotoxy(61,i); cout<<"|"; gotoxy(63,i); cout<<row[4]; gotoxy(71,i); cout<<"|"; gotoxy(74,i); cout<<row[5]; gotoxy(81,i); cout<<"|"; gotoxy(85,i); cout<<row[6]; gotoxy(92,i); cout<<"+"<<endl<<endl;
           i=i+1;

            }

        }
}


void employee::salupd()
{

      string sal,empid;
      gotoxy(40,5); cout<<"Update Salary"<<endl;
      cout<<"enter Amount you want to change ";
      cin>>sal;
      cout<<"enter the emp_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE emp set salary = '" << sal << "' WHERE eid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
}
void employee::edelete()
{
       string empid;
       gotoxy(40,5); cout<<"Employee Leave"<<endl;
       cout<<"enter emp_id of employee which u want to delete";
       cin>>empid;
       stringstream ss1;
       stringstream ss2;
       /*ss2<<"select eid from emp";
         string query2 = ss2.str();
        const char* q2 = query2.c_str();
       int qstate = mysql_query(con, q2);
       res =mysql_store_result(con);
         while(row=mysql_fetch_row(res))
         {
       if(empid==row[0])
       {*/
            ss1<<"delete from emp where eid='" <<empid<< "' ";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
       int qstate1 = mysql_query(con, q1);
        if(qstate1 == 0){
            cout << "Record Deleted..." << endl;
        }

       else
       {
       cout<<"No record found";
       }



}
void employee::dept()
{

    int i=5;
     stringstream ss;
     ss<<"SELECT * from department";
         string query= ss.str();
        const char* q = query.c_str();
        int qstate=mysql_query(con,q);
        if(!qstate)
        {

        gotoxy(5,1);    cout<<"+----------------+--------------------+------------------+";
         gotoxy(5,2);   cout<<"+  Dep_name      |       Dept_no      |     Manager_ID    ";
         gotoxy(5,3);   cout<<"+----------------+--------------------+------------------+";
            res = mysql_store_result(con);
            while(row = mysql_fetch_row(res))
            {
              gotoxy(5,i); cout<<"+"; gotoxy(8,i); cout << row[0]; gotoxy(22,i);cout<<"|";gotoxy(32,i);cout<<row[1];gotoxy(43,i);cout<<"|";gotoxy(53,i);cout<< row[2]<<endl; gotoxy(62,i); cout<<"+"<<endl;
         i=i+1;
            }
        }

}
void employee::dinsert()
{
    int qstate;
    gotoxy(40,5); cout<<"New Department"<<endl;
    string dname,mgrid,did;
    cout<<"enter the Department name";
    cin>>dname;
    cout<<"enter the department id";
    cin>>did;
    cout<<"enter manager id";
    cin>>mgrid;
    stringstream ss;
    ss<< "INSERT INTO department(dep_name, dep_id,mgr_id) VALUES('" << dname << "', '"<< did << "','"<<mgrid<<"')";
    string query=ss.str();
    const char* q=query.c_str();
     qstate=mysql_query(con,q);
     if(qstate==0)
         cout<<"row inserted";
    else
        cout<<"EMP ID should be unique"<<endl;
        cout<<"record not inserted ";
}
void employee::ddelete()
{
        string empid;
        gotoxy(40,5); cout<<"Department Closed"<<endl;
       cout<<"enter Dep_id of Department which u want to delete";
       cin>>empid;
       stringstream ss1;
       ss1<<"delete from department where dep_id='" <<empid<< "' ";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
       int qstate1 = mysql_query(con, q1);
        if(qstate1 == 0){
            cout << "Record Deleted..." << endl;
        }else{
            cout << "NO Record Found"<< endl;

}
}
void employee::updmgr()
{

      string sal,empid;
      gotoxy(40,5); cout<<"Update Manager"<<endl;
      cout<<"enter new manager id of department  ";
      cin>>sal;
      cout<<"enter the Dep_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE department set mgr_id = '" << sal << "' WHERE dep_id = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
}
void employee::pdelete()
{
       string empid;
       gotoxy(40,5); cout<<"Project Cancalled"<<endl;
       cout<<"enter p_id of Project which u want to delete";
       cin>>empid;
       stringstream ss1;
       ss1<<"delete from project where pid='" <<empid<< "' ";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
       int qstate1 = mysql_query(con, q1);
        if(qstate1 == 0){
            cout << "Record Deleted..." << endl;
        }else{
            cout << "NO Record Found"<< endl;

}
}
void employee::pselect()
{

     stringstream ss;
     ss<<"SELECT * from project";
         string query= ss.str();
        const char* q = query.c_str();
        int qstate=mysql_query(con,q);
        int i=5;
        if(!qstate)
        {
            res = mysql_store_result(con);

                gotoxy(5,1);   cout<<"+----------------+----------------------+------------------+";
                gotoxy(5,2);   cout<<"+   Dept_no      |    Project_name      |     PROJECT_ID    ";
                gotoxy(5,3);   cout<<"+----------------+----------------------+------------------+";
            while(row = mysql_fetch_row(res))
            {

             gotoxy(5,i); cout<<"+";   gotoxy(11,i);  cout << row[0]; gotoxy(22,i);cout<<"|";gotoxy(30,i);cout<<row[1];gotoxy(45,i);cout<<"|";gotoxy(53,i);cout<< row[2]; gotoxy(64,i);cout<<"+"<<endl;
           i=i+1;
            }
        }
}
void employee::pupdate()
{
      string sal,empid;
      gotoxy(40,5); cout<<"Project Update"<<endl;
      cout<<"enter employee id where you want to change employee's project ";
      cin>>sal;
      cout<<"\n enter the p_id";
      cin>>empid;
      stringstream ss1;
      ss1 << "UPDATE works set eid = '" << sal << "' WHERE pid = '" << empid << "'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        int qstate1=mysql_query(con,q1);
        if(qstate1 == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(con) << endl;
        }
}
void employee::word()
{
    stringstream ss;
          ss<<"SELECT * FROM works";
            string query = ss.str();
        const char* q = query.c_str();
        int qstate,i=5;
        qstate = mysql_query(con, q);
        if(!qstate)
        {
                gotoxy(5,1);   cout<<"+-----------+------------+";
                gotoxy(5,2);   cout<<"+   EMP_ID  | Project_ID  ";
                gotoxy(5,3);   cout<<"+-----------+------------+";

            res = mysql_store_result(con);
            while(row = mysql_fetch_row(res))
            {

             gotoxy(5,i); cout<<"+";   gotoxy(9,i);  cout << row[1]; gotoxy(17,i);cout<<"|";gotoxy(22,i);cout<<row[0];gotoxy(30,i);cout<<"+"<<endl;
           i=i+1;
            }

        }

}
int main()
{
    employee e; int n;
    m:
        gotoxy(28,5); cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
        gotoxy(28,6); cout<<"$$      WELCOME TO EMPLOYEE MANAGEMENT SYSTEM      $$";
        gotoxy(28,7); cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
        cout<<endl;
        cout<<endl<<"\n\t1.User Login\n\n\t2.Admin Login\n\n\t3.Employee Registration\n\n";
        cout<<"\n\tEnter your choice:";
        cin>>n;
        system("CLS");
        switch(n)
        {
            case 1:
                e.userlogin();
                system("pause");
                goto m;
                break;
            case 2:
                e.admin();
                 system("pause");
                 goto m;
                break;
            case 3:
                e.registe();
                system("pause");
                system("CLS");
                goto m;
                break;
            default :
            cout<<" Wrong Choice. ";
            break;
        }

}


