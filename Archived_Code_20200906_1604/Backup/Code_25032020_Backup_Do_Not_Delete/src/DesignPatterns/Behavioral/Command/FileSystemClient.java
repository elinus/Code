package DesignPatterns.Behavioral.Command;

public class FileSystemClient {

    public static void main(String[] args) {
        FileSystemReceiver fs = FileSystemReceiverUtil.getUnderlyingFileSystem();
        OpenFileCommand openFileCommand = new OpenFileCommand(fs);
        FileInvoker file = new FileInvoker(openFileCommand);
        file.ExecuteCommand();

        WriteFileCommand writeFileCommand = new WriteFileCommand(fs);
        file = new FileInvoker(writeFileCommand);
        file.ExecuteCommand();

        CloseFileCommand closeFileCommand = new CloseFileCommand(fs);
        file = new FileInvoker(closeFileCommand);
        file.ExecuteCommand();
    }
}
