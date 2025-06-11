#include <iostream>
using namespace std;

template <typename T>
class Simplevector {
	private:
	T* data;
	int _size;
	int _capacity;

public:

	Simplevector(): _size(0), _capacity(10) {
		data = new T[_capacity];
	}

	Simplevector(int capacity): _size(0), _capacity(capacity) {
		data = new T[_capacity];
	}

	~Simplevector() {
		delete[] data;
	}

	void push_back(const T& value) {
		if (_size >= _capacity) return;
		data[_size++] = value;
	}

	void pop_back() {
		if (_size == 0) return;
			_size--;
		}
	
	int size() const {
		return _size;
	}

	int capacity() const {
		return _capacity;
	}

	T& operator[](int index) {
		return data[index];
	}
};

int main() {
	Simplevector<int> vec(5);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	cout << " size: " << vec.size() << endl;
	cout << " capacity: " << vec.capacity() << endl;

	vec.pop_back();
	cout << "size after:" << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " "; 
	}
}