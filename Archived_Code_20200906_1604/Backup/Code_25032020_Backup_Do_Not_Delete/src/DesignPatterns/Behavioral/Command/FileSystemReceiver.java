package DesignPatterns.Behavioral.Command;

public interface FileSystemReceiver {
    void openFile();
    void writeFile();
    void  closeFile();
}
