/*
 *  Date: Sept 23, 2024
 *  Author: Isabel K. Lee
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// create global variables to store hour, minute, and second values that all functions can access
unsigned int HOUR;
unsigned int MINUTE;
unsigned int SECOND;

// this function takes an integer and formats it into a 2-digit string
string twoDigitString(unsigned int n) {

  // create a string variable that converts and stores the integer into a string
  string str = to_string(n);

  // conditional that checks if the integer is between 0 and 9, inclusive
  if (n >= 0 && n <= 9) {

    // add a 0 in front of the string
    str = "0" + str;

    // return the updated string
    return str;

  // if it's not, assume that it's between 10 and 59
  // simply return the string as is
  } else {
    return str;
  }
}

// this function takes an integer and a character
// and outputs a string of the character multiplied by the given integer
string nCharString(size_t n, char c) {
  return string(n, c);
}

// this function takes 3 integers and turns them into a 24-hour time format
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
  // stringify the hour, minute, and second values
  string hour = twoDigitString(h);
  string minute = twoDigitString(m);
  string second = twoDigitString(s);

  // create a new string with the proper format
  string newStr = hour + ":" + minute + ":" + second;
  return newStr;
}

// this function takes 3 integers and turns them into a 12-hour time format
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
  // the AM/PM value as a boolean
  bool AM = true;

  // check if the hour is between 12-23
  if (h >= 12) {
    // then AM is false, so the time is in PM
    AM = false;
    // subtract 12 from the hour
    h = h - 12;
  }

  // if the hour is 0, meaning that it's 12PM
  if (h == 0) {
    // reassign it to 12
    h = 12;
  }

  // stringify the hour, minute, and second values
  string hour = twoDigitString(h);
  string minute = twoDigitString(m);
  string second = twoDigitString(s);
  string newStr = hour + ":" + minute + ":" + second;

  // return the new time string, plus the AM/PM value
  return newStr.append(AM ? " A M" : " P M");
}

// this function prints a formatted menu
void printMenu(char * strings[], unsigned int numStrings, unsigned char width) {
  // print a line of stars that's the length of the given width value
  // the Sense tool insisted that this width parameter by typed as a char
  // so I wasn't able to reuse my nCharString(n, c) function
  // because of the mismatching param types
  cout << string(width, '*') << endl;

  string tempString;
  // store the calculated line width for each menu option
  int lineWidth;

  // iterate the number of times given by numStrings
  for (int i = 0; i < numStrings; ++i) {
    // format each menu option and store it in the temporary string
    tempString = "* " + to_string(i+1) + " - " + strings[i];
    // calculate the number of whitespaces needed
    lineWidth = width - tempString.length() - 1;
    // print the formatted menu option
    cout << tempString << string(lineWidth, ' ') << '*' << endl;

    // print a blank line for each menu option
    // except for the last one
    if (i != numStrings - 1) {
      cout << endl;
    }
  }

  // print a line of stars
  cout << string(width, '*') << endl;
}

// this function gets the user's input
unsigned int getMenuChoice(unsigned int maxChoice) {
  unsigned int userInput;
  // create boolean condition to keep the while loop running
  bool continueInput = true;

  while (continueInput) {
    // prompt the user for their input while continueInput is true
    cin >> userInput;

    // if the user enters a number that is between 1 and the maximum choice, inclusive
    // exit the loop
    if (userInput > 0 && userInput <= maxChoice) {
      continueInput = false;
    // otherwise, print an error message and continue prompting the user
    } else {
      cout << "Please enter a valid option: " << endl;
    }
  }

  // return the user's input
  return userInput;
}

// this function takes the hour, minute, and seconds and formats them in both 12-hour and 24-hour time
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
  // Print a line consisting of 27 stars, 3 spaces, and another 27 stars.
  cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

  // Print a line consisting of 1 star, 6 spaces, "12-HOUR CLOCK", 6 spaces, another star, and 3 spaces.
  cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');

  // Print a line consisting of 1 star, 6 spaces, "24-HOUR CLOCK", 6 spaces, another star, and a line break.

  cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;

  // Print a blank line.
  cout << endl;

  // Print a line consisting of 1 star, 6 spaces, the formatted time in 12-hour clock format, 7 spaces, another star, and 3 spaces.
  cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h,m,s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');

  // Print a line consisting of 1 star, 8 spaces, the formatted time in 24-hour clock format, 9 spaces, another star, and a line break.
  cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h,m,s) << nCharString(9, ' ') << nCharString(1, '*') << endl;

  // Print a line consisting of 27 stars, 3 spaces, and another 27 stars.
  cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

// this function gets the hour from the user's input
int getHour() {
  cout << "Enter the hour: " << endl;
  cin >> HOUR;

  // if the user enters an invalid hour
  // display an error message and continue prompting them
  if (HOUR > 23) {
    cout << "Please enter a valid hour between 0-23: " << endl;
    getHour();
  }

  return HOUR;
}

// this function operates the same way as getHour()
int getMinute() {
  cout << "Enter the minute: " << endl;
  cin >> MINUTE;

  if (MINUTE > 59) {
    cout << "Please enter a valid minute between 0-59: " << endl;
    getMinute();
  }

  return MINUTE;
}

// this function operates the same way as getSecond()
int getSecond() {
  cout << "Enter the second: " << endl;
  cin >> SECOND;

  if (SECOND > 59) {
    cout << "Please enter a valid second between 0-59: " << endl;
    getSecond();
  }

  return SECOND;
}

// this function sets the global variable to the given hour value
void setHour(unsigned int h) {
  HOUR = h;
}

// this function operates the same way as setHour()
void setMinute(unsigned int m) {
  MINUTE = m;
}

// this function operates the same way as setMinute()
void setSecond(unsigned int s) {
  SECOND = s;
}

// this function adds 1 hour to the global HOUR variable
void addOneHour() {
  int newHour;

  // if the current hour is less than 23
  if (HOUR < 23) {
    // add 1 to the hour and set it
    newHour = ++HOUR;
    setHour(newHour);
  // otherwise, if the hour is 24, set it to 0
  } else {
    setHour(0);
  }

  cout << "New hour: " << HOUR << endl;
}

// this function operates the same way as addOneHour()
void addOneMinute() {
  int newMinute;

  if (MINUTE < 59) {
    newMinute = ++MINUTE;
    setMinute(newMinute);
  } else {
    setMinute(0);
    // add 1 hour since the minute has reached 60
    addOneHour();
  }

  cout << "New minute: " << MINUTE << endl;
}

// this function operates the same way as addOneMinute()
void addOneSecond() {
  int newSecond;

  if (SECOND <= 58) {
    newSecond = ++SECOND;
    setSecond(newSecond);
  } else {
    setSecond(0);
    // add 1 minute since the second has reached 60
    addOneMinute();
  }

  cout << "New minute: " << SECOND << endl;
}

void mainMenu() {
  // menu options
  char * strings[] = {"Add one hour", "Add one minute", "Add one second", "Exit program"};
  // print the menu with the above array of strings, the number of menu options, and the number of stars in a line
  printMenu(strings, 4, 26);

  cout << "Select a menu option: " << endl;
  // store the user's input in a variable
  int userInput = getMenuChoice(4);
  
  // conditional logic to execute the appropriate operations
  // depending on the user's input
  // recursively call the mainMenu() for inputs 1-3
  if (userInput == 1) {
    cout << "Add one hour" << endl;
    addOneHour();
    displayClocks(HOUR, MINUTE, SECOND);
    mainMenu();
  } else if (userInput == 2) {
    cout << "Add one minute" << endl;
    addOneMinute();
    displayClocks(HOUR, MINUTE, SECOND);
    mainMenu();
  } else if (userInput == 3) {
    cout << "Add one second" << endl;
    addOneSecond();
    displayClocks(HOUR, MINUTE, SECOND);
    mainMenu();
  // for any other input, including 4, exit the program
  } else {
    cout << "Good bye!" << endl;
  }
}

int main() {
  // get user input for initial time
  getHour();
  getMinute();
  getSecond();
  displayClocks(HOUR, MINUTE, SECOND);

  // display the main menu
  mainMenu();
  return 0;
}
