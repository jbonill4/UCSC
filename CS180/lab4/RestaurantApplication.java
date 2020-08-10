/*
*   Jason Bonilla
*   Lab4
*/
import java.sql.*;
import java.util.*;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Types;

/**
 * The class implements methods of the Restaurant database interface.
 *
 * All methods of the class receive a Connection object through which all
 * communication to the database should be performed. Note: the
 * Connection object should not be closed by any method.
 *
 * Also, no method should throw any exceptions. In particular, in case
 * an error occurs in the database, then the method should print an
 * error message and call System.exit(-1);
 */

public class RestaurantApplication {

    private Connection connection;
    /*
     * Constructor
     */
    public RestaurantApplication(Connection connection) {
        this.connection = connection;
    }

    public Connection getConnection()
    {
        return connection;
    }

    /**
     * getFrequentlyOrderedMenuItems has an integer argument called numMenuItemsOrdered,
     * and returns the menuItemID for each menuItem where the total quantity (adding up quantity 
     * across all billEntry tuples) of that menuItem is greater than or equal to numMenuItemsOrdered.  
     * A value of numMenuItemsOrdered that’s not positive is an error.
     */

    public List<Integer> getFrequentlyOrderedMenuItems(int numMenuItemsOrdered) throws SQLException
    {
        if (numMenuItemsOrdered < 0) {
            throw new SQLException("Input is negative");
        }
        List<Integer> result = new ArrayList<Integer>();
        PreparedStatement s2 = connection.prepareStatement("SELECT M.menuItemID, SUM(B.quantity)" + 
            " FROM menuItem M, billEntry B" +
            " WHERE M.menuItemID = B.menuItemID" + 
            " GROUP BY M.menuItemID ");
        ResultSet res =  s2.executeQuery();
        while(res.next())
        {
            Integer mID = res.getInt(1);
            Integer sum = res.getInt(2);
            //System.out.println(mID + ": " + sum);
            if (sum >= numMenuItemsOrdered) {
                result.add(mID);
            }
        }
        return result;
    }

    /**
     * updateServerName method has two arguments, an integer argument, theServerID, and a string 
     * argument, newServerName.  For the tuple in the server table (if any) whose serverID equals 
     * theServerID, updateServerName should update name to be newServerName.  (Note that there may 
     * not be any tuples whose serverID matches theServerID.)  
     * updateServerName should return the number of tuples that were updated, which will always be 0 or 1.
     */

    public int updateServerName(int theServerID, String newServerName) throws SQLException
    {
        // your code here; return 0 appears for now to allow this skeleton to compile.
        PreparedStatement s3 = connection.prepareStatement("SELECT serverID FROM Server");
        ResultSet servers = s3.executeQuery();
        while(servers.next())
        {
            //System.out.println("");
            int sID = servers.getInt(1);
            if (sID == theServerID) 
            {
                //System.out.println("EQUAL");
                PreparedStatement s4 = connection.prepareStatement("UPDATE Server SET name = "+ "'" + newServerName + "'"+ " WHERE serverID = " + theServerID);
                s4.executeUpdate();
                return 1;   
            }
        }
        return 0;
    }


    /**
     * reduceSomeVisitCosts has an integer parameters, maxVisitCount.  It invokes a stored function
     * reduceSomeCostsFunction that you will need to implement and store in the database according to the
     * description in Section 5.  reduceSomeCostsFunction should have the same parameters, maxVisitCount.
     * A value of maxVisitCount that’s not positive is an error.
     *
     * The visits table has a cost attribute.  reduceSomeCostsFunction will reduce the cost for some 
     * (but not necessarily all) visits; Section 5 explains which visits should have their cost reduced, 
     * and also tells you how much they should be reduced.  The reduceSomeVisitCosts method should return 
     * the same integer result that the reduceSomeCostsFunction stored function returns.
     *
     * The reduceSomeVisitCosts method must only invoke the stored function reduceSomeCostsFunction, which
     * does all of the assignment work; do not implement the reduceSomeVisitCosts method using a bunch
     * of SQL statements through JDBC.
     */

