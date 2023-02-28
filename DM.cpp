#include<bits/stdc++.h>
using namespace std;
// For only 4 sample types

class Food{
	int M; int *ans;
	ofstream file;

public:
	Food(string filename,int m=16):ans(new int[M]{0}),M(m){
		srand(time(NULL));
		file.open(filename,ios::out);
	}

	~Food(){
		file.close();
		delete [] ans;
	}

	void solve(int n){
		int ch,idx,ct,k=1;

		file<<"(ABCD)',A,B,C,D,AB,BC,CD,AC,BD,AD,ABC,BCD,CDA,DAB,ABCD"<<endl;

		// cout<<"NO\tA\tB\tC\tD\tAB\tBC\tCD\tAC\tBD\tAD\tABC\tBCD\tCAD\tDAB\tABCD\n";

		if(file.fail()) return;


		for(int i=0;i<n;++i){

			int *arr = new int[M]{0};
			ch=rand()%M;
			ct=2;
			// ch=i%M;
			
			// cout<<"ch = "<<ch<<endl;

			arr[ch]++;

			if(ch<=4) ct=0;

			else if(ch==M-1){ ch-=10; ct=4;}

			else if(ch>10){ ch-=10; ct=3;}

			else if(ch>=8){
				ch-=6;
				
				if(ch+1>4){
					arr[ch]++;
					arr[ch+1-4]++;
				}else{
					arr[ch-1]++;
					arr[ch+1]++;
				}
				ct=0;
			}

			while(ct--){
				while(ch>4) ch-=4;
				arr[ch]++; ch++;
			}

			for(int j=0;j<M;j++){
				ans[j]+=arr[j];
				file<<(arr[j]?"Yes":"No")<<",";
				// cout<<arr[j]<<"\t"; 
			}
			file<<endl;
			// cout<<endl;

			delete [] arr;

		}

		for(int j=0;j<M;j++) file<<ans[j]<<"\t,"; file<<endl;
		// for(int j=0;j<M;j++) cout<<ans[j]<<"\t"; cout<<endl;
	}

};


int main(int argc, char const *argv[]){
	int n;
	string filename;

	cout<<"Enter your file name with extension(.csv)"<<endl;
	cout<<"--> "; cin>>filename;

	cout<<"How many sample you want?"<<endl;
	cout<<"--> "; cin>>n;

	Food DM(filename);

	DM.solve(n);
}

//code by jay-neo
