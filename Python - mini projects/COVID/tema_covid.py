import pandas as pd
from selenium import webdriver
from selenium.webdriver import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager

option = webdriver.ChromeOptions()
option.add_argument('start-maximized')
driver = webdriver.Chrome(service= Service(ChromeDriverManager().install()), options = option)

#button = driver.find_element(by = By.CLASS_NAME, value = 'swal2-close')
#button.click()

#button = driver.find_element(by = By.XPATH, value = '//*[@id="pages-2"]/ul/li[2]')
#button.location_once_scrolled_into_view
#button.click()

dictionar = { "NR. CRT": [], "Judet" : [], "10.12": [], "11.12": [], "12.12": [], "13.12": [], "14.12": [] }
header_text = ["NR. CRT", "Judet", "10.12", "11.12", "12.12", "13.12", "14.12"]

for i in range(0, 5):

    driver.get(f'https://www.mai.gov.ro/informare-covid-19-grupul-de-comunicare-strategica-1{i}-decembrie-ora-13-00-2/')

    loc = driver.find_element(by = By.CLASS_NAME, value = 'entry-content')
    table = loc.find_element(by = By.XPATH, value = '//table[1]')


    rows = table.find_elements(by = By.TAG_NAME, value = 'tr')

    lista = []
    for row in rows:
        row.location_once_scrolled_into_view
        cells = row.find_elements(by = By.TAG_NAME, value = 'td')

        if row == rows[-1]:
            val = cells[0].text
            val = val.strip()
            lista.append(val)

            lista.append("")

            val = cells[1].text
            val = val.strip()
            lista.append(val)

        else:
            for cell in cells[0:3]:
                val = cell.text
                val = val.strip()
                lista.append(val)

    if i == 0:
        for k in range(0, 3):
            for j in range(3 + k, len(lista), 3):
                dictionar[ header_text[k] ].append(lista[j])
    else:
        for j in range(5, len(lista), 3):
            dictionar[ header_text[2 + i] ].append(lista[j])
            
df = pd.DataFrame(dictionar)
df.to_csv("COVID-19_DATA.csv", index = False)
