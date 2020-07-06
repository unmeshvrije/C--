#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <cstring>
#include <map>

using namespace std;

/*
A 65  B : - 65

a 92  

0 48
9 57
A 65

*/
#define	N	200
#define	TIME_UNIT	5

typedef struct Node
{

} Node;

int main(int argc, char *argv[])
{
  int Count[N];
  int Positions[N];
  int T,n;
/*  queue[3] = 2;
  queue[5] = 1;
  queue[1] = 6;
*/


  FILE *fp;
  fp = fopen(argv[1], "r");

  fscanf(fp,"%d", &T);
  cout << T << endl;

  for (int i = 0; i < T; ++i)
  {
    fscanf(fp, "%d ", &n);
    cout << n <<endl;

    memset(Positions, 0, sizeof(Positions));
    memset(Count, 0, sizeof(Count));
    map <int, int> queue;
    map <int, int>::const_iterator iter;

    for (int j = 0; j < n; ++j)
    {
      int ch = fgetc(fp);
      cout << "ch = " << ch << endl;
      Count[ch]++;
      Positions[ch] = j+1;
    }

    int TotalWait = 0;

    for (int j = 0; j < N; ++j)
    {
       if (Positions[j] > 0)
       {
          queue[Positions[j]] = j;
	  cout << "pos[" << j << "] = "  << Positions[j] << endl;
	  TotalWait += Positions[j] * Count[j] * TIME_UNIT;
       }
    }

    int CurPos = 0;
    int OptWait = 0;
    for (iter = queue.begin(); iter != queue.end(); iter++)
    {
      CurPos +=  Count[iter->second];
      OptWait += Count[iter->second] * CurPos * TIME_UNIT;
      //cout << iter->second << " " << iter->first << endl;
    }

    cout << "total = " << TotalWait << " Opt = " << OptWait << endl;
    cout <<  TotalWait - OptWait << endl;

  }

  fclose(fp);
  return 0;
}
