<strong>Property Manager</strong><br><br>
Create an application that allows:<br>
&emsp;&emsp;- management of a list of tenants -> Tenant: apartment, owner name, area, apartment type <br>
&emsp;&emsp;- add, delete, modify and display tenants <br>
&emsp;&emsp;- apartment search <br>
&emsp;&emsp;- filter apartments by: apartment type, area <br>
&emsp;&emsp;- sort apartments by: owner name, area, apartment type + area <br><br>

&emsp;Replace the std::vector class with your own parameterized class (Template) that implements a list using the chained list or dynamic vector data structure <br><br>

Data validation: The user is notified by a message if: <br>
* enters wrong input values;
* tries to add an entity twice;
* tries to delete / modify a non-existent entity <br> (exceptions will be used) <br><br>

&emsp;Create a UML class diagram to sketch the application architecture <br><br>

&emsp;Modify the application: use the vector class from STL and replace all the "for" from the application with algorithms from the STL and the c++11 version of "for" (range for). <br>
&emsp;Use exceptions to report errors (create your own exception classes) <br>
&emsp;Enter the possibility to create a notification list. The user can interactively create a list of apartments to be notified. Add the following actions (menu items): <br>
* empty the list: deletes all apartments from the list.
* add to list: adds an apartment by apartment number
* generate list: the user enters the total number of apartments and the list is randomly populated with apartments
* export: save the list to file: CVS or HTML, save to file only when this menu is selected, the list is not persistent (when restarting the application the list is empty again), the user enters the name of the file where to save each export
* after each user action, the total number of apartments in the list is displayed <br><br>

&emsp;Add the possibility to save apartment data in files. <br><br>

&emsp;Add "undo" for the operations: add, delete and modify. For implementation use inherit and polymorphism <br><br>

&emsp;**GUI** <br><br>
&emsp;Create the graphical user interface using Qt for the application you are working on. <br>
&emsp;Windows are created from code, without window designers, drag&drop etc. All functionality in the application must be accessible using the user interface <br>
&emsp;There must be at least 2 windows in the application. <br> <br>

&emsp;**1. Observer Pattern** <br>
&emsp;Create two different windows showing the contents of the list (CosCRUDGUI, CosReadOnlyGUI): <br>
* CosCRUDGUI - contains a list or table (the items in the list) and buttons for empty/generate.
* CosReadOnlyGUI - use drawing to show the number of items in the list. Geometric figures or images on random positions appear on this window. So many as many figures as the list has elements. <br>

&emsp;On the main application window: <br>
* add functionality to add/delete/generate list contents
* add 2 buttons that open windows showing the list (CartCRUDGUI, CosReadOnlyGUI). Each click opens a new window. <br>

&emsp;**Attention!** Each window shows the contents of that list. Any modification of the basket must be automatically visible in all open windows (use the Observer template). <br><br>

&emsp;**2. Model / View** <br>
&emsp;For the List/Table to use Qt View/Model components ( classes QListView / QTableView ). Create your own model, a class that extends QAbstractListModel or QAbstractTableModel. For the List/Table use QT View / Model components ( the QListView / QTableView ). Create your own model, a class that extends QAbstractListModel or QAbstractTableModel. <br><br>

&emsp;**Keywords**: Entity, Const Correctness, Templates, Data Validation, UML Diagram, STL Algorithms, Exceptions, Inheritance, Polymorphism, Encapsulation, Abstraction
Memory Management, GUI Application (QT), Observer Pattern, QT Model / View, Painter
