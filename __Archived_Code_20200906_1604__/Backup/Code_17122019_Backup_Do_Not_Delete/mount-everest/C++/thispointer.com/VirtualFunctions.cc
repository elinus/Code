#include <iostream>
#include <string>

class MessageConverter {
    public:
        virtual std::string convert(std::string msg) {
            msg = "[START]" + msg + "[END]";
            return msg;
        }
};

class NewMessageConverter : public MessageConverter {
    public:
        std::string convert(std::string msg) {
            msg = "<START>" + msg + "<END>";
            return msg;
        }
};

class MessageSender {
    private:
        MessageConverter *mpMsgConv;
    public:
        MessageSender()
            : mpMsgConv(nullptr)
        {}
        void setMessageConverter(MessageConverter *pMsgConv) {
            mpMsgConv = pMsgConv;
        }
        void sendMessage(std::string msg) {
            if (mpMsgConv)
                msg = mpMsgConv->convert(msg);
            std::cout << "Message sent :: " << msg << "\n";
        }
};


int main (int argc, char *argv[]) 
{
    MessageSender oMsgSender;
    MessageConverter *poMsgConv = new MessageConverter();
    oMsgSender.setMessageConverter(poMsgConv);
    oMsgSender.sendMessage("Hello World!");
    delete poMsgConv;

    NewMessageConverter *poNewMsgConv = new NewMessageConverter();
    oMsgSender.setMessageConverter(poNewMsgConv);
    oMsgSender.sendMessage("Hello World!");
    delete poMsgConv;
    
    return 0;
}

