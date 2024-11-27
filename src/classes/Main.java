import javax.swing.*;
public class Main{

    public static void main(String[] args) {
            SwingUtilities.invokeLater(() -> {
            CustomGameInterface gameInterface = new CustomGameInterface();
            gameInterface.setVisible(true);
        });
        // GameRunner gameRunner = new GameRunner();
        // gameRunner.runGame();
    }
}
