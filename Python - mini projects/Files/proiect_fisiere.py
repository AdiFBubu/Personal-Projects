from datetime import datetime
import time

def create_files():
    with open("tasks.txt", 'w') as file:
        pass
    with open("categorii.txt", 'w') as file:
        pass



def menu():

    print("\n\nMeniu\n ")
    print("1. Listare date")
    print("2. Sortare")
    print("3. Filtrare date")
    print("4. Adaugare nou task in lista initiala")
    print("5. Editare detalii referitoare la task, data, persoana, categorie")
    print("6. Stergere task din lista initiala")
    print("7. Iesire din aplicatie")


def add_category(categorii):

    with open('categorii.txt', 'w') as file:
        print("Introduceti de la tastatura categoriile dorite: ")
        print("Daca ai finalizat operatia anterioara, introduceti litera: 'x'")
        categorie = input()
        while True:
            if categorie == 'x':
                print("Ai iesit din functionalitatea de adaugare categorii!\n")
                return
            else:
                if categorie in categorii:
                    print("Exista deja aceasta categorie inregistrata!\n")
                else:
                    categorii.append(categorie)
                    file.write(categorie)
                    file.write('\n')
            categorie = input()

def add_task(categorii, tasks):
    task_name = input("Introdu numele task-ului: ")
    date = input("Intodu data limita de realizare a task-ului: ")
    attr = date.split(' ')

    date = attr[0]
    time = attr[1]

    person = input("Introdu numele persoanei responsabile cu realizarea task-ului respectiv: ")
    category = input("Introduceti categoria din care face parte task-ul: ")
    if category not in categorii:
        print("Nu exista categoria introdusa!")
        return
    task = task_name + '/' + date+ '/'  + time + '/' + person + '/' + category
    if task in tasks:
        print("Acest task a fost introdus deja!")
        return
    tasks.append(task)

    with open('tasks.txt', 'a') as file:
        file.write(task)
        file.write('\n')
    print("Task adaugat cu succes!")

    return

def get_tasks():
    tasks_copy = []
    with open("tasks.txt", 'r') as file:
        for line in file.readlines():
            line = list(line)
            if line[-1] == '\n':
                line = line[:-1]
            line = ''.join(line)
            task_copy = line.split('/')
            tasks_copy.append(task_copy)
    return tasks_copy
def date_list():

    tasks_copy = get_tasks()
    if len(tasks_copy) == 0:
        print("Nu exista niciun task inregistrat!")
    else:
        print("\n\nListarea datelor ordonate dupa categoria task-ului: ")
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[4])
        for task in sorted_tasks:
            line = 'TASK: ' + task[0] + ', DATA: ' + task[1] + ' ' + task[2] + ', ' + 'PERSOANA RESPONSABILA: ' + task[3] + ', CATEGORIE TASK: ' + task[4]
            print(line)

def sorting_menu():
    print("Meniu sortari: ")
    print("1. sortare ascendenta task")
    print("2. sortare descendenta task")
    print("3. sortare ascendenta data")
    print("4. sortare descendenta data")
    print("5. sortare ascendenta persoana responsabila")
    print("6. sortare descendenta persoana responsabila")
    print("7. sortare ascendenta categorie")
    print("8. sortare descendenta categorie")

def sorting():
    sorting_menu()
    try:
        cmd = int(input("Intodu cifra corespunzatoare operatiei dorite: "))
    except ValueError:
        print("Trebuie sa introduci o cifra!")
        return
    tasks_copy = get_tasks()
    if cmd == 1:
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[0])
    elif cmd == 2:
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[0], reverse = True)
    elif cmd == 3:
        sorted_tasks = sorted(tasks_copy, key = lambda x: (datetime.strptime(x[1], "%d.%m.%Y"), time.strptime(x[2], "%H:%M") ) )
    elif cmd == 4:
        sorted_tasks = sorted(tasks_copy, key = lambda x: (datetime.strptime(x[1], "%d.%m.%Y"), time.strptime(x[2], "%H:%M") ), reverse = True)
    elif cmd == 5:
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[3])
    elif cmd == 6:
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[3], reverse = True)
    elif cmd == 7:
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[4])
    elif cmd == 8:
        sorted_tasks = sorted(tasks_copy, key = lambda x: x[4], reverse = True)
    else:
        print("Nu ai introdus o cifra potrivita!")
        return
    print("\n\nTask-urile sortate sunt: ")
    for task in sorted_tasks:
        line = 'TASK: ' + task[0] + ', DATA: ' + task[1] + ' ' + task[2] + ', ' + 'PERSOANA RESPONSABILA: ' + task[3] + ', CATEGORIE TASK: ' + task[4]
        print(line)

    return

def filter_menu():
    print("\nFiltrare dupa: ")
    print("1. Task")
    print("2. Data")
    print("3. Persoana responsabila")
    print("4. Categorie")
