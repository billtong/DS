package cmpe365.lab1.util;

import cmpe365.lab1.entity.Flight;
import cmpe365.lab1.entity.FlightMatrix;

import java.util.ArrayList;

public class Dijkstra {
    public ArrayList<Flight> s;
    public ArrayList<Flight> u;
    private static int BIG_INT = 100000;
    private static int UNKNOWN_SOURCE = -1;
    private static int NOT_FOUND_INDEX = -2;

    public Dijkstra(FlightMatrix flightMatrix, int start, int end) {
        s = new ArrayList<>(0);
        u = new ArrayList<>(flightMatrix.length);
        for (int i=0; i<flightMatrix.length; i++) {
            if (i==start) {
                u.add(new Flight(i, i, 0, 0, 0));
            } else {
                u.add(new Flight(UNKNOWN_SOURCE, i, 0, 0, BIG_INT));
            }
        }
        while (u.size() > 0) {
            Flight fastFlight = new Flight(u.get(0));
            int fastFlightIndex = 0;
            for (int i=0; i<u.size(); i++) {
                if (u.get(i).source != UNKNOWN_SOURCE && fastFlight.duration > u.get(i).duration) {
                    fastFlight = u.get(i);
                    fastFlightIndex = i;
                }
            }
            if (fastFlight.duration == BIG_INT) {
                System.out.println("ERROR: there is no valid path, but here is some result output");
                break;
            }
            s.add(fastFlight);
            u.remove(fastFlightIndex);
            if (fastFlight.destination == end) {
                break;
            }
            for (int i=0; i<u.size(); i++) {
                u.get(i).source = fastFlight.destination;
                ArrayList<Flight> flightList = flightMatrix.matrix[u.get(i).source][u.get(i).destination];
                if (flightList!=null && !flightList.isEmpty()) {
                    for (Flight flight : flightList) {
                        if (flight.departureTime > fastFlight.arrivalTime && flight.arrivalTime - fastFlight.arrivalTime + fastFlight.duration < u.get(i).duration) {
                            Flight flight1 = u.get(i);
                            flight1.departureTime = flight.departureTime;
                            flight1.arrivalTime = flight.arrivalTime;
                            flight1.duration = flight.arrivalTime - fastFlight.arrivalTime + fastFlight.duration;
                        }
                    }
                } else {
                    Flight flight = u.get(i);
                    flight.departureTime = 0;
                    flight.arrivalTime = 0;
                    flight.duration = BIG_INT;
                    u.set(i, flight);
                }
            }
        }
    }
}
