/**
 * Created on 17-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.multithreading;

public class Account {
    private int balance = 10000;
    public void deposit(int amt) {
        balance += amt;
    }

    public void withdraw(int amt) {
        balance -= amt;
    }

    public int getBalance() {
        return balance;
    }

    public static void transfer(Account account1, Account account2, int amt) {
        account1.withdraw(amt);
        account2.deposit(amt);
    }
}
