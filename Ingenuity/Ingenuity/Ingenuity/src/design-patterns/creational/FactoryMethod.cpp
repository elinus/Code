#include <iostream>

using namespace std;

class Document {
public:
	virtual ~Document() {};
	virtual void open() = 0;
};

class SpreadSheetDocument : public Document {
	void open() override {
		cout << "Opening spreadsheet document!" << endl;
	}
};

class TextDocument : public Document {
	void open() override {
		cout << "Opening text document!" << endl;
	}
};

class DocumentFactory {
public:
	virtual Document* create() = 0;
	//Document* create_document() {
	//	Document* doc = create();
	//	return doc;
	//}
	virtual ~DocumentFactory() {}
};

class SpreadSheetDocumentFactory : public DocumentFactory {
	Document* create() override {
		return new SpreadSheetDocument();
	}
};

class TextDocumentFactory : public DocumentFactory {
	Document* create() override {
		return new TextDocument();
	}
};

class Controller {
private:
	Document* document_;
	DocumentFactory *document_factory_;
public:
	Controller() : document_{ nullptr }, document_factory_{ nullptr }
	{}
	~Controller() {
		delete document_;
	}
	void initialize() {
		document_ = document_factory_->create();
		document_->open();
	}
	void set_factory(DocumentFactory* factory) {
		document_factory_ = factory;
	}
};

//int main() {
//	Controller controller;
//	TextDocumentFactory tdf;
//	controller.set_factory(&tdf);
//	controller.initialize();
//}