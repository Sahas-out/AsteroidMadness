public class GameRunner
{
    public native int runGame();
    //
        static 
        {
           // Load the native library (ensure the library is in the Java library path)
           System.loadLibrary("RunGame");  // The name of your C++ library without the file extension
        }    
    
}
