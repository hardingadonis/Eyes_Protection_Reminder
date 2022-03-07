import eel
import sys
from utils.relativeLink import relative_to_assets

def start_landing(): 
   eel.init('assets/landing')

   @eel.expose
   def log_eel():
      print(eel)

   eel.start('index.html', size=(500, 800))