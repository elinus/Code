struct Document;

struct IMachine {
  virtual void print(const Document &doc) = 0;
  virtual void scan(const Document &doc) = 0;
  virtual void fax(const Document &doc) = 0;
};

struct MultifunctionPrinter : public IMachine {
  void print(const Document &doc) override{};
  void scan(const Document &doc) override{};
  void fax(const Document &doc) override{};
};

struct Scanner : public IMachine {
  void print(const Document &doc) override{};
  void scan(const Document &doc) override{};
  void fax(const Document &doc) override{};
};