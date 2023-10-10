#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<chrono>

using namespace std;

int Borrow_item[100];
string Borrow_magJ[100];
int User_id[50];
string time_book[100], time_mag[100], time_journal[100] ;

int size_of_b = 0, n = 0;
int size_of_mj = 0;
class e_items{

    int ebooks;
    int electronic_items;
    e_items()
    {
        ebooks = 100;
        electronic_items = 100;
    }

};
class record{

    public:
    int b_count; 
    string title;
    record()
    {
        b_count = 0;
    }

    
};
class books: public record{

    public:
    int id;
    int ISBN;
    string publication;
    string author;
    books()
    {
        id = 0;
        ISBN = 0;
    }
    
};
class journals{
    public:
    string title;

};
class Magazines: public record{
    public:
    string rank;

};
books Book[100];
Magazines mag[100];
journals J[100];

class Library{
    
    public:
void read_books();
void read_magazines();
void read_journal();
};

   void Library :: read_books()
    {
    ifstream ip("Books.csv");
    

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string temp;
  int i=0;
  getline(ip, temp, '\n');
  while(ip.good())
  {

    getline(ip,temp,',');
    Book[i].id = atoi(temp.c_str());
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    Book[i].b_count = atoi(temp.c_str());
    getline(ip,temp,',');
    Book[i].ISBN = atoi(temp.c_str());
    getline(ip,temp,',');
    getline(ip,temp,',');
    Book[i].author = temp.c_str();
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    Book[i].title = temp.c_str();
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,'\n');

    //cout << "Book id: "<< Book[i].id<< '\n';
    //cout << "Book title : "<< Book[i].title<< '\n';
    //cout << "Book author : "<< Book[i].author<< '\n';
    //cout << "Book ISBN : "<< Book[i].ISBN<< '\n';

    //cout << "-------------------" << '\n';
    i++;
  }
}

void Library :: read_magazines()
{

    ifstream ip("Magazines.csv");
    

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string temp;
  int i=0;
  getline(ip, temp, '\n');
  while(ip.good())
  {

    getline(ip,temp,',');
    mag[i].title = temp.c_str();
    getline(ip,temp,',');
    mag[i].rank = temp.c_str();
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,',');
    getline(ip,temp,'\n');
    //cout << "magazines id: "<< mag[i].id<< '\n';
    //cout << "magazines title : "<< mag[i].title<< '\n';
    //cout << "magazines author : "<< mag[i].author<< '\n';
    //cout << "magazines rank : "<< mag[i].rank<< '\n';

    //cout << "-------------------" << '\n';
    i++;
  }

}

void Library :: read_journal(){
    ifstream ip("journals - journals.csv");
    

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string temp;
  int i=0;
  while(ip.good())
  {

    getline(ip,temp,',');
    J[i].title = temp.c_str();
    getline(ip,temp,'\n');
    
    //cout << "Journal title : "<< J[i].title<< '\n';

    //cout << "-------------------" << '\n';
    i++;
  }

}

class user{
    private:
    int user_id;
    string m_name;
    int phone_no;
    string user_type;
    public:
   
    void registration(string name, string user_type, int phone, int id)
    {
        m_name=name;
        user_type= user_type;
        phone_no = phone;
        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(User_id[i] == id)
            {             
                cout<<"User already registered!!";
                flag = 1;
                break;
            }  
        }
        
        if(flag == 1)
        {
            ++n;
            User_id[n] = id;
        }

       ++n;
       cout<<"User with id:"<<User_id[n]<<" registered sucessfully";

    }

    void Display()
    {
        cout<<"User added successfully with below details:\n";
        cout<<m_name<<"\n";
        cout<<user_type<<"\n";
        cout<<phone_no<<"\n";
        cout<<user_id;
    }

    void borrow_books(int book_id)
    {
        int flag = 0;
        for(int i=0;i<size_of_b;i++)
        {
            if(Borrow_item[i] == book_id)
            {
                cout<<"Book borrowed and is not available right now";
                flag = 1;
                break;
            }  
        }
        
        if(flag == 1)
        {
            ++size_of_b;
            Borrow_item[size_of_b] = book_id;
        }

       ++size_of_b;
       cout<<"Item with id:"<<Borrow_item[size_of_b]<<"is issued sucessfully";

    }

    void borrow_magJ(string name)
    {
        int flag = 0;
        for(int i=0;i<size_of_b;i++)
        {
            if(Borrow_magJ[i] == name)
            {
                cout<<"Item borrowed and is not available right now";
                flag = 1;
                break;
            }  
        }
        
        if(flag == 1)
        {
            ++size_of_mj;
            Borrow_magJ[size_of_mj] = name;
        }

       ++size_of_mj;
       cout<<"Item with id:"<<Borrow_item[size_of_mj]<<"is issued sucessfully";

    }

    void location_books(int id, string author, int ISBN)
    {
        int ch=0;

       for(int i=0;i<100;i++)
       {
            if(Book[i].id == id && Book[i].author == author && Book[i].ISBN == ISBN)
            {   
                ch = i;
                break;
                
            }
        } 
        cout<<"shelf no.: "<<1<<"\n";
                cout<<"row: "<<ch+1;

                auto now = chrono::system_clock::now();
                auto nowTimeT = chrono::system_clock::to_time_t(now);
                time_book[ch] = ctime(&nowTimeT);
                cout<<"\nTime: "<<time_book[ch];     
       
    }
    void location_mag(string name, string mag_rank)
    {
        int x=0;
        for(int i=0;i<81;i++)
        {
            if(mag[i].title == name && mag[i].rank == mag_rank)
            {
                x=i;
            break;

            }
        }
        cout<<"shelf no.: "<<2<<"\n";
            cout<<"row: "<<x+1;
            auto now = chrono::system_clock::now();
            auto nowTimeT = chrono::system_clock::to_time_t(now);
            time_mag[x] = ctime(&nowTimeT);
            cout<<"\nTime: "<<time_mag[x];
    }
    void location_Journal(string name)
    {
        int y=0;
        for(int i=0;i<99;i++)
        {
            if(J[i].title == name)
            {
            y=i;
            break;
            }
        }
        cout<<"shelf no.: "<<3<<"\n";
            cout<<"row: "<<y+1;
            auto now = chrono::system_clock::now();
            auto nowTimeT = chrono::system_clock::to_time_t(now);
            time_journal[y] = ctime(&nowTimeT);
            cout<<"\nTime: "<<time_journal[y]<<endl;
    }
    
    
};
class Librarian: public books
{
    private:
    int copies;
    public:
  

