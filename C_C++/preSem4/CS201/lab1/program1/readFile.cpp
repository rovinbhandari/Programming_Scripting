#include<readFile.h>
ifstream fOpen(string filename)
{
  ifstream f;
  f.open(filename);
  return f;
}
string fReadline(string filename, int n)
{
  ifstream f;
  string s;
  f.getline(s);
  return s;
}
void fClose(string filename)
{
  ifstream f;
  f.close(filename);
}
