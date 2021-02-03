struct Document;

struct IPrinter {
	virtual void print(Document& doc) = 0;
};

struct IScanner {
	virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter {
	// Inherited via IPrinter
	virtual void print(Document& doc) override
	{}
};

struct Scanner : IScanner {
	// Inherited via IScanner
	virtual void scan(Document& doc) override
	{}
};

struct IMachine : IPrinter, IScanner {
	virtual void fax(Document& doc) = 0;
};

struct MultiFunctionPrinter : IMachine {
	// Inherited via IMachine
	virtual void print(Document& doc) override
	{}
	virtual void scan(Document& doc) override
	{}
	virtual void fax(Document& doc) override
	{}
};