#include <iostream>

struct Document;
struct IPrinter{
   virtual void print(Document& doc) = 0;
};
struct IScanner{
   virtual void scan(Document& doc) = 0;
};
struct IFax{
   virtual void fax(Document& doc) = 0;
};

struct Printer : IPrinter{
   void print(Document& doc) override{
   }
};

struct Scanner : IScanner{
   void scan(Document& doc) override{
   }
};

struct IMachine : IPrinter, IScanner{};

struct Machine : IMachine{
    IPrinter& printer_;
    IScanner& scanner_;
    Machine(IPrinter& printer, IScanner& scanner):
    printer_(printer),
    scanner_(scanner){
    }

    void print(Document& doc) override {
        printer_.print(doc);
    }
    void scan(Document& doc) override {
        scanner_.scan(doc);
    }

};


int main(){
    return 0;
}
