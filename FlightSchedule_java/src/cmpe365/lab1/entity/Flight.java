package cmpe365.lab1.entity;

public class Flight {
    public int source;
    public int destination;
    public int departureTime;
    public int arrivalTime;

    public Flight(int source, int destination, int departureTime, int arrivalTime) {
        this.source = source;
        this.destination = destination;
        this.departureTime = departureTime;
        this.arrivalTime = arrivalTime;
    }

    public Flight(Flight flight) {
        this(flight.source, flight.destination, flight.departureTime, flight.arrivalTime);
    }

    @Override
    public String toString() {
        return "Flight{" +
                "source=" + source +
                ", destination=" + destination +
                ", departureTime=" + departureTime +
                ", arrivalTime=" + arrivalTime +
                '}';
    }
}
