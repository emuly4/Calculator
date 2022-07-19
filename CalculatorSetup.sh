# Get System Updates and Upgrades
sudo apt-get update
sudo apt-get upgrade

# INSTALL PROGRAMMING APPS & LIBS: GIT (version control), MELD (file differences), code (Visual Studio Code), AND AVRDUDE (avr programming)
sudo apt-get install -y build-essential git meld gcc-avr avr-libc avrdude code cmake

# Remove Mode Manager Which Causes Issues with programming
sudo apt-get purge modemmanager
sudo apt-get autoremove

# SETUP UDEV RULES FOR CALC
sudo sh -c 'echo "SUBSYSTEMS==\"usb\", KERNEL==\"ttyACM[0-9]*\", ACTION==\"add\", ATTRS{idVendor}==\"239a\", ATTRS{idProduct}==\"000e\", MODE=\"0666\", SYMLINK+=\"ttyCalc\", GROUP=\"dialout\" " > /etc/udev/rules.d/99-calc.rules'

sudo udevadm control --reload-rules && sudo service udev restart && sudo udevadm trigger
