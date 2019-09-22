package cmpe365.lab1.util;

import cmpe365.lab1.entity.Flight;
import cmpe365.lab1.entity.FlightTable;

import java.util.Stack;

public class Dijkstra {
    private int[] totalTime;
    private int[] route;
    private int start;
    private int end;

    public Dijkstra(FlightTable flightMatrix, int start, int end) {
        totalTime = new int[flightMatrix.length];
        route = new int[flightMatrix.length];
        this.start = start;
        this.end = end;

        int[] estimate = new int[flightMatrix.length];
        boolean[] candidate = new boolean[flightMatrix.length];
        boolean[] reached = new boolean[flightMatrix.length];
        int currTime = -1;

        totalTime[start] = 0;
        estimate[start] = 0;
        reached[start] = true;
        candidate[start] = false;
        for (int i = 0; i < flightMatrix.length; i++) {
            if (i != start) {
                estimate[i] = Integer.MAX_VALUE;
                reached[i] = false;
                candidate[i] = false;
            }
        }
        for (int i = 0; i < flightMatrix.table.size(); i++) {
            Flight f = flightMatrix.table.get(i);
            if (f.source == start && f.arrivalTime < estimate[f.destination]) {
                estimate[f.destination] = f.arrivalTime;
                candidate[f.destination] = true;
                route[f.destination] = start;
            }
        }
        while (true) {
            int fastestArrivalTime = Integer.MAX_VALUE;
            int nextCity = -1;
            for (int i = 0; i < flightMatrix.length; i++) {
                if (candidate[i] && estimate[i] < fastestArrivalTime) {
                    nextCity = i;
                    fastestArrivalTime = estimate[i];
                }
            }
            reached[nextCity] = true;
            candidate[nextCity] = false;
            totalTime[nextCity] = fastestArrivalTime;
            currTime = fastestArrivalTime;
            if (reached[end]) {
                break;
            }
            for (int i = 0; i < flightMatrix.table.size(); i++) {
                Flight f = flightMatrix.table.get(i);
                if (f.source == nextCity && !reached[f.destination]) {
                    if (f.arrivalTime < estimate[f.destination] && f.departureTime > currTime) {
                        estimate[f.destination] = f.arrivalTime;
                        candidate[f.destination] = true;
                        route[f.destination] = nextCity;
                    }
                }
            }
        }
    }

    private void initDijkstra() {
    }

    public String routeToString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Optimal route from " + start + " to " + end + "\n");
        Stack<Integer> stack = new Stack<>();
        int a = end;
        while (a != start) {
            stack.push(a);
            a = route[a];
        }
        stack.push(start);
        while (stack.size() > 0) {
            stringBuilder.append(stack.pop());
            if (stack.size() != 0) {    // Formats the last route
                stringBuilder.append(" -> ");
            }
        }
        stringBuilder.append("\n");
        stringBuilder.append("Arrival Time at city " + end + " is: " + totalTime[end]);
        return stringBuilder.toString();
    }
}