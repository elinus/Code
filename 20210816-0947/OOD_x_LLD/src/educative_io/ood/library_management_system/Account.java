package educative_io.ood.library_management_system;

public abstract class Account {
    private String mId;
    private String mPassword;
    private AccountStatus mAccountStatus;
    private Person mPerson;

    public boolean resetPassword() {
        return true;
    }
}
