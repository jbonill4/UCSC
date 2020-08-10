/*
*   Jason Bonilla
*   Lab4
*/
import java.sql.*;
import java.io.*;
import java.util.*;

/**
 * A class that connects to PostgreSQL and disconnects.
 * You will need to change your credentials below, to match the usename and password of your account
 * in the PostgreSQL server.
 * The name of your database in the server is the same as your username.
 * You are asked to include code that tests the methods of the RestaurantApplication class
 * in a similar manner to the sample RunFilmsApplication.java program.
*/


public class RunRestaurantApplication
{
    public static void main(String[] args) {
    	
    	Connection connection = null;
    	try {
    	    //Register the driver
    		Class.forName("org.postgresql.Driver"); 
    	    // Make the connection.
            // You will need to fill in your real username (twice) and password for your
            // Postgres account in the arguments of the getConnection method below.
            connection = DriverManager.getConnection(
                                                     "jdbc:postgresql://cse180-db.lt.ucsc.edu/jbonill4",
                                                     "jbonill4",
                                                     "password");/*change to real password*/
            
            if (connection != null)
                System.out.println("Connected to the database!");
            /* Include your code below to test the methods of the RestaurantApplication class
             * The sample code in RunFilmsApplication.java should be useful.
             * That code tests other methods for a different database schema.
             * Your code below: */
            /********************************************************************/
             RestaurantApplication temp = new RestaurantApplication(connection);
             List<Integer> menuIDs = new ArrayList<Integer>();
             menuIDs = temp.getFrequentlyOrderedMenuItems(65);

             for(int i = 0; i < menuIDs.size(); i++) {   
                System.out.println(menuIDs.get(i));
                }  
             /*

            * Output of getFrequentlyOrderedMenuItems

            * when the parameter numMenuItemsOrdered is 65.
            * SERVER IS DOWN SO I CANNOT RUN IT

            */
            /********************************************************************/ 
            int count = 0;
            String jim = "Phileas Fogg";
            String jim2 = "John Smith";
            int update = temp.updateServerName(3, jim);
            int update2 = temp.updateServerName(10, jim2);
           // System.out.println("Total updates: "+ update);
            //System.out.println("Total updates: "+ update2);
            /*

            * Output of updateServerName when theServerID is 3

            * and newServerName is ‘Phileas Fogg’

            SERVER IS DOWN SO I CANNOT RUN IT

            */

            /*

            * Output of updateServerName when theServerID is 10

            * and newServerName is ‘John Smith’

            SERVER IS DOWN SO I CANNOT RUN IT

            */


            /********************************************************************/
            //int x = temp.reduceSomeVisitCosts(66);
            //System.out.println("Total reduced: "+ x);
            /********************************************************************/
            int third = temp.reduceSomeVisitCosts(3);
            System.out.println("Third: "+ third);
            /*******************
            * Your code ends here */
            
    	}
    	catch (SQLException | ClassNotFoundException e) {
    		System.out.println("Error while connecting to database: " + e);
    		e.printStackTrace();
    	}
    	finally {
    		if (connection != null) {
    			// Closing Connection
    			try {
					connection.close();
				} catch (SQLException e) {
					System.out.println("Failed to close connection: " + e);
					e.printStackTrace();
				}
    		}
    	}
    }
}