    void purchase_books()
    {


            cout<<"Name of new book to be purchased: ";
            getline(cin, title);
            cout<<"Name of the author: ";
            getline(cin, author);
            cout<<"ISBN no.: ";
            cin>>ISBN;
            cout<<"\ncopies:";
            cin>>copies;
            int f =0;
            for(int i=0;i<100;i++)
            {
                if(Book[i].author == author && Book[i].ISBN == ISBN)
                {
                    f=1;
                    cout<<"Book details already present";
                    Book[i].b_count += copies;
                }
            
            }
            if(f!=1)
            cout<<"\nNew Books with "<<copies<<" copies purchased successfully";
            else 
            cout<<"\nBook count updated!";
    } 



};

//main function
int main()
{
    char ch, choice;
    Library b;
    int copies, phone, id, password;
    string name_of_book, name, type, title, author, e_item, rank, J;
    Librarian L;
    b.read_books();
    b.read_magazines();
    b.read_journal();
    while(1)
    {cout<<"Library Portal:\n";
    cout<<"1.Enter as Librarian\n";
    cout<<"2.Enter as Member\n";
    cout<<"3.Exit\n";
    cout<<"Enter your choice:";
    cin>>ch;
    user u;
    switch(ch)
    {
        case '1':   
                    L.purchase_books();
                    break;
        case '2': 
                while(1)
                {
                cout<<"Member portal:\n";
                cout<<"1. New Registeration"<<endl;
                cout<<"2. Issue Item"<<endl;
                cout<<"3. Query location for some Item"<<endl;
                cout<<"4. Exit"<<endl;
                cout<<"Enter your choice:"<<endl;
                cin>>choice;
                
                switch(choice)
                {
                    case '1': 
                                cout<<"Enter user id:";
                                cin>>id;
                                cout<<"Enter user name:";
                                getline(cin,name);
                                cout<<"Enter user type:";
                                getline(cin,type);
                                cout<<"Enter user phone no.";
                                cin>>phone;
                                u.registration(name, type, phone, id);
                                break;
                    case '2':   int ch_item;
                                cout<<"Enter Item to be issued: \n 1.Book\n 2.Magazines\n 3.Journal\n 4.Ebooks\n 5.Electronics Items\nEnter your choice: ";
                                cin>>ch_item;
                                switch(ch_item)
                                {
                                    case 1: 
                                              int book_id;
                                              cout<<"Enter book id to be issued: ";
                                              cin>>book_id;
                                              u.borrow_books(book_id);
                                              break;
                                    case 2:   
                                              //string name;
                                              cout<<"Enter Magazine name: ";
                                              getline(cin,name);
                                              u.borrow_magJ(name);
                                              break;
                                    case 3:   //string J;
                                              cout<<"Enter Journal name:";
                                              getline(cin,J);
                                              u.borrow_magJ(J);
                                              break;
                                    case 4:   //string title, author;
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter Ebook name:";
                                              getline(cin,title);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter Ebook author";
                                              getline(cin,author);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Ebook "<<title<<" issued successfully!";
                                              break;
                                    case 5:   //string e_item;
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter which electronic item do you want?";
                                              getline(cin,e_item);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Electronic item "<<e_item<<" issued successfully";
                                              break;
                                    default : cout<<"Invalid option";
                                              break;
                             }
                             break;
                    case '3':   int choice_loc;
                                
                                cout<<"Enter Item to search for location: \n 1.Book\n 2.Magazines\n 3.Journal\n";
                                cin>>choice_loc;
                                switch(choice_loc)
                                {
                                    case 1: int book_id, ISBN;
                                              //string author;
                                              cout<<"Enter book id: ";
                                              cin>>book_id;
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"\nEnter book author: ";
                                              getline(cin,author);
                                              cout<<"\nEnter book ISBN: ";
                                              cin>>ISBN;
                                              u.location_books(book_id, author, ISBN);
                                              break;
                                    case 2:   
                                              //string name;
                                              //string rank;
                                              cout<<"Enter Magazine name: ";
                                              getline(cin,name);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter Magazine rank: ";
                                              getline(cin,rank);
                                              u.location_mag(name, rank);
                                              break;
                                    case 3:
                                              //string J;
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter Journal name:";
                                              getline(cin,J);
                                              u.location_Journal(J);
                                              break;
                                    default : 
                                              cout<<"Invalid option";
                                              break;
                             }
                             break;
                    case '4': cout<<"\nThanks for visiting the library!";
                              exit(0);
                    default: cout<<"Invalid option";
                             break;
                }
                }
                break;
        case '3': cout<<"\nThanks for visiting the library!";
                  exit(0); 

        default : cout<<"Invalid option";
                  break;

    }  
    }
    return 0;

}


