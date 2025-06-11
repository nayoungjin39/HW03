#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream> // 필요에 따라 제거 (인라인 함수 디버깅용)
#include <stdexcept> // std::out_of_range (예외 처리를 위해)

template <typename T>
class SimpleVector {
private:
    T* data;       // 데이터를 저장할 배열 포인터
    size_t size_;    // 현재 벡터에 저장된 원소의 개수
    size_t capacity_; // 벡터가 현재 할당받은 메모리 공간의 크기 (배열의 크기)

public:
    // 생성자
    SimpleVector();
    SimpleVector(size_t capacity);
    SimpleVector(const SimpleVector& other);
    SimpleVector(SimpleVector&& other);

    // 소멸자
    ~SimpleVector();

    // 멤버 함수
    void push_back(const T& value);
    void pop_back();
    size_t size() const;
    size_t capacity() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // 대입 연산자
    SimpleVector& operator=(const SimpleVector& other);
    SimpleVector& operator=(SimpleVector&& other);
};

#endif // SIMPLEVECTOR_H
