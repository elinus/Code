/**
 * Created on 28-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.InterviewPreparation2x19;

import java.util.ArrayList;
import java.util.Collections;

public class MovieMain {
    public static void main(String[] args) {
        ArrayList<Movie> list = new ArrayList<>();
        list.add(new Movie("Force Awakens", 8.3, 2015));
        list.add(new Movie("Star Wars", 8.7, 1977));
        list.add(new Movie("Empire Strikes Back", 8.8, 1980));
        list.add(new Movie("Return of the Jedi", 8.4, 1983));

        System.out.println("\nSort by year:-");
        Collections.sort(list);
        for (Movie movie: list) {
            System.out.println(movie.toString());
        }

        System.out.println("\nSort by name:-");
        NameCompare nameCompare = new NameCompare();
        Collections.sort(list, nameCompare);
        for (Movie movie: list) {
            System.out.println(movie.toString());
        }

        System.out.println("\nSort by rating:-");
        RatingCompare ratingCompare = new RatingCompare();
        Collections.sort(list, ratingCompare);
        for (Movie movie: list) {
            System.out.println(movie.toString());
        }
    }
}
