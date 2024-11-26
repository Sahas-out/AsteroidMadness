import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CustomGameInterface extends JFrame {
    int l = 1430;
    int h = 850;

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
                GradientPaint gradient = new GradientPaint(0, 0, Color.BLUE, getWidth(), getHeight(), Color.MAGENTA);
                g2d.setPaint(gradient);
                g2d.fillRect(0, 0, getWidth(), getHeight());
            }
        };
        //backgroundPanel.setBounds(0, this.h, this.l, -100);  // Set size and position for the title panel
        backgroundPanel.setLayout(null);
        setContentPane(backgroundPanel);

        JPanel titlePanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                GradientPaint gradient = new GradientPaint(0, 0, Color.BLUE, getWidth(), getHeight(), Color.MAGENTA);
                g2d.setPaint(gradient);
                g2d.fillRect(0, 0, getWidth(), getHeight());

                // Draw title text in the center
                g2d.setColor(Color.WHITE);
                g2d.setFont(new Font("Roman", Font.BOLD, 30));
                String titleText = "Asteroid Madness";
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(titleText)) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(titleText, x, y);
            }
        };
        titlePanel.setBounds(0, 0, this.l, 100);  // Set size and position for the title panel
        backgroundPanel.add(titlePanel);

        // Create custom "Play Game" button
        JButton playButton = new JButton("Start Game") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, Color.GREEN, getWidth(), getHeight(), Color.DARK_GRAY);
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);

                // Draw the text
                g2d.setColor(Color.WHITE); // Make text white to contrast the background
                g2d.setFont(getFont());    // Use the button's default font
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(getText())) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(getText(), x, y);
                g2d.dispose();
            }
        };
        setupButton(playButton, (((this.l) / 4) - 150), ((this.h) / 2 - 40), "Starting the game...");

        // Create custom "View Score" button
        JButton scoreButton = new JButton("LeaderBoard") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, Color.CYAN, getWidth(), getHeight(), Color.BLUE);
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);

                // Draw the text
                g2d.setColor(Color.WHITE); // Make text white to contrast the background
                g2d.setFont(getFont());    // Use the button's default font
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(getText())) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(getText(), x, y);
                g2d.dispose();
            }
        };
        setupButton(scoreButton, (((this.l) * 3) / 4 - 150), ((this.h) / 2 - 40), "Displaying the scores...");

        // Add buttons to the panel
        backgroundPanel.add(playButton);
        backgroundPanel.add(scoreButton);
    }

    private void setupButton(JButton button, int x, int y, String message) {
        button.setBounds(x, y, 300, 80);
        button.setFont(new Font("Arial", Font.BOLD, 16));
        button.setForeground(Color.BLACK);
        button.setFocusPainted(false);
        button.setContentAreaFilled(false); // Needed for custom painting
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, message);
            }
        });
    }

}
