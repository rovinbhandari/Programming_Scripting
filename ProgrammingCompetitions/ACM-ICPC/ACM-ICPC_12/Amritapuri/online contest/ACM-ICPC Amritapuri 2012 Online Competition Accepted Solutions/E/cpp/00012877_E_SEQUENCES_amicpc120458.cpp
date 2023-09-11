#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i=0; i<T; i++)
	{
		int N; cin >> N;
		string seqStr; cin >> seqStr;
		vector<int> seq;
		for (int j=0; j<N; j++) {seq.push_back((int)(seqStr[j]-48));}
		vector<int> numZero, numOnet, numOne;
		int num0= 0, num1= 0;
		for (int j=0; j<N; j++) 
		{
			if (seq[j]==0) {numZero.push_back(++num0);}
			else numZero.push_back(num0);
		}
		
		for (int j=N-1; j>-1; j--) 
		{
			if (seq[j]==1) {numOnet.push_back(++num1);}
			else numOnet.push_back(num1);
		}
		
		
		vector<int> sums;
		for (int j=0; j<N; j++) 
		{
			numOne.push_back(numOnet[N-1-j]);
			sums.push_back(numZero[j] + numOne[j]);
		}
		
		
		int rootN= sqrt(N);
		vector<int> segSums, segIndices;
		int k=0;
		while (k<N)
		{
			int segMin=0, lMin=0;
			for (int l=0; l<rootN; l++)
			{
				if (segMin < sums[l+k]) {segMin = sums[l+k]; lMin= l;}
			}
			segSums.push_back(segMin);
			segIndices.push_back(lMin+k);
			k+=rootN;
		}
		
		int Q; cin >> Q;
		for (k=0; k<Q; k++)
		{
			int a, b; cin >> a >> b;
			a--; b--;
			
			int lowSeg= a/rootN, hiSeg= b/rootN;
			
			vector<int> toCompareSums, toCompareIndices;
			
			for (int l=lowSeg+1; l<hiSeg; l++)
			{
				toCompareSums.push_back(segSums[l]);
				toCompareIndices.push_back(segIndices[l]);
			}
			
				int bdr1= min(b+1, rootN*(lowSeg+1));
				int bdr2= max(a, rootN*hiSeg);
				
				int minSeg1=0, minSegIndex1=0;
				for (int m=a; m<bdr1; m++)
				{
					if (sums[m]>minSeg1) {minSeg1= sums[m]; minSegIndex1= m;}
				}
				toCompareSums.push_back(minSeg1);
				toCompareIndices.push_back(minSegIndex1);
				
				int minSeg2=0, minSegIndex2=0;
				for (int m=bdr2; m<=b; m++)
				{
					if (sums[m]>minSeg2) {minSeg2= sums[m]; minSegIndex2= m;}
				}
				toCompareSums.push_back(minSeg2);
				toCompareIndices.push_back(minSegIndex2);
				
				int numComp= toCompareSums.size();
				int maxRange=0, maxIndex=0;
				for (int aa=0; aa<numComp; aa++)
				{
					if (toCompareSums[aa]>maxRange) {maxRange= toCompareSums[aa]; maxIndex=aa;}
				}
				int finalSum= sums[toCompareIndices[maxIndex]];
				if (a>0) {finalSum-=numZero[a-1];}
				if (b<N-1) {finalSum-=numOne[b+1];}
			cout << finalSum << endl;
		}
		
	}

	return 0;
}
