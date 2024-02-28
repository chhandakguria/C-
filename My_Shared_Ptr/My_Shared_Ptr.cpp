#include<iostream>
#include<string.h>


using namespace std;



using namespace std;

class A {
	public:
		int i;
		explicit A(int _i) : i(_i) {
		}
		~A() {
			cout << "deleting A" << endl;
		}
};
template <typename T>
class CuShPtr {
	T* ptr;
	int *count;	//shared. shallow copied

	inline void dec_count() {
		(*count)--;
	}

	inline void inc_count() {
		(*count)++;
	}
public:
	CuShPtr(T* _ptr) {
		ptr = _ptr;
		count = new int(1);
	}

	~CuShPtr() {
		//cout << "In ~CuShPtr" << endl;
		if(count != nullptr) {
			dec_count();
			if(*count == 0) {
				delete ptr;
				delete count;
			}
		}
	}

	CuShPtr(const CuShPtr<T>& other) {
		ptr = other.ptr;
		count = other.count;
		inc_count();
	}
	CuShPtr<T>& operator=(const CuShPtr<T>& other) {
		//TODO: only if count != nullptr?
		ptr = other.ptr;
		count = other.count;
		inc_count();
		return *this;
	}

	int use_count() const {
		if(count != nullptr)
			return *count;
		else
			return 0;
	}

	void reset() {
		if(count != nullptr) {
			dec_count();
			if(*count == 0) {
				delete ptr;
				delete count;
			}
			count = nullptr;
			ptr = nullptr;
		}
	}

	T& operator*() {
		//cout << "In operator *" << endl;
		return ptr;
	}

	T* operator ->() {
		//cout << "In operator ->" << endl;
		return ptr;
	}
};

CuShPtr<A> make_A() {
	CuShPtr<A> a(new A(5));
	return a;
}

int main() {
	CuShPtr<A> a = make_A();
	CuShPtr<A> b = a;
	CuShPtr<A> c = a;

	cout << a.use_count() << " " << b.use_count() << " " << c.use_count() << endl;

	c.reset();

	cout << a.use_count() << " " << b.use_count() << " " << c.use_count() << endl;
	cout << a->i << endl;
}

