package DesignPatterns.Behavioral.Command;

public class UnixFileSystemReceiver implements FileSystemReceiver {

    private static final String TAG = "[UNIX]";

    @Override
    public void openFile() {
        System.out.println(TAG + " open file");
    }

    @Override
    public void writeFile() {
        System.out.println(TAG + " write file");
    }

    @Override
    public void closeFile() {
        System.out.println(TAG + " close file");
    }
}
