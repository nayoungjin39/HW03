#include "HW03.h" // 헤더 파일 포함

template <typename T>
SimpleVector<T>::SimpleVector() : size_(0), capacity_(10), data(new T[capacity_]) {
    // std::cout << "기본 생성자 호출됨" << std::endl; // 디버깅용 출력 (배포 시 제거)
}

template <typename T>
SimpleVector<T>::SimpleVector(size_t capacity) : size_(0), capacity_(capacity), data(new T[capacity_]) {
    // std::cout << "매개변수 생성자 호출됨, capacity: " << capacity_ << std::endl; // 디버깅용 출력 (배포 시 제거)
}

template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other) : size_(other.size_), capacity_(other.capacity_), data(new T[capacity_]) {
    // std::cout << "복사 생성자 호출됨" << std::endl; // 디버깅용 출력 (배포 시 제거)
    for (size_t i = 0; i < size_; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
SimpleVector<T>::SimpleVector(SimpleVector&& other) : data(other.data), size_(other.size_), capacity_(other.capacity_) {
    // std::cout << "이동 생성자 호출됨" << std::endl; // 디버깅용 출력 (배포 시 제거)
    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    // std::cout << "소멸자 호출됨" << std::endl; // 디버깅용 출력 (배포 시 제거)
    delete[] data;
}

template <typename T>
void SimpleVector<T>::push_back(const T& value) {
    if (size_ < capacity_) {
        data[size_++] = value;
    }
    else {
        // std::cout << "벡터가 가득 찼습니다. push_back 불가능." << std::endl; // 에러 메시지 (선택 사항)
        throw std::out_of_range("Vector is full");
    }
}

template <typename T>
void SimpleVector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
    }
    else {
        // std::cout << "벡터가 비어있습니다. pop_back 불가능." << std::endl; // 에러 메시지 (선택 사항)
        throw std::out_of_range("Vector is empty");
    }
}

template <typename T>
size_t SimpleVector<T>::size() const {
    return size_;
}

template <typename T>
size_t SimpleVector<T>::capacity() const {
    return capacity_;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    if (index < size_) {
        return data[index];
    }
    else {
        std::cerr << "인덱스가 범위를 벗어났습니다!" << std::endl;
        throw std::out_of_range("Index out of bounds");
    }
}

template <typename T>
const T& SimpleVector<T>::operator[](size_t index) const {
    if (index < size_) {
        return data[index];
    }
    else {
        std::cerr << "인덱스가 범위를 벗어났습니다!" << std::endl;
        throw std::out_of_range("Index out of bounds");
    }
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector& other) {
    // std::cout << "대입 연산자 호출됨" << std::endl; // 디버깅용 출력 (배포 시 제거)
    if (this == &other) {
        return *this;
    }

    delete[] data;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data = new T[capacity_];

    for (size_t i = 0; i < size_; ++i) {
        data[i] = other.data[i];
    }

    return *this;
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator=(SimpleVector&& other) {
    // std::cout << "이동 대입 연산자 호출됨" << std::endl; // 디버깅용 출력 (배포 시 제거)
    if (this == &other) {
        return *this;
    }

    delete[] data;

    data = other.data;
    size_ = other.size_;
    capacity_ = other.capacity_;

    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;

    return *this;
}