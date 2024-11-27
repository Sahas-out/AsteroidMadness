import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class LeaderBoard extends JFrame {
    private int l = 1430;
    private int h = 850;
    private ArrayList<String> top = new ArrayList<>();

    public LeaderBoard(ScoreManager s) {
        gettop();
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
        backgroundPanel.setLayout(null);
        setContentPane(backgroundPanel);

        // Title Panel
        JPanel titlePanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                GradientPaint gradient = new GradientPaint(0, 0, Color.BLUE, getWidth(), getHeight(), Color.MAGENTA);
                g2d.setPaint(gradient);
                g2d.fillRect(0, 0, getWidth(), getHeight());
                g2d.setColor(Color.WHITE);
                g2d.setFont(new Font("Roman", Font.BOLD, 40));
                String titleText = "LeaderBoard";
                FontMetrics fm = g2d.getFontMetrics();
                int x = (getWidth() - fm.stringWidth(titleText)) / 2;
                int y = (getHeight() + fm.getAscent()) / 2 - fm.getDescent();
                g2d.drawString(titleText, x, y);
            }
        };
        titlePanel.setBounds(0, 0, this.l, 100);
        backgroundPanel.add(titlePanel);

        // First Button (Gold)
        JButton first = new JButton("#1") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, new Color(205, 127, 50), getWidth(), getHeight(), Color.YELLOW);
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);
                g2d.setColor(new Color(0,0,0,130));
                g2d.setFont(new Font("Arial", Font.BOLD, 25));
                FontMetrics fm = g2d.getFontMetrics();
                int x1 = (getWidth() - fm.stringWidth(getText())) / 2;
                int y1 = (fm.getAscent());
                g2d.drawString(getText(), x1, y1);
                if (top.size() > 0) {
                    int x2 = (getWidth() - fm.stringWidth(top.get(0))) / 2;
                    int y2 = (getHeight() - fm.getAscent()) / 2 - fm.getDescent();
                    g2d.drawString(top.get(0), x2, y2);
                }
            }
        };
        setupButton(first, (this.l / 2) - 140, 200, "First Position: \n" + top.get(0));

        // Second Button (Silver)
        JButton second = new JButton("#2") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, Color.GRAY, getWidth(), getHeight(), Color.WHITE);
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);
                g2d.setColor(new Color(0,0,0,130));
                g2d.setFont(new Font("Arial", Font.BOLD, 25));
                FontMetrics fm = g2d.getFontMetrics();
                int x1 = (getWidth() - fm.stringWidth(getText())) / 2;
                int y1 = (fm.getAscent());
                g2d.drawString(getText(), x1, y1);
                if (top.size() > 1) {
                    int x2 = (getWidth() - fm.stringWidth(top.get(1))) / 2;
                    int y2 = (getHeight() - fm.getAscent()) / 2 - fm.getDescent();
                    g2d.drawString(top.get(1), x2, y2);
                }
            }
        };
        setupButton(second, (this.l / 4) - 140, 250, "Second Position: \n" + top.get(1));

        // Third Button (Bronze)
        JButton third = new JButton("#3") {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g.create();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                GradientPaint buttonGradient = new GradientPaint(0, 0, new Color(139, 69, 19), getWidth(), getHeight(), new Color(205, 127, 30));
                g2d.setPaint(buttonGradient);
                g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 30, 30);
                g2d.setColor(new Color(0,0,0,130));
                g2d.setFont(new Font("Arial", Font.BOLD, 25));
                FontMetrics fm = g2d.getFontMetrics();
                int x1 = (getWidth() - fm.stringWidth(getText())) / 2;
                int y1 = (fm.getAscent());
                g2d.drawString(getText(), x1, y1);
                if (top.size() > 2) {
                    int x2 = (getWidth() - fm.stringWidth(top.get(2))) / 2;
                    int y2 = (getHeight() - fm.getAscent()) / 2 - fm.getDescent();
                    g2d.drawString(top.get(2), x2, y2);
                }
            }
        };
        setupButton(third, (this.l * 3 / 4) - 140, 300, "Third Position: \n" + top.get(2));

        // Add buttons to the background panel
        backgroundPanel.add(first);
        backgroundPanel.add(second);
        backgroundPanel.add(third);
    }

    private void setupButton(JButton button, int x, int y, String message) {
        button.setBounds(x, y, 280, 400);
        button.setForeground(Color.BLACK);
        button.setFocusPainted(false);
        button.setContentAreaFilled(false);
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, message);

            }
        });
    }

    private void gettop() {
        String filename = "src/score_file.txt";
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                top.add(line);
            }
        } catch (IOException e) {
            System.err.println("An error occurred while reading the file.");
            e.printStackTrace();
        }
    }
}
