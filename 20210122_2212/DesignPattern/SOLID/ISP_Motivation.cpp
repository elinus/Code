struct Document;

struct IMachine {
	virtual void print(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
};

struct MultiFunctionPrinter : IMachine {
	// Inherited via IMachine
	virtual void print(Document& doc) override
	{}
	virtual void fax(Document& doc) override
	{}
	virtual void scan(Document& doc) override
	{}
};

struct Scanner : IMachine {
	// Inherited via IMachine
	virtual void print(Document& doc) override
	{}
	virtual void fax(Document& doc) override
	{}
	virtual void scan(Document& doc) override
	{}
};