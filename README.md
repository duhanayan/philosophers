# Philosophers Project
The Philosophers project is a simulation of the dining philosophers problem, which is a classic problem in computer science and concurrency. The problem involves a group of philosophers sitting around a table, with a chopstick placed between each pair of adjacent philosophers. The philosophers alternate between thinking and eating, but they need two chopsticks to eat. The challenge is to avoid deadlock and starvation while ensuring that all philosophers have a fair chance to eat.

## Installation
To use the Philosophers project, first clone the repository from GitHub:

`git clone https://github.com/duhanayan/philosophers.git`

Once you have the project files on your local machine, navigate to the root directory of the project and run the following command to compile the program:

`make`

This will create an executable file named philo. To run the program, use the following command:

`./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]`

Here, number_of_philosophers is the number of philosophers you want to simulate, time_to_die is the maximum time a philosopher can go without eating before they die, time_to_eat is the time it takes for a philosopher to eat, time_to_sleep is the time it takes for a philosopher to sleep, and number_of_times_each_philosopher_must_eat is the number of times each philosopher must eat before the simulation ends (optional).

## Usage
Once you have run the program, the philosophers will start thinking and eating according to the specified parameters. The program will display messages to indicate when a philosopher starts thinking, starts eating, and dies. If a philosopher goes too long without eating, they will die and the program will display a message indicating their death.

The program will run until all philosophers have eaten the required number of times or until a philosopher dies.

## Examples
To simulate 5 philosophers with a time-to-die of 800 ms, a time-to-eat of 200 ms, and a time-to-sleep of 200 ms, use the following command:

`./philo 5 800 200 200`

To simulate 5 philosophers with a time-to-die of 800 ms, a time-to-eat of 200 ms, a time-to-sleep of 200 ms, and a requirement to eat 7 times each, use the following command:

`./philo 5 800 200 200 7`
