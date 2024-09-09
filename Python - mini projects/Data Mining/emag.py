import pandas as pd
from selenium import webdriver
from selenium.common import exceptions
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.service import Service

option = webdriver.ChromeOptions()
option.add_argument('start-maximized')
driver = webdriver.Chrome(service = Service(ChromeDriverManager().install()), options = option)
driver.get('https://www.emag.ro/#opensearch')
get_element = driver.find_element(by=By.ID, value = 'searchboxTrigger')
get_element.send_keys('telefon')
get_element.submit()
element = driver.find_elements(by=By.CLASS_NAME, value = 'card-item')
product_list, price_list, list_of_elements = [], [], []
#for i in element:
#    try:
#        product = i.find_element(by=By.CLASS_NAME, value = 'card-v2-title')
#        product_list.append(product.text)
#        price = i.find_element(by=By.CLASS_NAME, value = 'product-new-price')
#        price_list.append(price.text)
#    except exceptions.NoSuchElementException:
#        pass
#print(product_list)
#print(price_list)
#list_of_elements.append(product_list)
#list_of_elements.append(price_list)
#df = pd.DataFrame(list_of_elements).transpose()
#df.to_csv('emag_all_products.csv')

#var 2

#dictionar = {f"telefon_{i}" : [] for i in range(1, len(element) + 1)}

#dictionar = {}
#for i in range(1, len(element) + 1):
#    dictonar[f"telefon_{i}"] = []

dictionar = {'name': [], 'price': []}

list_of_products = []

for i, v in enumerate(element):
    try:
        product = v.find_element(by=By.CLASS_NAME, value = 'card-v2-title')
        price = v.find_element(by=By.CLASS_NAME, value = 'product-new-price')
        product_list.append(product.text)
        price_list.append(price.text)
        list_of_products.append(f"telefon_{i + 1}")
    except exceptions.NoSuchElementException:
        pass

dictionar['name'] = product_list
dictionar['price'] = product_list
df = pd.DataFrame(dictionar, index = list_of_products)
df.to_csv('emag_all_products_dict.csv')
