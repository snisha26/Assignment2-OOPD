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

