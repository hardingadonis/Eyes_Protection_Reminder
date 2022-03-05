import eel
import sys

eel.init('landing/dist')

@eel.expose
def log_eel():
   print(eel)

@eel.expose
def exit():
   sys.exit()

eel.start('index.html', size=(500, 800))