import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class AddingWord implements IGetButton {
    private JPanel jPanel;

    public JPanel getPanel() {
        return jPanel;
    }

    private List<JButton> buttons = new ArrayList<>();

    @Override
    public List<JButton> getButtons() {
        return buttons;
    }


    public AddingWord(JFrame frame) {
        jPanel = new JPanel();

        JTextField textField = new JTextField(15);
        JComboBox<String> comboBox = new JComboBox<>();

        comboBox.addItem("first");
        comboBox.addItem("second");
        JButton button = new JButton("кнопка");
        button.addActionListener(e -> {
            boolean isEquals = false;
            for (int i = 0; i < comboBox.getItemCount(); i++) {
                if (textField.getText().equals(comboBox.getItemAt(i))) {
                    isEquals = true;
                }
            }
            if (isEquals) {
                JOptionPane.showMessageDialog(frame,
                        "Ваше слово уже есть");
            } else {
                comboBox.addItem(textField.getText());
            }
        });
        buttons.add(button);
        jPanel.add(button);
        jPanel.add(textField);
        jPanel.add(comboBox);
    }
}
