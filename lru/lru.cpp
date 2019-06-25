//使用hash_map和list实现的LRU。 实现了get和put操作
//get 得到对应的value，并且移到队列首。
//put 不存在：队列首加入，此时根据容量可能会挤掉尾元素。存在：移动到队列首。
 
//改进点在于如果get发生缺页是否需要处理，这时候可以添加一个
//hash_map存储key-value，并在get不到数据时，put一下即可。
 #include <list>
 #include <unordered_map>
 #include <iostream> 
 using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) : capacity(capacity) {}
	int get(int key) {
		if (pos.find(key) != pos.end()){
			put(key, pos[key]->second);
			return pos[key]->second;
		}
		return -1;
	}
	void put(int key, int value) {
	//存在key
		if (pos.find(key) != pos.end())
			recent.erase(pos[key]);
		//否则不存在，判断当前是否满了
		// 当前满
		else if (recent.size() >= capacity) {
			pos.erase(recent.back().first);
			recent.pop_back();
		}
		recent.push_front({ key, value });
		pos[key] = recent.begin();
	}
private:
	int capacity;
	list<pair<int, int> > recent;
	unordered_map<int, list<pair<int, int> >::iterator> pos;  //value存储的是一个迭代器
};




int main(int argc,const char *argvs[]){
	LRUCache *cache =new LRUCache(10);
	int i=0;
	for (;i<15;i++){
		 cache->put(i,i);		
	}
	for (i=0;i<15;i++){
		std::cout<< cache->get(i) <<std::endl;
	}

	delete cache;

	return 0;
}




