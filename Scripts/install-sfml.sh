sudo /sbin/ldconfig
sudo apt-get install libpthread-stubs0-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libx11-dev
sudo apt-get install libxrandr-dev
sudo apt-get install libfreetype6-dev
sudo apt-get install libglew1.5-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libsndfile1-dev
sudo apt-get install libopenal-dev
sudo apt-get install libudev-dev
sudo apt-get install libxcb-icccm4-dev
sudo apt-get install libxcb-image0-dev
sudo apt-get install libxcb-util0-dev

git clone https://github.com/LaurentGomila/SFML.git sfml-repository
cd sfml-repository
git pull origin master
cd ..
cd sfml-repository
echo "Build shared release..."
sudo cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=TRUE . > install.log
sudo make >> install.log
sudo make install >> install.log
echo "Build shared debug..."
sudo cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=TRUE . >> install.log
sudo make >> install.log
sudo make install >> install.log
echo "Build static release..."
sudo cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=FALSE . >> install.log
sudo make >> install.log
sudo make install >> install.log
echo "Build static debug..."
sudo cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=FALSE . >> install.log
sudo make >> install.log
sudo make install >> install.log
cd ..
less < sfml-repository/install.log
