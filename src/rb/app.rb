#!/usr/bin/env ruby

require "selenium-webdriver"

driver = Selenium::WebDriver.for :firefox
driver.navigate.to "http://google.com"

element = driver.find_element(name: 'q')
element.send_keys "helloo webdriverrr"
element.submit

puts driver.title

sleep(25)

driver.quit