    public int reduceSomeVisitCosts (int maxVisitCount) throws SQLException
    {
        if (maxVisitCount < 0) {
            throw new SQLException("Input is negative");
        }

        CallableStatement stmt = connection.prepareCall("{? = call incriment(?)}");
        stmt.registerOutParameter(1,Types.INTEGER);
        stmt.setInt(2,maxVisitCount);
        stmt.execute();
        System.out.println("This is the result:" + stmt.getInt(1));

        return stmt.getInt(1);
        
        // There's nothing special about the name storedFunctionResult
        //int storedFunctionResult = reduceSomeCostsFunctio(maxVisitCount);
        //return storedFunctionResult;
        // end of your code
        //return storedFunctionResult;
    }




    public int reduceSomeCostsFunctio (int maxpoint) throws SQLException
    {
        int count = maxpoint;
        int returnValue = 0;
        PreparedStatement s5 = connection.prepareStatement("UPDATE Customer "+ 
            "SET status = 'J' " + 
            "WHERE status = 'M'; ");
        s5.executeUpdate();

        PreparedStatement s4 = connection.prepareStatement("SELECT name, status, joinDate FROM Customer ORDER By status ASC, joinDate ASC;");
        ResultSet nameStat = s4.executeQuery();
        while(nameStat.next() && count > 0)
        {
            String name = nameStat.getString(1);
            String stat = nameStat.getString(2);
            //System.out.println("Name: "+name+ ", Status: "+ stat);
            if (stat == null) {
                //System.out.println("IN null");
            }
            else
            if (stat.equals("H") && count > 0) {
                //System.out.println("IN H");
                //System.out.println(name);
                //System.out.println(stat);
                PreparedStatement s6 = connection.prepareStatement("UPDATE Visit V " +
                                                                    "SET cost = cost*0.9 " + 
                                                                    "WHERE V.custID IN (SELECT C.custID FROM Customer C" + 
                                                                    " WHERE C.status = '" + stat+ "' AND " + " C.custID = V.custID AND name = '"+ name+ "' ) " +
                                                                    "AND cost IS NOT NULL;");
                s6.executeUpdate();
                returnValue++;
            }
            else
            if (stat.equals("J") && count > 0) {
                //System.out.println("IN J");
                //System.out.println("Name: "+name);
                //System.out.println("Status: "+ stat);
                PreparedStatement s7 = connection.prepareStatement("UPDATE Visit V " +
                                                                    "SET cost = cost*0.95 " + 
                                                                    "WHERE V.custID IN (SELECT C.custID FROM Customer C" + 
                                                                    " WHERE C.status = '" + stat+ "' AND " + " C.custID = V.custID AND name = '"+ name+ "' ) " +
                                                                    "AND cost IS NOT NULL;");
                s7.executeUpdate();
                returnValue++;

            }
            else
            if (stat.equals("L") && count > 0) {
                //System.out.println("IN L");
                //System.out.println("Name: "+name);
                //System.out.println("Status: "+ stat);
                PreparedStatement s8 = connection.prepareStatement("UPDATE Visit V " +
                                                                    "SET cost = cost*0.99 " + 
                                                                    "WHERE V.custID IN (SELECT C.custID FROM Customer C" + 
                                                                    " WHERE C.status = '" + stat+ "' AND " + " C.custID = V.custID AND name = '"+ name+ "' ) " +
                                                                    "AND cost IS NOT NULL;");
                s8.executeUpdate();
                returnValue++;
            }
            else
            {
                //
            }
            count--;
            //System.out.println("Count: "+ count );
        }
        PreparedStatement s9 = connection.prepareStatement("UPDATE Customer "+ 
            "SET status = 'M' " + 
            "WHERE status = 'J'; ");
        s9.executeUpdate();
        return returnValue;
    }

};
