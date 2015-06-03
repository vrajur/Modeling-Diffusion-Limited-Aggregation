# Modeling-Diffusion-Limited-Aggregation
Authors: Vinay Rajur

Last Updated: 6/3/2015


Summary:
-------------------------------------------------------------------------------
A project to simulate the physical mechanism underlying some types of crystal 
formation processes. The goal of this project is to study the effectiveness and
limitations of the numerical model in simulating the process of Diffusion 
Limited Aggregation.


Operation Instructions:
-------------------------------------------------------------------------------
[TO BE COMPLETED: Brief Description on How to Use Code]


Implementation Overview:
-------------------------------------------------------------------------------
[TO BE COMPLETED: Semi-Detailed Overview on Implementation]


Repository Overview:
-------------------------------------------------------------------------------
Project Report: Modeling Diffusion Limited Aggregation.pdf

Source Code: Contains C++ files which are the numerical model implementation
	as well as MATLAB files for plotting and data analysis 
	
LaTeX Source: Contains LaTeX source files used for creating the project report


Directory of Key Files:
-------------------------------------------------------------------------------

**Source Code/final.cpp**
- Script to initialize parameters, run DLA simulation, and output particle 
	locations to text file 
	
**Source Code/r_walk.h**
- Function to test properties of the random walk model used in final.cpp

**Source Code/p_neighbors.h**
- Function to calculate and return the probability (as a function of neighboring 
	particles)of a particle sticking to the aggregate

**Source Code/p_curvature.h**
- Function to calculate and return the probability (as a function of local
	curvature of the aggregrate) of a particle sticking to the aggregate

**Source Code/p_coeff.h**
- Function to calculate and return the probability (as a constant-valued 
	function) of a particle sticking to the aggregate

**Source Code/arrayt.hpp**
- C++ array implementation supplied by professor (not authored by me)

**Source Code/MATLAB (plotting)/circularity.m **
- Script to calculate circularity of aggregate structure

**Source Code/MATLAB (plotting)/plott2.m**
- Script to read output data file containing particle locations and produce plot
	of aggregrate and calculate property values of the simulation

**Source Code/MATLAB (plotting)/rwalkstest.m **
- Script to analyze output data from r_walk.h

**LaTex Write Up/Final Project.tex **
- LaTeX file for project report

**LaTex Write Up/Final Project.bbl**
- BibTeX file containing bibliographic information for report





