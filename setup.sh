# Build source codes
find . -type d -name "_*" -exec make -C {} \;

# Move the bin folder to the home directory
mv ../bin ~/bin

# Add the following line to the end of the .zshrc file
echo "# Set PATH so it includes user's private bin if it exists
if [ -d "$HOME/bin" ] ; then
	PATH="$HOME/bin:$PATH"
fi" >> ~/.zshrc # or ~/.bashrc

# Change the permissions of the files in the bin folder
chmod + ~/bin/*
