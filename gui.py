import sys
import subprocess
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QLineEdit, QTextEdit, QPushButton, QVBoxLayout, QWidget

class CompilerWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Compiler")
        self.setGeometry(100, 100, 500, 400)

        main_widget = QWidget(self)
        self.setCentralWidget(main_widget)

        layout = QVBoxLayout(main_widget)

        self.text_input = QTextEdit()
        layout.addWidget(self.text_input)

        self.compile_button = QPushButton("Compile")
        layout.addWidget(self.compile_button)
        self.compile_button.clicked.connect(self.compile_button_clicked)

        self.functions_textbox = QTextEdit()
        layout.addWidget(self.functions_textbox)

        self.instructions_textbox = QTextEdit()
        layout.addWidget(self.instructions_textbox)

        self.symbols_textbox = QTextEdit()
        layout.addWidget(self.symbols_textbox)

    def compile_button_clicked(self):

        code_text = self.text_input.text()

        # Store the code in a file named "code_text"
        with open("code_text", "w") as file:
            file.write(code_text)

        # Close the file
        file.close()

        # Call the bash script "run.sh"
        subprocess.call(["./run.sh", "code_text"])


        functions_file = "functions.txt"
        instructions_file = "instructions.txt"
        symbols_file = "symbols.txt"

        self.functions_textbox.clear()
        self.instructions_textbox.clear()
        self.symbols_textbox.clear()

        # Create a file named "functions.txt" and store the functions in it
        # Create a file named "instructions.txt" and store the instructions in it
        # Create a file named "symbols.txt" and store the symbols in it


        with open(functions_file, "r") as file:
            functions_data = file.read()
            self.functions_textbox.setText(functions_data)

        with open(instructions_file, "r") as file:
            instructions_data = file.read()
            self.instructions_textbox.setText(instructions_data)

        with open(symbols_file, "r") as file:
            symbols_data = file.read()
            self.symbols_textbox.setText(symbols_data)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = CompilerWindow()
    window.show()
    sys.exit(app.exec())