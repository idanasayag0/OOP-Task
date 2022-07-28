#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <vector>
#include <algorithm>
using namespace std;



template <class T>
class Stream {
	vector<T> items;
public:

	Stream(vector<T> items):items(items){}
	Stream() = default;

	void push(T t)
	{
		items.push_back(t);
	}

	vector<T> get()
	{
		return items;
	}

	Stream<T> distinct() {
		Stream<T> temp;
		for (int i = 0; i < items.size(); i++) {
			if (find(temp.items.begin(), temp.items.end(), items[i]) == temp.items.end()) {
				temp.items.push_back(items[i]);
			}
		}
		return temp;
	}

	template<class Func>
	Stream<T> filter(Func f) {
		Stream<T> filtered_items;
		for (int i = 0; i < items.size(); i++) {
			if (f(items[i])) {
				filtered_items.items.push_back(items[i]);
			}
		}
		return filtered_items;

	}
	template<class Func>
	Func forEach(Func f) {
		for (auto item : items) {
			f(item);
		}
		return f;
	}
	template <class T,class Func>
	T reduce(T t,Func f) {
		for (auto item : items) {
			t = f(t, item);
		}
		return t;
	}
	template <class Func>
	bool allMatch(Func f) {
		for (auto item : items) {
			if (!f(item)) {
				return false;
			}
		}
		return true;
	}
	template <class Func>
	bool anyMatch(Func f) {
		for (auto item : items) {
			if (f(item)) {
				return true;
			}
		}
		return false;
	}
};


#endif /* SRC_Q2_H_ */
