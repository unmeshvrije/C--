#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

typedef struct MESSAGE
{
   int msgid;
   int (*msg_handler)();

} MESSAGE;

typedef struct CLASS
{
   struct CLASS *base_class;
   int DataSize;
   int NumMessages;
   MESSAGE *messages;

} CLASS;


typedef struct OBJECT
{
   void *pData;
   CLASS *pClass;   

} OBJECT;

#define	ALLOCATE_DATA	1
#define	COMPUTE_AREA	3


OBJECT * newCircle(double, double, double);
OBJECT * newRectangle(double, double, double, double);


int send_message(OBJECT* pObj, int MsgId, ...);
int class_message(CLASS *pClass, OBJECT *pObj, int msgid, va_list argp);

void *allocate_memory(size_t bytes);
int get_offset(CLASS *pClass);
