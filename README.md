Created by Sabeet A. Chowdhury
5/3/20

1. 
This is a Preemptive Round Robin Priority based scheduler for
Professor Svadlenka of CS340(Operating Sysytems)

2.
This is a program written in C++ that allows a user to insert
a tab delimitted process chart as a text file. Once the program
reads the chart, it takes in the values to output the turn around time
and wait time for each individual process aswell as the total turn around
time and wait time.

It contains:
    sabeetChowdhury_340Project3.cpp
    README.txt
    output.txt

3.
Challenges I had to face were reading from the delimited text 
file. There were alot of issues for me to debug but eventually, 
once I made my return/output from the text granular, i was able to 
achieve my goal of reading the numbers column by column. I was unable to 
create the round robin  scheduler accordingly. There were 
key issues in how I was implementing  it with queue so my code kept on 
falling apart in that regards even though I understand how the Gantt works. Specifically,
p1 and p6 would go missing and I wasn't sure for what reason. That ended up
affecting the individual wait time and turn around times.
I listened to the webex video as many times as I could but something was off
when it came to coding it. I hope to find a solution as I did enjoy 
coding this. This project singlehandedly changed my approach to
coding in C++ in general.

4. INSTRUCTIONS
this program was coded on a linux environment. I was using
gpp as my compiler

The text file used is named Book1.txt and that is hard coded 
into the program

the number of process is also hard coded. We have 6 for this 
project as there were only 6 in the given table

TO RUN CODE:
    On a linux terminal,
    $cd [desired directory with cpp and text file]
    $gpp sabeetChowdhury_340Project3.cpp
    $./a.out
