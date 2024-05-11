import requests
from bs4 import BeautifulSoup
import re
import serial
import time
#import simpleaudio as sa
 
old1 = 0
old2 = 0
 
#wave_obj = sa.WaveObject.from_wave_file("gol.wav")
 
while True:
    url = "https://online.sport.cz/detail/81106/#hp-sport"
    response = requests.get(url)
 
    soup = BeautifulSoup(response.text, 'html.parser')
 
    tag = soup.find("h1", id="article-title-superior")
 
    if tag:
        tag_content = tag.text.strip()
 
        numbers = re.findall(r'\b\d+\b', tag_content)
        print(tag_content)
 
        if(old1 != numbers[0] or old2 != numbers[1]):
#           play_obj = wave_obj.play()
            old1 = numbers[0]
            old2 = numbers[1]
 
        with serial.Serial('/dev/ttyACM0', 9600, timeout=1) as ser:
                ser.write(f"{numbers[0]},{numbers[1]}\n".encode())
 
        if len(numbers) == 2:
            print("Numbers extracted:", numbers)
        else:
            print("Error: Couldn't extract two numbers between the colon")
    else:
        print("Error: Tag not found")
    time.sleep(10)
 

