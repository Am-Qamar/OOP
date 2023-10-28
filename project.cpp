#include <iostream>
#include <fstream>
#include <cstring>
#include<stdlib.h>
using namespace std;
class M_Name{               //class of name of the movie
string name;
public:
    M_Name()                //default constructor
    {
        name="No-Name";
    }
    M_Name(string n)       //parametrize constructor
    {
        setName(n);
    }
    //setter getter
    void setName(string n)
    {
        name=n;
    }
    string GetName()
    {
        return name;
    }
    void Display()
    {
        cout<<"Name: "<<GetName()<<endl;
    }


    friend ifstream& operator>>(ifstream &in,M_Name &obj);  //overload >> for read data from file for M_Name class
    friend ofstream& operator<<(ofstream &out,M_Name &obj);  //overload << for write data on file for M_Name class
};

   ifstream& operator>>(ifstream &in,M_Name &obj)
    {in>>obj.name;}
    ofstream& operator<<(ofstream &out,M_Name &obj)
    {out<<obj.name<<endl;}
class M_Year     //class of the year release of the movie
{
    int year;
public:
    M_Year()            //default constructor
    {
        year=0;
    }
    M_Year(int y)      //overloaded constructor
    {
        setYear(y);
    }
    //setter getter
    void setYear(int s)
    {year=s;}
    int GetYear()
    {return year;}
    void Display()
    {
        cout<<"Year: "<<year<<endl;
    }
    friend ifstream& operator>>(ifstream &in,M_Year &obj);  //overload >> for read data from file for M_Year class
    friend ofstream& operator<<(ofstream &out,M_Year &obj);  //overload << for write data on file for M_Year class
};
   ifstream& operator>>(ifstream &in,M_Year &obj)
    {in>>obj.year;}
    ofstream& operator<<(ofstream &out,M_Year &obj)
    {out<<obj.year<<endl;}
class Stars                           //class of the stars of the movie
    {
        string str1;
        string str2;
    public:
        Stars()       //default constructor
        {
            str1="No";
            str2="no";
       }
       Stars(string n1,string n2)  //overloaded constructor
       {
           setStr1(n1);
           setStr2(n2);
       }
       void setStr1(string n1)
       {str1=n1;}
       void setStr2(string n2)
       {str2=n2;}
       string GetStr1()
       {return str1;}
       string GetStr2()
       {return str2;}
       void Display()
       {
           cout<<"Star 1: "<<GetStr1()<<endl;
           cout<<"Star 2: "<<GetStr2()<<endl;
        }
    friend ifstream& operator>>(ifstream &in,Stars &obj);  //overload >> for read data from file of class stars
    friend ofstream& operator<<(ofstream &out,Stars &obj);  //overload << for write data on file of class stars
};
    ifstream& operator>>(ifstream &in,Stars &obj)
    {
     in>>obj.str1;
     in>>obj.str2;
    }
    ofstream& operator<<(ofstream &out,Stars &obj)
    {
      out<<obj.str1<<endl;
      out<<obj.str2<<endl;
    }
class Movie      // Movie class Compose (M_name,M_Year,Stars)
   {
       M_Name obj;
       M_Year obj2;
       Stars  obj3;
       int NumOfCopy;
       int NumOfCopyRe;
   public:
    Movie() //default constructor
    {
        NumOfCopy=0;
        NumOfCopyRe=0;
    }
    Movie(string n,int y,string s,string s2,int N,int NR):obj(n),obj2(y),obj3(s,s2) //overloaded constructor with member initializing list
{
        setNumOfCopy(N);
        setNumOfCopyRe(NR);
}
    void setAll()   //set all values after taking from user
{
        string na,c,c2;
        int r;
        cout<<"Enter Name of the Movie: ";
        cin.ignore();
        getline(cin,na);
        cout<<"Enter Year release of the Movie: ";
        cin>>r;
        cout<<"Enter star's Name of the Movie: ";
        cin>>c;
        cout<<"Enter 2nd Star's Name of the Movie: " ;
        cin>>c2;
        int cop,Rcop;
        obj.setName(na);
        obj2.setYear(r);
        obj3.setStr1(c);
        obj3.setStr2(c2);
        cout<<"Enter Number of Copies of the movie: ";
        cin>>cop;
        setNumOfCopy(cop);
        cout<<"Enter return copies: ";
        cin>>Rcop;
        setNumOfCopyRe(Rcop);
}
   void setNumOfCopy(int N)
   { this->NumOfCopy=N; }
   void setNumOfCopyRe(int NR)
   { this->NumOfCopyRe=NR; }
   int GetNumOfCopy()
   { return NumOfCopy; }
   int GetNumOfCopyRe()
   { return NumOfCopyRe; }
   string GetName()
   { return obj.GetName(); }
   int GetYear()
   { return obj2.GetYear(); }
   string GetStr1()
   { return obj3.GetStr1(); }
   string GetStr2()
   { return obj3.GetStr2(); }
   void CopiesAdd()
   {
       int ad;
       cout<<"enter the number of movies that you want to return: ";
       cin>>ad;
       setNumOfCopyRe(GetNumOfCopyRe()-ad);
   }
   void CopiesSub()
   {
       int Sub;
       cout<<"enter the number of movies that you want to take: ";
       cin>>Sub;
       setNumOfCopyRe(GetNumOfCopyRe()+Sub);

   }
    void Display()
    {
        obj.Display();
        obj2.Display();
        obj3.Display();
        cout<<"Number of copies : "<<GetNumOfCopy()<<endl;
        cout<<"Number of copies return: "<<GetNumOfCopyRe()<<endl;
    }

    friend ifstream& operator>>(ifstream &in,Movie &obj);  //overload >> for read data from file for class
    friend ofstream& operator<<(ofstream &out,Movie &obj);  //overload << for write data on file for class
};
ifstream& operator>>(ifstream &in,Movie &mov)
    {
     in>>mov.obj;
     in>>mov.obj2;
     in>>mov.obj3;
     in>>mov.NumOfCopy;
     in>>mov.NumOfCopyRe;
     }
    ofstream& operator<<(ofstream &out,Movie &mov)
    {
      out<<mov.obj;
      out<<mov.obj2;
      out<<mov.obj3;
      out<<mov.NumOfCopy<<endl;
      out<<mov.NumOfCopyRe<<endl;
    }
