import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.border.Border;

public class CustomGameInterface extends JFrame {
    private int l = 1430;
    private int h = 850;
    private ScoreManager scr=new ScoreManager();
    private GameRunner gameRunner = new GameRunner();
    public CustomGameInterface() {
        // Set up the frame
        setTitle("Asteroid Madness");
        setSize(this.l, this.h);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(null); // Use absolute positioning for custom design


        // Custom panel for gradient background
        JPanel backgroundPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                GradientPaint gradient = new GradientPaint(0, 200, Color.ORANGE, getWidth(), getHeight(), Color.MAGENTA);
                g2d.setPaint(gradient);
                g2d.fillRect(0, 0, getWidth(), getHeight());
            }
        };

        backgroundPanel.setLayout(null);
        setContentPane(backgroundPanel);

        JPanel titlePanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                GradientPaint gradient = new GradientPaint(0, 0, Color.ORANGE, getWidth(), getHeight(), Color.MAGENTA);
                g2d.setPaint(gradient);
                g2d.fillRect(0, 0, getWidth(), getHeight());

                // Draw title text in the center
                g2d.setColor(Color.WHITE);
                g2d.setFont(new Font("Times New Roman", Font.BOLD, 50));
                String titleText = "Asteroid Madness";
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(titleText)) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(titleText, x, y);
            }
        };
        titlePanel.setBounds(0, 0, this.l, 100);  // Set size and position for the title panel
        backgroundPanel.add(titlePanel);

        //taking name input form user
        JTextField nameField = new JTextField("...Enter your Name...") {
            @Override
            protected void paintComponent(Graphics g) {
                Graphics2D g2 = (Graphics2D) g;
                g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

                // Draw the rounded rectangle background
                g2.setColor(new Color(200, 255, 255, 100));
                g2.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);

                // Draw the rounded rectangle border
                g2.setColor(Color.BLACK);
                g2.drawRoundRect(0, 0, getWidth() - 1, getHeight() - 1, 30, 30);

                // Set font and text color with translucency
                g2.setFont(new Font("Roman", Font.BOLD+Font.ITALIC, 25)); // Bold font
                g2.setColor(new Color(0, 0, 0, 150)); // Black with 200 alpha (translucent text)

                // Draw the text
                String text = getText();
                FontMetrics metrics = g2.getFontMetrics();
                int x = (getWidth() - metrics.stringWidth(text)) / 2; // Center text horizontally
                int y = (getHeight() + metrics.getAscent() - metrics.getDescent()) / 2; // Center text vertically
                g2.drawString(text, x, y);
            }

            @Override
            public void setBorder(Border border) {
                // Disable default border behavior
            }
        };

        nameField.setHorizontalAlignment(SwingConstants.CENTER);
        //nameField.setFont(new Font("Roman", Font.PLAIN, 18));
        nameField.setBounds((l / 2) - 200, 160, 400, 70);
        nameField.setOpaque(false); // Make the background transparent for custom painting

        backgroundPanel.add(nameField);

        // Create custom "Play Game" button
        JButton playButton = new JButton("Start Game") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, Color.GREEN, getWidth(), getHeight(), Color.YELLOW);
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);

                // Draw the text
                g2d.setColor(new Color(0, 0, 0, 150)); // Make text white to contrast the background
                g2d.setFont(new Font("Arial",Font.BOLD,25));    // Use the button's default font
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(getText())) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(getText(), x, y);
                g2d.dispose();
            }
        };
        setupButton(playButton, (((this.l) / 4) - 150), ((this.h) / 2 - 75), "Starting the game...",nameField);

        // Create custom "View Score" button
        JButton scoreButton = new JButton("LeaderBoard") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, Color.CYAN, getWidth(), getHeight(), Color.lightGray);
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);

                // Draw the text
                g2d.setColor(new Color(0, 0, 0, 150)); // Make text white to contrast the background
                g2d.setFont(new Font("Arial",Font.BOLD,25));    // Use the button's default font
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(getText())) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(getText(), x, y);
                g2d.dispose();
            }
        };
        setupButton(scoreButton, (((this.l) * 3) / 4 - 150), ((this.h) / 2 - 75), "Displaying the scores...",nameField);

        // Add buttons to the panel
        backgroundPanel.add(playButton);
        backgroundPanel.add(scoreButton);
    }

    private void setupButton(JButton button, int x, int y, String message,JTextField nameField) {
        button.setBounds(x, y, 300, 150);
        //button.setFont(new Font("Arial", Font.ITALIC, 16));
        button.setForeground(Color.BLACK);
        button.setFocusPainted(false);
        button.setContentAreaFilled(false); // Needed for custom painting
        button.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                String userName = nameField.getText().trim();
                JOptionPane.showMessageDialog(null, message);
                if(message.equals("Starting the game...")){
                    int usr_score = 0; 
                    usr_score = gameRunner.runGame();
                    scr.addscore(userName,usr_score);
                    //startGame();
                }
                else if(message.equals("Displaying the scores...")){
                    LeaderBoard board=new LeaderBoard(scr);
                    board.setVisible(true);
                }
            }
        });
    }

}
