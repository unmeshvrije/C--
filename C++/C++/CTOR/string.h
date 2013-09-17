class String
{
   private:
     char *str;
     int len;

   public:
     String();
     String(const String& temp);
     String(const char *str, int len);
     ~String();

     char* GetString(void);
};
