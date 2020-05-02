package GoF_Design_Patterns.Structural.Proxy;

public class ProxyClient {

    public static void main(String[] args) {

        Server server = new ProxyServer();

        server.authenticate();
        server.get();
        server.post();
        server.put();
        server.delete();
        server.logout();
    }
}
