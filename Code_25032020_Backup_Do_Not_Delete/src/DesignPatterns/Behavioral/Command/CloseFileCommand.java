package DesignPatterns.Behavioral.Command;

public class CloseFileCommand implements  Command {

    private FileSystemReceiver fileSystem;

    public CloseFileCommand(FileSystemReceiver fileSystem) {
        this.fileSystem = fileSystem;
    }

    @Override
    public void execute() {
        fileSystem.closeFile();
    }
}
