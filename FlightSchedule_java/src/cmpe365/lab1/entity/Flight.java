package cmpe365.lab1.entity;

public class Flight {
    public int source;
    public int destination;
    public int departureTime;
    public int arrivalTime;
    public int duration;

    public Flight(int source, int destination, int departureTime, int arrivalTime, int duration) {
        this.source = source;
        this.destination = destination;
        this.departureTime = departureTime;
        this.arrivalTime = arrivalTime;
        this.duration = duration;
    }

    public Flight(Flight flight) {
        this(flight.source, flight.destination, flight.departureTime, flight.arrivalTime, flight.duration);
    }

    @Override
    public String toString() {
        return "Flight{" +
                "source=" + source +
                ", destination=" + destination +
                ", departureTime=" + departureTime +
                ", arrivalTime=" + arrivalTime +
                ", duration=" + duration +
                '}';
    }
}
