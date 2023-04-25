import requests
from pynput.keyboard import Key, Listener

# function to send joystick command based on pressed key
def send_command(key):
    key= str(key)
    axis, value = mapping[key]
    if (axis == "x_axis"):
        x_val = value
        y_val = 0
    elif(axis == "y_axis"):
        y_val = value
        x_val = 0
    else:
        pass
    call_req(x_val, y_val)

# define keyboard-to-joystick mapping (arrows and X/Y analog)
mapping = {
    'Key.up': ("y_axis", 1),
    'Key.down': ("y_axis", -1),
    'Key.left': ("x_axis", -1),
    'Key.right': ("x_axis", 1)
}

#Call request using direction from key
def call_req(x_val=0, y_val=0):
    url = "http://192.168.4.1/joystick"
    params = {"x_axis": x_val, "y_axis": y_val}
    response = requests.get(url, params = params, timeout = 5)
    print("X axis: {}, Y axis: {}".format(x_val, y_val))

#Release key
def on_release(key):
    call_req()
    if key == Key.esc:
        # Stop listener
        return False
        
    
# Collect events until released
with Listener(
        on_press=send_command,
        on_release=on_release) as listener:
    listener.join()