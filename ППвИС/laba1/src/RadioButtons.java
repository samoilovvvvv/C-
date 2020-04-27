import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class RadioButtons implements IGetButton {

    private JPanel panel;
    private List<JButton> buttons = new ArrayList<>();

    @Override
    public List<JButton> getButtons() {
        return buttons;
    }

    public JPanel getPanel() {
        return panel;
    }

    RadioButtons(JFrame frame) {
        JTextField textField = new JTextField(15);
        JButton button = new JButton("choose");
        JRadioButton radioButton1 = new JRadioButton("first");
        JRadioButton radioButton2 = new JRadioButton("second");
        JRadioButton radioButton3 = new JRadioButton("third");
        buttons.add(button);
        List<JRadioButton> radioButtons = new ArrayList<>();
        radioButtons.add(radioButton1);
        radioButtons.add(radioButton2);
        radioButtons.add(radioButton3);
        button.addActionListener(e -> {
            for (JRadioButton button1 : radioButtons) {
                button1.setSelected(textField.getText().equals(button1.getText()));
            }
        });


        panel = new JPanel();
        panel.add(textField);
        panel.add(button);
        panel.add(radioButton1);
        panel.add(radioButton2);
        panel.add(radioButton3);
    }
}
