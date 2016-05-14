#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;


struct Foo {
    Foo () {
        cerr << "Foo [" << this << "] constructed\n";
    }
    virtual ~Foo () {
        cerr << "Foo [" << this << "] destructed\n";
    }
};

void sink (unique_ptr <Foo> p){
    cerr << "Sink owns Foo [" << p.get() << "]\n";
}

unique_ptr <Foo> source () {
    cerr << "Creating Foo in source\n";
    return unique_ptr <Foo>(new Foo);
}

int main() {
    cerr << "Calling source\n";
    unique_ptr <Foo> pmain = source ();

    cerr << "Now pmain owns Foo [" << pmain.get() << "]\n";
    cerr << "Passing it to sink\n";
    sink (move(pmain));
    cerr << "Value of pmain after passing it to sink [" << pmain.get() << "]\n";
    cerr << "Main done\n";
    return 0;
}
