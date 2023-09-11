#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1002];

int binarysearch(int A[], int key, int imin, int imax, int mod);

int main()
{
    int T, N, L , H, i, j, hi, li, higher, lower, sum, range, types;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &N, &L, &H);
        for (i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+N);
        types = 0;
        for (i = 0; i < N-1; i++)
        {
            for (j = i+1; j < N; j++)
            {
                sum = arr[i] + arr[j];
                higher = (H - sum + 1);
                lower = (L - sum - 1);
                //printf("for %d, %d: higher = %d, lower = %d\n", arr[i], arr[j], higher, lower);
                hi = binarysearch (arr, higher, 0, N-1, +1) - 1;
                li = binarysearch (arr, lower, 0, N-1, -1) + 1;
                //printf("higher at %d, lower at %d\n", arr[hi], arr[li]);
                if (hi < li)
                    continue;
                range = (hi - li + 1);
                if (i >= li && i <= hi)
                    range--;
                if (j >= li && j <= hi)
                    range--;
                    
                types += range;
            }
        }
        printf("%d\n", types / 3);
    }
}


int binarysearch(int A[], int key, int imin, int imax, int mod)
{
    // continue searching while [imin,imax] is not empty
    int imid;
    while (imax >= imin)
    {
        /* calculate the midpoint for roughly equal partition */
        imid = (imin + imax) / 2;
        
        // determine which subarray to search
        if      (A[imid] <  key)
            // change min index to search upper subarray
        imin = imid + 1;
        else if (A[imid] > key )
            // change max index to search lower subarray
        imax = imid - 1;
        else
            // key found at index imid
            return imid;
    }
    // key not found
    if (mod == 1 && A[imid] > key)
        return imid;
    else if (mod == -1 && A[imid] < key)
        return imid;
    else
        return imid + mod;
}
