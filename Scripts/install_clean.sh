echo "Install last gc version"
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install g++-5

rm /usr/bin/g++
ln -s /usr/bin/g++-5 /usr/bin/g++
