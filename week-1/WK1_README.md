# Learning C

First time writing in C is frustrating because of the syntax hang ups (leaving out a parenthesis) it is the priniciples are important. The rest will come with muscle memory etc. 

 Source code (written in any language) gets compiled (by a compiler) into "machine code"
 
 
 

The closest equivelent to "ask" function in scratch example "what is your name" is get_string 

So if I wanted to ask someones name in C I would type:

`get_string("what is your name?\n");`

Now once I ask the user for their name with the above function and to do this, you can use this: 

`string answer = get_string("what is your name?\n");`

In C you can think of the logic as running from right to left. So the equal sign (=) in the above does not mean that string answer is equal to "what is your name" but rather that 

string answer has been assigned the meaning "what is your name".

So in scratch there was a "say function" but in C you use `printf`

But you dont just want to put "hello, answer" because it will literally say hello answer. The way to join the users input is: 


`printf("hello, %s\n");`

The percent (%) and the s (for string) is the place holder for the answer - since we do not know what the answer is going to be in advance. 

You separate arguments with commas 

NOTE: code executes right to left in C 


`# include <cs50.h>`
`# include <stdio.h>
int main(void)
{ 
string answer = get_string("whats your name?\n");
printf("hello, %s\n", answer);
}`

There are lots of different types of variables - strings (characters) and integers (numbers) for example. 

With C you have to tell it what type of variable the variable is - so if we wanted numbers we would say 

`int`

In scratch we had a counter to tell the cat how many times to meow. If we wanted that in C we could do 

`int counter = 0;`

But how do we incremental increases for counter you would add +1 or ++

How do we do a condition? 

```if (x<y)
 
{
printf("x is less than y/n");
}

else

{
printf("x is not less than y/n");
}```

Double = (==) means = in the conventional way because is in C a single = sign is just an "assignment" 

So if you wanted to create a loop that is a fixed number of times you would write something like this

```
int i =0;
while (i<50)
{
printf("hello, world\n")
i++;
}```

What that means is that the variable i which stands for integer starts at 0, and while that number is less than 50, the program should print "hello world", the bottom of the code i++ refers to the fact that each time this happens another 1 is added to the integer - so it starts at 0 and then when the code runs once it goes ip to 1 and then when it runs again it goes up to 2. Now, you could do this in a more succinct way with a for loop 

```for (int 1=0; i<50; 1++)
{
printf("hello, world\n")
}```

The above has all the same logic, just done in a "neater" way 

So if I wanted to create a little app that tells you your age in days I would do this: 

```
int age = get_int("what is your age?\n");
int days = age * 365;
printf("you are atleast %i days old.\n", days);```

What the above means that the int age in this instanse is the input from the user of how old they are in years 
in days transforms that number of years into days 
printf is asking for the % (which is a place holder for the number of integers - in this instance days) to the variable days

I could do the same thing with a variable called a float (which just means that it allows decimals)


```
float price = get_float("what is the price?\n");
printf("your total is %2f.\n", price * 5.20;```

So the above I just take the input which is the price and add tax with the section "price * 5.20" - the 5.20 is just the made up tax rate I added. The 2f is so that I only see 2 decimal points. 










