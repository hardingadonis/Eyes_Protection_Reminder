call ./.venv/Scripts/activate
pip install -r requirements.txt
pyinstaller --noconfirm --onefile --windowed --icon "assets/icon_white.ico" --name "Eyes Protection Reminder" --add-data "D:/Learning/Python/Eyes_Protection_Reminder/assets;assets/"  "main.py"