import os

# where we will save our configuration
DIR_PATH = os.path.join(os.environ['APPDATA'], 'Eyes_Protection_Reminder')

# Don't use this function
def _stateFactoryMaker():
   # Unique id, each id is the name of the file which we will use to store 
   # current state
   index = 0

   def stateFactory(initialValue):
      # Create an unique id between each state to save in roaming
      nonlocal index
      index += 1

      # Declare state
      state = initialValue

      # configuration file, which will be unique for each state
      FILE_NAME = os.path.join(DIR_PATH, str(index))

      # Create folder Eyes_Protection_Reminder in Roaming folder
      if not os.path.exists(DIR_PATH):
         os.makedirs(DIR_PATH)

      # Assign state to value and save it to configuration file
      def setState(value):
         nonlocal state
         state = value

         with open(FILE_NAME, 'w') as reader:
            reader.write(str(value))
      
      # sometime, the value in the file can be broken in some way,
      # in that case, all we need to do is abandon it, so the state
      # will be assigned to initialValue and in the next time we call
      # setState, the value in that file will be normal again
      try:
         if os.path.exists(FILE_NAME):
            with open(FILE_NAME, 'r') as reader:
               # Convert data in the file from string to initial data type
               state = type(initialValue)(reader.read())
      except: 
         pass

      # return setState, state
      return state, setState

   return stateFactory

# import this function
# create a higher-order function that create a getter and setter for a state
#
# @param {initialValue} initial value which will be assigned to state if no configuration file has been found
#
# @return (state, setState) state is a variable which will be used to get current state
#                            setState is a function which take 1 arguments as the value that we need to assign to state
#
# @example 
# timing, setTiming = stateFactory(100)
# print('Timing: ', timing) # Timing: 100
# setTiming(300)
# print('Timing: ', timing) # Timing: 300

# in the next time,
# print('Timing: ', timing) # Timing: 300
# The timing state has been saved to roaming so we can use it later
stateFactory = _stateFactoryMaker()