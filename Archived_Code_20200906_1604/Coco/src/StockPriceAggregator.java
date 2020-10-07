import java.util.*;

public class StockPriceAggregator {

    public static class StatisticsAggregatorImpl implements StatisticsAggregator {
        HashMap<String, Double> hm_price = new HashMap<String, Double>();
        HashMap<String, Integer> hm_count = new HashMap<String, Integer>();
        @Override
        public void putNewPrice(String symbol, double price) {
            if (hm_price.containsKey(symbol)) {
                hm_price.put(symbol, hm_price.get(symbol) + price);
            } else {
                hm_price.put(symbol, price);
            }
            if (hm_count.containsKey(symbol)) {
                hm_count.put(symbol, hm_count.get(symbol) + 1);
            } else {
                hm_count.put(symbol, 1);
            }
        }

        @Override
        public double getAveragePrice(String symbol) {
            double price = 0;
            int count = 0;
            if (hm_price.containsKey(symbol)) {
                price = hm_price.get(symbol);
                count = hm_count.get(symbol);
                return price / count;
            } else {
                return 0.0;
            }
        }

        @Override
        public int getTickCount(String symbol) {
            if (hm_count.containsKey(symbol))
                return hm_count.get(symbol);
            return  0;
        }
    }

    ////////////////// DO NOT MODIFY BELOW THIS LINE ///////////////////

    public interface StatisticsAggregator {
        // This is an input. Make note of this price.
        public void putNewPrice(String symbol, double price);

        // Get the average price
        public double getAveragePrice(String symbol);

        // Get the total number of prices recorded
        public int getTickCount(String symbol);
    }

    public static void main(String[] args) {
// 1,IBM 22.22,AAPL 33.33,IBM 44.44,AAPL 55.55,IBM 66.66
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            final StatisticsAggregator stats = new StatisticsAggregatorImpl();
            final Set<String> symbols = new TreeSet<>();

            String line = scanner.nextLine();
            String[] inputs = line.split(",");
            for (int i = 1; i < inputs.length; ++i) {
                String[] tokens = inputs[i].split(" ");
                final String symbol = tokens[0];
                symbols.add(symbol);
                final double price = Double.parseDouble(tokens[1]);

                stats.putNewPrice(symbol, price);

            }

            for (String symbol : symbols) {
                System.out.println(
                        String.format("%s %.4f %d", symbol, stats.getAveragePrice(symbol), stats.getTickCount(symbol)));
            }
        }
        scanner.close();

    }
}
