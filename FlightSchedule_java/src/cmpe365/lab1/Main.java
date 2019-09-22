package cmpe365.lab1;

import cmpe365.lab1.entity.FlightTable;
import cmpe365.lab1.util.Dijkstra;

public class Main {
    private static String test = "2019_Lab_2_flights_test_data.txt";
    private static String real = "2019_Lab_2_flights_real_data.txt";

    public static void main(String args[]) {
        FlightTable fm = new FlightTable(real);
        Dijkstra dijkstra = new Dijkstra(fm, 98, 36);
        System.out.print(dijkstra.routeToString());
    }
    /**
     *  Optimal route from 36 to 98
     *  36 -> 157 -> 126 -> 42 -> 98
     *  Arrival Time at city 98 is: 23
     *  Process finished with exit code 0
     */
}
