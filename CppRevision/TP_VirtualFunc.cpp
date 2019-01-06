#include <iostream>
#include <string>

class MessageConverter 
{
    public:
        virtual std::string convert(std::string msg)
        {
            return "[START] " + msg + " [END]";
        }
};

class MessageSender
{
    private:
        MessageConverter *mMsgConverterPtr;
    public:
        MessageSender()
        {
            mMsgConverterPtr = nullptr;
        }
        
        void setMessageConverterPtr(MessageConverter *ptr)
        {
            mMsgConverterPtr = ptr;
        }

        void sendMessage(std::string msg)
        {
            if(mMsgConverterPtr){
                msg = mMsgConverterPtr->convert(msg);
            }
            std::cout << "Message Sent: " << msg << std::endl;
        }

};

class NewMessageConverter : public MessageConverter
{
    public:
        std::string convert(std::string msg)
        {
            return "<<START>> " + msg + " <<END>>";
        }
};

int main(int argc, char *argv[])
{
    MessageSender msgSenderObj;
    MessageConverter *msgConverterObj = new MessageConverter();
    msgSenderObj.setMessageConverterPtr(msgConverterObj);
    msgSenderObj.sendMessage("Hello");
    
    
    NewMessageConverter *newMsgConverterObj = new NewMessageConverter();
    msgSenderObj.setMessageConverterPtr(newMsgConverterObj);
    msgSenderObj.sendMessage("Hello");
    return 0;
}

