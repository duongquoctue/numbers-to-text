# Numbers to text representation.

# The workflow:
* First, the user will input the number (limited by max/min of "long int" C++ type), the program will check if the value is correct or not.
* Then, the program will do the job of displaying the text representation. It reads the input number by group of 3 digits, then match the group of digits with the corresponding text string in "resource.h".
* Then, join the group of 3 digits to make a complete text representation of the number.
* Finally, display the result on the screen.

# The architecture:
* The program contains two class: User class and NumsToText class (derived from the User class).
* User class is used to handle input from the user, hence checking for positive/negative number.
* Then, the input will be handled by the NumsToText class, to read the number by group of 3 digits using read_group() and joining them by read_number(), then display the text representation.
* Also, the "resource.h" is used for storing the text strings, for flexibility of changing it into other languages.

