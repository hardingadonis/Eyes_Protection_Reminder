import eel
import sys

eel.init('landing')

@eel.expose
def log_eel():
   print(eel)

eel.start('index.html', size=(500, 800))