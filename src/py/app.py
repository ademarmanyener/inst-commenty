#!/usr/bin/env python3
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
import time
import os, sys

'''

if keyboard key pressed
"q" then exit

'''

def error_message(msg):
    print("error")
    print("=====")
    print(" -> " + msg)

def main(username, password, addr, msg):
    time_delay = 4

    options = Options()
    options.add_argument("--headless")

    driver = webdriver.Firefox(options=options)
    driver.get("https://instagram.com/accounts/login")

    time.sleep(time_delay)

    # username - passwd inputs
    username_input = driver.find_element_by_name("username")
    password_input = driver.find_element_by_name("password")
    username_input.send_keys(username)
    password_input.send_keys(password)
    password_input.send_keys(Keys.ENTER)
    
    time.sleep(time_delay)
    
    driver.get(addr)

    time.sleep(time_delay)

    # enter message and send
    text_area = driver.find_element_by_class_name("Ypffh")
    text_area.click()
    text_area = driver.find_element_by_class_name("Ypffh")
    text_area.send_keys(msg)
    text_area.send_keys(Keys.ENTER)
    
    time.sleep(time_delay)
    driver.close()

if len(sys.argv) > 7:
    username = ""
    password = ""
    addr = ""
    msg = ""
    if sys.argv[1] == "--username":
        username = sys.argv[2]
    if sys.argv[3] == "--password":
        password = sys.argv[4]
    if sys.argv[5] == "--addr":
        addr = sys.argv[6]
    if sys.argv[7] == "--msg":
        msg = sys.argv[8]
    main(username, password, addr, msg)
else: 
    error_message("unexpected param length, use --usage")

  
