
### Instruction

```python
stateFactory(initialValue -> any) -> (state, setState)
```

`initialValue`: initial value which will be set to `state` if no configuration has been found  
`state`: Current state  
`setState: (value -> any)`: we can use this function to set value for current state, that state will be automatically saved to configuration file in `C:\User\{User}\AppData\Roaming\Eyes_Protection_Reminder` 

#### Example:

```python
timing, setTiming = stateFactory(100)

print(timing) # 100

setTiming(200) 
print(timing) # 200
```

#### We can declare hundreds of state with this function, for example, if we want to save `reminding time` configuration, just declare:
```python
remindTime, setRemindingTime = stateFactory(200)
```
in a file in your directory ( i.e. `index.py`)
and now whenever you want to get `remindingTime` or set new value to it, just import `index.py` and call it


