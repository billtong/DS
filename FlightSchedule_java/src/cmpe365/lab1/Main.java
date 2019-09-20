package cmpe365.lab1;

import cmpe365.lab1.entity.Flight;
import cmpe365.lab1.entity.FlightMatrix;
import cmpe365.lab1.util.Dijkstra;

public class Main {
    private static String test = "2019_Lab_2_flights_test_data.txt";
    private static String real = "2019_Lab_2_flights_real_data.txt";

    public static void main(String args[]) {
        FlightMatrix fm = new FlightMatrix(real);
        Dijkstra dijkstra = new Dijkstra(fm, 16, 23);
        for (Flight flight : dijkstra.s) {
            System.out.println(flight);
        }
    }
    /** output
     * Flight{source=16, destination=16, departureTime=0, arrivalTime=0, duration=0}
     * Flight{source=16, destination=96, departureTime=1, arrivalTime=2, duration=2}
     * Flight{source=96, destination=15, departureTime=4, arrivalTime=5, duration=5}
     * Flight{source=15, destination=81, departureTime=7, arrivalTime=8, duration=8}
     * Flight{source=81, destination=23, departureTime=11, arrivalTime=13, duration=13}
     */
}
