import requests
from pynput.keyboard import Key, Listener

x_last = 0
y_last = 0
x_axis = 0
y_axis = 0

# function to send joystick command based on pressed key
def send_command(event):
    if event.name in mapping:
        axis, value = mapping[event.name]
        if (axis == "x_axis"):
            x_axis = value
        elif(axis == "y_axis"):
            y_axis = value
    elif event.name == 'esc':
        # exit program on Escape key press
        exit(0)

# define keyboard-to-joystick mapping (arrows and X/Y analog)
mapping = {
    'up': ("x_axis", 1),
    'down': ("x_axis", -1),
    'left': ("y_axis", 1),
    'right': ("y_axis", -1)
}

# if (x_axis != x_last or y_axis != y_last):
#         url = "http://192.168.4.1/joystick"
#         params = {"x_axis": x_axis, "y_axis": y_axis}
#         #response = requests.get(url, params = params, timeout = 5)
#         print("X axis: {}, Y axis: {},last X: {}, last Y: {}".format(x_axis, y_axis, x_last, y_last))
#         x_last = x_axis
#         y_last = y_axis


def on_release(key):
    #print('{0} release'.format(key))
    if key == Key.esc:
        # Stop listener
        print('{0} release'.format(key))
        return False
    
# Collect events until released
with Listener(
        on_press=send_command,
        on_release=on_release) as listener:
    listener.join()