package cmpe365.lab1.entity;

import java.io.*;
import java.net.URISyntaxException;
import java.util.ArrayList;

public class FlightTable {
    public ArrayList<Flight> table;
    public int length;

    public FlightTable(String filename) {
        try {
            String filepath = FlightTable.class.getResource("/").toURI().getPath() + "//cmpe365//lab1//assets//" + filename;
            File file = new File(filepath);
            InputStreamReader isr = new InputStreamReader(new FileInputStream(file));
            BufferedReader br = new BufferedReader(isr);
            String lineTxt = br.readLine();
            this.length = Integer.parseInt(lineTxt.trim());
            this.table = new ArrayList<>();
            while ((lineTxt = br.readLine()) != null) {
                lineTxt.split("\t");
                int source = Integer.parseInt(lineTxt.split("\t")[0]);
                int destination = Integer.parseInt(lineTxt.split("\t")[1]);
                int arrivalTime = Integer.parseInt(lineTxt.split("\t")[2]);
                int departureTime = Integer.parseInt(lineTxt.split("\t")[3]);
                this.table.add(new Flight(source, destination, arrivalTime, departureTime));
            }
            br.close();
            isr.close();
        } catch (IOException | URISyntaxException e) {
            e.printStackTrace();
        }
    }

    public void printMatrix() {
        for (int i = 0; i < length; i++) {
            System.out.println(table.get(i));
        }
    }

}
