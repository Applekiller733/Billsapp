# Billsapp

## Description

This is an app I made to further practice working with the Qt Framework for C++. It's a basic app that allows the user to filter a list of bills by paid/unpaid bills, aswell as calculate their total unpaid bills for a selected company.



1. Visualizes all the bills in a list (QListWidget). The list will display the 
company name, serial of the bill and the sum. When the application starts, the list is populated
automatically and the elements are sorted by company name.

3. Shows all unpaid bills with a red background in the list. Allows the user to filter the 
list by paid/unpaid bills (QCheckBox).

4. Calculates the total of unpaid bills, for a given company. Input the name of the company 
in a QLineEdit and when the button “Calculate total” is clicked, shows the total sum of 
the unpaid bills (in a QLineEdit). Shows an error message if 
there are no such companies.
