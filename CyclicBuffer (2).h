#include <iostream>
#pragma once
using namespace std;

typedef unsigned int size_t;

template <typename T>
class CyclicBuffer
{
    template <typename T2>
    class Iter: public std::iterator<std::random_access_iterator_tag, T2> {
        T2* _pointer;
        T2* _begin;
        int _max_offset;
        //typedef std::iterator<std::random_access_iterator_tag, T> base_template;
    public:
    	/*
        typedef typename base_template::value_type           value_type;
		typedef typename base_template::pointer              pointer;
		typedef typename base_template::reference            reference;
		typedef typename base_template::iterator_category    iterator_category;
		typedef typename base_template::difference_type      differencetype;
     */
        
        Iter() { }

        Iter(T2* begin, const int& offset, const int& max_offset):
        _pointer(begin + offset), 
        _begin(begin),
        _max_offset(max_offset) { }

        T2& operator* () { return *_pointer; }

        Iter <T2> operator++() // post
        {
            Iter<T2> old_iter(*this);
            ++_pointer; 
            if (_pointer > _begin + _max_offset)
                _pointer = _begin;
            return old_iter;
        }

        Iter <T2>& operator++(int ) // pre
        {
            ++_pointer; 
            if (_pointer > _begin + _max_offset)
                _pointer = _begin;
            return *this;
        }

        Iter<T2> operator--() // post
        {
            Iter<T2> oldIter(*this);
            --_pointer; 
            if (_pointer < _begin)
                _pointer = _begin + _max_offset;
            return oldIter;
        }

        Iter<T2>& operator--(int ) // pre
        {
            ++_pointer; 
            if (_pointer < _begin)
                _pointer = _begin + _max_offset;
            return *this;
        }

        Iter<T2>& operator+=(const int& value)
        {
            int result_offset = (_pointer - _begin + value) % (_max_offset + 1);
            _pointer = _begin + (_max_offset + 1 + result_offset) % (_max_offset + 1);
            return *this;
        }

        Iter<T2> operator-=(const int& value)
        {
            return operator+=(-value);
        }

        Iter<T2> operator+(const int& value)
        {
            Iter<T2> res(*this);
            return res += value;
        }

        Iter<T2> operator-(const int& value)
        {
            Iter<T2> res(*this);
            return res + -value;
        }

        friend bool operator!= (Iter<T2> one, Iter<T2> other)
        {
            return one._pointer != other._pointer;
        }
        friend bool operator== (Iter<T2> one, Iter<T2> other)
        {
            return one._pointer == other._pointer;
        }
        friend bool operator< (Iter<T2> one, Iter<T2> other)
        {
            return one._pointer < other._pointer;
        }
        friend bool operator> (Iter<T2> one, Iter<T2> other)
        {
            return other._pointer < one._pointer;
        }
        friend bool operator<= (Iter<T2> one, Iter<T2> other)
        {
            return !(one._pointer > other._pointer);
        }
        friend bool operator>= (Iter<T2> one, Iter<T2> other)
        {
            return other._pointer <= one._pointer;
        }
        friend int operator-(Iter<T2> one, Iter<T2> other)
        {
            return one._pointer - other._pointer;
        }
    };

// !! КОНСТАНТНЫЙ ИТЕРАТОР!!!!1111АДЫН
    template <typename T2>
    class Const_Iter: public std::iterator<std::random_access_iterator_tag, T2> {
        T2* _pointer;
        T2* _begin;
        int _max_offset;

    public:

        Const_Iter() { };

        Const_Iter(T2* begin, const int& offset, const int& max_offset):
        _pointer(begin + offset), 
        _begin(begin),
        _max_offset(max_offset) { }

        const T2& operator* () const { return *_pointer; }

        // ctrl-c

        Const_Iter <T2> operator++() {
            Const_Iter<T2> old_iter(*this);
            ++_pointer; 
            if (_pointer > _begin + _max_offset)
                _pointer = _begin;
            return old_iter;
        }

        Const_Iter <T2>& operator++(int ) {
            ++_pointer; 
            if (_pointer > _begin + _max_offset)
                _pointer = _begin;
            return *this;
        }

        Const_Iter<T2> operator--() {
            Const_Iter<T2> oldIter(*this);
            --_pointer; 
            if (_pointer < _begin)
                _pointer = _begin + _max_offset;
            return oldIter;
        }

