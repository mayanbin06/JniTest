this test first run JniTest.cpp to create a JVM,then call java method in com/myb/helloworld.. then load native lib and call native method.
javac compile.
javap -s [class] , let get the class and method signature.

m3u8 parser: source build_java.sh && cd out && java com.iheartradio.m3u8.TestUtil /var/www/video/m3u8/v2.m3u8
