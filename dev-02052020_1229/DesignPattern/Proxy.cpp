#include <iostream>
#include <memory>

class Server {
    public:
        Server() = default;
        virtual ~Server() {}
        virtual void authenticate() = 0;
        virtual void get() = 0;
        virtual void post() = 0;
        virtual void put() = 0;
        virtual void destroy() = 0;
        virtual void logout() = 0;
};

class RealServer : public Server {
    public:
        void authenticate() {
            std::cout << "Logged into the Real Server\n";
        }
        void get() {
            std::cout << "Get command executed\n";
        }
        void post() {
            std::cout << "Post command executed\n";
        }
        void put() {
            std::cout << "Put command executed\n";
        }
        void destroy() {
            std::cout << "Destroy command executed\n";
        }
        void logout() { 
            std::cout << "Logged out from the Real Server\n";
        }
};

class ProxyServer : public Server {
    private:
        std::unique_ptr<RealServer> m_RealServer;
        bool m_SessionActive;
    public:
        ProxyServer() {
            m_RealServer = std::make_unique<RealServer>();
            m_SessionActive = false;
        }
        ~ProxyServer() {
            m_RealServer = nullptr;
        }
        void authenticate() {
            m_RealServer->authenticate();
            m_SessionActive = true;
        }
        void get() {
            if (m_SessionActive) {
                m_RealServer->get();
            } else {
                std::cout << "Invalid session\n";
            }
        }
        void post() {
            if (m_SessionActive) {
                m_RealServer->post();
            } else {
                std::cout << "Invalid session\n";
            }
        }
        void put() {
            if (m_SessionActive) {
                m_RealServer->put();
            } else {
                std::cout << "Invalid session\n";
            }
        }
        void destroy() {
            if (m_SessionActive) {
                m_RealServer->destroy();
            } else {
                std::cout << "Invalid session\n";
            }
        }
        void logout() {
            m_RealServer->logout();
            m_SessionActive = false;
        }
};

int main (int argc, char *argv[]) {
    std::unique_ptr<Server> server = std::make_unique<ProxyServer>();
    server->authenticate();
    server->get();
    server->post();
    server->put();
    server->destroy();
    server->logout();
    return 0;
}


