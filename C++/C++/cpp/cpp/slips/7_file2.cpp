#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAX 12

class File
{
  fstream fp;
  char fn[MAX];
public:
  void display ();
  void operator - ();
  File& operator+(File& f2);
  File& operator=(File&);
    File ();
    File(char fnm[]);
    File(File &f);
   
   
};

File::File(File &f2)
{
  strcpy(this->fn,f2.fn);
}



File& File ::operator=(File &f2)
{
  strcpy(this->fn,f2.fn);
}

File& File:: operator+(File &f2)
{

   File tempFile;
   
   tempFile.fp.open(tempFile.fn,ios::out); 
   int temp = tempFile.fp.rdstate();
   cout << "temp = " << temp <<endl;
   if(temp == 0)
   {
     cout <<endl <<" Now we can write in file";
     (this->fp).clear();
     (this->fp).open(this->fn,ios::in);
     while(!(this->fp).eof())
     {
     	char c;
       (this->fp).get(c);
       if(!(this->fp).eof())
         tempFile.fp.put(c);
     }
     (this->fp).close();
     
     (f2.fp).clear();
     (f2.fp).open(f2.fn,ios::in);
     while(!(f2.fp).eof())
     {
     	char c;
       (f2.fp).get(c);
       if(!(f2.fp).eof())
         tempFile.fp.put(c);
     }
     f2.fp.close();
   }
  
   tempFile.fp.close();
  return tempFile;
}



void
File::operator- ()
{
  char c;		// f2 will be this
  fp.open(fn,ios::in);
  int temp = fp.rdstate();
  cout <<endl<< "after opening in read mode ; " <<temp;
  if(temp != 0)
  {
    fp.clear();
  }
  fp.close();
  fp.open (fn, ios::in | ios::out);
  int t = fp.rdstate ();
  cout << "\n In oprt - t=" << t;
  if (t == 0)
    {
      fp.seekg (0, ios::beg);
      while (1)
	{
	  fp.get (c);
	  cout <<endl<< "c = " << c;
	  
	  if (fp.eof ())
	    break;
	  if (!fp.eof ())
	    {
	      if (c >= 'A' && c <= 'Z')
		{
		/*
		AbCFdEGGD
		
		*/
		  c += 32;
		  fp.seekg (-1, ios::cur);
		  fp.put (c);
		  int temp = fp.rdstate();
		  cout << endl<<"after putting '" << c << "' into file : "<<temp;
		  getchar();
		}
	      else if (c >= 'a' && c <= 'z')
		{
		  c -= 32;
		  fp.seekg (-1, ios::cur);
		  fp.put (c);
		  int temp = fp.rdstate();
		  cout << endl<<"after putting '" << c << "' into file : "<<temp;
		  getchar();
		}
	    }
	}
	 fp.close ();
    }
}

File::File ()
{
  char name[30];
  cout << "Please enter filename : ";
  cin >> name;
  if (strlen (name) > 12)
    cout << "Max 12 chars are allowed";
  else
    strcpy (this->fn, name);
}

void
File::display ()
{
  char c;
  fp.clear();
  fp.open (fn, ios::in);
  int t = fp.rdstate ();
  if (t != 0)
    {
      cout << "\n\t\tFile is not created yet, please create";
    }
  else
    {
      fp.seekg (0, ios::beg);
      while (!fp.eof ())
	{
	  fp.get (c);
	  if (!fp.eof ())
	    cout << c;
	}
    }
  fp.close ();
}

main ()
{
  File f1;
  f1.display ();
  File f2;
  f2.display ();
	
  File f3;
    
  f3 = f1 + f2;
  //-f2;
  //f2.display ();

}
