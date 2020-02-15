#!/usr/bin/env python3
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import os, sys

'''

if keyboard key pressed
"q" then exit

'''

def main(addr, msg):
    driver = webdriver.Firefox()
    driver.get(addr)
    element = driver.find_element_by_name("q")
    element.clear()
    element.send_keys(msg)
    element.send_keys(Keys.RETURN)
    print("Title::: " + driver.title)
    time.sleep(25)
    driver.close()

if len(sys.argv) > 4:
    addr = ""
    msg = ""
    if sys.argv[1] == "addr":
        addr = sys.argv[2]
    if sys.argv[3] == "msg":
        msg = sys.argv[4]

    main(addr, msg)
else:
    print("unexpected param length")
