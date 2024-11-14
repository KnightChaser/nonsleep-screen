# nonsleep-screen

This is a simple GTK-based program written in C that allows you to toggle sleep inhibition (preventing the screen from automatically turning off) on Ubuntu Desktop.

![image](https://github.com/user-attachments/assets/08886d58-cbe9-4f60-8ed3-e96279cb815e)

## Requirements

- **GTK 3** development libraries
  - Install via: `sudo apt update && sudo apt install libgtk-3-dev`

## What It Does (simple!)

- Provides a small window with:
  - A **button** to toggle sleep inhibition on and off.
  - A **label** showing the current status of sleep inhibition, displayed in bold and color:
    - **Green** text for "Enabled"
    - **Red** text for "Disabled"

## Build and Run

1. **Build the Program**  
   Run `make` in the project directory to compile the program into `main.out`.

2. **Run the Program**  
   Execute the program with:

   ```bash
   ./main.out

3. (Optional) If you want to register the compiled binary as an application for your Ubuntu Desktop, run `./register_as_app.sh` with a root(`sudo`) permission. It eliminates the need of manually opening the terminal, finding the path of `main.out` of this project, and manually run.

    ```bash
    sudo ./register_as_app.sh
    ```
