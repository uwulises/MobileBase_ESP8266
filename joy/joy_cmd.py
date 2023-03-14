import requests
import pygame

pygame.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

while True:
    try:
        pygame.event.get()
        x_axis = round(joystick.get_axis(0))
        y_axis = -round(joystick.get_axis(1))
        print("X axis: {}, Y axis: {}".format(x_axis, y_axis))
        
        # Make GET request
        url = "http://192.168.4.1/joystick"
        params = {"x_axis": x_axis, "y_axis": y_axis}
        response = requests.get(url, params = params, timeout = 5)
    except KeyboardInterrupt:
        break
