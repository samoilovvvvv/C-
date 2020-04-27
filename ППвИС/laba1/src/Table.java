import javax.swing.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Table implements IGetButton{
    private int i = 0, rand;
    private JPanel panel;
    private List<JButton> buttons = new ArrayList<>();

    public List<JButton> getButtons() {
        return buttons;
    }

    public JPanel getPanel() {
        return panel;
    }

    Table() {
        JTextField textField = new JTextField(15);
        JButton button1 = new JButton("first");

        JButton button2 = new JButton("second");
        JButton button3 = new JButton("third");
        JTable table = new JTable(6, 2);
        buttons.add(button1);
        buttons.add(button2);
        buttons.add(button3);

        button1.addActionListener(e -> {
            this.rand = new Random().nextInt(table.getRowCount());
            if (table.getValueAt(rand, 1) == null && table.getValueAt(rand, 0) == null) {
                table.setValueAt(textField.getText(), rand, 0);
            }
        });
        button2.addActionListener(e -> {
            if (table.getValueAt(rand, 0) != null) {
                table.setValueAt(table.getValueAt(rand, 0), rand, 1);
                table.setValueAt(null, rand, 0);
            }
        });
        button3.addActionListener(e -> {
            if (table.getValueAt(rand, 1) != null) {
                table.setValueAt(table.getValueAt(rand, 1), rand, 0);
                table.setValueAt(null, rand, 1);
            }
        });

        panel = new JPanel();
        panel.add(textField);
        panel.add(table);
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        //add(panel);
    }
}
