#include <iostream>
#include <string>
using namespace std;

int main()
{
   char s[30];
   int i;
   //display a message to user to enter the string
   cout<<"Enter the String in lowercase: "; 
   //storing the string into the char array 
   cin>>s;

   /* running the loop from 0 to the length of the string
    * to convert each individual char of string to uppercase
    * by subtracting 32 from the ASCII value of each char
    */
   for(i=0;i<=s;i++) { 
      /* Here we are performing a check so that only lowercase 
       * characters gets converted into uppercase. 
       * ASCII value of a to z(lowercase chars) ranges from 97 to 122 
       */ 
      if(s[i]>=97 && s[i]<=122)
      {
		s[i]=s[i]-32;
      }
   }
   cout<<"The entered string in uppercase: "<<s;
   return 0;
}
