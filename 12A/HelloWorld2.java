/*
	Jason Bonilla 2016
	prints greeting and system information
*/
public class HelloWorld2
{
   public static void main(String[] args)
   {
	 String os = System.getProperty("os.name");
	 String osVer = System.getProperty("os.version");
	 String jre = System.getProperty("java.runtime.name");
	 String jreVer = System.getProperty("java.runtime.version");
	 String jvm = System.getProperty("java.vm.name");
	 String jvmVer = System.getProperty("java.vm.version");
	 String home = System.getProperty("java.home");
	 double freemem = Runtime.getRuntime().freeMemory();
	 long time = System.currentTimeMillis();
	 System.out.println("Hello, World!");
	 System.out.println("Operating system: "+os+" "+osVer);
	 System.out.println("Runtime environment: "+jre+" "+jreVer);
	 System.out.println("Virtual machine: "+jvm+" "+jvmVer);
	 System.out.println("Java home directory: "+home);
	 System.out.println("Free memory: "+freemem+" bytes");
	 System.out.printf("Time: %tc.%n", time);
   }
}

