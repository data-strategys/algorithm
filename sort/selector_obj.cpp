#include <iostream>

using namespace std;

#define swap(a,b)\
	do{\
		typeof(a) tmp = a;\
		a = b;\
		b=tmp;\
		} while(0);

template <typename T>
void selectorSort(T arr[],int n){

	int i;
	for (i=0;i<n;i++){  //select for
		int miniSelect =i;

	    for (int j=i;j<n;j++){ //compare
	       if (arr[miniSelect]>arr[j]){
		   	swap(arr[miniSelect],arr[j])
		   }
		}
	}
}


class Student{
	public:
		int score;
		char name[30];

		public:
			bool operator > (const Student &other)
			{
				return this->score  > other.score;
			}

			friend ostream& operator << (ostream& os ,const Student &other){
					os<< "name:"<<other.name << " socre:" <<other.score << endl;
				return os;
			}

	
};


int main(int argc,const char *argvs[]){

	Student stus[]={
			{100,"xiaoming"},
			{80,"xiaohong"},
			{150,"xiaozhang"},
			{60,"xiaojun"}
	};

	selectorSort(stus,4);
	int i;
	for (i=0;i<4;i++){

		cout<< stus[i]<<endl;
		
	}

	return 0;
}






