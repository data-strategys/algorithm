#include <iostream>

using namespace std;

#define swap(a,b)\
	do{\
		typeof(a) tmp = a;\
		a = b;\
		b=tmp;\
		} while(0);

  
template <typename T>  
class Less{

	public:
    bool operator () (T e1, T e2) // 重载括号
    {
        return e1.score<e2.score; // 等同于less
    }


};

template <typename T>  
class More{

	public:
    bool operator () (T e1, T e2) // 重载括号
    {
        return e1.score>e2.score; // 等同于more
    }


};


template <typename T,typename CmpFn>
void selectorSort(T arr[],int n){
	CmpFn fn;
	//CmpFn<T> fn; error 如果该代码块，是作为生成代码（宏代码块）可以，执行代码块(比如函数)不可以
	int i;
	for (i=0;i<n;i++){  //select for
		int miniSelect =i;

	    for (int j=i;j<n;j++){ //compare
	       if (fn(arr[miniSelect],arr[j])){
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
//change strategy func template
	//selectorSort<Student,Less<Student> >(stus,4);
	selectorSort<Student,More<Student> >(stus,4);
	int i;
	for (i=0;i<4;i++){
		cout<< stus[i]<<endl;
	}

	return 0;
}







