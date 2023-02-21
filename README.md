Author: Ethan Sims, ea.sims@me.com

This project was a school assignment from the Colorado School of Mines CSCI404 course.

The goal of this project was to implement the A* Search algorithm using an input map formatted properly in a txt file. This implementation does not store visited nodes in order to minimize memory usage.

Since the aim of this program was to simply implement the algorithm, I did not program error handling related to user input (command-line arguments and input file).

Command-line input format: ./find_route.exe input_file_path startCityName destinationCityName

Input file format: City1 City2 Distance(integer in km) City2 City3 Distance(integer in km) City2 City4 Distance(integer in km) ... END OF INPUT

Outputs the total distance, then the route with distance between each city.