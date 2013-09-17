class lib
{
  int bno;
                                                                                                 
public:
  char **c, **flag;
  lib ()
  {
    for (int i = 0; i < 5; i++)
      {
        bno = i + 1;
        c = new char *[i];
        flag = new char *[i];
      }
    for (int i = 0; i < 5; i++)
      {
        c[i] = new char[20];
        flag[i] = new char[20];
      }
  }                             //end of constr
void dislib();
void getdata();
void modify(int,char[]);
void modifyr(int,char[]);
};

class Queue
{
  int size;
  char **name;
friend class lib;
public:
int head,end;
    Queue ()            //constructer of queue class
  {
    size = 5;
      head = -1, end = -1;
//this will make head & end 0,0 and will start allowing- scanning the user names in the queue
    for (int i = 0; i < size; i++)
        name = new char *[i];
                                                                                                 
    for (int i = 0; i < size; i++)
        name[i] = new char[20];
        }
                                                                                                 
  void Add (char[]);
    void display ();
char* deleteq ();
int isempty();
};//queue class end