        Const_Iter<T2>& operator--(int ) {
            ++_pointer; 
            if (_pointer < _begin)
                _pointer = _begin + _max_offset;
            return *this;
        }

        Const_Iter<T2>& operator+=(const int& value) {
            int result_offset = (_pointer - _begin + value) % (_max_offset + 1);
            _pointer = _begin + (_max_offset + 1 + result_offset) % (_max_offset + 1);
            return *this;
        }

        Const_Iter<T2> operator-=(const int& value) {
            return operator+=(-value);
        }

        Const_Iter<T2> operator+(const int& value) {
            Const_Iter<T2> res(*this);
            return res += value;
        }

        Const_Iter<T2> operator-(const int& value) {
            Const_Iter<T2> res(*this);
            return res + -value;
        }

        friend bool operator!= (Const_Iter<T2> one, Const_Iter<T2> other) {
            return one._pointer != other._pointer;
        }
        friend bool operator== (Const_Iter<T2> one, Const_Iter<T2> other) {
            return one._pointer == other._pointer;
        }
        friend bool operator< (Const_Iter<T2> one, Const_Iter<T2> other) {
            return one._pointer < other._pointer;
        }
        friend bool operator> (Const_Iter<T2> one, Const_Iter<T2> other) {
            return other._pointer < one._pointer;
        }
        friend bool operator<= (Const_Iter<T2> one, Const_Iter<T2> other) {
            return !(one._pointer > other._pointer);
        }
        friend bool operator>= (Const_Iter<T2> one, Const_Iter<T2> other) {
            return other._pointer <= one._pointer;
        }
        friend int operator-(Const_Iter<T2> one, Const_Iter<T2> other) {
            return one._pointer - other._pointer;
        }

        // ctrl-v
    };

    T* _mas;
    Iter <T> _b, _e;
    size_t _size, _maxSize;
    
public:
    CyclicBuffer(const size_t& s) : _size(0), _maxSize(s) {
        _mas = new T[_maxSize + 1];
        _b = Iter <T> (_mas, 0, _maxSize + 1);
        _e = Iter <T>(_mas, 0, _maxSize + 1);
    }

    ~CyclicBuffer() {
        delete[] _mas;
    }

    void resize(const size_t& new_size) {
        T* new_mas = new T[new_size + 1];
		_maxSize = new_size;

		if (_size > new_size)
			_size = new_size;
		
        for (int i(0); i < (int)_size; ++i)
			new_mas[i] = operator[](i);

		delete[] _mas;
		_mas = new_mas;
		_b = Iter<T>(_mas, 0, new_size);
		_e = Iter<T>(_mas, _size, new_size);
    }
// !!! РЕСАЙЗ ПРИ ПЕРЕПОЛНЕНИИ
    void push_back(const T& value) {
        if (_size < _maxSize) {
            ++_size;
            *_e = value;
            ++_e;
        }
        else {
            // *_e = value;
            // ++_e;
            // ++_b;

            this->resize(_maxSize + 1);
            push_back(value);
        }  
    }

// !!! РЕСАЙЗ ПРИ ПЕРЕПОЛНЕНИИ
    void push_front(const T& value) {
        if (_size < _maxSize) {
            ++_size;
            if (_size)
                --_b;
            *_b = value;
        }
        else {
            // --_b;
            // *_b = value;
            // --_e;
            this->resize(_maxSize + 1);
            push_front(value);
        }
    }

    T pop_back() {
        --_size;
        T res = *_e;
        --_e;
        return res;
    }

    T pop_front() {
        --_size;
        T res = *_b;
        ++_b;
        return res;
    }

    T& back() { 
        if (_size == 0)
            throw std::out_of_range("Cyclic buffer is empty");
        return *(_e-1);
    }

    T& front() {
        if (_size == 0)
            throw std::out_of_range("Cyclic buffer is empty");
        return *_b; 
    }

    T& operator[](const int& pos) {
        auto tmp = _b;
        tmp += pos;
        return *(tmp);
    }


    Iter<T> begin() { return _b; }

    Iter<T> end() { return _e; }

    size_t size() { return _size; }

    void print_buffer()
    {
        // for (auto& e : *this)
        //     cout << e << " ";
        // cout  << endl;
        //auto& e = _b;
        for (auto e = (_b); e != _e; ++e) {
            cout << *e << " ";
            //e++;
        }
        cout << endl;
    }
};