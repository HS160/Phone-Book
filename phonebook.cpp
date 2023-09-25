#include<iostream>
#include<string.h>
using namespace std;
class dnode
{
    public:
    char number[50];
    char gmail[40];
    char name[30];
    dnode *prev,*next;
    dnode(char n[],char r[],char g[])
    {
        strcpy(name,n);
        strcpy(number ,r);
        strcpy(gmail,g);
        next=NULL;
        prev=NULL;
    }
    friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr;
    dnode *ptr1,*ptr2,*dup;
    
    public:
    dnode *prevn;
    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[20]);
    void searchbygmail(char g[20]);
    void accept();
    void display();
    void update(char ch[10]);
    dlist()
    {
        head=NULL;
        temp=NULL;
        ptr=NULL;
        ptr1=NULL;
        ptr2=NULL;
        dup=NULL;
    }
};

void dlist :: accept()
{
    char number[50];
    char gmail[40];
    char name[30];
    char ans;
    do
    {
        cout<<"\tEnter Name : ";
        cin>>name;
        cout<<"\tEnter Number : ";
        cin>>number;
        
        while(strlen(number)!=10)
        {
            cout<<"Enter Valid Number : ";
            cin>>number;
        }
        cout<<"Enter G-mail : ";
        cin>>gmail;
        temp=new dnode(name,number,gmail);
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
        }
        cout<<"Do you want to continue ?";
        cin>>ans;
    }
    while(ans=='y');
}

