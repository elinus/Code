#include <vector>

struct Document;

struct IMachine {
  virtual void print(Document &doc) = 0;
  virtual void fax(Document &doc) = 0;
  virtual void scan(Document &doc) = 0;
};

struct RandomMachine : IMachine {
  void print(Document &doc) override;
  void fax(Document &doc) override;
  void scan(Document &doc) override;
};

struct IPrinter {
  virtual void print(Document &doc) = 0;
};

struct IScanner {
  virtual void scan(Document &doc) = 0;
};

struct Printer : IPrinter {
  void print(Document &doc) override;
};

struct Scanner : IScanner {
  void scan(Document &doc) override;
};

struct IMachine_ : IPrinter, IScanner {
  void print(Document &doc) override;
  void scan(Document &doc) override;
};

struct Machine : IMachine_ {
  IPrinter &printer;
  IScanner &scanner;
  Machine(IPrinter &printer, IScanner &scanner)
      : printer(printer), scanner(scanner) {}
  void print(Document &doc) override { printer.print(doc); }
  void scan(Document &doc) override { scanner.scan(doc); }
};

int main(int argc, char const *argv[]) { return 0; }
