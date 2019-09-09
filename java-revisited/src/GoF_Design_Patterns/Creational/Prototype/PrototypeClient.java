package GoF_Design_Patterns.Creational.Prototype;

public class PrototypeClient {

    public static void main(String[] args) {
        MachineImage linuxVM =
                new MachineImage("Ubuntu 18.04 LTS", "ESET NOD32 Antivirus");
        MachineImage windowsVM =
                new MachineImage("Window 10", "Microsoft Defender");

        try {
            MachineImage linuxWebServer = (MachineImage) linuxVM.clone();
            linuxWebServer.install(" << Linux Web Server S/W >>");
            MachineImage dbServer = (MachineImage) linuxWebServer.clone();
            dbServer.install(" {{ DB Server S/W }}");
            System.out.println("----- LINUX WEB SERVER S/W -----");
            linuxWebServer.printSW();
            System.out.println("----- DB SERVER S/W -----" );
            dbServer.printSW();
            System.out.println("\n");
            MachineImage windowsWebServer = (MachineImage) windowsVM.clone();
            System.out.println("----- WINDOWS WEB SERVER S/W -----");
            windowsWebServer.printSW();

        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }
}
