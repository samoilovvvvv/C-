import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class Checkboxes implements IGetButton {

    private JPanel panel;
    private JButton button;
    public JButton getButton(){
        return button;
    }
    public JPanel getPanel(){
        return  panel;
    }

    private List<JButton> buttons = new ArrayList<>();

    @Override
    public List<JButton> getButtons() {
        return buttons;
    }

    Checkboxes(JFrame frame){
        JTextField textField = new JTextField(15);
        button = new JButton("choose");
        JCheckBox checkBox1 = new JCheckBox("first");
        JCheckBox checkBox2 = new JCheckBox("second");
        JCheckBox checkBox3 = new JCheckBox("third");
        List<JCheckBox> boxes = new ArrayList<>();
        boxes.add(checkBox1);
        boxes.add(checkBox2);
        boxes.add(checkBox3);
        buttons.add(button);
        button.addActionListener(e -> {

            for(JCheckBox box:boxes){
                if(textField.getText().equals(box.getText())){
                    box.setSelected(!box.isSelected());
                }else {
                    JOptionPane.showMessageDialog(frame,
                            "такого нет");
                }
            }
        });
         panel = new JPanel();
        panel.add(textField);
        panel.add(button);
        panel.add(checkBox1);
        panel.add(checkBox2);
        panel.add(checkBox3);
    }


}
