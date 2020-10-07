package GoF_Design_Patterns.Structural.Proxy;

public interface Server {
    public void authenticate();
    public void get();
    public void post();
    public void put();
    public void delete();
    public void logout();
}
