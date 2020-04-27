import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class SetTextOfButton implements IGetButton{
    private JPanel panel;
    private List<JButton> buttons;
    JButton firstButton, secondButton;

    public List<JButton> getButtons() {
        return buttons;
    }

    public JPanel getPanel() {
        return panel;
    }

    SetTextOfButton() {
        buttons = new ArrayList<>();
        JTextField textField = new JTextField(18);
        firstButton = new JButton("first");
        secondButton = new JButton();
        firstButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                secondButton.setText(textField.getText());

            }
        });
        secondButton.addActionListener(e -> {
            String temp = secondButton.getText();
            secondButton.setText(firstButton.getText());
            firstButton.setText(temp);
        });
        buttons.add(firstButton);
        buttons.add(secondButton);
        panel = new JPanel();
        panel.add(textField);
        panel.add(firstButton);
        panel.add(secondButton);
        // add(panel);
    }
}