def date_filter():

    filter_menu()
    try:
        cmd = int(input("Introdu cifra corespunzatoare filtrarii dorite: "))
    except ValueError:
        print("Trebuie sa introduci o cifra!")
        return
    tasks_copy = get_tasks()
    filter_string = input("Introdu un string in functie de care doresti sa aiba loc filtrarea: ")

    if cmd == 1:
        filter_list = filter(lambda x : x[0] == filter_string, tasks_copy)
    elif cmd == 2:
        attr = filter_string.split(' ')
        filter_list = filter(lambda x : ( x[1] == attr[0] and x[2] == attr[1] ), tasks_copy )
    elif cmd == 3:
        filter_list = filter(lambda x : x[3] == filter_string, tasks_copy)
    elif cmd == 4:
        filter_list = filter(lambda x : x[4] == filter_string, tasks_copy)
    else:
        print("Trebuie sa introduci o cifra de la 1 la 4!")
        return
    filter_list = list(filter_list)
    if len(filter_list) == 0:
        print("Nu exista niciun task cu prorpietatea introdusa!")
        return
    print("\n\nLista filtrata dupa proprietatea data este: ")
    for task in filter_list:
        line = 'TASK: ' + task[0] + ', DATA: ' + task[1] + ' ' + task[2] + ', ' + 'PERSOANA RESPONSABILA: ' + task[3] + ', CATEGORIE TASK: ' + task[4]
        print(line)

def show_tasks():
    tasks_copy = get_tasks()
    print("\n\nLista de task-uri actuala este: ")
    for index, task in enumerate(tasks_copy):
        line = "INDEX: " + str(index) + ' -> '
        line += 'TASK: ' + task[0] + ', DATA: ' + task[1] + ' ' + task[2] + ', ' + 'PERSOANA RESPONSABILA: ' + task[3] + ', CATEGORIE TASK: ' + task[4]
        print(line)
    print('\n')
def edit_tasks():
    show_tasks()
    try:
        cmd = int(input("Introdu cifra corespunzatoare task-ului asupra caruia doresti sa editezi datele: ") )
    except ValueError:
        print("Trebuie sa introduci un numar intreg!")
        return
    if cmd >= len(tasks):
        print("Nu exista indicele introdus!")
        return

    task_name = input("Introdu numele task-ului de editat: ")
    date = input("Intodu data limita de realizare a task-ului de editat ")
    attr = date.split(' ')

    date = attr[0]
    time = attr[1]

    person = input("Introdu numele persoanei responsabile cu realizarea task-ului de editat respectiv: ")
    category = input("Introduceti categoria din care face parte task-ul de editat: ")

    task = task_name + '/' + date+ '/'  + time + '/' + person + '/' + category
    if task in tasks:
        print("Acest task a fost introdus deja!")
        return

    tasks[cmd] = task

    with open("tasks.txt", "w") as file:
        for task in tasks:
            file.write(task)
            file.write('\n')
    print("Task editat cu succes!")
    print("\n\nLista actualizata cu task-uri este: ")
    for task in tasks:
        line = 'TASK: ' + task[0] + ', DATA: ' + task[1] + ' ' + task[2] + ', ' + 'PERSOANA RESPONSABILA: ' + task[3] + ', CATEGORIE TASK: ' + task[4]
        print(line)
    print("\n\n")

def delete_task():
    if len(tasks) == 0:
        print("Nu poti sterge niciun task, caci niciunul nu e inregistrat!")
        return
    show_tasks()
    try:
        cmd = int(input("Introdu indexul task-ului pe care doresti sa il stergi: "))
    except ValueError:
        print("Trebuie sa introduci un numar intreg!")
        return
    if cmd >= len(tasks):
        print("Nu exista indicele introdus!")
        return
    tasks.pop(cmd)

    with open("tasks.txt", "w") as file:
        for task in tasks:
            file.write(task)
            file.write('\n')
    print("Task editat cu succes!")
    print("\n\nLista actualizata cu task-uri este: ")
    for task in tasks:
        line = 'TASK: ' + task[0] + ', DATA: ' + task[1] + ' ' + task[2] + ', ' + 'PERSOANA RESPONSABILA: ' + task[3] + ', CATEGORIE TASK: ' + task[4]
        print(line)
    print("\n\n")





create_files()
categorii = []
tasks = []
add_category(categorii)

while True:

    menu()
    try:
        cmd = int(input("Introdu cifra dorita: "))
    except ValueError:
        print("Trebuie sa introduci o cifra!")
        continue

    if cmd == 1:
        date_list()

    elif cmd == 2:
        sorting()

    elif cmd == 3:
        date_filter()

    elif cmd == 4:
        add_task(categorii, tasks)

    elif cmd == 5:
        edit_tasks()

    elif cmd == 6:
        delete_task()

    elif cmd == 7:
        break

    else:
        print("Trebuie sa introduci o cifra intre 1 si 7!")

