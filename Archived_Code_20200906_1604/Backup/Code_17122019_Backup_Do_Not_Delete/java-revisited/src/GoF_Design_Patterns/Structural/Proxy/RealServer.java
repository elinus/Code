package GoF_Design_Patterns.Structural.Proxy;

public class RealServer implements Server {
    @Override
    public void authenticate() {
        System.out.println("RealServer.authenticate");
    }

    @Override
    public void get() {
        System.out.println("RealServer.get");
    }

    @Override
    public void post() {
        System.out.println("RealServer.post");
    }

    @Override
    public void put() {
        System.out.println("RealServer.put");
    }

    @Override
    public void delete() {
        System.out.println("RealServer.delete");
    }

    @Override
    public void logout() {
        System.out.println("RealServer.logout");
    }
}
