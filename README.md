# heapOfStudents

## ULM Diagram
[![](https://mermaid.ink/img/pako:eNp1U8FSwyAU_JUMXmpNfyDjxZmOelAvvTm5YN5rykwDGXg4xpp_FxJqqFAuhF2yj90HJ9YoQFax5siN2Qreat7VsnBjRxZQUnH_s9kUDwAajckwW05Yy5mYRM57TzPmx01hSAvZ-gmRMkQjaMjun9QT_Fv0C3pXfCoB57Kr24QRUtBqLl1OlcpZuPQ66fbelaBI7exujE162zmH4PDd9BmTTrDolKTDfxD48B8akOvkTL7cNWdLySte4p_Hy16FVuZ7NVGpmcDvhTb0xrtcf5x2QvlTrAtQHymIXz02hPCkOcRsaML68votUTUaQdCzstrEzoOpy7w2WTS-H5HdK0FmJQxBVQXfLdKLs_7oo4kS9xMrWYe64wLca5vyrhkd0GXEKvcJuOf2SDWr5ei2cktqN8iGVaQtlkwr2x5YtedH41a29z0Pr_UP7bl8V2pZ-2yUfg3v20_jL8DhLek?type=png)](https://mermaid.live/edit#pako:eNp1U8FSwyAU_JUMXmpNfyDjxZmOelAvvTm5YN5rykwDGXg4xpp_FxJqqFAuhF2yj90HJ9YoQFax5siN2Qreat7VsnBjRxZQUnH_s9kUDwAajckwW05Yy5mYRM57TzPmx01hSAvZ-gmRMkQjaMjun9QT_Fv0C3pXfCoB57Kr24QRUtBqLl1OlcpZuPQ66fbelaBI7exujE162zmH4PDd9BmTTrDolKTDfxD48B8akOvkTL7cNWdLySte4p_Hy16FVuZ7NVGpmcDvhTb0xrtcf5x2QvlTrAtQHymIXz02hPCkOcRsaML68votUTUaQdCzstrEzoOpy7w2WTS-H5HdK0FmJQxBVQXfLdKLs_7oo4kS9xMrWYe64wLca5vyrhkd0GXEKvcJuOf2SDWr5ei2cktqN8iGVaQtlkwr2x5YtedH41a29z0Pr_UP7bl8V2pZ-2yUfg3v20_jL8DhLek)

### Student
- Student init(studentString) will take entire string and conduct a parse.
- Convert credit hour string to int and assign
- Create Date dob instance on heap
- Create Date gradDate instance on heap
- Create Address instance on heap

### Address
- Instances of Address will be created on the heap.
- Initialize Address objects with 4 string arguements: street, city, state, zip.
- Contains a printAddress function.

### Date
- Instances of Date will be created on the heap.
- Create separate instances for a student's date of birth and a student's expected graduation date.
- Each instance will initialize with a string date in the format MM/DD/YYYY.
- Print the date as "Month DD, YYYY" format.

```
 void Date::init(date)
	give dateString the string date
	intialize a stringstream
	initialize variables to store number strings of sMonth, sDay, and sYear
	give the stringstream the date
	parse the dates and store into the string month, day, and year
	convert the strings into integers and store in month, day, year
```

### main

- Loading the student data.

```
studentPtr vector init in main

void loudStudents(studentPtr vector REFERENCE):
	open up the students.csv file
	parse each line of the file for studentStrings
	create a Student instance (using pointers) on the heap
	Initialize that instance with the studentString from the csv file
	append that instance to the vector at the end
	close the file
```

- Deleting the student data.

```
studentPtr vector init in main

void delStudents(stdentPtr vector REFERENCE):
	for each item in students vector
		delete item
```
- Printing the student data.
```
studentPtr vector init in main

void printStudents(studentPtr vector REFERENCE)
	for each item in students vector
		item printStudent();

```
- Showing students last name and first name.

```
studentPtr vector init in main

void showStudentNames(studentPtr vector REFERENCE)
	for each item in students vector
		print item getLastFirst()
```

- Finding students by their last name.

```

studentPtr vector init in main

void findStudent(studentPtr vector REFERENCE)
	init string searchName, lastName
	init int counter as 1
	init bool results as false
	prompt user for last name
	store input in searchName
	for each student in the vector
		stringstream parse for last name
		store last name in lastName
		search last name for searchName
		if lastName contains searchName
			results is true
			print counter
			print student info
			add one to the counter
	if results remain false
		print no results found 	
```

- Prompting the menu.

```
string menu()
	print 0 to quit
	print 1 to print all names
	print 2 to print all data
	print 3 to find a student
	initialize string choice
	store user input in choice
	return choice
```


