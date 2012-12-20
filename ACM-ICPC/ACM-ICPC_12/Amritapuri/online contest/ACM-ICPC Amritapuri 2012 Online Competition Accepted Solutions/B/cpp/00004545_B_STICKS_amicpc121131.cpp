#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int numCases, numBoxes, numSticks;
    cin >> numCases;
    
    for(int i = 0; i< numCases; i++)
    {
        cin >> numSticks >> numBoxes;
        int sticks[numSticks];
        for(int j = 0; j < numSticks; j++)
        {
            cin >> sticks[j];
        }
        int boxes[numBoxes];
        double maxBox = 0;
        for(int k = 0; k < numBoxes; k++)
        {
            double l, b, h;
          cin >> l >> b >> h;
          double max = sqrt(l*l + b*b + h*h);
          boxes[k] = max;
          if(max > maxBox)
          {
              maxBox = max;
          }
        }
        int numFits = 0;
        for(int l = 0; l < numSticks; l++)
        {
           if(sticks[l] <= maxBox)
               numFits++;
        }
        cout << numFits << endl;
    }
    return 0;
}
