struct Document;

struct IPrinter {
  virtual void print(const Document &doc) = 0;
};

struct IScanner {
  virtual void scan(const Document &doc) = 0;
};

struct Printer : IPrinter {
  void print(const Document &doc) override {}
};

struct Scanner : IScanner {
  void scan(const Document &doc) override {}
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine {
  IPrinter &printer;
  IScanner &scanner;
  Machine(IPrinter &printer, IScanner &scanner)
      : printer{printer}, scanner{scanner} {}
  virtual void print(const Document &doc) override{};
  void scan(const Document &doc) override { scanner.scan(doc); };
  void print(const Document &doc) override { printer.print(doc); };
};
