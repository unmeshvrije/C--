
#define TYPE_CIRCLE	1
#define TYPE_RECT	2

typedef struct CIRCLE
{
   short type;
   int x,y;
   int radius;
}CIRCLE;

typedef struct RECTANGLE
{
   short type;
   int l;
   int b;
}RECT;

typedef struct SHAPE
{
    short type;
    union
    {
       CIRCLE c;
       RECT r;
    };

}SHAPE;

double
Compute_Area(
  SHAPE *pShape
  );

