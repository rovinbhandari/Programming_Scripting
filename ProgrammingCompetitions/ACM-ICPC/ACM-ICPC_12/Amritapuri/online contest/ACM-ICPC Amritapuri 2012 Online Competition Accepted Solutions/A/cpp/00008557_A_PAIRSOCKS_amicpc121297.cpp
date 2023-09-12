#include<iostream>
#include<set>
#include<vector>
#include<string>


using namespace std;
class Strings {
	int countR,countG,countB,countW;
	string str;
	bool flag;
public:
	Strings(string stri) {
		countR=0,countG=0,countB=0,countW=0;
		str = stri;
		flag=false;
	}

	void findCount() {
		for(size_t j=0;j<str.size();j++) {
			switch (str[j])
			{ 
			case'R': countR++;
				break;
			case'G': countG++;
				break;
			case'B': countB++;
				break;
			case'W': countW++;
				break;
			}
		}
		if((countR%2==0)&&(countG%2==0)&&(countB%2==0)&&(countW%2==0)) {
		flag = true;
		}
	}

	bool getFlag() {
		return flag;
	}

};
int main() {
	int n;
	string str;
	bool flag = true;
	vector<Strings> strings;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>str;
		strings.push_back(Strings(str));
	}

	for(vector<Strings>::iterator it = strings.begin();it!=strings.end();it++) {
		(*it).findCount();
		flag = (*it).getFlag();
		if(flag) 
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}

	return 0;
}