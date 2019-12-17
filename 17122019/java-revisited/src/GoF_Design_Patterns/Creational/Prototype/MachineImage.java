package GoF_Design_Patterns.Creational.Prototype;

public class MachineImage implements Cloneable {

    StringBuilder sbImage;

    public MachineImage(String os, String antivirus) {
        sbImage = new StringBuilder();
        sbImage.append("os = " + os).append(", antivirus = " + antivirus);
    }

    private MachineImage(String sw) {
        sbImage = new StringBuilder(sw);
    }

    public void install(String sw) {
        sbImage.append(sw);
    }

    public void printSW() {
        System.out.println("sbImage => " + sbImage);
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return new MachineImage(this.sbImage.toString());
    }
}
