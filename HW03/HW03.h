#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream> // �ʿ信 ���� ���� (�ζ��� �Լ� ������)
#include <stdexcept> // std::out_of_range (���� ó���� ����)

template <typename T>
class SimpleVector {
private:
    T* data;       // �����͸� ������ �迭 ������
    size_t size_;    // ���� ���Ϳ� ����� ������ ����
    size_t capacity_; // ���Ͱ� ���� �Ҵ���� �޸� ������ ũ�� (�迭�� ũ��)

public:
    // ������
    SimpleVector();
    SimpleVector(size_t capacity);
    SimpleVector(const SimpleVector& other);
    SimpleVector(SimpleVector&& other);

    // �Ҹ���
    ~SimpleVector();

    // ��� �Լ�
    void push_back(const T& value);
    void pop_back();
    size_t size() const;
    size_t capacity() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // ���� ������
    SimpleVector& operator=(const SimpleVector& other);
    SimpleVector& operator=(SimpleVector&& other);
};

#endif // SIMPLEVECTOR_H
