# GOT-PROJECT-3

# Installation

Build and install restclient-cpp using vcpkg dependency manager:

git clone https://github.com/Microsoft/vcpkg.git  
cd vcpkg  
./bootstrap-vcpkg.sh  
./vcpkg integrate install  
./vcpkg install restclient-cpp  

After that, clone this repository and open the project with CLion.

Go to Settings > Build, Execution, Deployment > CMake

And finally in CMake options paste this: -DCMAKE_TOOLCHAIN_FILE=/home/user/vcpkg/scripts/buildsystems/vcpkg.cmake

Obviusly you need to change "/user/" for your username in ubuntu.



Rest Api
-----

### MySql Server
From the following link: https://linuxhint.com/install_mysql_ubuntu_20-04/
> _How to install MySQL Server DBMS on Ubuntu:_
> + Step 1
> + Step 2
> + Step 3  *( Validate: NO, Password: root )*
> See step 4 in https://devanswers.co/how-to-reset-mysql-root-password-ubuntu/#1-confirm-mysql-version  _*Note:*_ If it does not work, start from step 1 of this page.

### MySql Workbench
sudo /etc/init.d/mysql start
Search for mysql workbench in snap store.  
https://i.imgur.com/zVZYpbH.png  
Password:: root

### VSCode Dependencies
Open folder Rest-Api in VSCode.  
Run in terminal:
*Dependencies:*  
+ nmp install express mysql
+ npm install nodemon -D  
*Execute:*  
+ npm run dev
