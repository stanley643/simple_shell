#!/bin/bash

# Display a message indicating the script has started
echo "Starting Git Add, Commit, and Push"

# Add all changes to the staging area
git add .

# Commit the changes with a default commit message
git commit -m "code a code"

# Push the changes to the remote repository (assuming origin and master branch, modify if needed)
git push origin master

clear
#Display a message indicating the script has completed
echo "Git Add, Commit, and Push completed"

