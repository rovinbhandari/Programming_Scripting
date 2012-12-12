#include <iostream>
#include <cstring>

using namespace std;

bool pair_socks (char *);

int main()
{
    int T;
    cin >> T;
    char c[50];
    for (int j = 0; j < 50; c[j] = '\0', j++);
    for (int i = 0; i < T; i++)
    {
        cin >> c;
        if (pair_socks (c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

bool pair_socks (char * c)
{
    int j;
    int * colour = new int[4];
    for (j = 0; j < 4; colour[j] = 0, j++);
    int len = strlen (c);
    for (j = 0; j < len; j++)
    {
        switch (c[j])
        {
            case 'R' :  colour[0]++;
                        break;
            case 'G' :  colour[1]++;
                        break;
            case 'B' :  colour[2]++;
                        break;
            case 'W' :  colour[3]++;
                        break;
        }
    }
    int flag = 1;
    for (j = 0; j < 4; j++)
        if (colour[j] % 2)
            flag = 0;
    delete[] colour;
    if (flag)
        return true;
    return false;
}
