package GoF_Design_Patterns.Structural.Proxy;

public class ProxyServer implements Server {

    private RealServer realServer;
    private boolean sessionActive;

    public ProxyServer() {
        realServer = new RealServer();
        sessionActive = false;
    }

    @Override
    public void authenticate() {
        realServer.authenticate();
        sessionActive = true;
    }

    @Override
    public void get() {
        if (sessionActive) {
            realServer.get();
        } else {
            System.out.println("sessionActive = " + sessionActive);
        }
    }

    @Override
    public void post() {
        if (sessionActive) {
            realServer.post();
        } else {
            System.out.println("sessionActive = " + sessionActive);
        }
    }

    @Override
    public void put() {
        if (sessionActive) {
            realServer.put();
        } else {
            System.out.println("sessionActive = " + sessionActive);
        }
    }

    @Override
    public void delete() {
        if (sessionActive) {
            realServer.delete();
        } else {
            System.out.println("sessionActive = " + sessionActive);
        }
    }

    @Override
    public void logout() {
        realServer.logout();
        sessionActive = false;
    }
}
