/*
 * GotW09_exception safety.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: songjiguo
 */

#include <algorithm>

template<class T>
T* NewCopy( const T* src, unsigned srcsize, unsigned destsize )
{
    destsize = std::max( srcsize, destsize ); // basic parm check
    T* dest = new T[destsize];
    // if we got here, the allocation/ctors were okay

    try
    {
        std::copy( src, src+srcsize, dest );
    }
    catch(...)
    {
        delete[] dest;
        throw;  // rethrow the original exception
    }
    // if we got here, the copy was okay

    return dest;
}


template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);

	void push(const T&);
	T pop();
	bool isEmpty();
	unsigned Count();
private:
	T* v_;

	unsigned vsize_;
	unsigned vused_;
};

template<class T>
Stack<T>::Stack() :
		v_(new T[10]), vsize_(10), vused_(10)
{
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) :
		v_(0), vsize_(other.vsize_), vused_(other.vused_)
{
	v_ = NewCopy(other.v_, other.vsize_, other.vused_);
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& other)
{
	if (this != &other) {
		T *v_new = NewCopy(other.v_, other.vsize_, other.vused_);
		delete[] v_;

		v_ = v_new;
		vsize_ = other.vsize_;
		vused_ = other.vused_;
	}

	return *this;
}

template<class T>
Stack<T>::~Stack() {
	delete[] v_;
}

template<class T>
unsigned Stack<T>::Count()
{
	return vused_;
}

template<class T>
void Stack<T>::push(const T& val)
{
	if (vused_ == vsize_) {
		unsigned new_sz = (vsize_ + 1) * 2;
		T *new_v = NewCopy(v_, vsize_, new_sz);
		delete[] v_;
		v_ = new_v;
		vsize_ = new_sz;
	}

	v_[vused_] = val;
	++vused_;
}

template<class T>
T Stack<T>::pop()
{
	T result;
	if (vused_ > 0) {
		result = v_[vused_-1];
		--vused_;
	}
	return result;
}

int main()
{

}
