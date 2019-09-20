package cmpe365.lab1.entity;

import java.io.*;
import java.net.URISyntaxException;
import java.util.ArrayList;

public class FlightMatrix {
    public ArrayList<Flight>[][] matrix;
    public int length;

    public FlightMatrix(String filename) {
        try {
            String filepath = FlightMatrix.class.getResource("/").toURI().getPath() + "//cmpe365//lab1//assets//" + filename;
            File file = new File(filepath);
            InputStreamReader isr = new InputStreamReader(new FileInputStream(file));
            BufferedReader br = new BufferedReader(isr);
            String lineTxt = br.readLine();
            this.length = Integer.parseInt(lineTxt.trim());
            this.matrix = new ArrayList[this.length][this.length];
            while ((lineTxt = br.readLine()) != null)
            {
                lineTxt.split("\t");
                int source = Integer.parseInt(lineTxt.split("\t")[0]);
                int destination = Integer.parseInt(lineTxt.split("\t")[1]);
                int arrivalTime = Integer.parseInt(lineTxt.split("\t")[2]);
                int departureTime = Integer.parseInt(lineTxt.split("\t")[3]);
                if (this.matrix[source][destination] == null) {
                    this.matrix[source][destination] = new ArrayList<>();
                }
                this.matrix[source][destination].add(new Flight(source, destination, arrivalTime, departureTime, arrivalTime-departureTime));
            }
            br.close();
            isr.close();
        } catch (IOException | URISyntaxException e) {
            e.printStackTrace();
        }
    }

    public void printMatrix() {
        for (int i=0; i<this.length; i++) {
            for (int j=0; j<this.length; j++) {
                System.out.println(i + "->" + j);
                if (this.matrix[i][j] != null) {
                    System.out.println(this.matrix[i][j]);
                }
            }
        }
    }

}
