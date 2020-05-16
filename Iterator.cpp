//
// Created by abhishek on 01/05/20.
//

#include <iostream>
#include <memory>


// usb  : vector of usbs
// serial : map of serial

// Interator
// usbIterator
// serialIterator

// Collection -> {getiterator, length, addElement, removeElement}
// Iterator -> {begin, end, next}
// Collction <-> UsbCollction, SerialCollction
// Iteration <- UsbIterator, SerialIterator

// Client

template<class T>
class Iterator {
public:
    virtual void Begin() = 0;
    virtual void End() = 0;
    virtual void Next() = 0;
    virtual void IsNext() = 0;
    //virtual void T CurrentElement() = 0;
};

template <class T>
class Collection {
public:
    virtual Iterator<T> * GetIterator() = 0;
    virtual unsigned int Count() = 0;
    virtual void Add(T t) = 0;
};

template<class T>
class FakeExt2IteratorConcrete : public Iterator<T> {
public:
    void Begin() override {

    }

    void End() override {

    }

    void Next() override {

    }

    void IsNext() override {

    }

};

template<class T>
class FakeExt4IteratorConcrete : public Iterator<T> {
public:
    void Begin() override {

    }

    void End() override {

    }

    void Next() override {

    }

    void IsNext() override {

    }
};

template<class T>
class FakeExt2CollectionConcrete : public Collection<T> {
public:
    Iterator<T> *GetIterator() override {
        return nullptr;
    }

    unsigned int Count() override {
        return 0;
    }

    void Add(T t) override {

    }
};

template<class T>
class FakeExt4CollectionConcrete : public Collection<T> {
public:
    Iterator<T> *GetIterator() override {
        return nullptr;
    }

    unsigned int Count() override {
        return 0;
    }

    void Add(T t) override {

    }
};

class Fs {
    FakeExt2CollectionConcrete<>
};

int main() {

    return 0;
}