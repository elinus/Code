package DesignPatterns.Behavioral.Strategy;

public class UpiStrategy implements PaymentStrategy {
    String upiId;
    String mobileNo;

    public UpiStrategy(String upiId, String mobileNo) {
        this.upiId = upiId;
        this.mobileNo = mobileNo;
    }

    @Override
    public String toString() {
        return "Upi{" +
                "upiId='" + upiId + '\'' +
                ", mobileNo='" + mobileNo + '\'' +
                '}';
    }

    @Override
    public void pay(int amount) {
        System.out.println("Payment done ##==>> " + this.toString());
    }
}