void dlist :: display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<"Name : "<<ptr->name<<endl;
        cout<<"Number : +91-"<<ptr->number<<endl;
        cout<<"G-Mail : "<<ptr->gmail<<endl;
        ptr=ptr->next;
    }
}
void dlist :: insert(){
    accept();
    }
    void dlist :: sort(){
    dnode *i,*j;
    int temp;
    char n[10];
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            temp=strcmp(i->name,j->name);
            if(temp>0){
                strcpy(n,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,n);

            }
        }
    }
}
void dlist :: deletecontact(char s[20]){
int c=0;
ptr=head;
while(ptr!=NULL){

if(strcmp(s,ptr->name)==0){
    c=1;
    break;
}
else{
    c=2;
}
ptr=ptr->next;
}
if(c==1&&ptr!=head&&ptr->next!=NULL){
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    delete(ptr);
    cout<<"Your Contact Is Successfully Deleted!  "<<endl<<endl;
}
if(ptr==head){
    head=head->next;
    head->prev=NULL;
    delete(ptr);
     cout<<"Your Contact Is Successfully Deleted!  "<<endl<<endl;
}
if(ptr->next==NULL){
    ptr->prev->next=NULL;
    ptr->prev=NULL;
    delete(ptr);
     cout<<"Your Contact Is Successfully Deleted!  "<<endl<<endl;
}
if(c==2){
    cout<<"Your Entered Name Is Not In The List! "<<endl<<endl;
}
}
void dlist :: deletesamename(){
ptr1=head;
while(ptr1!=NULL&&ptr1->next!=NULL){
    ptr2=ptr1;
    while(ptr2->next!=NULL){
        if(strcmp(ptr1->name,ptr2->next->name)==0){
            dup=ptr2->next;
            ptr2->next=ptr2->next->next;
            delete(dup);
            cout<<"SAME NAME DELETED SUCCESSFULLY!"<<endl;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    ptr1=ptr1->next;
}

}
void dlist :: deletesamegmail(){
ptr1=head;
while(ptr1!=NULL&&ptr1->next!=NULL){
    ptr2=ptr1;
    while(ptr2->next!=NULL){
        if(strcmp(ptr1->gmail,ptr2->next->gmail)==0){
            dup=ptr2->next;
            ptr2->next=ptr2->next->next;
            delete(dup);
        }
        else{
            ptr2=ptr2->next;
        }
    }
    ptr1=ptr1->next;
}
}
void dlist :: deletesamenumber(){
ptr1=head;
while(ptr1!=NULL&&ptr1->next!=NULL){
    ptr2=ptr1;
    while(ptr2->next!=NULL){
        if(strcmp(ptr1->number,ptr2->next->number)==0){
            dup=ptr2->next;
            ptr2->next=ptr2->next->next;
            delete(dup);
           cout<<"SAME NUMBER DELETED SUCCESSFULLY!"<<endl;
        }
        else{

            ptr2=ptr2->next;
        }
    }
    ptr1=ptr1->next;
}

}
void dlist :: searchbyname(char na[10]){
ptr=head;
while(ptr!=NULL){
    if(strcmp(na,ptr->name)==0){
        cout<<"Name Found"<<endl;
        cout<<"Contact Details Are Below : "<<endl;
        cout<<"Name : "<<ptr->name<<endl;
        cout<<"Number : +91-"<<ptr->number<<endl;
        cout<<"G-mail : "<<ptr->gmail<<endl;
    }
    ptr=ptr->next;
}
}
void dlist :: searchbynumber(char num[20]){
ptr=head;
while(ptr!=NULL){
    if(strcmp(num,ptr->number)==0){
        cout<<"Name Found"<<endl;
        cout<<"Contact Details Are Below : "<<endl;
        cout<<"Name : "<<ptr->name<<endl;
        cout<<"Number : +91-"<<ptr->number<<endl;
        cout<<"G-mail : "<<ptr->gmail<<endl;
    }
    ptr=ptr->next;
}
}
void dlist :: searchbygmail(char gm[10]){
ptr=head;
while(ptr!=NULL){
    if(strcmp(gm,ptr->gmail)==0){
        cout<<"Name Found"<<endl;
        cout<<"Contact Details Are Below : "<<endl;
        cout<<"Name : "<<ptr->name<<endl;
        cout<<"Number : +91-"<<ptr->number<<endl;
        cout<<"G-mail : "<<ptr->gmail<<endl;
    }
    ptr=ptr->next;
}
}
void dlist :: update(char n[20]){
char ans;
int c;
ptr=head;
while(ptr!=NULL){
    if(strcmp(n,ptr->name)==0){
        do{
            cout<<"What Do You Want To Update?\n1.Name\n2.Phone Number\n3.Gmail\n"<<endl;
            cin>>c;
            switch(c){
        case 1:
            cout<<"Enter New Name : ";
            cin>>ptr->name;
            break;
            case 2:
            cout<<"Enter New Phone Number : ";
            cin>>ptr->number;
            while(strlen(ptr->number)!=10){
                cout<<"Enter A Valid Phone Number : ";
                cin>>ptr->number;
            }
            break;
            case 3:
            cout<<"Enter New G-Mail : ";
            cin>>ptr->gmail;
            break;
            }
            cout<<"Do you Want To Continue Updating? ";
            cin>>ans;
            }while(ans=='y');
        }
        ptr=ptr->next;
    }
}


int main(){
    char n[20];
    char name[20];
    char number[10];
    char gmail[20];
    dlist d1;
    char ans;
    int ch,a;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^         Phone Book            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"\n=> What is your name?\n";
    cin.getline(name,20);
    cout<<endl;
    cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  WELCOME  "<<name<<"   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"Let's Create Our PhoneBook  "<<name<<  "\n\n  ";
    d1.accept();
    d1.sort();
    do{
    cout<<"\n\n\n\n1) Display Your Phone Book\n2) Insert New Contact \n3) Update Details On Existing Contact\n4) Delete Contact \n5) Delete Same Name in PhoneBook \n6) Delete Same Number In Phonebook \n7) Search\n "<<endl;
    cin>>ch;
    switch(ch){
    case 2:
        d1.insert();
        d1.sort();
        cout<<"Do You Want To Continue Operation?"<<endl;
            cin>>ans;

        break;
    case 1:
        d1.display();
        cout<<"Do You Want To Continue Operation?"<<endl;
            cin>>ans;

        break;
    case 3:
        cout<<"Enter The Name Of The Person Whose Details You Want To Update "<<endl;
        cin>>n;
        d1.update(n);
        d1.sort();
        cout<<"Do You Want To Continue Operation?"<<endl;
            cin>>ans;

        break;
    case 4:
        cout<<"Enter The Name That You Want To Delete "<<endl;
        cin>>name;
        d1.deletecontact(name);
        d1.sort();
        cout<<"Do You Want To Continue Operation?"<<endl;
            cin>>ans;

        break;
    case 5:
        d1.deletesamename();
        d1.display();
        d1.sort();
        cout<<"Do You Want To Continue Operation?"<<endl;
            cin>>ans;

        break;
    case 6:
        d1.deletesamenumber();
        d1.display();
        d1.sort();
        cout<<"Do You Want To Continue Operation?"<<endl;
            cin>>ans;

        break;
    case 7:
        do{
            cout<<"Use Your Phone Book For Searching By Name, Number and Gmail"<<endl;
            cout<<"Enter 1 To Search The contact Using Name."<<endl;
            cout<<"Enter 2 To Search The Contact Using Number."<<endl;
            cout<<"Enter 3 To search The Contact Using Gmail."<<endl;
            cin>>a;
            switch(a){
        case 1:
            cout<<"Enter The Name : ";
            cin>>name;
            d1.searchbyname(name);
            break;
        case 2:
            cout<<"Enter The Number : ";
            cin>>number;
            d1.searchbynumber(number);
            break;
        case 3:
            cout<<"Enter The Gmail : ";
            cin>>gmail;
            d1.searchbygmail(gmail);
            break;
        default:
            cout<<"Please Enter The Correct Input!"<<endl;
            }
            cout<<"Do You Want To Continue The Searching!"<<endl;
            cin>>ans;
        } while(ans=='y');
        d1.sort();
        cout<<"Do You Want To Continue Operation?"<<endl;
        cin>>ans;

        break;
        case 8:
            d1.deletesamegmail();
            d1.display();
            break;
        default:
            cout<<"Entered input is not correct"<<endl;

    }
    }while(ans=='y');

return 0;}