#!/bin/bash

# Check for root permission
if [ "$(id -u)" -ne 0 ]; then
    echo "This script must be run as root. Please run with sudo."
    exit 1
fi

# Variables
SOURCE_FILE="main.c"
TARGET_EXECUTABLE="nonsleep-screen"
TARGET_PATH="/usr/local/bin/$TARGET_EXECUTABLE"
DESKTOP_FILE="/usr/share/applications/NonsleepScreen.desktop"

# Compile the source code
echo "Compiling $SOURCE_FILE..."
gcc -o "$TARGET_EXECUTABLE" "$SOURCE_FILE" `pkg-config --cflags --libs gtk+-3.0`

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Please check for errors in $SOURCE_FILE."
    exit 1
fi

# Move the compiled executable to /usr/local/bin
echo "Moving $TARGET_EXECUTABLE to /usr/local/bin..."
mv "$TARGET_EXECUTABLE" "$TARGET_PATH"

# Check if the move was successful
if [ $? -ne 0 ]; then
    echo "Failed to move the executable. Please check permissions."
    exit 1
fi

# Create the .desktop file
echo "Creating .desktop file at $DESKTOP_FILE..."
cat <<EOF > "$DESKTOP_FILE"
[Desktop Entry]
Name=NonSleep Screen
Comment=Toggles screen sleep inhibition
Exec=$TARGET_PATH
Icon=system-suspend
Terminal=false
Type=Application
Categories=Utility;
EOF

# Set permissions for the .desktop file
chmod +x "$DESKTOP_FILE"

# Confirm completion
echo "Setup completed. You can now search for 'NonSleep Screen' in your applications menu."