class Movie_Store  //class Movie store (Aggregate movie class in it)
   {
       Movie *ptr;
       int Size;
   public:
    Movie_Store() //default constructor
{
        ptr=NULL;
        Size=0;
}
    Movie_Store(int size)  // overloaded constructor
{
        setsize(size);
        ptr=new Movie[size];
}
    ~Movie_Store()
{
        delete[] ptr;
        ptr=NULL;
}

    void setsize(int s)
    {Size=s;}
    int GetSize()
    {return Size;}
void InsertNew()   // that function will insert a new record in file
{
        ofstream out;
        out.open("Movie store.txt",ios::app);
            Movie New;
            New.setAll();
            out<<New;
            out.close();
}
void InserArray()  // that will insert the number of records
{
        ofstream out;
        out.open("Movie store.txt",ios::app);
        for(int i=0;i<Size;i++)
        {
            ptr[i].setAll();
            out<<ptr[i];
        }
       out.close();
}
void Search()  //search
{
        cout<<"Do You want to search movie \n1.Name \n2.Year \n3.Stars"<<endl;
        int Choice;
        cin>>Choice;
        Movie read;
        ifstream on;
        on.open("Movie store.txt");
        switch(Choice)
{
         case 1:
            {
          string S_name;
          cout<<"please Enter Name : ";
          cin>>S_name;
          while(!on.eof()){
          on>>read;
                  if((S_name.compare(read.GetName()))==0)
                     {
                    read.Display();
                    on.close();
                    return;
                     }}
           }
        case 2:
            {
                 int S_year;
                 cout<<"Enter Year for search : ";
                 cin>>S_year;
                 while(!on.eof()){
                 on>>read;
                if(S_year==read.GetYear())
                {
                    read.Display();
                   on.close();
                   return;}}
            }
        case 3:
            {
               string s_star;
               cout<<"Enter Name of star for search : ";
               cin>>s_star;
               while(!on.eof()){
               on>>read;
              if((s_star.compare(read.GetStr1()))==0)
              {
                read.Display();
                on.close();
                return;
             }
             else if((s_star.compare(read.GetStr2()))==0)
            {
               read.Display();
               on.close();
               return;}}}

        default:
            cout<<"invalid Choisce"<<endl;
}
       cout<<"Not found"<<endl;
}
void Dislay()
{
      Movie obj;
      ifstream in;
      in.open("Movie store.txt");
      int i=1;
      in>>obj;
       while(!in.eof())
            {
           cout<<"----- Record " << i<<" -------"<<endl;
           obj.Display();
           in>>obj;
           i++;
            }
     in.close();
}
void Update()
{
      Movie obj;
      ifstream in;
      in.open("Movie store.txt");
      int i=0;
      while(!in.eof())
           {
              in>>obj;
              i++;
           }
           in.close();
      Movie arr[i];
      ifstream fin;
      fin.open("Movie store.txt");
              for(int j=0;j<i;j++)
              {
              fin>>arr[j];
              }
      fin.close();
      cout<<"Enter the name of the movie that you want to Update: ";
      string check;
      cin>>check;

  	for(int j=0; j<i; j++)
	{
		if(arr[j].GetName()==check)
		{
          arr[j].setAll();
		}
	}

	ofstream out;
	out.open("Movie store.txt");
	for(int j=0;j<(i-1);j++)
    {
        out<<arr[j];
    }
    out.close();
    }
void CheckAvilable()
    {
        ifstream on;
        on.open("Movie store.txt");
        string C_name;
        cout<<"please Enter Name : ";
        cin>>C_name;
        Movie s;
        on>>s;
        while(!on.eof()){
        on>>s;
             if((C_name.compare(s.GetName()))==0)
                    {
                   if(s.GetNumOfCopy()>0)
                        {

                        cout<<"Avilable "<<(s.GetNumOfCopy()-s.GetNumOfCopyRe())<<" Copies"<<endl;
                        }
                        else
                        {
                            cout<<"No copy available "<<endl;
                        }
                      }
               }
               on.close();
}
void changeAvail()
         {
            Movie obj;
         ifstream in;
         in.open("Movie store.txt");
         int i=0;
         while(!in.eof())
           {
              in>>obj;
              i++;
           }
           in.close();
        Movie arr[i];
        ifstream fin;
        fin.open("Movie store.txt");
        for(int j=0;j<i;j++)
{
       fin>>arr[j];
}
        fin.close();
        cout<<"Enter the name of the movie that you want to to take rent or return: ";
        string check;
        cin>>check;
        for(int j=0; j<i; j++)
	    {
		  if(arr[j].GetName()==check)
		{
		    int chose;
		    cout<<"What do you want \n1.Take \n2.Return"<<endl;
		    cin>>chose;
		    if(chose==1)
            {
              arr[j].CopiesSub();
              cout<<"you can check available copies using check function(`,`) "<<endl;
            }
            else if(chose==2)
            {
                arr[j].CopiesAdd();
                cout<<"  you can check available copies using check function(`.`) "<<endl;
            }
            }
	}

	ofstream out;
	out.open("Movie store.txt");
	for(int j=0;j<(i-1);j++)
    {
        out<<arr[j];
    }
    out.close();
}

void Delete()
{
      Movie obj;
      ifstream in;
      in.open("Movie store.txt");
      in>>obj;
      int i=0;
      while(!in.eof())
           {
              in>>obj;
              i++;
           }
           in.close();
   Movie arr[i];
   ifstream fin;
   fin.open("Movie store.txt");
   for(int j=0;j<i;j++)
   {
       fin>>arr[j];
   }
      fin.close();
      cout<<"Enter the name of the movie that you want to delete"<<endl;
      string check;
      cin>>check;
      for(int j=0;j<i;j++)
      {
          if(arr[j].GetName()==check)
          {
              for(int k=j;k<(i-1);k++)
              {
                  arr[k]=arr[k+1];
              }
              break;
          }
      }
	ofstream out;
	out.open("Movie store.txt");
	for(int j=0;j<(i-1);j++)
    {
        out<<arr[j];
    }
    out.close();
    }

};

