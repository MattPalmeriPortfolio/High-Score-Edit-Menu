# High-Score-Edit-Menu

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	High_Score_Editing_Menu.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 8. Project 19.
A program displays a menu system that allows the user to edit a list of top 10 high scores in various ways. Demonstrates ability to create functional menu systems with editing options in c++.
Written using Microsoft Visual Studio. 

## Algorithm

1. store names and scores
	- names should be in their own array, same with scores - indexes should line up
2. begin menu
	2a. add new player and score - if in top 10, add to list SUBTASK 1
		- take input of name and score
		- check if score is higher than score in index 9
			if so, bubble sort the score to its proper space
			if it is not higher, print a message telling the user the score does not make it into the top 10.
		- iterate through the names list, placing the names in the same indexes as their scores
	2b. print top 10 names and scores sorted by highest to lowest
		- routine, as scores are automatically sorted during other menu commands
	2c. allow user to enter a name and output that name's highest score SUBTASK 2
		- starting from index 0, compare name to names in list
			if it appears, print name and score for the corresponding index
			if it does not appear, print message to user that name was not found in top 10
	2d. allow user to enter a player name and remove the highest score for that player from the list SUBTASK 2
		- starting from index 0, compare name to names in list
			if found, remove score from that index and iterate the rest up 1 spot, leaving spot 10 empty SUBTASK 1
	2e. allow user to exit
		- routine

## Requirements
No requirements or modules needed for running this program.
