# so_long
The objective of this project is to create a simple 2D game using **MiniLibX** library. Read **so_long.pdf** file to understand the task.  
  
This project is developed for **Linux**. **MiniLibX** for Linux requires ***xorg***, ***x11*** and ***zlib***, therefore you will need to install the following dependencies: ***xorg***, ***libxext-dev*** and ***zlib1g-dev***. Installing these dependencies on Ubuntu can be done as follows:  
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev
```  
Now all thats left is to configure MLX, just run the `configure` script in the root of the `mlx_linux` folder, and you are good to go.
For more information about **MiniLibX** please refer to https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