class Menu
{

public:
    void menu()
{
        cout<<"            ---------------------------------"<<endl;
        cout<< "                    **** MENU *****          "<<endl;
        cout<<"            ---------------------------------"<<endl;
        cout<<"                1.Insert Record "<<endl;
        cout<<"                2.Update Record "<<endl;
        cout<<"                3.Search Record "<<endl;
        cout<<"                4.Delete Record "<<endl;
        cout<<"                5.Display Record "<<endl;
        cout<<"                6.Check Availability"<<endl;
        cout<<"                7.change Availability"<<endl;
        cout<<"                8.Exit"<<endl;
}
void DisplayMenu(){
        Movie_Store obj;
        int choice;
        char c;
        do{
          menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            int check;
            cout<<"------Do you want to enter \n---1.single Record\n---2.Multipal record"<<endl;
            cin>>check;
            if(check==1){
            obj.InsertNew();
                        }
          else if(check==2)
          {
              int Record;
              cout<<"Enter the number of record that you want to enter"<<endl;
              cin>>Record;
              Movie_Store obj1(Record);
              obj1.InserArray();
          }
        break;
        case 2:
            obj.Update();
        break;
        case 3:
            obj.Search();
        break;
        case 4:
            obj.Delete();
        break;
        case 5:
            obj.Dislay();
        break;
        case 6:
            obj.CheckAvilable();
        break;
        case 7:
            obj.changeAvail();
        break;
        case 8:exit(0);
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }

            cout<<"Do you want to go Main menu Again  if yes then press y"<<endl;
            cin>>c;
         }while(c=='y'||c=='Y');
        }
};
int main()
{
   Menu obj;
   obj.DisplayMenu();
}
