# include <iostream>
# include <cstring>
# include <vector>

using namespace std;

int main ()
	{
		int t, max1, tho_max1, hmax, tmax, absmax;
		cin >> t;
		
		while ( t-- > 0 )
		{
			int len;
			cin >> len;
			
			string test;
			cin >> test;
			
			vector<int> numz(len+1);
			numz[0] = 0;
			 
			for(int a = 1; a <= len; a++ )
			{
				if(test.at(a-1) == '0') { numz[a] = numz[a-1] + 1; }
				else { numz[a] = numz[a-1] - 1; }
			}
			
			vector<int> ten;
			vector<int> hun;
			vector<int> tho;
			
			for ( int tx = 0; tx <= len; tx = tx+10 )
			{
				max1 = -len;
				
				for ( int cx = 0; cx < 10; cx++ )
				{
					if( (tx + cx <= len ) && numz[tx+cx] > max1){ max1 = numz[tx+cx]; }	
				}
				
				ten.push_back(max1);
			}
			
			for ( int tx = 0; tx < ten.size(); tx = tx+10 )
			{
				max1 = -len;
				
				for ( int cx = 0; cx < 10; cx++ )
				{
					if( (tx + cx < ten.size() ) && ten[tx+cx] > max1){ max1 = ten[tx+cx]; }	
				}
				
				hun.push_back(max1);
			}
			
			for ( int tx = 0; tx < hun.size(); tx = tx+10 )
			{
				max1 = -len;
				
				for ( int cx = 0; cx < 10; cx++ )
				{
					if( (tx + cx < hun.size() ) && hun[tx+cx] > max1){ max1 = hun[tx+cx]; }	
				}
				
				tho.push_back(max1);
			}
			
			int q;
			cin >> q;
			while ( q-- > 0 )
			{
				tho_max1 = -len, hmax = -len; tmax = -len, absmax = -len;
				int a, b;
				cin >> a >> b;
				
				a--;
				
				int ia = (a+999)/1000, ib = (b/1000);
				
				for (int ax = ia; ax < ib; ax++ )
				{
					if ( tho[ax] > tho_max1 ) { tho_max1 = tho[ax]; }
				}
				
				hmax = tho_max1;
				int ha = (a+99)/100, hb = (b/100);
				if (hb > ia*10) {
					for ( int tx = ha; tx < (ia * 10 ); tx++ )
					{
						if ( hun[tx] > hmax ) { hmax = hun[tx]; }
					}
				
					for ( int tx = ( ib * 10 ); tx < hb; tx ++ )
					{
						if ( hun[tx] > hmax ) { hmax = hun[tx]; }
					}
				}
				else {
					for ( int tx = ha; tx < hb; tx++ )
					{
						if ( hun[tx] > hmax ) { hmax = hun[tx]; }
					}
				}
				tmax = hmax;
				int ta = (a+9)/10, tb = (b/10);
				if (tb > ha*10) {
					for ( int tx = ta; tx < ( ha * 10 ); tx ++ )
					{
						if ( ten[tx] > tmax ){ tmax = ten[tx]; }
					}
				
					for ( int tx = hb * 10; tx < tb; tx++ )
					{
						if ( ten[tx] > tmax ){ tmax = ten[tx]; }
					}
				}
				else {
					for ( int tx = ta; tx < tb; tx++ )
					{
						if ( ten[tx] > tmax ){ tmax = ten[tx]; }
					}
				}
				
				absmax = tmax;
				if (b >= ta*10) {
					for ( int tx = a; tx < ta * 10; tx++ )
					{
						if( numz[tx] > absmax ) { absmax = numz[tx]; }
					}
				
					for ( int tx = tb * 10; tx <= b; tx++ )
					{
						if( numz[tx] > absmax ) { absmax = numz[tx]; }
					}
				}
				else {
					for ( int tx = a; tx <= b; tx++ )
					{
						if( numz[tx] > absmax ) { absmax = numz[tx]; }
					}
				}
				
				
				int sol = absmax + ( b - a -numz[a] - numz[b] )/2;
				cout << sol << endl;
			}			
		}
		
		return 0;
	}
