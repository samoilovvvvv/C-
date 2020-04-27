import javax.swing.*;
import java.util.ArrayList;
import java.util.List;


class TextFieldTest extends JFrame {




    public TextFieldTest() {
        super("Текстовые поля");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        JPanel main = new JPanel();
        main.setLayout(new BoxLayout(main, BoxLayout.Y_AXIS));
        IndividualTask composition6 = new IndividualTask();
        Checkboxes composition4 = new Checkboxes(this);
        SetTextOfButton composition2 = new SetTextOfButton();
        RadioButtons composition3 = new RadioButtons(this);
        Table composition5 = new Table();


        List<IGetButton> buttonList = new ArrayList<>();
        buttonList.add(new AddingWord(this));
        buttonList.add(new Checkboxes(this));
        buttonList.add(composition2);
        buttonList.add(composition3);
        buttonList.add(composition5);

        for (IGetButton getButton : buttonList) {
            main.add(getButton.getPanel());
            composition6.task(getButton.getButtons());
        }

        main.add(composition6.getPanel());
        add(main);
        setSize(800, 1030);
        setVisible(true);
    }

    public static void main(String[] args) {
        new TextFieldTest();

    }
}