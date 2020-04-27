import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class IndividualTask {

    private JPanel panel;

    public JPanel getPanel() {
        return this.panel;
    }

    private JButton myButton = new JButton("line");

    public void task(List<JButton> buttons) {
        myButton.addActionListener(actionEvent -> {
            for (JButton button : buttons) {
                button.setText(button.getText() + "  ");
                int last = button.getText().length() - 1;

                Timer timer = new Timer(170, actionEvent1 -> {
                    button.setText(button.getText().charAt(last) + button.getText().substring(0, last));
                });
                timer.start();
            }
        });
    }

    public IndividualTask() {

        panel = new JPanel();
        panel.add(myButton);
    }
}
