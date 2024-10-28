# Module 8 Journal 
## Questions
#### Summarize the project and what problem it was solving.

The objective of this project was to create a program that allows user input and simultaneously displays a 12- and 24-hour clock.

The program must allow users to change the hour, minute, and second.

#### What did you do particularly well?

My code was modular, well-documented, and clean. I demonstrated industry best practices by writing in-line comments to explain what my code achieved and used proper C++ naming conventions for my function names, variables, and parameters.

#### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

My code could be improved by implementing stronger error handling, in the form of try/catch statements, and taking into account edge cases. This can ensure a smoother user experience, as the user won’t simply be kicked out of the program if they enter the wrong inputs.

The modularity of my code could also be improved by creating a class for Time objects. This Time class neatly store related methods and fields.

#### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

I found it most challenging to write the functions for formatting 12-hour vs. 24-hour time. Since each time format has specific constraints, like differentiating between noon and midnight in 12-hour time, I had to make sure that my code was able to handle edge cases. I had the C++ language documentation open while I was writing this code!

#### What skills from this project will be particularly transferable to other projects or course work?

The skills of problem-solving, writing clean code, and understanding how branching and looping works, will translate to other programming projects and courses.

#### How did you make this program maintainable, readable, and adaptable?
I made this program maintainable by using modular design. My code is divided into relevant functions that have specific operations, which makes it easier to identify bugs, make improvements, and reuse code. 

My program is also readable because I used descriptive and concise naming conventions. Function names like displayClock() and getHour() make it obvious what they do at a glance, without having to understand how the functions are implemented.

Lastly, my program is adaptable because I use several helper functions to separate concerns. This makes it easy to build new functionalities on top of existing code or to change the outcome of this program.
