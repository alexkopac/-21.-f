#include <iostream>
//1
/*
class A {
public:
    int aValue;

    A() : aValue(0) { std::cout << "A constructor" << std::endl; }

    void setAValue(int value) { aValue = value; }
    int getAValue() const { return aValue; }

    virtual void display() { std::cout << "Class A" << std::endl; }
};

class B {
public:
    int bValue;

    B() : bValue(0) { std::cout << "B constructor" << std::endl; }

    void setBValue(int value) { bValue = value; }
    int getBValue() const { return bValue; }

    virtual void display() { std::cout << "Class B" << std::endl; }
};


class Rhombus : public virtual A, public virtual B {
public:
    Rhombus() { std::cout << "Rhombus constructor" << std::endl; }

    void setRhombusValues(int a, int b) {
        setAValue(a);
        setBValue(b);
    }

    void display() override {
        std::cout << "Class Rhombus" << std::endl;
        std::cout << "A Value: " << getAValue() << ", B Value: " << getBValue() << std::endl;
    }
};

int main() {
    Rhombus rhombus;
    rhombus.setRhombusValues(10, 20);
    rhombus.display();
    return 0;
}
*/
//2


template <typename T1, typename T2>
class Base {
public:
    T1 value1;
    T2 value2;

    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {
        std::cout << "Base constructor: " << value1 << ", " << value2 << std::endl;
    }

    void setValue1(T1 v) { value1 = v; }
    T1 getValue1() const { return value1; }

    void setValue2(T2 v) { value2 = v; }
    T2 getValue2() const { return value2; }

    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }

    void display() {
        std::cout << "Base values: " << value1 << ", " << value2 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
public:
    T3 value3;
    T4 value4;

    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {
        std::cout << "Child constructor: " << value3 << ", " << value4 << std::endl;
    }

    void setValue3(T3 v) { value3 = v; }
    T3 getValue3() const { return value3; }

    void setValue4(T4 v) { value4 = v; }
    T4 getValue4() const { return value4; }

    ~Child() {
        std::cout << "Child destructor" << std::endl;
    }

    void display() {
        Base<T1, T2>::display();
        std::cout << "Child values: " << value3 << ", " << value4 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
public:
    T5 value5;
    T6 value6;

    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {
        std::cout << "Child2 constructor: " << value5 << ", " << value6 << std::endl;
    }

    void setValue5(T5 v) { value5 = v; }
    T5 getValue5() const { return value5; }

    void setValue6(T6 v) { value6 = v; }
    T6 getValue6() const { return value6; }

    ~Child2() {
        std::cout << "Child2 destructor" << std::endl;
    }

    void display() {
        Child<T1, T2, T3, T4>::display();
        std::cout << "Child2 values: " << value5 << ", " << value6 << std::endl;
    }
};

int main() {
    Child2<int, float, double, char, std::string, bool> obj(10, 20.5f, 30.6, 'A', "Hello", true);

    obj.display();

    obj.setValue1(100);
    obj.setValue2(200.5f);
    obj.setValue3(300.6);
    obj.setValue4('B');
    obj.setValue5("World");
    obj.setValue6(false);

    std::cout << "Updated values:" << std::endl;
    std::cout << "value1: " << obj.getValue1() << std::endl;
    std::cout << "value2: " << obj.getValue2() << std::endl;
    std::cout << "value3: " << obj.getValue3() << std::endl;
    std::cout << "value4: " << obj.getValue4() << std::endl;
    std::cout << "value5: " << obj.getValue5() << std::endl;
    std::cout << "value6: " << obj.getValue6() << std::endl;

    return 0;
}
