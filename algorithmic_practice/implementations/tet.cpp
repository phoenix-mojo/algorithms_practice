#include <string>
#include <ctype.h>
...
string rawInput;
cout << "Enter a number, or numbers separated by a space, between 1 and 1000." << endl;
while( getline( cin, rawInput, ' ') )
{
  bool isNum = true;
  for(int i = 0; i < rawInput.length() && isNum; ++i)
  {
    isNum = isdigit( rawInput[i]);
  }

  if(isNum)
  {
    num = atoi( rawInput.c_str() );
    ...//do your stuff
  }
  else
    cout << rawInput << " is not a number!" << endl;
}