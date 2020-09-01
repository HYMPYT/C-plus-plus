/*
#include <iostream>
#include <string>


class Foo;
class Bar;
class Baz;

class Visitor {
public:
    virtual void visit(Foo &ref) = 0;
    virtual void visit(Bar &ref) = 0;
    virtual void visit(Baz &ref) = 0;

    virtual ~Visitor() = default;
};

class Element {
public:
    virtual void accept(Visitor &v) = 0;

    virtual ~Element() = default;
};

class Foo : public Element {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Bar : public Element {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Baz : public Element {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class GetType : public Visitor {
public:
    std::string value;

public:
    void visit(Foo &ref) override {
        value = "Foo";
    }
    void visit(Bar &ref) override {
        value = "Bar";
    }
    void visit(Baz &ref) override {
        value = "Baz";
    }
};


int main() {
    Foo foo;
    Bar bar;
    Baz baz;
    Element *elements[] = {&foo, &bar, &baz};

    for (auto elem : elements) {
        GetType visitor;
        elem->accept(visitor);
        std::cout << visitor.value << std::endl;
    }

    return 0;
}*/
