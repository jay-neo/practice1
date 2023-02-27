#include<bits/stdc++.h>
using namespace std;
// For 4 samples

class Jay{
	int M; int *ans;
	ofstream baal;

public:
	Jay(string filename,int m=16):ans(new int[M]{0}),M(m){
		srand(time(NULL));
		baal.open(filename,ios::out);
	}

	~Jay(){
		baal.close();
		delete [] ans;
	}

	void sob_faltu(int n){
		int ch,idx,ct,k=1;

		baal<<"Nil,A,B,C,D,AB,BC,CD,AC,BD,AD,ABC,BCD,CDA,DAB,ABCD"<<endl;

		// cout<<"NO\tA\tB\tC\tD\tAB\tBC\tCD\tAC\tBD\tAD\tABC\tBCD\tCAD\tDAB\tABCD\n";

		if(baal.fail()) return;


		for(int i=0;i<n;++i){

			int *arr = new int[M]{0};
			ch=rand()%M;
			ct=2;
			//ch=i%M;
			
			// cout<<"ch = "<<ch<<endl;

			arr[ch]++;

			if(ch<=4) ct=0;

			else if(ch==M-1){while(ch-->1) arr[ch]++; ct=0;}

			else if(ch>10){

				k=6;

				if(ch==14) k--;

				arr[ch-k]++;
				arr[ch-k+1]++;
				(ch-k+3>10)?arr[k]++:arr[ch-k+3]++;

				ch-=10;
				ct=3; k=1;
			}

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
				baal<<(arr[j]?"Yes":"No")<<",";
				// cout<<arr[j]<<"\t"; 
			}
			baal<<endl;
			// cout<<endl;

			delete [] arr;

		}

		for(int j=0;j<M;j++) baal<<ans[j]<<","; baal<<endl;
		// for(int j=0;j<M;j++) cout<<ans[j]<<" "; cout<<endl;
	}

};



int main(int argc, char const *argv[]){
	int n;
	string lol;

	cout<<"Enter your file name with extension .csv!!"<<endl;
	cout<<"--> "; cin>>lol;

	cout<<"How many sample you want?"<<endl;
	cout<<"--> "; cin>>n;

	Jay DM(lol);

	DM.sob_faltu(n);
}

//code by jay-neo
