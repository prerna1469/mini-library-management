

#include <iostream>
#include<string.h>
using namespace std;
class Book
{
	string title;
	string name;
	long isbn;
	string publisher;
	friend class Library;

public:
	Book()//default constructor of Book
	{
		title="\0";
		name="\0";
		isbn=0;
		publisher="\0";
	}
	void accept();//accept book details
	void display();//display book details
};
void Book::accept()
{
    string str;
    cout<<"\n Enter title of book ";
    getline(cin,str);
    getline(cin,title);
    cout<<"\n Enter name of author ";
    getline(cin,name);
    cout<<"\n Enter name of publisher ";
    getline(cin,publisher);
    cout<<"\n Enter ISBN no of book ";
    cin>>isbn;

}
void Book::display()
{
    cout<<"\n Title of book is "<<title;
    cout<<"\n Name of author is "<<name;
    cout<<"\n ISBN no of book is "<<isbn;
    cout<<"\n Name of publisher is "<<publisher;
}
class Library
{
    Book arr[20];//array of objects of type Book
    int num;//to store no of books
public:
	Library()//default constructor of Library
	{
	    num=0;
	}
	void create_booklist();
	void display_books();
	void search_book();
	void sort();
	void list_books();
	void insert();
};
void Library::create_booklist()//to add boos
{
    int i=0;
	cout<<"\n Enter no of books ";
	cin>>num;
	for(i=0;i<num;i++)//loop for items
	{
		arr[i].accept();//accept all books
	}
}
void Library::display_books()
{
    int i=0;
	cout<<"\n No of books are: "<<num;
	for(i=0;i<num;i++)
	{
		arr[i].display();//display all books
	}
}
void Library::search_book()
{
    string title1="\0";
	string str;
	int flag=0;
	int i=0;
	int pos=0;
	int temp=0;
	cout<<"\n Enter the book to be searched ";
	getline(cin,str);
	getline(cin,title1);
	for(i=0;i<num;i++)
	{
	    temp=title1.compare(arr[i].title);//comparing titles
	    if(temp==0)
	    {
	        pos=i;
	        flag=1;
	        break;
	    }
	}
	if(flag==1)
	{
	    cout<<"\n"<<title1<<" is found at position "<<pos;
	    cout<<"\n Details of "<<title1<<" are :";
	    for(i=0;i<num;i++)
	    {
		    arr[pos].display();//display details of book found
		    break;
	    }
	}
	else{
	    cout<<"\n Book not found";
	}
}
void Library::sort()
{
    //using bubble sort
	Book temp;
    int i=0;
    int j=0;
    cout<<"\n Before sorting: ";
    cout<<"\n Title ";
    cout<<"\t\t Author ";
    cout<<"\t Publisher ";
    cout<<"\t ISBN no ";
    for(i=0;i<num;i++)
    {
        cout<<"\n "<<arr[i].title;
        cout<<"\t "<<arr[i].name;
        cout<<"\t "<<arr[i].publisher;
        cout<<"\t "<<arr[i].isbn;
    }
    cout<<"\n After sorting: ";
    cout<<"\n Title ";
    cout<<"\t\t Author ";
    cout<<"\t Publisher ";
    cout<<"\t ISBN no ";
    for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
		    if(arr[j].isbn>arr[j+1].isbn)
		    {
		        temp=arr[j];
		        arr[j]=arr[j+1];
		        arr[j+1]=temp;
		    }
		}
	}
	for(i=0;i<num;i++)
    {
        cout<<"\n "<<arr[i].title;
        cout<<"\t "<<arr[i].name;
        cout<<"\t "<<arr[i].publisher;
        cout<<"\t "<<arr[i].isbn;
    }
}
void Library::list_books()
{
    //listing all books of a specified author
	string name1="\0";
	string str;
	int flag=0;
	int i=0;
	int temp=0;
	cout<<"\n Enter the author to be searched ";
	getline(cin,str);
	getline(cin,name1);
	for(i=0;i<num;i++)
	{
	    temp=name1.compare(arr[i].name);
	    if(temp==0)
	    {
	        flag=1;
	        arr[i].display();
	    }
	}
	if(flag==0)
	{
	    cout<<"\n Author not found";
	}
}
void Library::insert()
{
    int pos=0;
    int i=0;
    for(i=0;i<num;i++)
    {
        pos=i;
    }
    arr[pos+1].accept();
    num++;
}
int main()
{
    Library ob;
    int ch=0;
	do
	{
	    do
	    {
	        cout<<"\n Menu";
        	cout<<"\n 1.Create a list of books";
        	cout<<"\n 2.Display list of books";
        	cout<<"\n 3.Search a book in the library";
        	cout<<"\n 4.List all the books of a specified author";
        	cout<<"\n 5.Sort books according to isbn no";
        	cout<<"\n 6.Insert details of a book ";
        	cout<<"\n 0.Exit";
        	cout<<"\n Enter choice = ";
        	cin>>ch;
    	}while(ch<0 && ch>6);
    	switch(ch)
    	{
    	    case 1: ob.create_booklist();
    	            break;
    	    case 2: ob.display_books();
    	            break;
    	    case 3: ob.search_book();
    	            break;
    	    case 4: ob.list_books();
    	            break;
    	    case 5: ob.sort();
    	            break;
            case 6: ob.insert();
                    ob.display_books();
                    break;
    	    case 0: cout<<"\n End of program.Thank you";
    	            break;
    	    default: cout<<"\n Invalid entry,please enter again";
    	            break;

    	}
	}while(ch!=0);


    return 0;
}
/*Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 1

 Enter no of books 3

 Enter title of book inferno

 Enter name of author dan brown

 Enter name of publisher emperical

 Enter ISBN no of book 1

 Enter title of book harry potter

 Enter name of author jk rowling

 Enter name of publisher bloomsbury

 Enter ISBN no of book 3

 Enter title of book lost symbol

 Enter name of author dan brown

 Enter name of publisher emperical

 Enter ISBN no of book 2

 Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 2

 No of books are: 3
 Title of book is inferno
 Name of author is dan brown
 ISBN no of book is 1
 Name of publisher is emperical
 Title of book is harry potter
 Name of author is jk rowling
 ISBN no of book is 3
 Name of publisher is bloomsbury
 Title of book is lost symbol
 Name of author is dan brown
 ISBN no of book is 2
 Name of publisher is emperical
 Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 3

 Enter the book to be searched inferno

inferno is found at position 0
 Details of inferno are :
 Title of book is inferno
 Name of author is dan brown
 ISBN no of book is 1
 Name of publisher is emperical
 Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 4

 Enter the author to be searched dan brown

 Title of book is inferno
 Name of author is dan brown
 ISBN no of book is 1
 Name of publisher is emperical
 Title of book is lost symbol
 Name of author is dan brown
 ISBN no of book is 2
 Name of publisher is emperical
 Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 5

 Before sorting:
 Title 		 Author 	 Publisher 	 ISBN no
 inferno	 dan brown	 emperical	 1
 harry potter	 jk rowling	 bloomsbury	 3
 lost symbol	 dan brown	 emperical	 2
 After sorting:
 Title 		 Author 	 Publisher 	 ISBN no
 inferno	 dan brown	 emperical	 1
 lost symbol	 dan brown	 emperical	 2
 harry potter	 jk rowling	 bloomsbury	 3
 Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 6

 Enter title of book abc murders

 Enter name of author agatha christie

 Enter name of publisher revington

 Enter ISBN no of book 4

 No of books are: 4
 Title of book is inferno
 Name of author is dan brown
 ISBN no of book is 1
 Name of publisher is emperical
 Title of book is lost symbol
 Name of author is dan brown
 ISBN no of book is 2
 Name of publisher is emperical
 Title of book is harry potter
 Name of author is jk rowling
 ISBN no of book is 3
 Name of publisher is bloomsbury
 Title of book is abc murders
 Name of author is agatha christie
 ISBN no of book is 4
 Name of publisher is revington
 Menu
 1.Create a list of books
 2.Display list of books
 3.Search a book in the library
 4.List all the books of a specified author
 5.Sort books according to isbn no
 6.Insert details of a book
 0.Exit
 Enter choice = 0

 End of program.Thank you*/

