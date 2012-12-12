#include <iostream>
#include <string>


using namespace std;
int main()
{
    int no_of_inputs;
    //0-Red
    //1-Blue
    //2-Green
    //3-White
    bool socks[4];
    for ( int i=0; i<=3; i++ )
        socks[i] = true;
       
    int t;
    cin >> t;
    //char c;
    //cin >> c;
    string c;
    cin >> c;
   
    int x = 1;
    while ( x <= t )
    {
        for ( int i=0; i < c.length() ; i++ )
        {
                if ( c.at(i) == 'R' )
                    if ( socks[0] )
                        socks[0] = false;
                    else
                        socks[0] = true;
                else if ( c.at(i) == 'B' )
                    if ( socks[1] )
                        socks[1] = false;
                    else
                        socks[1] = true;
                else if ( c.at(i) == 'G' )
                    if ( socks[2] )
                        socks[2] = false;
                    else
                        socks[2] = true;
                else
                    if ( socks[3] )
                        socks[3] = false;
                    else
                        socks[3] = true;
           
            }   
        cin >> c;
        bool paired = true;
        for ( int i=0; i<=3; i++ )
            if ( ! socks[i] )
            {
                paired = false;
                break;
            }
        if ( paired )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        for ( int i=0; i<=3; i++ )
            socks[i] = true;
        x++;
    }
    return 0;
}
